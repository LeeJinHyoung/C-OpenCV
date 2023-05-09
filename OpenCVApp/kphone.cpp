#include "kphone.h"

kPhone::kPhone()
	:strNumber("000-0000-0000")
,isConnected(false)
,result(0)
{
	cout << "kphone::Ctor" << endl;
}

kPhone::~kPhone()
{
	cout << "kphone::Dtor" << endl;
}

int kPhone::Getresult()
{
	return result;
}

int kPhone::Cancel()
{
	cout << "cancel button activated" << endl;
	cout << "communication finish" << endl;
	isConnected = false;
	return 0;
}


int kPhone::Send()
{	//check number
	if (strNumber == "000-0000-0000")
	{
		cout << "Wrong number" << endl;
		return -1;
	}
	//check on the phone
	if (isConnected == true)
	{
		cout << "on the phone" << endl;
		return -1;
	}
	cout << "calling" << endl;
	cout << "linked" << endl;

	isConnected = true;
	cout << "communication start" << endl;
	//wait(5000);
	//Cancel
	//cout << "communication finish" << endl;

	//isConnected = false;
	return 0;
}

int kPhone::Receive()
{
	if (isConnected == true)
	{
		cout << "on the phone" << endl;
		return -1;
	}
	cout << "linked" << endl;

	isConnected = true;
	cout << "communication start" << endl;
	//Cancel
	//cout << "communication finish" << endl;

	//isConnected = false;

	return 0;
}

int kPhone::Numbers(string _strNumbers)
{
	strNumber = _strNumbers;
	return 0;
}

int kPhone::Numbers(int* pAudioData, int length)
{
	//pAudioData분석
	//음성인식 알고리즘 넣어줘
	string number = "010-1234-5678";//DoAnalysisAudio
	strNumber = number;
	return 0;
}

