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

//partial_sum 함수 start_index = 5, finish_index = 23
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
	//코드 작성
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
	//코드 작성
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
//partial_sum 함수 start_row, start_col (1,1), finish_row, finish_col (3,3)
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
	//partial data 추출

	cout << "image data sum = " << sum(pImg, width * height) << endl;
	//partial data 추출
	//partial_sum 함수 start_index = 5, finish_index = 23
	int start_index = 6, finish_index = 23;
	cout << "image data sum = "
		<< sum(pImg, width * height, start_index, finish_index) << endl;
	//partial_sum 함수 start_row,start_col (1,1), finish_row, finish_co (3,3)
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
			int arr[100] = { 0, }; //100이 정해졌을 때.
			//dynamic memory alloc
			int* pData = nullptr;//메모리를 사용할꺼야
		
			int sz = 100;//메모리크기 정해짐 //임의적으로 값을 바꿀수있는 변수로 초기화
			//memory create
			pData = new int[sz] { 0, };//동적 메모리 생성 //releas상태에서 프로그램이 동작하고있을때 내가 필요할때마다 생성소멸할수있는 장점
		//	CShape* pShape = new CCircle(); //클래스를 하나의 상위개념의 객체를 하위 개념 객체로 생성할수 있음
											//CCircle from CShape
		
			//memory delete
			if (pData != nullptr) //메모리는 꼭 생성소멸해야함 
			{
				delete[] pData; pData = nullptr;
			}
			//RAII (Resource Acquisition Is Initialization) 
			//C++11 표준...smart pointer 도입
			//unique_ptr:하나의 스마트 포인터만 특정 객체를 소유
			//			design pattern 많은 사람들이 유사한 패턴들로 프로그램을 하다보면 유사한안 입력결과를 얻게돼서 유사한 구조를 쓸수있다
			//						  : singletion //하나만 체크
			//shared_ptr:참조 횟수가 계산(reference count) int가 new operater을내부적으로 만났을때 int가 내부변수에서 +1 또다시 int에서 new로 동적할당할때 +2가올라감 내부적으로 관리하는 카운트가있음 참조횟수카운트를보고 해제해주면됨
			//슈도 코드
			//Class int
			//{
			//	unsigned int reference_count = 0;
			//	int();//create
			//	~int()//destroy
			//	{//if(reference_count>0)할 필요없음
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
			//자주쓰진않음
			//weak_ptr: 하나 이상의 shared_ptr 참조가 있는 객체에 대한 접근을 제공,소유자의 수에는 포함되지 않음
			//
		
			std::unique_ptr<int> pDatas = std::make_unique<int>(sz);
			std::shared_ptr<int> pTypes = std::make_shared<int>(sz);//delete 안해도 자동으로 해제됨
		
			//memory leak..매모리누수
		/*	if (pData != nullptr)
			{
				delete[] pData; pData = nullptr;
			}
		*/
		
			//pointer and reference
			int dA = 10;
			int* pdA = &dA;
			/*
			int function_name(int a){							////int a = int obj : copy //매개변수를 통해들어오면 외부데이터와 내부데이터로 나뉘게됨 
				내부데이터 != 외부데이타,단절
			}
			
			int function_name(int* pA){							//int* pA = int* obj :pointer 포인터객체를 주거나
				내부데이터(pA 주소, porinter) == 외부데이타 변경
			}
			int function_name(int* pA)//int* pA = int& obj :pointer 레퍼런스객체를 주거나 
			int function_name(int& A)//int&A = int obj nickname 객체의 닉네임을 주는것 
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
				tmp = *lhs;//10->20, 주소값에 해당하는 외부데이타변경
				*lhs = *rhs;//20->10, 주소값에 해당하는 외부데이타변경
				*rhs = tmp;
			}
			//3가지 상수 포인터
			int num = 10; int* pnum = &num;
			
			int* const numRef1 = &num;
			//1)int타입 데이터를 가리키는 const pointer
			//초기화 이후 다른 주소 값 대입 불가
			const int* numRef2 = &num;
			//2)const int 타입 데이타를 가리키는 포인터
			//*연산자로 참조 값 변경 불가 //다른주소값을 가르킬때 변경불가
			const int* const numRef3 = &num;
			//3)const int 타입 데이터를 가리키는 const포인터 
			//1),2)속성을 다 가짐.
		
			int num = 10; int* pnum = &num;
			int anotherNum = 20;
			const (int* ptr1) = &num; //값을 가르키고 있는 포인터변수를 상수화
			*ptr1 = 5;//10->, const int로 변경 불가, l-value화 됨, 값에 값을 변경하는 꼴
			ptr1 = &anotherNum; //레퍼런스주소를 통해 다른주소로 가르키는 건 가능
			
			//int* const ptr2;//초기화안하면 에러
			(int*) const ptr2 = nullptr;//초기화
			int* const ptr3 = &num;//레퍼런스 주소로 초기화
			*ptr3 = 6; //주소를 담고있는변수를 상수화
			ptr3 = &anotherNum;//const pointer로 대상 주소를 변경하지 못함
	
}


