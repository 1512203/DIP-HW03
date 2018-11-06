#ifndef BASEPROCESSOR_INCLUDED
#define BASEPROCESSOR_INCLUDED

#include "common.h"

class BaseProcessor {
private:
protected:
    Mat image;
    virtual Mat processImage(argv_t kwargs) = 0;
public:
    BaseProcessor(string pathToImage);
    void execute(argv_t kwargs);
    virtual ~BaseProcessor();
};

#endif

