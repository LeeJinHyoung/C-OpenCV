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
		cout << "���� ���� " << calc.Getresult() << endl;

		calc.Clear();
		calc.SetValue(1, 2, '+');
		calc.Dosum();
		cout << "���� ���� " << calc.Getresult() << endl;
	}
	if (false)
	{
		Calc* pCalc = new Calc(1, 1, '+'); //���ο� ��ü //�����޸��Ҵ����� ����

		int data[3] = { 1,2,3 };
		pCalc->sum(data, 3); //Ŭ������ ���ο� ������ ��ü�� ����
		cout << "���� ���� " << pCalc->Getresult() << endl;

		pCalc->Clear();
		pCalc->SetValue(1, 2, '+');
		pCalc->Dosum();
		cout << "���� ���� " << pCalc->Getresult() << endl;

		if (pCalc != nullptr)//�����޸��Ҵ� ���� //���ϸ� ������������ dtor���� �����
		{
			delete pCalc; //Ŭ������ �Ҹ��ڰ���
			pCalc = nullptr;//�����Ⱚ�� ����ų�������� �η� �����
		}
	}
	{	//smart pointer
		std::shared_ptr<Calc> pCalc = std::make_shared<Calc>(1,1,'+');//�������θ� ����� ��� exception������ ����

		int data[3] = { 1,2,3 };
		pCalc->sum(data, 3); //Ŭ������ ���ο� ������ ��ü�� ����
		cout << "���� ���� " << pCalc->Getresult() << endl;

		pCalc->Clear();
		pCalc->SetValue(1, 2, '+');
		pCalc->Dosum();
		cout << "���� ���� " << pCalc->Getresult() << endl;

	}
}