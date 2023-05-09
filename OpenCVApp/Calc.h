#pragma once
#include "common.h"

class Calc //struct 하고 똑같은데 접근제한지정자만 있을뿐
{
public:
	//얘네도 void 함수임
	//생성자 수정이 용이하지않음
	Calc();//Ctor...default Ctor 생성자 없어도 기본생성자가 있음 없애면 변수 초기화가 안됨
//	Calc(int a = 1, int b = 2, char sym = ' ');//오버로딩//값이 다 있어서 기본생성자 취급할수 있음
	Calc(int a, int b, char sym);//오버로딩

	//소멸자
	~Calc();//Dtor
	void Clear();
	void SetValue(int num1, int num2, char sym);
	int Dosum();
	int Domul();
	int Dosub();
	int Dodiv();
	int Getresult();
	int sum(const int* const pData, size_t length);
	float avg(const int* const pData, size_t length);
	int min(const int* const pData, size_t length);
	int max(const int* const pData, size_t length);

private: //메인에서 안보임
	int* pData = nullptr;
	int number1;//초기화 안된상태
	int number2;
	char symbol;
	int result;
};

//usuage
/*
 7.c++_class.cpp 만드세요

#include "Calc.h"
int main()
{
	Calc calc
	calc.SetValue(1,2,'+');
	clac.Dosum();
	cout<<"두수의 합은 " << calc.GetResult() <<endl;	
}
//console 창의 상태를 캡쳐하세요.

*/