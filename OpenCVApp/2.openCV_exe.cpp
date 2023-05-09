// OpenCVApp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>//입력과 출력을 제어하는 헤더
#include <opencv2/opencv.hpp>
#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else   //RELEASE
#pragma comment(lib,"opencv_world470.lib")
#endif

using namespace std;
using namespace cv;                                               

int main()
{
    cout << "Hello OpenCV World!\n";
    string fileName = "jetson.bmp";
    Mat img = cv::imread(fileName, IMREAD_COLOR);
//  Mat img = cv::imread(fileName, IMREAD_GRAYSCALE);

    int width = img.cols;
    int height = img.rows;
    uchar* pData = img.data;
    int channel = img.channels();
    //mask processing
    int mask_width = 3; int mask_height = 3;
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int index = row * width + col;
            if (channel == 3) 
                index *= 3;
            if (row >= 0 && row < mask_height)
            {
                if (col >= 0 && col < mask_width)
                {
                    pData[index] = 255;
                    if (channel == 3) pData[index + 1] = pData[index + 2] = 255;
                }
            }//좌상
            if (row >= 0 && row < mask_height)
            {
                if (col >= (width- mask_width) && col < width)
                {
                    pData[index] = 255;
                    if (channel == 3) pData[index + 1] = pData[index + 2] = 255;
                }
            }//우상
            if (row >= (height-mask_height) && row < height)
            {
                if (col >= 0 && col < mask_width)
                {
                    pData[index] = 255;
                    if (channel == 3) pData[index + 1] = pData[index + 2] = 255;
                }
            }//좌하
            if (row >= (height - mask_height) && row < height)
            {
                if (col >= (width - mask_width) && col < width)
                {
                    pData[index] = 255;
                    if (channel == 3) pData[index + 1] = pData[index + 2] = 255;
                }
            }//우하
        }
    }

    return 0; //int에 반환
}
