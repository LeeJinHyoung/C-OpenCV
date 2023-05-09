#include <iostream>//입출력헤더파일
//istrem vs ostream
//cin ">>"  cout "<<"
//#include <stdio.h> //standard io

//#define _CRT_SECURE_NO_WARNINGS //프로젝트 속성 > C/C++ 전처리기 추가
//#include "abc.h" user defined header
//함수 형태
//[반환형] [함수명] [(매개변수)] { }
int main() 
{	
	printf("Hello, ");
	printf("World\n");
	std::cout << "Hello, ";
	std::cout << "World\n";
	std::cout << "Hello, World" << std:: endl;

	printf("math - %d\n", 100); //정수
	std::cout << "math - %d\n" << 100 << std::endl;
	printf("pi - %lf\n", 3.14); //소수
	std::cout << "pi - %fl\n" << 3.14 << std::endl;
	printf("Score - %c\n", 'A'); //문자
	std::cout << "Score - %c\n" << 'A' << std::endl;

	printf("%d % lf %c", 100, 3.14, 'A'); //순서 안맞춰주면 제대로 작동X //cout을 이용하면 해당하는 자료형 자동으로 변경돼서 편리

	std::cout << "Hello, World \r\n" << std::endl; //end line

	//입력
	//c
	int i = 0;
	scanf("input - %d", &i); //이함수와 변수가 안전하지않다 secrety버전을 쓰거나 _CRT_SECURE_NO_WARNNINGS옵션 추가//★★★★★
	printf("%d typed", i);

	//c++
	std::cout << "input -";
	std::cin >> i; //★★★★★
	std::cout << i << "typed" << std::endl; // endl : \n

	return 1; //TRUE: 1, FALSE: 0 //어떤 신호없이 정상적인상태라고 여겨 임베디드에서 일반적으로 리턴0이 정상으로 봄

}