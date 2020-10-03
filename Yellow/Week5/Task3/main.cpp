#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
#include <memory>
#include <iomanip>

using namespace std;

class Figure{
public:
    virtual string Name() const = 0;
    virtual double Perimeter() const = 0;
    virtual double Area() const = 0;
};

class Triangle: public Figure{
public:
    Triangle(const double& a, const double& b, const double& c){
        this->a = a;
        this->b = b;
        this->c = c;
    }

    string Name() const override{
        return "TRIANGLE";
    }

    double Perimeter() const override{
        return a + b + c;
    }

    double Area() const override{
        double p = Perimeter() / 2;

        return sqrt(p*(p-a)*(p-b)*(p-c));
    }
private:
    double a, b, c;
};

class Rect: public Figure{
public:
    Rect(const double& w, const double& h){
        width = w;
        height = h;
    }
    string Name() const override{
        return "RECT";
    }

    double Perimeter() const override{
        return width*2 + height*2;
    }

    double Area() const override{
        return width * height;
    }

private:
    double width, height;
};

class Circle: public Figure{
public:
    Circle(double r){
        radius = r;
    }

    string Name() const override{
        return "CIRCLE";
    }

    double Perimeter() const override{
        return 2 * pi * radius;
    }

    double Area() const override{
        return pi * radius * radius;
    }

private:
    const double pi = 3.14;
    double radius;
};

shared_ptr<Figure> CreateFigure(istringstream& is){
    string figure;
    is >> figure;

    if (figure == "RECT"){
        double w, h;
        is >> w >> h;

        return make_shared<Rect>(w, h);
    } else if (figure == "CIRCLE"){
        double r;
        is >> r;

        return make_shared<Circle>(r);
    } else {
        double a, b, c;
        is >> a >> b >> c;

        return make_shared<Triangle>(a, b, c);
    }
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}
