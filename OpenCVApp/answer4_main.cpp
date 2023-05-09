#include <iostream>
#include<string>
using namespace std;

class Base
{
public:
	Base() { cout << "Ctour" << endl; }
	virtual ~Base() { cout << "Dtour" << endl; }
	virtual void Show() = 0;
};
class ChildA :public Base
{
public:
	ChildA() { cout << "Ctour" << endl; }
	~ChildA() { cout << "Dtour" << endl; }
	void Show() override { cout << "ChildA"  << endl; };
};
class ChildB :public Base
{
public:
	ChildB() { cout << "Ctour" << endl; }
	~ChildB() { cout << "Dtour" << endl; }
	void Show() override { cout << "ChildB" << endl; };
};
int main()
{
	Base* pBase = new ChildA();
	pBase->Show();
	Base* pBase2 = new ChildB();
	pBase2->Show();

	if (pBase != nullptr) { delete pBase; pBase = nullptr; }
	if (pBase2 != nullptr) { delete pBase2; pBase2 = nullptr; }

	return 1;
}

