//Quiz
//namespace�� �̿��Ͽ� ��Ģ���� ���⸦ ����� ���ô�.
//�� �� a,b �Է��� �޽��ϴ�.
//����� ��ȣ +,-,/,* �Է��� �޽��ϴ�.
//namespace Calc{} �����մϴ�.
//Calc ���ӽ����̽����� add(+), sub(-), mul(*), div(/) �Լ��� ������
//�Է°� ����� cin, cout
#include <iostream>

namespace Calc {
	double a=0., b = 0., resVal = 0.;
	char symbol = ' ';
	double add(double a, double b) { return a + b; }
	double sub(double a, double b) { return a - b; }
	double mul(double a, double b) { return a * b; }
	double div(double a, double b) { return a / b; }
	double result() {
		resVal = 0;
 
		if (symbol == '+') resVal = add(a, b);
		else if (symbol == '-')	resVal = sub(a, b);
		else if (symbol == '*')	resVal = mul(a, b);
		else if (symbol == '/')	resVal = div(a, b);

		//switch (symbol) {
		//case '+':
		//	resVal = add(a, b);
		//	break;
		//case '-':
		//	resVal = sub(a, b);
		//	break;
		//case '*':
		//	resVal = mul(a, b);
		//	break;
		//case '/':
		//	resVal = div(a, b);
		//	break;
		//default:
		//	std::cout << "�ٽ� �Է����ּ���" << std::endl;
		//}

		return resVal;
	}
}
//using namespace Calc;
using namespace std;
int main() {
	
	std::cout << "input1: ";	std::cin >> Calc::a;
	std::cout << "input2: ";	std::cin >> Calc::symbol;
	std::cout << "input3: ";	std::cin >> Calc::b;
	std::cout << "result: " << Calc::result() << std::endl;

	return 1;
}