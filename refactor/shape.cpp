#include "shape.h"


Shape::Shape(ShapeType _type, int _x1, int _y1, int _z1, int _x2, int _y2, int _z2, 
             int _x3, int _y3, int _z3, int _x4, int _y4, int _z4, int _x5, int _y5, int _z5, 
             int _x6, int _y6, int _z6, int _x7, int _y7, int _z7, int _x8, int _y8, int _z8)
    : type(_type) 
{
    setPoint(0, _x1, _y1, _z1);
    setPoint(1, _x2, _y2, _z2);
    setPoint(2, _x3, _y3, _z3);
    setPoint(3, _x4, _y4, _z4);
    setPoint(4, _x5, _y5, _z5);
    setPoint(5, _x6, _y6, _z6);
    setPoint(6, _x7, _y7, _z7);
    setPoint(7, _x8, _y8, _z8);
    
    calculateSquareAndVolume();
}

Shape::Shape(ShapeType _type, int _x1, int _y1, double R, double H)
    : type(_type), radius(R), height(H) 
{
    setPoint(0, _x1, _y1, 0); 
    calculateSquareAndVolume();
}

void Shape::calculateSquareAndVolume() {
    switch (type) {
    case ShapeType::Line:
        square = 0;
        volume = 0;
        break;
    case ShapeType::Square: {
        auto [x1, y1, z1] = getPoint(0);
        auto [x2, y2, z2] = getPoint(1);
        square = std::abs(x1 - x2) * std::abs(y1 - y2);
        volume = 0;
        break;
    }
    case ShapeType::Cube: {
        auto [x1, y1, z1] = getPoint(0);
        auto [x2, y2, z2] = getPoint(1);
        int a = std::abs(x1 - x2);
        int b = std::abs(y1 - y2);
        int c = std::abs(z1 - z2);
        square = 2 * (a * b + a * c + b * c);
        volume = a * b * c;
        break;
    }
    case ShapeType::Circle:
        square = M_PI * radius * radius;
        volume = 0;
        break;
    case ShapeType::Cylinder:
        square = 2 * M_PI * radius * (radius + height);
        volume = M_PI * radius * radius * height;
        break;
    default:
        break;
    }
}
