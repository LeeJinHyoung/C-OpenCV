#include "Employee.h"
int main() 
{	
	CDate date(2023, 2, 24);
	{
		Employee e("Parent", "Here", "010-0000-0000", date);
		e.DisplayEmployee();
		e.DoWork();
	}
	{
		//Employee* pEmployee = &e;
		//RegularEmployee* pRegularEmployee = &re;
		//�ٿ�ĳ����..�⺻Ŭ������ �Ļ�Ŭ������ ����Ų��.
		RegularEmployee re("KCCI", "Here", "010-1234-5678", date, 6000);
//		pEmployee = &re;//�ڽ�Ŭ���� ����ų���ִ�
		re.DisplayEmployee();
		re.DoWork();
	}
	////��ĳ���� �Ļ�Ŭ������ �θ�Ŭ���� ����Ŵ
	//pRegularEmployee = &e;

	return 1;
}

