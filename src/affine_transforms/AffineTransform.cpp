#include "AffineTransform.h"


AffineTransform::AffineTransform(double _x, double _y) {
    this->x = _x;
    this->y = _y;
    this->origin_x = _x;
    this->origin_y = _y;
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


double AffineTransform::getOriginX() {
    return this->origin_x;
}


double AffineTransform::getOriginY() {
    return this->origin_y;
}


int AffineTransform::getIntOriginX() {
    return cvRound(this->origin_x);
}


int AffineTransform::getIntOriginY() {
    return cvRound(this->origin_y);
}


AffineTransform* AffineTransform::translate(double t_x, double t_y) {
    double newX = this->x + t_x;
    double newY = this->y + t_y;
    this->x = newX;
    this->y = newY;
    return this;
}


AffineTransform* AffineTransform::rotate(double theta) {
    double newX = this->x * cos(theta) - this->y * sin(theta);
    double newY = this->x * sin(theta) + this->y * cos(theta);
    this->x = newX;
    this->y = newY;
    return this;
}


AffineTransform* AffineTransform::scale(double c_x, double c_y) {
    double newX = this->x * c_x;
    double newY = this->y * c_y;
    this->x = newX;
    this->y = newY;
    return this;
}

