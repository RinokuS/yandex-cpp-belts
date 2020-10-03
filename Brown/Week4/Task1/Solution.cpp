#include "Common.h"

using namespace std;

namespace Shapes{
    class Figure : public IShape{
    public:
        void SetPosition(Point point) override{
            point_ = point;
        }
        Point GetPosition() const override{
            return point_;
        }

        void SetSize(Size size) override{
            size_ = size;
        }
        Size GetSize() const override{
            return size_;
        }

        void SetTexture(std::shared_ptr<ITexture> texture) override{
            texture_ = texture;
        }
        ITexture* GetTexture() const override{
            return texture_.get();
        }

        // Рисует фигуру на указанном изображении
        void Draw(Image& image) const override{
            if (image.empty())
                return;

            const Image texture_image = texture_ ? texture_->GetImage() :
                                        Image(size_.height, std::string(size_.width, '.'));

            const int n = image.size();
            const int m = image[0].size();

            for (int y = point_.y; y < point_.y + size_.height; ++y) {
                for (int x = point_.x; x < point_.x + size_.width; ++x) {
                    if (y >= 0 && y < n && x >= 0 && x < m){
                        const Point point = Point{x - point_.x, y - point_.y};
                        const int y_index = y - point_.y;
                        const int x_index = x - point_.x;

                        if (CheckPointInShape(point)) {
                            if (CheckPointInTexture(point, texture_image)) {
                                image[y][x] = texture_image[point.y][point.x];
                            } else {
                                image[y][x] = '.';
                            }
                        }
                    }
                }
            }
        }

    private:
        Point point_;
        Size size_;
        shared_ptr<ITexture> texture_;

        bool CheckPointInTexture(Point point, const Image& texture_image) const
        {
            return point.y < texture_image.size() && point.x < texture_image[point.y].size();
        }

        virtual bool CheckPointInShape(Point) const = 0;
    };

    class Rectangle : public Figure{
    public:
        std::unique_ptr<IShape> Clone() const override{
            return make_unique<Rectangle>(*this);
        }
    private:
        bool CheckPointInShape(Point point) const override {
            return true;
        }
    };

    class Ellipse : public Figure{
    public:
        std::unique_ptr<IShape> Clone() const override{
            return make_unique<Ellipse>(*this);
        }
    private:
        bool CheckPointInShape(Point point) const override {
            return IsPointInEllipse(point, GetSize());
        }
    };
}

// Р­С‚РѕС‚ С„Р°Р№Р» СЃРґР°С‘С‚СЃСЏ РЅР° РїСЂРѕРІРµСЂРєСѓ
// Р—РґРµСЃСЊ РЅР°РїРёС€РёС‚Рµ СЂРµР°Р»РёР·Р°С†РёСЋ РЅРµРѕР±С…РѕРґРёРјС‹С… РєР»Р°СЃСЃРѕРІ-РїРѕС‚РѕРјРєРѕРІ `IShape`

// РќР°РїРёС€РёС‚Рµ СЂРµР°Р»РёР·Р°С†РёСЋ С„СѓРЅРєС†РёРё
unique_ptr<IShape> MakeShape(ShapeType shape_type) {
    unique_ptr<IShape> shape;

    if (shape_type == ShapeType::Rectangle){
        shape = make_unique<Shapes::Rectangle>();
    } else{
        shape = make_unique<Shapes::Ellipse>();
    }

    return shape;
}