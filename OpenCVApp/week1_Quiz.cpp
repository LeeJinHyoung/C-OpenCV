//Quiz
//namespace를 이용하여 사칙연산 계산기를 만들어 봅시다.
//두 수 a,b 입력을 받습니다.
//계산할 기호 +,-,/,* 입력을 받습니다.
//namespace Calc{} 선언합니다.
//Calc 네임스페이스엔믄 add(+), sub(-), mul(*), div(/) 함수를 만들어요
//입력과 출력은 cin, cout
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
		//	std::cout << "다시 입력해주세요" << std::endl;
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