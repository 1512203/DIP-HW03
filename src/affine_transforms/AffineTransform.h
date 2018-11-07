#ifndef AFFINETRANSFORM_INCLUDED
#define AFFINETRANSFORM_INCLUDED

#include "../common.h"

class AffineTransform {
private:
    double x, y;
protected:
public:
    AffineTransform(double _x, double _y);
    double getX();
    double getY();
    int getIntX();
    int getIntY();
    AffineTransform* translate(double t_x, double t_y);
    AffineTransform* rotate(double theta);
    AffineTransform* scale(double c_x, double c_y);
};

#endif

