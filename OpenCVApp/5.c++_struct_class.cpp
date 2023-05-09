//struct
//class
#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

//typedef unsigned char uchar;//사용자 타입 재지정
//typedef unsigned int uint;
//
//class Myclass
//{
//
//
//};
//
////구조체, struct		//struct class 1개의 차이점
////					struct(public)
////					class는 접근지정자가 나눠져 있음(public, pivate, )
//struct _stData
//{
//	//서로 다른 종류의 데이터 항목을 결합하여
//	//하나의 단위로 정의한 [데이터 타입]
//	int score;
//	double ratio;
//	std::string name;
//	int datas[100];
//	int* pPreData = nullptr;
//	int* pPostData = nullptr;
//	std::vector <int> vLines;
//
//	//함수
//	void sum(int& a, int &b) { return a + b; }
//	//클래스
//	Myclass mclass;
//};
//
//int a;
//_stData stData = { 10, 0.1, "hello", null, nullptr};
//_stData pstData = new _stData; //nullptr
////c
////typedef struc[tagName]
////{
////	//데이타형
////}[nickname];
//
//학생 정보-성적

enum {eEnglish, eMath, eKorean, eClassMax} ECLASS; //문자를 상수화시켜놓은 타입 ECLASS닉네임
//enum { eEnglish, eMath=5, eKorean, eClassMax } ECLASS; //문자를 상수화시켜놓은 타입 ECLASS닉네임
		//0				  //2->6	//6->7
//eClassMax: 배열의 length
struct _stSutudentInfo
{
//	int eng, math, kor;
	int scores[eClassMax];
	//0번째 인덱스 - english
	//1번째 인덱스 - math
	//2번째 인덱스 - korean
	int sum, min, max;
	float average;
	std::string name;
};

//인덱스가 1? 하드코딩 변수를 보고도 이해하기어려움 이배열의 현재인덱스는 어떤 데이터가 들어있다 몇번째 인덱스가 이넘의 무엇이다 명시해줘서 명확하게 값을 알수있음
//연속된 수가 자동으로 증분 
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
	student.name = "류혜진";
	std::vector< _stSutudentInfo> vStudent;
	//1차
	//함수 ...sum, average, min, max
	//input scores[],length
	//return sum(int), average(float), min(int), max(int)
	while (1){
		
		
			std::cin >> student.name 
			if (student.name == "Q") break;
			std::cin >> student.scores[eEnglish] >> student.scores[eMath] >> student.scores[eKorean];
				std::cout << "이름: " << student.name << std::endl;
				std::cout << "세 과목의 합은  " << sum(student.scores, eClassMax) << std::endl;
				std::cout << "세 과목의 평균값은  " << average(student.scores, eClassMax) << std::endl;
				std::cout << "세 과목 중 최솟값은  " << min(student.scores, eClassMax) << std::endl;
				std::cout << "세 과목 중 최댓값은  " << max(student.scores, eClassMax) << std::endl;
				vStudent.push_back(student);
	}

	for (size_t i = 0; i < vStudent.size(); i++)
	{
		_stSutudentInfo* pStudent = &vStudent[i];

	}


	return 0;
	//display - 출력
	//[이름]
	//english - ??, math - ??, korean - ??
	//sum - ??, average - ??, min -? , max -?

	//2차 - 자동으로 입력 및 성적 출력
	//사용자로부터 입력을 받습니다.
	//struct에 string name을 입력 받아요.
	//각 eng, math. kor 점수를 입력 받아요.
	//위 display로 출력을 합니다
	//Q입력을 받으면 더이상 입력을 받지 않습니다.


}