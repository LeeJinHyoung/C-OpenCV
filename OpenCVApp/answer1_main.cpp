#include <iostream>
#include<string>
using namespace std;

int main() {
	string strName;
	int strAge;
	string strAddress;
	cin >> strName >> strAge >> strAddress;
	cout << "�̸�: " << strName << endl
		<< "����: " << strAge << endl
		<< "Link URL: " << strAddress << endl;

	return 0;
}