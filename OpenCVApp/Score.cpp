#include "Score.h"

StudentScore::StudentScore()
{
	cout << "StudentScore::Ctor" << endl;
}

StudentScore::~StudentScore()
{
	cout << "StudentScore::Dtor" << endl;
}

void StudentScore::SetStudent(string* subject, string Name,int* score)
{
	stSutudentInfo.name = Name;
	for (size_t i = 0; i < eClassMax; i++)
	{
		stSutudentInfo.scores[i] = score[i];
		stSutudentInfo.subject[i] = subject[i];
	}
}

void StudentScore::DoCalc()
{
	cout << "ÀÌ¸§: " << stSutudentInfo.name << endl;
	for (size_t i = 0; i < eClassMax; i++)
	{
		cout << stSutudentInfo.subject[i] <<": " << stSutudentInfo.scores[i] << endl;
	}
	cout << "ÃÑÇÕÀº " << stSutudentInfo.sum << endl;
	cout << "Æò±ÕÀº " << stSutudentInfo.avg << endl;
	cout << "ÃÖ¼Ú°ªÀº " << stSutudentInfo.min << endl;
	cout << "ÃÖ´ñ°ªÀº " << stSutudentInfo.max << endl;

}


int StudentScore::Getsum(const int* const pData, size_t length)
{
	int sum = 0;
	for (size_t i = 0; i < length; i++) {
		sum += pData[i];
	}
	stSutudentInfo.sum = sum;
	return stSutudentInfo.sum;
}

float StudentScore::Getavg(const int* const pData, size_t length)
{
	stSutudentInfo.avg=Getsum(pData, length) / static_cast<float>(length);
	return stSutudentInfo.avg;
}

int StudentScore::Getmin(const int* const pData, size_t length)
{
	int min = pData[0];
	for (size_t i = 0; i < length; i++) {
		if (min > pData[i]) min = pData[i];
	}
	stSutudentInfo.min = min;
	return stSutudentInfo.min;
}

int StudentScore::Getmax(const int* const pData, size_t length)
{
	int max = pData[0];
	for (size_t i = 0; i < length; i++) {
		if (max < pData[i]) max = pData[i];
	}
	stSutudentInfo.max = max;
	return stSutudentInfo.max;
}