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


BaseProcessor::~BaseProcessor() {
    //
}

