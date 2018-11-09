#ifndef NONCONSERVATIVEROTATION_INCLUDED
#define NONCONSERVATIVEROTATION_INCLUDED

#include "common.h"
#include "BaseProcessor.h"
#include "affine_transforms/AffineTransform.h"


class NonConservativeRotation: public BaseProcessor {
private:
protected:
    Mat processImage(argv_t kwargs);
public:
    NonConservativeRotation(string pathToImage): BaseProcessor(pathToImage) {}
    ~NonConservativeRotation() {};
};

#endif

