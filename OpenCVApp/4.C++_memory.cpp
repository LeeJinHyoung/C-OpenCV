#include <iostream>
#include <memory>
using namespace std;

//1) int sum(int* const pData, int size){}
//2) int sum(const int* pData, int size){}
//3) int sum(const int* const pData, int size){}
//int sum(int* pData, int size){
int sum(const unsigned int* const pData, int length) 
{
	int sum = 0;
	for (size_t i = 0; i < length; i++) { sum += pData[i]; }
	return sum;
}

//partial_sum �Լ� start_index = 5, finish_index = 23
int sum(const unsigned int* const pData, int length, int start_index, int finish_index)
{
	if (finish_index >= length) return -1;
	int sum = 0;
	for (size_t i = start_index; i <= finish_index; i++) { sum += pData[i]; }
	return sum;
}
int sum(const unsigned int* const pData, int width, int height,	int start_row, int start_col, int finish_row, int finish_col) 
{
	int sum = 0;
	//�ڵ� �ۼ�
	for (size_t row = start_row; row <= finish_row; row++)
	{
		for (size_t col = start_col; col <= finish_col; col++)
		{
			size_t index = (row)*width + (col);
			sum += pData[index];
		}
	}
	return sum;
}
int sum(const unsigned int* const pData, int width, int height,
	int start_row, int start_col, int finish_row, int finish_col) {
	int sum = 0;
	//�ڵ� �ۼ�
	for (size_t row = start_row; row <= finish_row; row++)
	{
		for (size_t col = start_col; col <= finish_col; col++)
		{
			size_t index = (row)*width + (col);
			sum += pData[index];
		}
	}
	return sum;
}
//partial_sum �Լ� start_row, start_col (1,1), finish_row, finish_col (3,3)
//int sum(const int* const pData, int width, int height, int start_row, int start_col, int finish_row, int finish_col)
//{
//	int sum = 0;
//	int mask_width = 3; int mask_height = 3;
//	for (int row = 0; row < height; row++)
//	{
//		for (int col = 0; col < width; col++)
//		{
//			int index = 3 * (row * width + col);
//			if (row >= 0 && row < mask_height)
//			{
//				if (col >= 0 && col < mask_width)
//				{
//					pData[index + i] = 0;
//				}
//			}
//
//			return sum;
//		}
//	}
//}
int main()
{
	int width = 5;
	int height = 5;
	unsigned int* pImg = new unsigned int[width * height] {
		//->col[0]...[4]
			3, 4, 5, 6, 2,//row[0]
			6, 5, 8, 3, 4,
			4, 1, 3, 6, 8,
			6, 5, 8, 2, 3,
			2, 4, 8, 3, 4,//row[4]
	};

	//cout << "image data = " << sum(pImg, width * height) << endl;
	//partial data ����

	cout << "image data sum = " << sum(pImg, width * height) << endl;
	//partial data ����
	//partial_sum �Լ� start_index = 5, finish_index = 23
	int start_index = 6, finish_index = 23;
	cout << "image data sum = "
		<< sum(pImg, width * height, start_index, finish_index) << endl;
	//partial_sum �Լ� start_row,start_col (1,1), finish_row, finish_co (3,3)
	cout << "image data sum = "
		<< sum(pImg, width, height, 1, 1, 3, 3) << endl;
	if (pImg != nullptr)delete[] pImg;

		return 0;


			int* pImg = new int[5]{ 1,2,3,4,5 };
			std::cout << "buffer sum result : " << sum(pImg, 5) << std::endl;
			if (pImg != nullptr)
			{
				delete[]pImg; pImg = nullptr;
			}
		
			//memory
			int a; double b; char c;
			int* pA; double pB; char* pC;
			//array
			int arr[100] = { 0, }; //100�� �������� ��.
			//dynamic memory alloc
			int* pData = nullptr;//�޸𸮸� ����Ҳ���
		
			int sz = 100;//�޸�ũ�� ������ //���������� ���� �ٲܼ��ִ� ������ �ʱ�ȭ
			//memory create
			pData = new int[sz] { 0, };//���� �޸� ���� //releas���¿��� ���α׷��� �����ϰ������� ���� �ʿ��Ҷ����� �����Ҹ��Ҽ��ִ� ����
		//	CShape* pShape = new CCircle(); //Ŭ������ �ϳ��� ���������� ��ü�� ���� ���� ��ü�� �����Ҽ� ����
											//CCircle from CShape
		
			//memory delete
			if (pData != nullptr) //�޸𸮴� �� �����Ҹ��ؾ��� 
			{
				delete[] pData; pData = nullptr;
			}
			//RAII (Resource Acquisition Is Initialization) 
			//C++11 ǥ��...smart pointer ����
			//unique_ptr:�ϳ��� ����Ʈ �����͸� Ư�� ��ü�� ����
			//			design pattern ���� ������� ������ ���ϵ�� ���α׷��� �ϴٺ��� �����Ѿ� �Է°���� ��Եż� ������ ������ �����ִ�
			//						  : singletion //�ϳ��� üũ
			//shared_ptr:���� Ƚ���� ���(reference count) int�� new operater������������ �������� int�� ���κ������� +1 �Ǵٽ� int���� new�� �����Ҵ��Ҷ� +2���ö� ���������� �����ϴ� ī��Ʈ������ ����Ƚ��ī��Ʈ������ �������ָ��
			//���� �ڵ�
			//Class int
			//{
			//	unsigned int reference_count = 0;
			//	int();//create
			//	~int()//destroy
			//	{//if(reference_count>0)�� �ʿ����
			//		for (size_t rc = 0; rc < reference_count; rc++)
			//		{
			//			if (this_mem != nullptr)
			//			{
			//				delete[] this_mem; this_mem = nullptr;
			//			}
			//		}
			//	}
			//	//pData = new int[sz] { 0, }; -> reference_count:1
			//	//pData = new int[sz] { 0, }; -> reference_count:2
			//	//pData = new int[sz] { 0, }; -> reference_count:3
			//	int* new()
			//	{ reference_count++; }
			//	
			//}
			//���־�������
			//weak_ptr: �ϳ� �̻��� shared_ptr ������ �ִ� ��ü�� ���� ������ ����,�������� ������ ���Ե��� ����
			//
		
			std::unique_ptr<int> pDatas = std::make_unique<int>(sz);
			std::shared_ptr<int> pTypes = std::make_shared<int>(sz);//delete ���ص� �ڵ����� ������
		
			//memory leak..�Ÿ𸮴���
		/*	if (pData != nullptr)
			{
				delete[] pData; pData = nullptr;
			}
		*/
		
			//pointer and reference
			int dA = 10;
			int* pdA = &dA;
			/*
			int function_name(int a){							////int a = int obj : copy //�Ű������� ���ص����� �ܺε����Ϳ� ���ε����ͷ� �����Ե� 
				���ε����� != �ܺε���Ÿ,����
			}
			
			int function_name(int* pA){							//int* pA = int* obj :pointer �����Ͱ�ü�� �ְų�
				���ε�����(pA �ּ�, porinter) == �ܺε���Ÿ ����
			}
			int function_name(int* pA)//int* pA = int& obj :pointer ���۷�����ü�� �ְų� 
			int function_name(int& A)//int&A = int obj nickname ��ü�� �г����� �ִ°� 
			*/
			void swap_A(int lhs, int rhs)//swap_A(a(10),b(20) -> a:10, b:20
			{
				int tmp; 
				tmp = lhs;//tmp:10
				lhs = rhs;//10->20
				rhs = tmp;//20->10
			}
			void swap_B(int* lhs, int* rhs)//swap_B(&a(10),&b(20) -> a:20, b:10
			{
				int tmp; //tmp:10
				tmp = *lhs;//10->20, �ּҰ��� �ش��ϴ� �ܺε���Ÿ����
				*lhs = *rhs;//20->10, �ּҰ��� �ش��ϴ� �ܺε���Ÿ����
				*rhs = tmp;
			}
			//3���� ��� ������
			int num = 10; int* pnum = &num;
			
			int* const numRef1 = &num;
			//1)intŸ�� �����͸� ����Ű�� const pointer
			//�ʱ�ȭ ���� �ٸ� �ּ� �� ���� �Ұ�
			const int* numRef2 = &num;
			//2)const int Ÿ�� ����Ÿ�� ����Ű�� ������
			//*�����ڷ� ���� �� ���� �Ұ� //�ٸ��ּҰ��� ����ų�� ����Ұ�
			const int* const numRef3 = &num;
			//3)const int Ÿ�� �����͸� ����Ű�� const������ 
			//1),2)�Ӽ��� �� ����.
		
			int num = 10; int* pnum = &num;
			int anotherNum = 20;
			const (int* ptr1) = &num; //���� ����Ű�� �ִ� �����ͺ����� ���ȭ
			*ptr1 = 5;//10->, const int�� ���� �Ұ�, l-valueȭ ��, ���� ���� �����ϴ� ��
			ptr1 = &anotherNum; //���۷����ּҸ� ���� �ٸ��ּҷ� ����Ű�� �� ����
			
			//int* const ptr2;//�ʱ�ȭ���ϸ� ����
			(int*) const ptr2 = nullptr;//�ʱ�ȭ
			int* const ptr3 = &num;//���۷��� �ּҷ� �ʱ�ȭ
			*ptr3 = 6; //�ּҸ� ����ִº����� ���ȭ
			ptr3 = &anotherNum;//const pointer�� ��� �ּҸ� �������� ����
	
}


