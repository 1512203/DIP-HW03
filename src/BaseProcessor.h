#ifndef BASEPROCESSOR_INCLUDED
#define BASEPROCESSOR_INCLUDED

#include "common.h"
#include "affine_transforms/AffineTransform.h"

class BaseProcessor {
private:
protected:
    Mat image;
    virtual Mat processImage(argv_t kwargs);
    double getF(int x, int y, double f[][4]);
    void calculateFeatureVector(double f[][4], double g[16]);          // Here we use f as f(x, y), x is on horizontal axis while y is on vertical axis
                                                                    // f shoule be able to index as follows:
                                                                    //     f | -1 | 0 | 1 | 2  |
                                                                    //    ---------------------|
                                                                    //    -1 |    |   |   |    |
                                                                    //    ---------------------|
                                                                    //     0 |    |   |   |    |
                                                                    //    ---------------------|
                                                                    //     1 |    |   |   |    |
                                                                    //    ---------------------|
                                                                    //     2 |    |   |   |    |
                                                                    //    ---------------------|
    double bicubicInterpolation(double a, double b, double f[][4]);    // Here we use f as f(x, y), x is on horizontal axis while y is on vertical axis
                                                                    // f shoule be able to index as follows:
                                                                    //     f | -1 | 0 | 1 | 2  |
                                                                    //    ---------------------|
                                                                    //    -1 |    |   |   |    |
                                                                    //    ---------------------|
                                                                    //     0 |    |   |   |    |
                                                                    //    ---------------------|
                                                                    //     1 |    |   |   |    |
                                                                    //    ---------------------|
                                                                    //     2 |    |   |   |    |
                                                                    //    ---------------------|
    void pixelInterpolation(AffineTransform* r, Mat* result);
public:
    BaseProcessor(string pathToImage);
    void execute(argv_t kwargs);
    virtual ~BaseProcessor();
};

#endif

