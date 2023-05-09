#pragma once
#include "common.h"

class Calc //struct �ϰ� �Ȱ����� �������������ڸ� ������
{
public:
	//��׵� void �Լ���
	//������ ������ ������������
	Calc();//Ctor...default Ctor ������ ��� �⺻�����ڰ� ���� ���ָ� ���� �ʱ�ȭ�� �ȵ�
//	Calc(int a = 1, int b = 2, char sym = ' ');//�����ε�//���� �� �־ �⺻������ ����Ҽ� ����
	Calc(int a, int b, char sym);//�����ε�

	//�Ҹ���
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

private: //���ο��� �Ⱥ���
	int* pData = nullptr;
	int number1;//�ʱ�ȭ �ȵȻ���
	int number2;
	char symbol;
	int result;
};

//usuage
/*
 7.c++_class.cpp ���弼��

#include "Calc.h"
int main()
{
	Calc calc
	calc.SetValue(1,2,'+');
	clac.Dosum();
	cout<<"�μ��� ���� " << calc.GetResult() <<endl;	
}
//console â�� ���¸� ĸ���ϼ���.

*/