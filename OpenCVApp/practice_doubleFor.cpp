#include <iostream>

//int main() 
//{
//	for (int row=5; row > 0 ;row--)
//	{
//		for (int col=1 ; col<6 ;col++)
//		{
//			if(col >=row)std::cout << "*";
//			else std::cout << " ";
//		}
//		
//		/*for (int col = 5; col >= 0; col--)
//		{
//			std::cout << "*";
//		}*/
//		std::cout << "\n";
//	}
//
//}

int main() {
	std::cout << "row�� col�� �������϶�" << std::endl;
	for (int row = 0; row < 5; row++) {
		for (int col = 0; col < 5; col++) {
			printf("%5d", (row * 5) + col);
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << "row�� ����, col�� �������϶�"<<std::endl;
	for (int row = 5; row > 0; row--) {
		for (int col = 0; col < 5; col++) {
			printf("%5d", (row * 5) - col);
		}
		std::cout << std::endl;
	}
}