#include "Calc.h"

//Calc::Calc() 
////:number1(0) //member initializer 생성과 동시에 초기화
////, number2(0)
////, symbol(' ')
////, result(0)
//{	
//	cout <<"Calc::Ctor" <<endl;
//}
Calc::Calc()//두번 생성되는게 아니라 위임한 생성자로 들어갔다 나오는것
	:Calc(1, 1, ' ') //위임 생성자: 생성자가 생성자를 다시 호출해줌
{
	cout << "Calc::Ctor2" << endl;
	
}
Calc::Calc(int a, int b, char sym) //사용자 지정 생성자
:number1(a) //member initializer 생성과 동시에 초기화
, number2(b)
, symbol(sym)
, result(0)
, pData(nullptr)
{
	cout << "Calc::Ctor1" << endl;
	//this->a = a;
	//this->b = a;
	//this->sym = a;

	pData = new int[100];//int type ctor
}

Calc::~Calc()
{
	cout << "Calc::Dtor" << endl;
	if (pData != nullptr)
	{
		delete[] pData;
		pData = nullptr;
	}
}

void Calc::Clear()
{
	number1 = 0; //생성 후 대입연산자를 이용한 초기화
	number2 = 0;
	symbol = ' ';
	result = 0;
	if (pData != nullptr)
	{
		delete[] pData;
		pData = nullptr;
	}
}

void Calc::SetValue(int num1, int num2, char sym)
{
	number1 = num1;
	number2 = num2;
	symbol = sym;
}

int Calc::Dosum()
{
	result = number1 + number2;
	return result;
}

int Calc::Domul()
{
	result = number1 * number2;
	return result;
}

int Calc::Dosub()
{
	result = number1 - number2;
	return result;
}

int Calc::Dodiv()
{
	result = number1 / number2;
	return result;
}

int Calc::Getresult()
{
	return result;
}

int Calc::sum(const int* const pData, size_t length)
{
	int sum = 0;
	for (size_t i = 0; i < length; i++) {
		sum += pData[i];
	}
	result = sum;
	return sum;
}

float Calc::avg(const int* const pData, size_t length)
{	
	result= sum(pData, length) / length;
	
	return result;

}

int Calc::min(const int* const pData, size_t length)
{
	int min = pData[0];
	for (size_t i = 0; i < length; i++) {
		if (min > pData[i]) min = pData[i];
	}
	result = min;
	return min;
}

int Calc::max(const int* const pData, size_t length)
{
	int max = pData[0];
	for (size_t i = 0; i < length; i++) {
		if (max < pData[i]) max = pData[i];
	}
	result = max;
	return max;
}



