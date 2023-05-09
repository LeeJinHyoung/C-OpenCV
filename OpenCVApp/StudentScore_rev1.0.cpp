#include "StudentScore_rev1.0.h"


StudentScore::StudentScore()
{
	cout << "StudentScore::Ctor" << endl;
}
StudentScore::~StudentScore()
{
	cout << "StudentScore::Dtor" << endl;
}
void StudentScore::SetStudentName(string name)
{
	studentInfo.name = name;
	studentInfo.mTable.clear();

}
void StudentScore::SetSubjectScore(string subject, int score)
{
	
	//입력받는 과목 대문자로 바꾼뒤 비교
	//c-style
	//for (size_t i = 0; i<str.size(); i++)
	//{
	//	str[i] = std::toupper(str[i]);
	//}
	//c++-style ::lambda expression
	string str = subject;

//	std::transform(str.begin(), str.end(), str.begin(), [](uchar c) {return toupper(c); });
	//문자열의시작과 끝을 알려주고 
	//이름없는 함수 lambda
	//[](uchar c) // [함수이름??](매개변수){retrun }
	//{
	//	uchar upC = toupper(c);
	//	return upC; //불필요한 코드 메모리 잡음
	//}

	//if (str == "KOR") studentInfo.kor = score;
	//else if (str == "ENG") studentInfo.eng = score;
	//else if (str == "MATH")	studentInfo.math = score;
	//else cout << "Subject {kor, eng, math} Only" << endl;
	if (studentInfo.mTable.find(subject)!=studentInfo.mTable.end())
	{
		cout << "same subject found" << endl;
		return;
	}

	studentInfo.mTable.insert({ subject,score });


}
void StudentScore::DoCalc()
{

	cout << studentInfo.name << "=>";

	string StudentReport;
	for (auto iter = studentInfo.mTable.begin();
		iter!=studentInfo.mTable.end();
		iter++)
	{
		StudentReport += iter->first;
		StudentReport += " : ";
		StudentReport += std::to_string(iter->second);
		StudentReport += " ";
	}

	cout << StudentReport << "\t"<<

		"총합: " << GetSum() << "\t" <<
		"평균: " << GetAvg() << "\t" <<
		"최소: " << GetMin() << "\t" <<
		"최대: " << GetMax() << endl;
	
}
int StudentScore::GetSum()
{
//	return (studentInfo.kor + studentInfo.eng + studentInfo.math);
	int sum = 0;
	//using map (key, value)
	//values
	vector<int> vScores;
	for (auto iter = studentInfo.mTable.begin();
		iter != studentInfo.mTable.end();
		iter++)
	{
		iter->first;//key:string
		iter->second;//value:int
//		sum = sum + iter->second;
		vScores.push_back(iter->second);//맵에서 원하는 데이터 추출해서 벡터에 넣음

	}
	for (auto iter = vScores.begin();
		iter != vScores.end();
		iter++)
	{
		sum += *iter;//value, iter::pointer address //벡터로 계산
	}
	return sum;
}

float StudentScore::GetAvg()
{
	return GetSum() / studentInfo.mTable.size();
}

int StudentScore::GetMin()
{
	//int score[3] = { studentInfo.kor,studentInfo.eng,studentInfo.math };
	//int min = score[0];
	//for (size_t i = 0; i < 3; i++)
	//{
	//	if (min > score[i]) min = score[i];
	//}
	////오름차순{0,작은수,...}
	//std::sort(score, score + 3);//score.begin(), score.end()
	//return score[0];
	vector<int> vScores;
	for (auto iter = studentInfo.mTable.begin();
		iter != studentInfo.mTable.end();
		iter++)
	{
		iter->first;//key:string
		iter->second;//value:int
		//		sum = sum + iter->second;
		vScores.push_back(iter->second);//맵에서 원하는 데이터 추출해서 벡터에 넣음

	}
	std::sort(vScores.begin(), vScores.end());
//	std::sort(vScores.begin(), vScores.begin()+ vScores.size());
	return vScores[0];

}

int StudentScore::GetMax()
{
	//int score[3] = { studentInfo.kor,studentInfo.eng,studentInfo.math };
	//int min = score[0];
	//for (size_t i = 0; i < 3; i++)
	//{
	//	if (min > score[i]) min = score[i];
	//}
	////오름차순{0,작은수,...}
	//std::sort(score, score + 3);//score.begin(), score.end()
	//return score[3 - 1];
	vector<int> vScores;
	for (auto iter = studentInfo.mTable.begin();
		iter != studentInfo.mTable.end();
		iter++)
	{
		iter->first;
		iter->second;

		vScores.push_back(iter->second);

	}
	std::sort(vScores.begin(), vScores.end());
	return vScores[vScores.size() - 1];

}
