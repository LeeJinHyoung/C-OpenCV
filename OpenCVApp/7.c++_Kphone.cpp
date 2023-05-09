#include "kphone.h"
int main()
{
	//전화 걸기
	{
		//전화기를 든다
		kPhone* kphone = new kPhone();

		//전화 번호 입력
		//kphone->Numbers("010-1234-5678");
		int* pAudio = new int[11] {
			0, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8
		};
		int length = 11;
		kphone->Numbers(pAudio,length);
		//전화 걸기
		kphone->Send();

		//전화기를 내린다
		if (kphone != nullptr)
		{
			delete kphone;
			kphone = nullptr;
		}
	}
	//전화받기
	{
		
		//전화기를 든다
		kPhone* kphone = new kPhone();

		//전화 걸기
		kphone->Send();//reversion 2.0

		kphone->Cancel(); //reversion 3.0


		//전화기를 내린다
		if (kphone != nullptr)
		{
			delete kphone;
			kphone = nullptr;
		}
	
	}

	return 1;

}