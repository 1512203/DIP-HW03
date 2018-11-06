#include "common.h"

void displayImage(string windowName, Mat img) {
    namedWindow(windowName, WINDOW_AUTOSIZE);
    imshow(windowName, img);
}


Mat readImage(string pathToImage) {
    return imread(pathToImage, IMREAD_COLOR);
}


bool isEqualDouble(double a, double b) {
    double delta = a-b;
    return delta <= EPSILON && delta >= -EPSILON;
}

