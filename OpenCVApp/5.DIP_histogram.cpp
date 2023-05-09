#include <iostream>

//Histogram을 출력하세요
//histo[0] = 0,0,0,0...4
//histo[1] = 1,1,1,1...4
//histo[5] = 5.........1
using namespace std;
int main()
{
	int data[5 * 5] = {
	1,2,3,4,5,
	1,0,2,0,4,
	2,3,0,2,3,
	3,1,2,3,2,
	1,2,3,0,2 };
	int histo[6] = { 0, };
	int max=0;
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
	{
		histo[data[i]]++;
	}
	for (int i = 0; i <=5; i++) 
	{
		if (max < histo[i]) {
			max = histo[i]; //8
		}
	}
	//histo[0] = 4
	// 
	for (int i = max; i>0 ;i--)
	{
		std::cout << i << "|";
		for (int j = 0; j<=5; j++) 
		{	
			if (histo[j] >= i) std::cout << "*";
			else std::cout << " ";
		}

		std::cout << endl;
	}
	std::cout << "  012345";
	std::cout << endl;
	for (int i = 0; i < sizeof(histo) / sizeof(histo[0]); i++)
	{	 
		std::cout  << histo[i] << " ";
		for (int j = 0; j <histo[i];j++) {
			std::cout << "*" ;
		}
		std::cout << endl;
	}

	
	
}