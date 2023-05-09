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
