#include "Score.h"

int main()
{
	StudentScore Score;
	string subject[eClassMax] = { " ", };
	string Name = " ";
	int score[eClassMax] = {0, };
	cout << "�̸��� �Է��ϼ���: " <<endl;
	cin >> Name;
	cout << "������ �Է��ϼ���: " << endl;
	for (size_t i = 0; i < eClassMax; i++) {

		cin >> subject[i];
	}
	cout << "������ �Է��ϼ���: " << endl;
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