#pragma once
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include <algorithm>
#include <opencv2/opencv.hpp>

#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else	//RELEASE 
#pragma comment(lib,"opencv_world470.lib")
#endif


using namespace std;
using namespace cv;
