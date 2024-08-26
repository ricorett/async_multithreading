#pragma once
#include "shape.h"
#include <array>

class Transform {
public:
    Transform(const Shape& sh);
    
    Shape shift(int m, int n, int k);
    Shape scaleX(int a);
    Shape scaleY(int d);
    Shape scaleZ(int e);
    Shape scale(int s);

private:
    Shape shape;

    void shiftCoordinates(int m, int n, int k);
    void scaleCoordinatesX(int factor);
    void scaleCoordinatesY(int factor);
    void scaleCoordinatesZ(int factor);
};
