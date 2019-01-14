#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;
using namespace cv;
#pragma once
void InitializeFaceDetection(VideoCapture v_Cap, Mat v_Frame, string windowName);
void FaceDetectionLoop();