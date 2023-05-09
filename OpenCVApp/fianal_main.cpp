#include <iostream>
#include<string>
#include "13.c++_fianl.h"
using namespace std;


class Base
{
public:
	Base() { cout << "Ctour" << endl; }
	virtual~Base() { cout << "Dtour" << endl; }//�Ҹ��� virtual  ��Ӱ���
	virtual void Show() { cout << "Base: " << "_a" << endl; }//virtual keyword �ڽ��� ������ �Ѵ�
	//������ pure, �˾Ƽ� ���ض� �׳� �����Լ�
	//virtual void Show()=0; ���������Լ� ������
	//virtual void Show(); �����Լ� ������
	void SetValue(int a) { _a = a; }
	int GetValue() { return _a; }
private:
	int _a = 0; //Ŭ������ ���м�
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
			auto i = 10; //for������ ���� ��������

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
//Quiz 1. ����� �̸�(string),����(int), �ּ�(string) �Է�
//		�̸�: �̼���
//		����: 100
//		�ּ�: ����� 12-123


	//Data data("�̼���", 100, "12-123");
	//data.DisplayEmployee();
	
	
//Quiz 2. �����޸� �Ҵ�(int*), ũ��(int,10), ���Ұ�(1,2,3,4,5,6,7,8,9,10)�� �迭�� ��/ �ּ� / �ִ� ���
//		//��:?
//		//�ּ�:?
//		//�ִ�:?
	
	int* pdata = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	Data data;
	cout << "int datas sum  = " << data.sum(pdata, 10) << endl;
	cout << "int datas max  = " << data.max(pdata, 10) << endl;
	cout << "int datas max  = " << data.min(pdata, 10) << endl;

if (pdata != nullptr) { delete[] pdata; pdata = nullptr; }

//Quiz 3. C++ ��ü�������� Ư¡�� ����Ͻÿ�
cout << "ĸ��ȭ: ���õ� �����Ϳ� �Լ��� �ϳ��� ������ ��� �ܺο��� ������ �� ���� �ϴ� ���� �ǹ��Ѵ�.\n"
	<< "Ŭ������ ĸ��ȭ�� �����ϴ� ���� �⺻���� �����̸�, ���� ������ ���� ��ü�� ���� ������ ����� �ܺο����� �������̽��� ���ؼ��� ��ü�� ������ �� �ֵ��� �մϴ�.\n"
	<<"���: �̹� ���ǵ� Ŭ������ ������� ���ο� Ŭ������ ������ �� �ֽ��ϴ�.����� ���� ���� Ŭ������ ������� �״�� ����ϸ鼭 ���ο� ����� �߰��ϰų� ���� ����� ������ �� �ֽ��ϴ�. \n"
	<<"������ : ���� �̸��� �Լ��� �ٸ� ������ �����ϴ� ���� �ǹ��մϴ�.C++���� �������� �Լ� �����ε��� ���� �Լ��� �̿��Ͽ� �����˴ϴ�. \n"
	<<"�߻�ȭ : ������ �ý����� �ܼ�ȭ�Ͽ� �ʿ��� �κи��� �����ϴ� ���� �ǹ��մϴ�.Ŭ������ �������̽��� �����ϰ� ��ü�� ���������ν� �߻�ȭ�� ������ �� �ֽ��ϴ�.\n"
	<<"��ü ��ü�� �����Ϳ� �Լ��� �����Դϴ�. \n"
	<<"C++���� ��� ���� ��ü�� ǥ���˴ϴ�.Ŭ������ �����Ͽ� ��ü�� �����ϰ�, ��ü�� �����ϸ鼭 ���α׷��� �ۼ��մϴ�. \n"
	<<"�޸� ���� : C++�� �޸𸮸� ���� �Ҵ��ϰ� �����ϴ� ���� �����մϴ�.�̸� ���� �޸� ������ ȿ�������� ������ �� �ֽ��ϴ�.������ �޸� ������ �Ǽ��� ��쿡�� �޸� ������ �߸��� �޸� ���� ���� ������ �߻��� �� �����Ƿ� ���ǰ� �ʿ��մϴ�.�ֽ� C++ ���������� ����Ʈ ������ ���� ����� �����Ͽ� �޸� ������ �ڵ�ȭ�� �� �ֵ��� �����մϴ�."
 << endl;



//Quiz 4. �Ʒ� Ŭ������ �������� ��ġ�� ���� ����Ͻÿ�
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
	//���
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