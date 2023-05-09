#include <iostream>
#include<string>
#include "common.h"

using namespace std;
class Data
{
public:
	Data() { cout << "Data::Ctor" << endl; }
	~Data() { cout << "Data::Dtor" << endl; }

	double sum(double* pdatas, int length)
	{
		double _sum = 0;
		for (size_t i = 0; i < length; i++) { _sum += pdatas[i]; }

		return _sum;
	}
};
int main()
{
	double* pdata = new double[20] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,12,13,14,15,16,17,18,19,20 };
	Data data;
	cout << "double datas sum  = " << data.sum(pdata, 20) << endl;

	if (pdata != nullptr) { delete[] pdata; pdata = nullptr; }

	return 1;
}