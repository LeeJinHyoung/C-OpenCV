#include "Score.h"

int main()
{
	StudentScore Score;
	string subject[eClassMax] = { " ", };
	string Name = " ";
	int score[eClassMax] = {0, };
	cout << "이름을 입력하세요: " <<endl;
	cin >> Name;
	cout << "과목을 입력하세요: " << endl;
	for (size_t i = 0; i < eClassMax; i++) {

		cin >> subject[i];
	}
	cout << "점수를 입력하세요: " << endl;
	for (size_t i = 0; i < eClassMax; i++) {

		cin >> score[i];
	}
	Score.SetStudent(subject, Name, score);
	Score.Getsum(score, eClassMax);
	Score.Getavg(score, eClassMax);
	Score.Getmin(score, eClassMax);
	Score.Getmax(score, eClassMax);
	Score.DoCalc();

	return 0;
}