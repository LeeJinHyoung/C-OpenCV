// OpenCVApp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <iostream>//입력과 출력을 제어하는 헤더
#include <string>
#include <vector>
#define AAA "aaa"
#define PI 3.14

using namespace std; //std에 해당되는 네이스페이스를 안쓸래
int main()
{   
    int sum = 10;
    if (sum > 10)
        cout << "sum > 10" << endl;
    else if (sum > 5)
        cout << "sum > 5" << endl;
    else
        cout << "no result" << endl;

    //Quiz
    //학점을 출력하세요
    //정수 타입 변수 Score가 100보다 같거나 클때, A
    //정수 타입 변수 Score가 100보다 작고 90보다 클때, B
    //정수 타입 변수 Score가 90보다 작고 80보다 클때, C
    //그외, None
    //로 출력되는 조건문 코드를 작성하세요.

    int Score;
    cin >> Score;

    if ((Score >= 100))
        cout << "A" << endl;
    else if ((Score < 100)&&(Score >= 90))
        cout << "B" << endl;
    else if ((Score < 90) && (Score >= 80))
        cout << "C" << endl;
    else
        cout << "None" << endl;

    //반복문
    int rows = 10;
    int cols = 10;
    for (int row = 0; row < rows; row++)
    {
        cout << "row = " << row << "\t";
        for (int col = 0; col < cols; col++)
        {
            cout << "col = " << col << "\t";

        }
        cout << endl;
    }

    //pointer, reference
    //메모리 주소를 의미하는 곳을 저장하는 형태의 변수
    //장점 : 배열과 같은 연속 데이터에 접근+조작이 용이
    //메모리 동적 할당/해제 리소스 관리 가능-효율성
    //복잡한 자료 구조 효율적으로 접근 가능 및 처리
    int Data = 100;
   // int* pData = nullptr;
   // pData = &Data;
    int* pData = &Data;

    int nArray[10] = { 1,2,3,4,5,6,7,8,9,10 };
    int* pArray = nArray; //&nArray[0]
    for (int i = 0; i < sizeof(nArray) / sizeof(nArray[0]); i++)//40 /4 = 10 인덱스개수
    {
        cout << *(pArray + i) << "\t"; //주소갔다가 데이터로 
        cout << pArray[i] << "\t";// 그나마 제일 안전 첫번째 세번째 방식이 더 빠름
        cout << *(pArray++) << "\t";
    }

    return 0; 
}
