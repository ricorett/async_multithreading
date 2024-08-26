#include "transform.h"

Transform::Transform(const Shape& sh) : shape(sh) {}

void Transform::shiftCoordinates(int m, int n, int k) {
    for (int i = 0; i < 8; ++i) {
        auto [x, y, z] = shape.getPoint(i);
        shape.setPoint(i, x + m, y + n, z + k);
    }
}

void Transform::scaleCoordinatesX(int factor) {
    for (int i = 0; i < 8; ++i) {
        auto [x, y, z] = shape.getPoint(i);
        shape.setPoint(i, x * factor, y, z);
    }
}

void Transform::scaleCoordinatesY(int factor) {
    for (int i = 0; i < 8; ++i) {
        auto [x, y, z] = shape.getPoint(i);
        shape.setPoint(i, x, y * factor, z);
    }
}

void Transform::scaleCoordinatesZ(int factor) {
    for (int i = 0; i < 8; ++i) {
        auto [x, y, z] = shape.getPoint(i);
        shape.setPoint(i, x, y, z * factor);
    }
}

Shape Transform::shift(int m, int n, int k) {
    shiftCoordinates(m, n, k);
    return shape;
}

Shape Transform::scaleX(int a) {
    scaleCoordinatesX(a);
    return shape;
}

Shape Transform::scaleY(int d) {
    scaleCoordinatesY(d);
    return shape;
}

Shape Transform::scaleZ(int e) {
    scaleCoordinatesZ(e);
    return shape;
}

Shape Transform::scale(int s) {
    scaleCoordinatesX(s);
    scaleCoordinatesY(s);
    scaleCoordinatesZ(s);
    return shape;
}
