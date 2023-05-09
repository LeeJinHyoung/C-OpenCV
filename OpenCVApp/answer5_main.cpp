#include <iostream>
#include<string>
using namespace std;

int main()
{
	class IShape
	{
	public:
		IShape() { cout << "IShape Ctor" << endl; }
		virtual~IShape() { cout << "IShape Dtor" << endl; }
		virtual void Show(){ cout << "IShape Default " << endl; }
		virtual int GetShape() = 0;
	};
	class Circle :public IShape
	{
	public:
		Circle() { cout << "Circle Ctor" << endl; }
		~Circle() override { cout << "Circle Dtor" << endl; }
		int GetShape() { return 1; }
	};
	class Rect :public IShape
	{
	public:
		Rect() { cout << "Rect Ctor" << endl; }
		~Rect() override { cout << "Rect Dtor" << endl; }
		int GetShape() { return 2; }
	};

	IShape* pShape = new Circle();

	cout << pShape->GetShape() << endl;

	pShape = new Rect();

	cout << pShape->GetShape() << endl;
	if (pShape != nullptr) {delete pShape; pShape = nullptr;}

	return 1;
}
