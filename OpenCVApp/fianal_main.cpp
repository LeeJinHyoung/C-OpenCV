#include <iostream>
#include<string>
#include "13.c++_fianl.h"
using namespace std;


class Base
{
public:
	Base() { cout << "Ctour" << endl; }
	virtual~Base() { cout << "Dtour" << endl; }//소멸자 virtual  상속관계
	virtual void Show() { cout << "Base: " << "_a" << endl; }//virtual keyword 자식이 재정의 한다
	//강제성 pure, 알아서 잘해라 그냥 가상함수
	//virtual void Show()=0; 순수가상함수 강제성
	//virtual void Show(); 가상함수 강제성
	void SetValue(int a) { _a = a; }
	int GetValue() { return _a; }
private:
	int _a = 0; //클래스의 은닉성
protected:

};
class Child :public Base
{
public:
	Child() { cout << "Ctour" << endl; }
	~Child() { cout << "Dtour" << endl; }
	void Show() override { cout << "Derived" << GetValue()/*of Base*/ << endl; };//of Child

private:
protected:

};
int main()
{
	if (false)
	{
		struct _datas
		{
			int a; double b; char c; string str;
		};
		_datas datas;
		class _cDatas
		{
		public:
			_cDatas() { cout << "Ctour" << endl; }
			~_cDatas() { cout << "Dtour" << endl; }
		private:
		protected:

		};
		_cDatas cData;
		if (false)
		{
			//DATA TYPES
			int a; double b; char c; std:string str;
			cout << "Hello World" << endl;
			cin >> a;
			auto i = 10; //for문에서 쉽게 쓰기위해

		}

		int* pData = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		_datas* pstData = new _datas();
		_cDatas* pCData = new _cDatas();
		//free
		//if (pData != nullptr) { delete[] pData; pData = nullptr; }
		//if (pData != nullptr) { delete[] pstData; pstData = nullptr; }
		//if (pData != nullptr) { delete[] pCData; pCData = nullptr; }

//		cout << "int datas sum = " << sum(pData, 10) << endl;

		Base base;
		Child child;
		Base* pBase = new Base();
		Child* pChild = new Child();
		pBase->SetValue(10);
		pBase->Show();
		pChild->SetValue(20);
		pChild->Show();
		if (pBase != nullptr) { delete pBase; pBase = nullptr; }
		if (pChild != nullptr) { delete pChild; pChild = nullptr; }
	}
//Quiz 1. 사용자 이름(string),나이(int), 주소(string) 입력
//		이름: 이순신
//		나이: 100
//		주소: 서울시 12-123


	//Data data("이순신", 100, "12-123");
	//data.DisplayEmployee();
	
	
//Quiz 2. 동적메모리 할당(int*), 크기(int,10), 원소값(1,2,3,4,5,6,7,8,9,10)인 배열의 합/ 최소 / 최대 출력
//		//합:?
//		//최소:?
//		//최대:?
	
	int* pdata = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Data data;
	cout << "int datas sum  = " << data.sum(pdata, 10) << endl;
	cout << "int datas max  = " << data.max(pdata, 10) << endl;
	cout << "int datas max  = " << data.min(pdata, 10) << endl;

if (pdata != nullptr) { delete[] pdata; pdata = nullptr; }

//Quiz 3. C++ 객체지향언어의 특징을 출력하시오
cout << "캡슐화: 관련된 데이터와 함수를 하나의 단위로 묶어서 외부에서 접근할 수 없게 하는 것을 의미한다.\n"
	<< "클래스는 캡슐화를 구현하는 가장 기본적인 단위이며, 정보 은닉을 통해 객체의 내부 구현을 숨기고 외부에서는 인터페이스를 통해서만 객체에 접근할 수 있도록 합니다.\n"
	<<"상속: 이미 정의된 클래스를 기반으로 새로운 클래스를 정의할 수 있습니다.상속을 통해 기존 클래스의 멤버들을 그대로 사용하면서 새로운 기능을 추가하거나 기존 기능을 변경할 수 있습니다. \n"
	<<"다형성 : 같은 이름의 함수가 다른 동작을 수행하는 것을 의미합니다.C++에서 다형성은 함수 오버로딩과 가상 함수를 이용하여 구현됩니다. \n"
	<<"추상화 : 복잡한 시스템을 단순화하여 필요한 부분만을 추출하는 것을 의미합니다.클래스와 인터페이스를 정의하고 객체를 생성함으로써 추상화를 구현할 수 있습니다.\n"
	<<"객체 객체는 데이터와 함수의 묶음입니다. \n"
	<<"C++에서 모든 것은 객체로 표현됩니다.클래스를 정의하여 객체를 생성하고, 객체를 조작하면서 프로그램을 작성합니다. \n"
	<<"메모리 관리 : C++은 메모리를 직접 할당하고 해제하는 것이 가능합니다.이를 통해 메모리 관리를 효율적으로 수행할 수 있습니다.하지만 메모리 관리를 실수할 경우에는 메모리 누수나 잘못된 메모리 참조 등의 문제가 발생할 수 있으므로 주의가 필요합니다.최신 C++ 버전에서는 스마트 포인터 등의 기능을 제공하여 메모리 관리를 자동화할 수 있도록 지원합니다."
 << endl;



//Quiz 4. 아래 클래스의 문제점을 고치고 정상 출력하시오
class Shape
{
public:
	Shape() { cout << "Shape::Ctor" << endl; }
	virtual~Shape() { cout << "Shape::Dtor" << endl; }
	virtual void Show() { cout << "Shape Default " << endl; }
};
class Circle :public Shape
{
public:
	Circle() { cout << "Circle::Ctor" << endl; }
	~Circle() override { cout << "Circle::Dtor" << endl; }
	void Show() override { cout << "Shape Circle" << endl; }
};
	Shape* pShape = new Circle();
	pShape->Show();
//	delete pShape;
    if (pShape != nullptr) { delete pShape; pShape = nullptr; }
	//출력
	//Shape::Ctour
	//Circle::Ctour
	//Shape Circle
	//Shape::Dtour
	//Circle::Dtour

	return 1;
}

/*
h
#pragma once
#include "common.h"

class Data
{
public:
	Data();
	~Data();
	Data(string strName, int age, string strAddress);
	void DisplayEmployee();
	int sum(int* pdatas, int length);
	int max(int* pdatas, int length);
	int min(int* pdatas, int length);
private:
	string name, address;
	int age;
};
*/

/*
cpp
#include "13.c++_fianl.h"

Data::Data()
{
	cout << "Data::Ctor" << endl;
}

Data::Data(string name, int age, string address)
{
	cout << "Data::Ctor" << endl;
	this->name = name;
	this->address = address;
	this->age = age;

}

void Data::DisplayEmployee()
{
	cout << "name : " << name << endl;
	cout << "age : " << age << endl;
	cout << "address : " << address << endl;

}

Data::~Data()
{
	cout << "Data::Dtor" << endl;
}
int Data::sum(int* pdatas, int length)
{
	int _sum = 0;
	for (size_t i = 0; i < length; i++) { _sum += pdatas[i]; }

	return _sum;
}

int Data::max(int* pdatas, int length)
{
	int max= pdatas[0];
	for (int i=0;i<length;i++)
	{
		if (pdatas[i] > max)
		{
			max = pdatas[i];
		}
	}
	return max;
}
int Data::min(int* pdatas, int length)
{
	int min = pdatas[0];
	for (int i = 0; i < length; i++)
	{
		if (pdatas[i] < min)
		{
			min = pdatas[i];
		}
	}
	return min;
}

*/