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
    for (int y = 0; y < H; ++y) {
        for (int x = 0; x < W; ++x) {
            AffineTransform* t = new AffineTransform(x, y);
            t = t -> translate(-(W - 1.0) / 2.0, -(H - 1.0) / 2.0)
                  -> rotate(theta)
                  -> translate((W - 1.0) / 2.0, (H - 1.0) / 2.0);
            result.at<Vec3b>(t->getIntY() - minY, t->getIntX() - minX) = this->image.at<Vec3b>(y, x);
            delete t;
        }
    }
    return result;
}

