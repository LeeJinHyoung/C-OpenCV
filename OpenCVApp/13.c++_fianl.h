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
