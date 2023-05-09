#include <iostream>
#include<string>
using namespace std;

int main() {
	string strName;
	int strAge;
	string strAddress;
	cin >> strName >> strAge >> strAddress;
	cout << "이름: " << strName << endl
		<< "나이: " << strAge << endl
		<< "Link URL: " << strAddress << endl;

	return 0;
}