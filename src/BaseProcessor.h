#ifndef BASEPROCESSOR_INCLUDED
#define BASEPROCESSOR_INCLUDED

#include "common.h"
#include "affine_transforms/AffineTransform.h"

class BaseProcessor {
private:
protected:
    Mat image;
    virtual Mat processImage(argv_t kwargs);
    void pixelInterpolation(AffineTransform* r, Mat* result);
public:
    BaseProcessor(string pathToImage);
    void execute(argv_t kwargs);
    virtual ~BaseProcessor();
};

#endif

