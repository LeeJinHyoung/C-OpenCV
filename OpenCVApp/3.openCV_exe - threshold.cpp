// OpenCVApp.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>//�Է°� ����� �����ϴ� ���
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
    cv::threshold(img, thrImag, threshold, 255, THRESH_BINARY);//�Է� ��� ���ذ� ��ȯ�� ���

    //threshold processing
    for (int row = 0; row < height; row++)
    {
        for (int col = 0; col < width; col++)
        {
            int index = row * width + col;
            if (pData[index]>= threshold) // ��ĭ�� threshold���� ũ�� pData�� 255�� �����Ѵ�.
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

    return 0; //int�� ��ȯ
}
