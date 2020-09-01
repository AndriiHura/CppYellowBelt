// PA3_FiguresSet.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

class Figure {
public:
    virtual string Name() const = 0;

    virtual double Perimeter() const = 0;

    virtual double Area() const = 0;

    virtual ~Figure() = default;

};

class Triangle : public Figure {
public:

    Triangle(const string& name_in, double a_in, double b_in, double c_in)
        : name(name_in), a(a_in), b(b_in), c(c_in){}

    virtual string Name() const override {
        return name;
    }

    virtual double Perimeter() const override {
        return a + b + c;
    }

    virtual double Area() const override {
        double p = Perimeter() / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

private:
    const string name;
    const double a, b, c;
};

class Rect : public Figure {
public:

    Rect(const string& name_in, double width_in, double height_in)
        : name(name_in), width(width_in), height(height_in) {}

    virtual string Name() const override {
        return name;
    }

    virtual double Perimeter() const override {
        return width * 2 + height * 2;
    }

    virtual double Area() const override {
        return width * height;
    }

private:
    const string name;
    const double width, height;
};

class Circle : public Figure {
public:
    Circle(const string name_in, const double R_in)
        : name(name_in), R(R_in) {}

    virtual string Name() const override {
        return name;
    }

    virtual double Perimeter() const override {
        return 2 * PI * R;
    }

    virtual double Area() const override {
        return PI * R * R;
    }

private:
    const string name;
    const double R;
    const double PI = 3.14;
};


shared_ptr<Figure> CreateFigure(istringstream& is) {
    string figureName;
    is >> figureName;

    if (figureName == "RECT") {
        double width, height;
        is >> width>> height;
        return make_shared<Rect>(figureName, width, height);
    }
    else if (figureName == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(figureName, a, b, c);
    }
    else if (figureName == "CIRCLE") {
        double R;
        is >> R;
        return make_shared<Circle>(figureName, R);
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
        }
        else if (command == "PRINT") {
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
