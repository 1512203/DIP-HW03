#include "Scaling.h"


Mat Scaling::processImage(argv_t kwargs) {
    double c_x = stof(kwargs["c_x"]);
    double c_y = stof(kwargs["c_y"]);
    int H = this->image.rows;
    int W = this->image.cols;

    assert(H > 1 && W > 1);

    AffineTransform* t = new AffineTransform(W - 1.0, H - 1.0);
    t = t -> scale(c_x, c_y);
    int newW = t->getIntX() + 1;
    int newH = t->getIntY() + 1;
    delete t;

    Mat result = Mat::zeros(newH, newW, this->image.type());

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            AffineTransform* t = new AffineTransform(x, y);
            t = t -> scale(c_x, c_y);
            result.at<Vec3b>(t->getIntY(), t->getIntX()) = this->image.at<Vec3b>(y, x);
            delete t;
        }
    }
    return result;
}


