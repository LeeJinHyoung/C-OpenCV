#pragma once
#include "common.h"
class StudentScore
{
public:
	StudentScore();
	~StudentScore();

	void SetStudentName(string name);
	void SetSubjectScore(string subject, int score);
	void DoCalc();

private:
	int GetSum();
	float GetAvg();
	int GetMin();
	int GetMax();
	struct StudentInfo
	{
		string name;
//		int eng, kor, math;
		int sum, min, max;
		float avg;
		std::map<string, int> mTable;
	};
	StudentInfo studentInfo;
//	std::map<string, studentInfo> mTable;
};
//std::map<string, StudentScore> mTable; //학생이름 성적
//std::map<string, void*> mTable;
//void* ....(int*)(void*)
//[](uchar )
