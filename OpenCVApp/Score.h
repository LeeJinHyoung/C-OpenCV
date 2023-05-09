#pragma once
#include "common.h"
enum { eEng, eMath, eKor, eClassMax };
struct SutudentInfo
{	
	int sum, avg, min, max = 0;
	string subject[eClassMax] = { " ", };
	int scores[eClassMax] = { 0, };
	string name = " ";
};
class StudentScore
{
public:
	StudentScore();
	~StudentScore();
	void SetStudent(string* subject, string Name, int* score);
	void DoCalc();
	int Getsum(const int* const pData, size_t length);
	float Getavg(const int* const pData, size_t length);
	int Getmin(const int* const pData, size_t length);
	int Getmax(const int* const pData, size_t length);

private:
	SutudentInfo stSutudentInfo;
	map<string, int> score;
	int result=0;
};
