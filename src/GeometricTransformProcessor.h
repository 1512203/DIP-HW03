#ifndef GEOMETRICTRANSFORMPROCESSOR_INCLUDED
#define GEOMETRICTRANSFORMPROCESSOR_INCLUDED

#include "common.h"
#include "BaseProcessor.h"


class GeometricTransformProcessor: public BaseProcessor {
private:
protected:
    Mat processImage(argv_t kwargs);
public:
    GeometricTransformProcessor(string pathToImage): BaseProcessor(pathToImage) {}
    virtual ~GeometricTransformProcessor() {};
};


#endif

