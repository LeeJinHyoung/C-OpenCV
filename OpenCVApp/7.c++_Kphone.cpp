#include "kphone.h"
int main()
{
	//��ȭ �ɱ�
	{
		//��ȭ�⸦ ���
		kPhone* kphone = new kPhone();

		//��ȭ ��ȣ �Է�
		//kphone->Numbers("010-1234-5678");
		int* pAudio = new int[11] {
			0, 1, 0, 1, 2, 3, 4, 5, 6, 7, 8
		};
		int length = 11;
		kphone->Numbers(pAudio,length);
		//��ȭ �ɱ�
		kphone->Send();

		//��ȭ�⸦ ������
		if (kphone != nullptr)
		{
			delete kphone;
			kphone = nullptr;
		}
	}
	//��ȭ�ޱ�
	{
		
		//��ȭ�⸦ ���
		kPhone* kphone = new kPhone();

		//��ȭ �ɱ�
		kphone->Send();//reversion 2.0

		kphone->Cancel(); //reversion 3.0


		//��ȭ�⸦ ������
		if (kphone != nullptr)
		{
			delete kphone;
			kphone = nullptr;
		}
	
	}

	return 1;

}