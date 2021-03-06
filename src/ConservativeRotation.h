#ifndef CONSERVATIVEROTATION_INCLUDED
#define CONSERVATIVEROTATION_INCLUDED

#include "common.h"
#include "BaseProcessor.h"
#include "affine_transforms/AffineTransform.h"


class ConservativeRotation: public BaseProcessor {
private:
protected:
    Mat processImage(argv_t kwargs);
public:
    ConservativeRotation(string pathToImage): BaseProcessor(pathToImage) {}
    ~ConservativeRotation() {};
};

#endif

