#include <iostream>//������������
//istrem vs ostream
//cin ">>"  cout "<<"
//#include <stdio.h> //standard io

//#define _CRT_SECURE_NO_WARNINGS //������Ʈ �Ӽ� > C/C++ ��ó���� �߰�
//#include "abc.h" user defined header
//�Լ� ����
//[��ȯ��] [�Լ���] [(�Ű�����)] { }
int main() 
{	
	printf("Hello, ");
	printf("World\n");
	std::cout << "Hello, ";
	std::cout << "World\n";
	std::cout << "Hello, World" << std:: endl;

	printf("math - %d\n", 100); //����
	std::cout << "math - %d\n" << 100 << std::endl;
	printf("pi - %lf\n", 3.14); //�Ҽ�
	std::cout << "pi - %fl\n" << 3.14 << std::endl;
	printf("Score - %c\n", 'A'); //����
	std::cout << "Score - %c\n" << 'A' << std::endl;

	printf("%d % lf %c", 100, 3.14, 'A'); //���� �ȸ����ָ� ����� �۵�X //cout�� �̿��ϸ� �ش��ϴ� �ڷ��� �ڵ����� ����ż� ��

	std::cout << "Hello, World \r\n" << std::endl; //end line

	//�Է�
	//c
	int i = 0;
	scanf("input - %d", &i); //���Լ��� ������ ���������ʴ� secrety������ ���ų� _CRT_SECURE_NO_WARNNINGS�ɼ� �߰�//�ڡڡڡڡ�
	printf("%d typed", i);

	//c++
	std::cout << "input -";
	std::cin >> i; //�ڡڡڡڡ�
	std::cout << i << "typed" << std::endl; // endl : \n

	return 1; //TRUE: 1, FALSE: 0 //� ��ȣ���� �������λ��¶�� ���� �Ӻ���忡�� �Ϲ������� ����0�� �������� ��

}