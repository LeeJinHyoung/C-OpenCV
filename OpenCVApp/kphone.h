#pragma once
#include "common.h"

class kPhone 
{
public:
	
	kPhone();
	~kPhone();
	int Getresult();
	int Cancel();
	int Send();
	int Receive();
	int Numbers(string _strNumbers);
	int Numbers(int* pAudioData, int length);

private: 
	string strNumber;
	bool isConnected;
	int result;
};