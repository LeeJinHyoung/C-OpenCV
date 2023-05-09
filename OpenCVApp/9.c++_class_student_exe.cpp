//#include "StudentScore_rev0.0.h"
#include "StudentScore_rev1.0.h"

int main()
{	
	if (false)
	{
		string strName;
		int scoreKor, scoreEng, scoreMath;

		cout << "Input Student Name";
		cin >> strName;
		cout << "Input Student subject {kor,eng,math} Score: ";
		cin >> scoreKor >> scoreEng >> scoreMath;

		StudentScore ss;
		ss.SetStudentName(strName);
		ss.SetSubjectScore("kor", scoreKor);
		ss.SetSubjectScore("ENG", scoreEng);
		ss.SetSubjectScore("Math", scoreMath);

		ss.DoCalc();
	}
	//해보기
	//SeuSubjectScore에 사용자가 입력한 subject와 score를
	//Q,q로 종료되기까지 입력 받아 그 결과를 출력하세요
	string strName;
	string subject;
	int score;
//	int scoreKor, scoreEng, scoreMath;
	StudentScore ss;
	vector<StudentScore> V;

	while (true)
	{
		cout << "Input Student Name";

		cin >> strName;
		if (strName == "Q") break;
		ss.SetStudentName(strName);


		while (true)
		{
			cout << "Input Student subject / Score: ";
			//	cin >> scoreKor >> scoreEng >> scoreMath;
			cin >> subject;
			if (subject == "Q") break;
			cin >> score;
			ss.SetSubjectScore(subject, score);
		}

		V.push_back(ss);
	}
	for (int i =0;i<V.size();i++)
	{
		V[i].DoCalc();
	}
	
	return 1;

}