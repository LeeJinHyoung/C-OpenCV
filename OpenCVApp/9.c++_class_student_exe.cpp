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
	//�غ���
	//SeuSubjectScore�� ����ڰ� �Է��� subject�� score��
	//Q,q�� ����Ǳ���� �Է� �޾� �� ����� ����ϼ���
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