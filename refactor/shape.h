#pragma once
#include <cmath>
#include <string>
#include <array>
#include <array>
#include <cmath>

enum class ShapeType {
    Line,
    Rectangle,
    Square,
    Cube,
    Circle,
    Cylinder
};

class Shape {
public:
    Shape(ShapeType type) : type(type) {}
    virtual ~Shape() = default;

    ShapeType getType() const { return type; }
    virtual double getSquare() const = 0;
    virtual double getVolume() const = 0;

    virtual void shift(int m, int n, int k);
    virtual void scaleX(int a);
    virtual void scaleY(int d);
    virtual void scaleZ(int e);
    virtual void scale(int s);

protected:
    ShapeType type;
    std::array<int, 8> x_coords = {0};
    std::array<int, 8> y_coords = {0};
    std::array<int, 8> z_coords = {0};

    void setPoint(int index, int x, int y, int z) {
        x_coords[index] = x;
        y_coords[index] = y;
        z_coords[index] = z;
    }

    std::array<int, 3> getPoint(int index) const {
        return {x_coords[index], y_coords[index], z_coords[index]};
    }

    void shiftCoordinates(int m, int n, int k);
    void scaleCoordinatesX(int factor);
    void scaleCoordinatesY(int factor);
    void scaleCoordinatesZ(int factor);
};

void Shape::shift(int m, int n, int k) {
    shiftCoordinates(m, n, k);
}

void Shape::scaleX(int a) {
    scaleCoordinatesX(a);
}

void Shape::scaleY(int d) {
    scaleCoordinatesY(d);
}

void Shape::scaleZ(int e) {
    scaleCoordinatesZ(e);
}

void Shape::scale(int s) {
    scaleCoordinatesX(s);
    scaleCoordinatesY(s);
    scaleCoordinatesZ(s);
}

void Shape::shiftCoordinates(int m, int n, int k) {
    for (int i = 0; i < 8; ++i) {
        auto [x, y, z] = getPoint(i);
        setPoint(i, x + m, y + n, z + k);
    }
}

void Shape::scaleCoordinatesX(int factor) {
    for (int i = 0; i < 8; ++i) {
        auto [x, y, z] = getPoint(i);
        setPoint(i, x * factor, y, z);
    }
}

void Shape::scaleCoordinatesY(int factor) {
    for (int i = 0; i < 8; ++i) {
        auto [x, y, z] = getPoint(i);
        setPoint(i, x, y * factor, z);
    }
}

void Shape::scaleCoordinatesZ(int factor) {
    for (int i = 0; i < 8; ++i) {
        auto [x, y, z] = getPoint(i);
        setPoint(i, x, y, z * factor);
    }
}

class Line : public Shape {
public:
    Line(int x1, int y1, int z1, int x2, int y2, int z2)
            : Shape(ShapeType::Line) {
        setPoint(0, x1, y1, z1);
        setPoint(1, x2, y2, z2);
    }

    double getSquare() const override { return 0; }
    double getVolume() const override { return 0; }
};

class Rectangle : public Shape {
public:
    Rectangle(int x1, int y1, int x2, int y2)
            : Shape(ShapeType::Rectangle) {
        setPoint(0, x1, y1, 0);
        setPoint(1, x2, y2, 0);
    }

    double getSquare() const override {
        auto [x1, y1, _] = getPoint(0);
        auto [x2, y2, _] = getPoint(1);
        return std::abs(x1 - x2) * std::abs(y1 - y2);
    }

    double getVolume() const override { return 0; }
};

class Square : public Rectangle {
public:
    Square(int x1, int y1, int side)
            : Rectangle(x1, y1, x1 + side, y1 + side) {
        type = ShapeType::Square;
    }
};

class Cube : public Shape {
public:
    Cube(int x1, int y1, int z1, int side)
            : Shape(ShapeType::Cube) {
        setPoint(0, x1, y1, z1);
        setPoint(1, x1 + side, y1 + side, z1 + side);
    }

    double getSquare() const override {
        auto [x1, y1, z1] = getPoint(0);
        auto [x2, y2, z2] = getPoint(1);
        int a = std::abs(x1 - x2);
        return 6 * a * a;
    }

    double getVolume() const override {
        auto [x1, y1, z1] = getPoint(0);
        auto [x2, y2, z2] = getPoint(1);
        int a = std::abs(x1 - x2);
        return a * a * a;
    }
};

class Circle : public Shape {
public:
    Circle(int x, int y, double radius)
            : Shape(ShapeType::Circle), radius(radius) {
        setPoint(0, x, y, 0);
    }

    double getSquare() const override { return M_PI * radius * radius; }
    double getVolume() const override { return 0; }

protected:
    double radius;
};

// Derived class for Cylinder
class Cylinder : public Circle {
public:
    Cylinder(int x, int y, double radius, double height)
            : Circle(x, y, radius), height(height) {
        type = ShapeType::Cylinder;
    }

    double getSquare() const override {
        return 2 * M_PI * radius * (radius + height);
    }

    double getVolume() const override {
        return M_PI * radius * radius * height;
    }

private:
    double height;
};
