// OpenCVApp.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>//입력과 출력을 제어하는 헤더
#include <string>
#include <vector>

using namespace std; //std에 해당되는 네이스페이스를 안쓸래
#define AAA "aaa"
#define PI 3.14
int main()
{   
    const char* const_AAA = "aaa";
    const float const_PI = 3.14; //조사식을 통해볼수있으니깐 이방식을 권장
    int a1 = 10;
    //const_PI = 4.123; //const 파일 값변경 불가 컴파일시점에서 에러
    //10 = a1; 
    //BOOL babc = TRUE; //BOOL에 디파인된걸 트루로 인트타입 이젠 한바이트로 읽는 bool생김
    
    const bool bComp = false;//const 상수로 만들어줌
    const int const_int = 100;
    const short const_short = 0xfff;
    const std::string const_str = "abcd"; //스트링을 사용하기위해서 네임스페이스 이용
    string str_a = "a";

    int a = 0; //함수랑 변수랑 같다 자료형이 생성하고 0으로 밀어줌
    int b(0);//메모리공간이 열리자마자 초기화 포인터할때 초기화조심  
    std::cout << "Hello World!\n";
   
    int arrimg[25] = {0,};
    arrimg[5] = 5;

    std::vector<int> vimg(5); //vector은 클래스 C++은 백터사용가능
    //인덱스 범위 벗어나면 알려줌 
    int sz_int = sizeof(int); //날것 
    //C++ 안정성확보 C는 자유롭게 쓸수있는대신 프로그램이 다치기쉬움

    float f_data = 1.23;
    int n_data = (int)f_data;//형변환한걸로 임시메모리저장공간에 넣어뒀다가 새로운데이타로 n데이타에 넣어줌
    n_data = static_cast<int>(f_data);// C++_style
 
    //f_data
    //(int)f_data; 임시객체는 n데이터에 들어가는 순간 소멸
    //n_data =??

    const char const_string[] = "ABC";
    std::cout << const_string << std::endl;
    char* msg = const_cast<char*>(const_string);//const_cast: const속성을 벗겨낸다
    msg[0] = 'D';
    std::cout << const_string <<std::endl;
    std::cout << msg << std::endl;
    

    //static cast
    char cNum = 'a';
    int* pNum = nullptr;
    pNum = (int*)(&cNum);//C-style
   // pNum = static_cast<int*>(&cNum); //C++
    *pNum = 5;

    return 0; //int에 반환
}
