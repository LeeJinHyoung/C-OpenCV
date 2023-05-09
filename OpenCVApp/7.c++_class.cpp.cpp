#include "Calc.h"
int main()
{	
	if (true) 
	{
		Calc calc;

		//	calc.SetValue(1, 2, '+');
		//	calc.Dosum();
		int data[3] = { 1,2,3 };
		calc.sum(data, 3);
		cout << "수의 합은 " << calc.Getresult() << endl;

		calc.Clear();
		calc.SetValue(1, 2, '+');
		calc.Dosum();
		cout << "수의 합은 " << calc.Getresult() << endl;
	}
	if (false)
	{
		Calc* pCalc = new Calc(1, 1, '+'); //새로운 객체 //동적메모리할당으로 생성

		int data[3] = { 1,2,3 };
		pCalc->sum(data, 3); //클래스에 새로운 포인터 객체로 접근
		cout << "수의 합은 " << pCalc->Getresult() << endl;

		pCalc->Clear();
		pCalc->SetValue(1, 2, '+');
		pCalc->Dosum();
		cout << "수의 합은 " << pCalc->Getresult() << endl;

		if (pCalc != nullptr)//동적메모리할당 해제 //안하면 비정상적종료 dtor없이 종료됨
		{
			delete pCalc; //클래스에 소멸자가옴
			pCalc = nullptr;//쓰레기값을 가르킬수있으니 널로 만들기
		}
	}
	{	//smart pointer
		std::shared_ptr<Calc> pCalc = std::make_shared<Calc>(1,1,'+');//동적으로만 사용할 경우 exception방지를 위해

		int data[3] = { 1,2,3 };
		pCalc->sum(data, 3); //클래스에 새로운 포인터 객체로 접근
		cout << "수의 합은 " << pCalc->Getresult() << endl;

		pCalc->Clear();
		pCalc->SetValue(1, 2, '+');
		pCalc->Dosum();
		cout << "수의 합은 " << pCalc->Getresult() << endl;

	}
}