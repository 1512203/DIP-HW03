#ifndef COMMON_INCLUDED
#define COMMON_INCLUDED



/* Include libraries */

// C Library
#include <cmath>
#include <cstring>
#include <cstdio>

// C++ Standard Libraries
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

// OpenCV Libraries
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>



/* Include elements in namespace std */

// Std input/output
using std::cin;
using std::cerr;
using std::cout;
using std::endl;

// Std data structures
using std::map;
using std::string;
using std::vector;

// Std utility functions
using std::max;
using std::min;
using std::stof;



/* Include elements in namespace cv */

// OpenCV Constants 
using cv::IMREAD_COLOR;
using cv::WINDOW_AUTOSIZE;

// OpenCV data structures
using cv::Mat;
using cv::Point;
using cv::Scalar;
using cv::Vec3b;

// OpenCV utility functions
using cv::imshow;
using cv::imread;
using cv::imwrite;
using cv::namedWindow;
using cv::saturate_cast;
using cv::waitKey;



/* Define to pass argument */

typedef map<string, string> argv_t;
typedef map<string, void*> argv_json;



/* Define constants */

#define ERROR_MESS_INVALID_ARGUMENTS                "Invalid arguments!"
#define ERROR_MESS_INVALID_COMMANDS                 "Invalid command!"

#define COMMAND_GEOMETRIC_TRANSFORMATION_ROTATE_RESERVE 	"--rotate"
#define COMMAND_GEOMETRIC_TRANSFORMATION_ROTATE_NONRESERVE	"--rotateN"
#define COMMAND_GEOMETRIC_TRANSFORMATION_SCALE				"--scale"

const double EPSILON = 1E-9;
const int ooInt = 2147483647;


/* Some utility function */

void displayImage(string windowName, Mat img);
Mat readImage(string pathToImage);
bool isEqualDouble(double a, double b);

const double BICUBIC_INTERPOLATION_INV_MATRIX[16][16] = {
	{ 1.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0., 0.,  0.,  0.},
	{ 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  1.,  0.,  0.,  0.,  0., 0.,  0.,  0.},
	{-3.,  3., -0., -0., -0., -0., -0., -0., -2., -1., -0., -0., -0., -0., -0., -0.},
	{ 2., -2.,  0.,  0.,  0.,  0.,  0.,  0.,  1.,  1.,  0.,  0.,  0., 0.,  0.,  0.},
	{ 0.,  0.,  0.,  0.,  1.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0., 0.,  0.,  0.},
	{ 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  1., 0.,  0.,  0.},
	{-0., -0., -0., -0., -3.,  3., -0., -0., -0., -0., -0., -0., -2., -1., -0., -0.},
	{ 0.,  0.,  0.,  0.,  2., -2.,  0.,  0.,  0.,  0.,  0.,  0.,  1., 1.,  0.,  0.},
	{-3.,  0.,  3.,  0., -2.,  0., -1.,  0.,  0.,  0.,  0.,  0.,  0., 0.,  0.,  0.},
	{ 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0., -3.,  0.,  3.,  0., -2., 0., -1.,  0.},
	{ 9., -9., -9.,  9.,  6., -6.,  3., -3.,  6.,  3., -6., -3.,  4., 2.,  2.,  1.},
	{-6.,  6.,  6., -6., -4.,  4., -2.,  2., -3., -3.,  3.,  3., -2., -2., -1., -1.},
	{ 2., -0., -2., -0.,  1., -0.,  1., -0., -0., -0., -0., -0., -0., -0., -0., -0.},
	{ 0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  2.,  0., -2.,  0.,  1., 0.,  1.,  0.},
	{-6.,  6.,  6., -6., -3.,  3., -3.,  3., -4., -2.,  4.,  2., -2., -1., -2., -1.},
	{ 4., -4., -4.,  4.,  2., -2.,  2., -2.,  2.,  2., -2., -2.,  1., 1.,  1.,  1.}
};

#endif

