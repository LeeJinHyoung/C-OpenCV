#include "StudentScore_rev0.0.h"

StudentScore::StudentScore()
{
	cout << "StudentScore::Ctor" << endl;
}
StudentScore::~StudentScore()
{
	cout << "StudentScore::Dtor" << endl;
}
int StudentScore::SetStudentName(string name)
{
	studentInfo.name = name;
	return 0;
}
int StudentScore::SetSubjectScore(string subject, int score)
{	
	string str = subject;
	//입력받는 과목 대문자로 바꾼뒤 비교
	//c-style
	//for (size_t i = 0; i<str.size(); i++)
	//{
	//	str[i] = std::toupper(str[i]);
	//}
	//c++-style ::lambda expression
	std::transform(str.begin(), str.end(), str.begin(), [](uchar c) {return toupper(c); });
	//문자열의시작과 끝을 알려주고 
	//이름없는 함수 lambda
	//[](uchar c) // [함수이름??](매개변수){retrun }
	//{
	//	uchar upC = toupper(c);
	//	return upC; //불필요한 코드 메모리 잡음
	//}

	if (str == "KOR") studentInfo.kor = score;
	else if (str == "ENG") studentInfo.eng = score;
	else if (str == "MATH")	studentInfo.math = score;
	else cout << "Subject {kor, eng, math} Only" << endl;
	return 0;
}
int StudentScore::DoCalc()
{
	cout << studentInfo.name << "=" << " | " <<
		"국어 : " << studentInfo.kor <<
		"영어 : " << studentInfo.eng <<
		"수학: " << studentInfo.math <<
		"총합: " << GetSum() <<
		"평균: " << GetAvg() <<
		"최소: " << GetMin() <<
		"최대: " << GetMax() << endl;
	return 0;
}
int StudentScore::GetSum()
{
	return (studentInfo.kor + studentInfo.eng + studentInfo.math);
}

float StudentScore::GetAvg()
{
	return GetSum() / 3.0;
}

int StudentScore::GetMin()
{
	int score[3] = { studentInfo.kor,studentInfo.eng,studentInfo.math };
	int min = score[0];
	for (size_t i=0; i < 3; i ++ )
	{
		if (min > score[i]) min = score[i];
	}
	//오름차순{0,작은수,...}
	std::sort(score, score + 3);//score.begin(), score.end()
	return score[0];
}

int StudentScore::GetMax()
{
	int score[3] = { studentInfo.kor,studentInfo.eng,studentInfo.math };
	int min = score[0];
	for (size_t i=0; i < 3; i ++ )
	{
		if (min > score[i]) min = score[i];
	}
	//오름차순{0,작은수,...}
	std::sort(score, score + 3);//score.begin(), score.end()
	return score[3-1];
}
