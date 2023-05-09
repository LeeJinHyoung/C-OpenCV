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
	//�Է¹޴� ���� �빮�ڷ� �ٲ۵� ��
	//c-style
	//for (size_t i = 0; i<str.size(); i++)
	//{
	//	str[i] = std::toupper(str[i]);
	//}
	//c++-style ::lambda expression
	std::transform(str.begin(), str.end(), str.begin(), [](uchar c) {return toupper(c); });
	//���ڿ��ǽ��۰� ���� �˷��ְ� 
	//�̸����� �Լ� lambda
	//[](uchar c) // [�Լ��̸�??](�Ű�����){retrun }
	//{
	//	uchar upC = toupper(c);
	//	return upC; //���ʿ��� �ڵ� �޸� ����
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
		"���� : " << studentInfo.kor <<
		"���� : " << studentInfo.eng <<
		"����: " << studentInfo.math <<
		"����: " << GetSum() <<
		"���: " << GetAvg() <<
		"�ּ�: " << GetMin() <<
		"�ִ�: " << GetMax() << endl;
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
	//��������{0,������,...}
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
	//��������{0,������,...}
	std::sort(score, score + 3);//score.begin(), score.end()
	return score[3-1];
}
