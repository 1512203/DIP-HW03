#ifndef SCALING_INCLUDED
#define SCALING_INCLUDED

#include "common.h"
#include "BaseProcessor.h"
#include "affine_transforms/AffineTransform.h"


class Scaling: public BaseProcessor {
private:
protected:
    Mat processImage(argv_t kwargs);
public:
    Scaling(string pathToImage): BaseProcessor(pathToImage) {}
    ~Scaling() {};
};

#endif


