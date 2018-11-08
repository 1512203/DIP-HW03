#include "BaseProcessor.h"


BaseProcessor::BaseProcessor(string pathToImage) {
    this->image = readImage(pathToImage);
}


void BaseProcessor::execute(argv_t kwargs) {
    displayImage("Original Image", this->image);
    Mat resultImage = this->processImage(kwargs);
    displayImage("Result Image", resultImage);
	waitKey(0);
}


void BaseProcessor::pixelInterpolation(AffineTransform* r, Mat* result) {
    int W = this->image.cols;
    int H = this->image.rows;
    if (r->getX() < W-1 && r->getX() > 0 && r->getY() < H-1 && r->getY() > 0) {
        double x = r->getX();
        double y = r->getY();
        int l = trunc(x);
        int k = trunc(y);
        double a = x - l;
        double b = y - k;
        for (int c = 0; c < 3; ++c) {
            result->at<Vec3b>(r->getIntOriginY(), r->getIntOriginX())[c]
                = cvRound(
                        (1-a) * (1-b) * this->image.at<Vec3b>(k, l)[c]
                      + a * b * this->image.at<Vec3b>(k+1, l+1)[c]
                      + (1-a) * b * this->image.at<Vec3b>(k, l+1)[c]
                      + a * (1-b) * this->image.at<Vec3b>(k+1, l)[c]
                );
        }
    }
}


Mat BaseProcessor::processImage(argv_t kwargs) {
    Mat result = Mat::zeros( this->image.size(), this->image.type() );
    return result;
}


BaseProcessor::~BaseProcessor() {
    //
}

