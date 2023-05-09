// OpenCVApp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

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

    std::cout << "Hello World!\n";
    std::string fileName = "jetson.bmp";
 //   cv::Mat img = cv::imread(fileName, IMREAD_COLOR);
    cv::Mat img = cv::imread(fileName, IMREAD_GRAYSCALE);
    //cv::String


    int width = img.cols;
    int height = img.rows;
    uchar* pData = img.data;
 
    //mask processing
    int threshold = 100;

    Mat  thrImag;
    cv::threshold(img, thrImag, threshold, 255, THRESH_BINARY);//입력 출력 기준값 반환값 방법

    //threshold processing
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int index = row * width + col;
            if (pData[index]>= threshold) // 빈칸에 threshold보다 크면 pData를 255에 대입한다.
            {
                pData[index] = 255;
            }
            else
            {
                pData[index] = 0;
            }
            //(pData[index] >= threshold)? pData[index] = 0:pData[index] =255;
        }
     
    }

    return 0; //int에 반환
}
