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
		//다운캐스팅..기본클래스가 파생클래스를 가리킨다.
		RegularEmployee re("KCCI", "Here", "010-1234-5678", date, 6000);
//		pEmployee = &re;//자식클래스 가르킬수있다
		re.DisplayEmployee();
		re.DoWork();
	}
	////업캐스팅 파생클래스가 부모클래스 가르킴
	//pRegularEmployee = &e;

	return 1;
}

