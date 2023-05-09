#pragma once
#include "common.h"
class StudentScore
{
public:
	StudentScore();
	~StudentScore();

	int SetStudentName(string name);
	int SetSubjectScore(string subject, int score);
	int DoCalc();

private:
	int GetSum();
	float GetAvg();
	int GetMin();
	int GetMax();
	struct StudentInfo
	{
		string name;
		int eng, kor, math;
		int sum, min, max;
		float avg;
	};
	StudentInfo studentInfo;
};

