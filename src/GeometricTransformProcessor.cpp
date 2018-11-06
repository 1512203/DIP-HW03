#include "GeometricTransformProcessor.h"


Mat GeometricTransformProcessor::processImage(argv_t kwargs) {
    Mat result = Mat::zeros(this->image.size(), this->image.type());
    return result;
}
