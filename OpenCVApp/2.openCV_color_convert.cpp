#include <iostream>
#include <opencv2/opencv.hpp>
#ifdef _DEBUG
#pragma comment(lib,"opencv_world470d.lib")
#else
#pragma comment(lib,"opencv_world470.lib")
#endif

using namespace std;
using namespace cv;

int sum(const uchar* const pData, int width, int height, int start_row, int start_col, int finish_row, int finish_col) {
    int sum = 0;
    //�ڵ� �ۼ�
    for (size_t row = start_row; row <= finish_row; row++)
    {
        for (size_t col = start_col; col <= finish_col; col++)
        {
            size_t index = (row)*width + (col);
            sum += pData[index];
        }
    }
    return sum;
}
int main()
{
    std::cout << "Hello World!\n";
    std::string fileName = "jetson.bmp";
    cv::Mat src = cv::imread(fileName, IMREAD_COLOR);

    //    int width = src.cols;
    //    int height = src.rows;

    if (src.empty())
    {
        return -1;
    }
    Mat gray = Mat(src.rows, src.cols, CV_8UC1);//openCV 8��Ʈ unsigned char �Ѻ�Ʈ¥��
    //gray = 0;
    //convert color::rgb to gray 

    for (size_t row = 0; row < src.rows; row++)
    {
        for (size_t col = 0; col < src.cols; col++)
        {
            int index = 3*(row * src.cols + col);

            int b = src.data[index + 0];    //uchar* pData = src.data;
            int g = src.data[index + 1];
            int r = src.data[index + 2];
            //1.����
             float Y = 0.299 * r + 0.587 * g + 0.114 * b;
            //2.���ο� Gray �̹��� ���ۿ� ����
            // gray.data[index/3] = Y; //�Ͻ��� ����ȯ
            //gray.data[row * src.cols + col] = (uchar)y;���������ȯ-c
            gray.data[index/3] =static_cast<uchar>(Y);//����� ����ȯ //��ȣ���� 1����Ʈ ����
            //gray.data[row * src.cols + col] = static_cast<uchar>(y);
        }
    }
    //sym of gray buffer
    cout << "image data sum = "
        << sum(gray.data,gray.cols, gray.rows, 1, 1, 3, 3) << endl;
  //  if (gray.data != nullptr)delete[] gray.data;

    return 0;
}
