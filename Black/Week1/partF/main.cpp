#include <iostream>
#include <optional>
#include <variant>
#include <string>
#include <utility>
#include <ostream>
#include <vector>
#include <cstdint>
#include <memory>

using namespace std;

namespace Svg{
    struct Point{
        double x, y;

        void Render(std::ostream& os) const
        {
            os << x << "," << y;
        }
    };

    struct Rgb{
        int red, green, blue;

        void Render(std::ostream& os) const
        {
            os << "rgb(" << red << "," << green << "," << blue << ")";
        }
    };

    class Color{
    private:
        std::optional<std::variant<std::string, Rgb>> color_;
    public:
        Color(){
            color_ = nullopt;
        }

        Color(string str){
            color_ = move(str);
        }

        Color(Rgb rgb){
            color_ = rgb;
        }

        Color(const Color& other){
            *this = other;
        }

        [[nodiscard]] const std::optional<std::variant<std::string, Rgb>>&
        GetColor() const
        {
            return color_;
        }

        void Render(std::ostream& os) const
        {
            if (color_)
            {
                const size_t index = color_->index();

                switch (index)
                {
                    case 0:
                        os << std::get<std::string>(*color_);
                        break;

                    case 1:
                        std::get<Rgb>(*color_).Render(os);
                        break;

                    default:
                        throw std::bad_variant_access();
                }
            }
            else
            {
                os << "none";
            }
        }
    };

    const Color NoneColor = Color();

    class SvgObject
    {
    public:
        virtual void Render(std::ostream&) const = 0;

        virtual ~SvgObject() = default;
    };

    class Document : public SvgObject{
    private:
        std::vector<std::unique_ptr<SvgObject>> objects_;
    public:
        Document() = default;

        template<typename ObjectClass>
        void Add(ObjectClass obj){
            objects_.emplace_back(make_unique<ObjectClass>(move(obj)));
        }

        void Render(ostream& os) const override{
            os << R"(<?xml version="1.0" encoding="UTF-8" ?>)";
            os << R"(<svg xmlns="http://www.w3.org/2000/svg" version="1.1">)";

            for(const auto& obj: objects_){
                obj->Render(os);
            }

            os << "</svg>";
        }
    };

    template <class SvgChild>
    class SvgBase : public SvgObject{
    private:
        Color fill_ = NoneColor;
        Color stroke_ = NoneColor;
        double stroke_width_ = 1.0;

        optional<string> stroke_linecap_ = nullopt;
        optional<string> stroke_linejoin_ = nullopt;
    public:
        SvgChild& GetChild()
        {
            return static_cast<SvgChild&>(*this);
        }

        template<typename ColorInit>
        SvgChild& SetFillColor(const ColorInit& color_init){
            fill_ = Color(color_init);
            return GetChild();
        }

        template<typename ColorInit>
        SvgChild& SetStrokeColor(const ColorInit& color_init){
            stroke_ = Color(color_init);
            return GetChild();
        }

        SvgChild& SetStrokeWidth(double width){
            stroke_width_ = width;
            return GetChild();
        }

        SvgChild& SetStrokeLineCap(const string& line_cap){
            stroke_linecap_ = line_cap;
            return GetChild();
        }

        SvgChild& SetStrokeLineJoin(const string& line_join){
            stroke_linejoin_ = line_join;
            return GetChild();
        }

        void Render(ostream& os) const override{
            os << "fill=\"";
            fill_.Render(os);
            os << "\" ";

            os << "stroke=\"";
            stroke_.Render(os);
            os << "\" ";

            os << "stroke-width=\"" << stroke_width_ << "\" ";

            if (stroke_linejoin_)
                os << "stroke-linejoin=\"" << *stroke_linejoin_ << "\" ";
            if (stroke_linecap_)
                os << "stroke-linecap=\"" << *stroke_linecap_ << "\" ";
        }
    };

    class Circle : public SvgBase<Circle>{
    private:
        Point centre_;
        double radius_;
    public:
        Circle() : centre_(Point{0,0}), radius_(1.0) {}

        Circle& SetCenter(Point point){
            centre_ = point;
            return *this;
        }

        Circle& SetRadius(double rad){
            radius_ = rad;
            return *this;
        }

        void Render(ostream& os) const override{
            os << "<circle ";

            SvgBase<Circle>::Render(os);
            os << "cx=\"" << centre_.x << "\" cy=\"" << centre_.y << "\" ";
            os << "r=\"" << radius_ << "\" ";

            os << "/>";
        }
    };

    class Polyline : public SvgBase<Polyline>{
    private:
        vector<Point> points_;
    public:
        Polyline& AddPoint(Point point){
            points_.push_back(point);
            return *this;
        }

        void Render(ostream& os) const override{
            os << "<polyline ";

            SvgBase<Polyline>::Render(os);

            os << "points=\"";
            for(const auto& point: points_){
                point.Render(os);
                os << " ";
            }

            os << "/>";
        }
    };

    class Text : public SvgBase<Text>{
    private:
        Point text_coords_ = Point{0,0};
        Point text_offset_ = Point{0,0};
        uint32_t font_size_ = 1;
        string data_;

        optional<string> font_family_ = nullopt;
    public:
        Text& SetPoint(Point point){
            text_coords_ = point;
            return *this;
        }

        Text& SetOffset(Point point){
            text_offset_ = point;
            return *this;
        }

        Text& SetFontSize(uint32_t size){
            font_size_ = size;
            return *this;
        }

        Text& SetFontFamily(const string& font_family){
            font_family_ = font_family;
            return *this;
        }

        Text& SetData(const string& text){
            data_ = text;
            return *this;
        }

        void Render(ostream& os) const override{
            os << "<text ";

            SvgBase<Text>::Render(os);

            os << "x=\"" << text_coords_.x << "\" y=\"" << text_coords_.y << "\" ";
            os << "dx=\"" << text_offset_.x << "\" dy=\"" << text_offset_.y << "\" ";
            os << "font-size=\"" << font_size_ << "\" ";
            if (font_family_)
                os << "font-family=\"" << *font_family_ << "\" ";

            os << ">";
            os << data_ << "</text>";
        }
    };
}



int main() {
    Svg::Document svg;

    svg.Add(
            Svg::Polyline{}
                    .SetStrokeColor(Svg::Rgb{140, 198, 63})  // soft green
                    .SetStrokeWidth(16)
                    .SetStrokeLineCap("round")
                    .AddPoint({50, 50})
                    .AddPoint({250, 250})
    );

    for (const auto point : {Svg::Point{50, 50}, Svg::Point{250, 250}}) {
        svg.Add(
                Svg::Circle{}
                        .SetFillColor("white")
                        .SetRadius(6)
                        .SetCenter(point)
        );
    }

    svg.Add(
            Svg::Text{}
                    .SetPoint({50, 50})
                    .SetOffset({10, -10})
                    .SetFontSize(20)
                    .SetFontFamily("Verdana")
                    .SetFillColor("black")
                    .SetData("C")
    );
    svg.Add(
            Svg::Text{}
                    .SetPoint({250, 250})
                    .SetOffset({10, -10})
                    .SetFontSize(20)
                    .SetFontFamily("Verdana")
                    .SetFillColor("black")
                    .SetData("C++")
    );

    svg.Render(std::cout);

    return 0;
}
