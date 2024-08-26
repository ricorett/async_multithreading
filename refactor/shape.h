#pragma once
#include <cmath>
#include <string>
#include <array>

enum class ShapeType {
    Line,
    Square,
    Cube,
    Circle,
    Cylinder
};

class Shape {
public:
    Shape() = default;
    Shape(ShapeType type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, 
          int _x3 = 0, int _y3 = 0, int _z3 = 0, int _x4 = 0, int _y4 = 0, int _z4 = 0, 
          int _x5 = 0, int _y5 = 0, int _z5 = 0, int _x6 = 0, int _y6 = 0, int _z6 = 0, 
          int _x7 = 0, int _y7 = 0, int _z7 = 0, int _x8 = 0, int _y8 = 0, int _z8 = 0);
    Shape(ShapeType type, int _x1, int _y1, double R, double H = 0);

    ShapeType getType() const { return type; }

    std::array<int, 3> getPoint(int index) const;
    void setPoint(int index, int x, int y, int z);

private:
    void calculateSquareAndVolume();

    ShapeType type;
    std::array<int, 8> x_coords = {0};
    std::array<int, 8> y_coords = {0};
    std::array<int, 8> z_coords = {0};

    double volume = 0;
    double square = 0;
    double height = 0;
    double radius = 0;
};


std::array<int, 3> Shape::getPoint(int index) const {
    return {x_coords[index], y_coords[index], z_coords[index]};
}


void Shape::setPoint(int index, int x, int y, int z) {
    x_coords[index] = x;
    y_coords[index] = y;
    z_coords[index] = z;
}
