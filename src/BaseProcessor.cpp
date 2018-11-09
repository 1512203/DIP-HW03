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


double BaseProcessor::getF(int x, int y, double f[][4]) {
    return f[x+1][y+1];
}


void BaseProcessor::calculateFeatureVector(double f[][4], double g[16]) { 
    int id = 0;
    for (int i = 0; i < 4; ++i) {
        g[id++] = this->getF(i/4, i%4, f);
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            g[id++] = this->getF(i+1, j, f)-this->getF(i-1, j, f);
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            g[id++] = this->getF(i, j+1, f)-this->getF(i, j-1, f);
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            g[id++] = this->getF(i+1, j+1, f)-this->getF(i-1, j+1, f)-this->getF(i+1, j-1, f)+this->getF(i-1, j-1, f);
        }
    }
}


double BaseProcessor::bicubicInterpolation(double a, double b, double f[][4]) {
    double alpha[4][4];
    double g[16];
    this->calculateFeatureVector(f, g);
    for (int i = 0; i < 16; ++i) {
        int i_x = i/4;
        int i_y = i%4;
        alpha[i_x][i_y] = 0.0;
        for (int j = 0; j < 16; ++j) {
            alpha[i_x][i_y] += BICUBIC_INTERPOLATION_INV_MATRIX[i][j] * g[j];
        }
    }
    double result = 0;
    double pa = 1.0;
    for (int i = 0; i < 4; ++i) {
        double pb = 1.0;
        for (int j = 0; j < 4; ++j) {
            result += pa * pb * alpha[i][j];
            pb *= b;
        }
        pa *= a;
    }
    return result;
}


void BaseProcessor::pixelInterpolation(AffineTransform* r, Mat* result) {
    int W = this->image.cols;
    int H = this->image.rows;
    double x = r->getX();
    double y = r->getY();
    int l = trunc(x);
    int k = trunc(y);
    double a = x - l;
    double b = y - k;
    if (l <= W-2 && l >= 1 && k <= H-2 && k >= 1 && !isEqualDouble(l, x) && !isEqualDouble(k, y)) {
        double f[4][4];
        for (int c = 0; c < 3; ++c) {
            for (int u = l-1; u <= l+2; ++u) {
                for (int v = k-1; v <= k+2; ++v) {
                    f[u-l+1][v-k+1] = this->image.at<Vec3b>(v, u)[c];
                }
            }
            int option_1 = cvRound(this->bicubicInterpolation(a, b, f));
            if (option_1 < 0) {
                option_1 = 0;
            }
            else if (option_1 > 255) {
                option_1 = 255;
            }
            result->at<Vec3b>(r->getIntOriginY(), r->getIntOriginX())[c] = option_1;
        }
    }
    else if (l < W-1 && l >= 0 && k < H-1 && k >= 0) {
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

