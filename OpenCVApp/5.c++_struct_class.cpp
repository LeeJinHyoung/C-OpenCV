//struct
//class
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

//typedef unsigned char uchar;//����� Ÿ�� ������
//typedef unsigned int uint;
//
//class Myclass
//{
//
//
//};
//
////����ü, struct		//struct class 1���� ������
////					struct(public)
////					class�� ���������ڰ� ������ ����(public, pivate, )
//struct _stData
//{
//	//���� �ٸ� ������ ������ �׸��� �����Ͽ�
//	//�ϳ��� ������ ������ [������ Ÿ��]
//	int score;
//	double ratio;
//	std::string name;
//	int datas[100];
//	int* pPreData = nullptr;
//	int* pPostData = nullptr;
//	std::vector <int> vLines;
//
//	//�Լ�
//	void sum(int& a, int &b) { return a + b; }
//	//Ŭ����
//	Myclass mclass;
//};
//
//int a;
//_stData stData = { 10, 0.1, "hello", null, nullptr};
//_stData pstData = new _stData; //nullptr
////c
////typedef struc[tagName]
////{
////	//����Ÿ��
////}[nickname];
//
//�л� ����-����

enum {eEnglish, eMath, eKorean, eClassMax} ECLASS; //���ڸ� ���ȭ���ѳ��� Ÿ�� ECLASS�г���
//enum { eEnglish, eMath=5, eKorean, eClassMax } ECLASS; //���ڸ� ���ȭ���ѳ��� Ÿ�� ECLASS�г���
		//0				  //2->6	//6->7
//eClassMax: �迭�� length
struct _stSutudentInfo
{
//	int eng, math, kor;
	int scores[eClassMax];
	//0��° �ε��� - english
	//1��° �ε��� - math
	//2��° �ε��� - korean
	int sum, min, max;
	float average;
	std::string name;
};

//�ε����� 1? �ϵ��ڵ� ������ ���� �����ϱ����� �̹迭�� �����ε����� � �����Ͱ� ����ִ� ���° �ε����� �̳��� �����̴� ������༭ ��Ȯ�ϰ� ���� �˼�����
//���ӵ� ���� �ڵ����� ���� 
//scores[eEnglish] = 5;
//scores[eKorean] = 3;
//for (size_t score = 0; score < eClassMax; score++)
//{
//
//}
int sum(const int* const pData, size_t length)
{
	int sum = 0;
	for (size_t i = 0; i < length; i++) { sum += pData[i]; }
	return sum;
}
float average(const int* const pData, size_t length)
{
	//float average = 0.;
	//average = (float)sum / (float)length;
	//return average;
	return sum(pData, length) / length;
}
int min(int* pData, int length)
{	
	int min = pData[0];
	for (size_t i = 0; i < length; i++)
	{
		if (pData[i] < min)
		{
			min = pData[i];
		}
	}
	return min;
}
int max(int* pData, int length)
{
	int max = pData[0];
	for (size_t i = 0; i < length; i++)
	{
		if (pData[i] > max)
		{
			max = pData[i];
		}
	}
	return max;
}
//float display()
//{
//	float result=0;
//
//
//	return result;
//}

int main()
{
	_stSutudentInfo student;
	student.scores[eEnglish] = 90;
	student.scores[eMath] = 95;
	student.scores[eKorean] = 92;
	student.name = "������";
	std::vector< _stSutudentInfo> vStudent;
	//1��
	//�Լ� ...sum, average, min, max
	//input scores[],length
	//return sum(int), average(float), min(int), max(int)
	while (1){
		
		
			std::cin >> student.name 
			if (student.name == "Q") break;
			std::cin >> student.scores[eEnglish] >> student.scores[eMath] >> student.scores[eKorean];
				std::cout << "�̸�: " << student.name << std::endl;
				std::cout << "�� ������ ����  " << sum(student.scores, eClassMax) << std::endl;
				std::cout << "�� ������ ��հ���  " << average(student.scores, eClassMax) << std::endl;
				std::cout << "�� ���� �� �ּڰ���  " << min(student.scores, eClassMax) << std::endl;
				std::cout << "�� ���� �� �ִ���  " << max(student.scores, eClassMax) << std::endl;
				vStudent.push_back(student);
	}

	for (size_t i = 0; i < vStudent.size(); i++)
	{
		_stSutudentInfo* pStudent = &vStudent[i];

	}


	return 0;
	//display - ���
	//[�̸�]
	//english - ??, math - ??, korean - ??
	//sum - ??, average - ??, min -? , max -?

	//2�� - �ڵ����� �Է� �� ���� ���
	//����ڷκ��� �Է��� �޽��ϴ�.
	//struct�� string name�� �Է� �޾ƿ�.
	//�� eng, math. kor ������ �Է� �޾ƿ�.
	//�� display�� ����� �մϴ�
	//Q�Է��� ������ ���̻� �Է��� ���� �ʽ��ϴ�.


}