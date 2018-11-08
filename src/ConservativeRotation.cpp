#include "ConservativeRotation.h"


Mat ConservativeRotation::processImage(argv_t kwargs) {
    double theta = stof(kwargs["theta"]) * acos(-1.0) / 180.0;
    int H = this->image.rows;
    int W = this->image.cols;
    int maxX = -ooInt, minX = ooInt;
    int maxY = -ooInt, minY = ooInt;

    assert(H > 1 && W > 1);

    for (int y = 0; y < H; y += H - 1) {
        for (int x = 0; x < W; x += W - 1) {
            AffineTransform* t = new AffineTransform(x, y);
            t = t -> translate(-(W - 1.0) / 2.0, -(H - 1.0) / 2.0)
                  -> rotate(theta)
                  -> translate((W - 1.0) / 2.0, (H - 1.0) / 2.0);
            maxX = max(maxX, t->getIntX());
            minX = min(minX, t->getIntX());
            maxY = max(maxY, t->getIntY());
            minY = min(minY, t->getIntY());
            delete t;
        }
    }
    int newW = maxX - minX + 1;
    int newH = maxY - minY + 1;
    Mat result = Mat::zeros(newH, newW, this->image.type());
    bool *isAssigned = new bool[newH * newW];
    memset(isAssigned, 0, sizeof(bool) * newH * newW);

    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            AffineTransform* t = new AffineTransform(x, y);
            t = t -> translate(-(W - 1.0) / 2.0, -(H - 1.0) / 2.0)
                  -> rotate(theta)
                  -> translate((W - 1.0) / 2.0, (H - 1.0) / 2.0)
                  -> translate(-minX, -minY);
            result.at<Vec3b>(t->getIntY(), t->getIntX()) = this->image.at<Vec3b>(y, x);
            isAssigned[t->getIntY() * newW + t->getIntX()] = 1;
            delete t;
        }
    }

    for (int y = 0; y < result.rows; ++y) {
        for (int x = 0; x < result.cols; ++x) 
            if (!isAssigned[y * newW + x]) {
                AffineTransform* t = new AffineTransform(x, y);
                t = t -> translate(minX, minY)
                      -> translate(-(W - 1.0) / 2.0, -(H - 1.0) / 2.0)
                      -> rotate(-theta)
                      -> translate((W - 1.0) / 2.0, (H - 1.0) / 2.0);
                this->pixelInterpolation(t, &result);
                delete t;
            }
    }
    delete[] isAssigned;
    return result;
}

