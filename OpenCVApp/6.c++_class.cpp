#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>

//class
//...object(객체)...
//소프트웨어 시스템을 나누는 단위
//특성(상태)와 행위를 가지는 어떠한 실체
//상태: 내부변수
//행위: 함수
//ex)자동차
//특성(상태) : 차체, 엔진, 스티어링휠, 변속기, 바퀴..
//행위: 한다{직진, 좌회전, 우회전, 정지, 가속}
//자동차를 운전하기 위해 명령을 보내는 상대 객체가 있어야 함
//운전자(주체)...메세지를 보냄... 자동차(객체) 

//클래스(class)
//유사한 특성(상태)와 행위를 갖는 객체를 표현하는 모형(틀)
//관념을 표현한다...추상화(abstraction)
//객체의 추상화가 class
//모든 객체는 클래스를 기반으로 생성되며 그 객체를 클래스의 인스턴스(instance)라고 한다.
class Car //Class [클래스 이름]
{	//scope시작
public: //접근지정한정자(public, protected, private)
	Car();//생성자(Creator, Ctor)
	~Car();//소멸자(destroy,Dtor)
	void setmoney(int kw) { money = kw; }//메소드 setmoney getmoney
	int getmoney(){ return money; }
protected:


private: 
	int money; //안보이도록 cpp파일로 따로 만듦
};//scope 끝
class BMW :public Car//상속성
{

};
//High-Level Programing
//객체지향언어
//추상화(Abstraction)...일반화
// 휴대폰- 전화 받기/걸기
// 정보은닉의 수단중 하나로 공통의 속성이나 기능을 묵어서 클래스로 정의한 것
//캡슐화(EnCapsulation)
// 실제로 구현 및 동작되는 부분에 대해 데이터를 처리함에 있어서 
// 객체의 데이터를 직접 접근할 수 없고 오로지 메소드를 통해서만 가능
//상속성(Inheritance)
// 기존 클래스를 확장한 파생 클래스를 정의하는 것
// iphone3s...iphone15...기본기능+확장된 개념으로 파생
//다양성(Polymorphism)★★★★★
//"오버라이딩"->재정의 ...다양한 형태로 나타날 수 있는 특징
//음성인식 기능 -> 아이폰 시리 호출... 갤럭시 빅스비 호출
//call()...number...>음성
