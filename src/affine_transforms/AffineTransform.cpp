#include "AffineTransform.h"


AffineTransform::AffineTransform(double _x, double _y) {
    this->x = _x;
    this->y = _y;
}


double AffineTransform::getX() {
    return this->x;
}


double AffineTransform::getY() {
    return this->y;
}


int AffineTransform::getIntX() {
    return cvRound(this->x);
}


int AffineTransform::getIntY() {
    return cvRound(this->y);
}


AffineTransform* AffineTransform::translate(double t_x, double t_y) {
    *this = AffineTransform(
            this->x + t_x, 
            this->y + t_y
    );
    return this;
}


AffineTransform* AffineTransform::rotate(double theta) {
    *this = AffineTransform(
        this->x * cos(theta) - this->y * sin(theta),
        this->x * sin(theta) + this->y * cos(theta)
    );
    return this;
}


AffineTransform* AffineTransform::scale(double c_x, double c_y) {
    *this = AffineTransform(
        this->x * c_x,
        this->y * c_y
    );
    return this;
}

