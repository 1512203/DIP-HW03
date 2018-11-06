#ifndef COMMON_INCLUDED
#define COMMON_INCLUDED



/* Include libraries */

// C Library
#include <cstring>

// C++ Standard Libraries
#include <algorithm>
#include <iostream>
#include <map>
#include <string>

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
#define COMMAND_GEOMETRIC_TRANSFORMATION_SCALE				"--rotate"

const double EPSILON = 1E-9;


/* Some utility function */

void displayImage(string windowName, Mat img);
Mat readImage(string pathToImage);
bool isEqualDouble(double a, double b);

#endif

