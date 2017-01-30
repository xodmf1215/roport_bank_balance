#include <iostream>
#include <stdlib.h>

using namespace std;

class Account //계좌 정보가 담겨있는 클래스
{
public: //private한 자료를 읽고 쓰기 위한 함수들
	void setName(char *na) {name=na;} // 쓰기 전용 함수들
	void setBalance(int bal) { balance=bal; }
	void setAmount(int amo) { amount=amo; }

	char* getName() {return name;} // 읽기 전용 함수들
	int getBalance() { return balance; }
	int getAmount() { return amount; }
	~Account() {
		//free(name);
	}
private:
	char *name=(char *)malloc(sizeof(char)*50); // 입금,출금액, 잔액, 그리고 이름 선언
	//char *name;
	//name = new char[50];
	int balance;
	int amount;
};

void deposit(Account &); //입금, 매개변수는 참조형 클래스 포인터
void testWithdraw(Account); //출금 테스트, 클래스 자체가 매개변수
void withdraw(Account &); //출금, 매개변수는 참조형 클래스 포인터

void main()
{
	int switchVal; //반복문에서 사용되는 변수들
	bool repeat = true;

	Account man; //계좌 클래스 생성

	char tmpName[50]; //입력을 위해 임시로 이름과 잔액을 저장하는 변수
	int tmpBal;
	cout << "계좌를 개설합니다\n"; // 계좌 개설하는 초기화 부분
	cout << "성함을 입력하세요______>";
	cin >> tmpName;
	man.setName(tmpName);
	cout << "초기 잔액을 입력하세요.______>";
	cin >> tmpBal;
	man.setBalance(tmpBal);

	while (repeat) // repeat이 false가 될때까지 반복한다.
	{
		cout << man.getName() << "님 ___________________현재 잔액 : " << man.getBalance() << "\n";
		cout << "1. 입금 후 잔액 확인 / 2. 출금시 예상 잔액 확인 / 3. 출금 후 잔액 확인 / 그 외. 종료 ___>";
		cin >> switchVal;

		switch (switchVal) //switchVal에 따라 스위치 구문으로 알맞은 함수를 찾아간다.
		{
		case 1://call by reference
			deposit(man); //참조형 포인터인 클래스를 매개변수로 한다
			break;
		case 2://call by value
			testWithdraw(man); //클래스 자체를 매개변수로 넘겨준다.
			break;
		case 3://call by reference
			withdraw(man); //참조형 포인터인 클래스를 매개변수로 한다.
			break;
		default:
			printf("프로그램을 종료합니다.\n");
			repeat = false;
			break;
		}
	}
}
void deposit(Account &ac)
{
	int tmpAmo;
	cout << "실제 입금을 진행합니다. 금액___>";
	cin >> tmpAmo;
	ac.setAmount(tmpAmo); //참조형 포인터기 때문에 넘겨줬던 자료값도 같이 변한다.
	ac.setBalance(ac.getAmount() + ac.getBalance());
	cout << "   <<<<   실제 입금액 : " << ac.getAmount() << " | 실제 잔액 : " << ac.getBalance() << "   >>>>\n\n\n";
}
void testWithdraw(Account manValue)
{
	int tmpAmo;
	cout << "출금시 예상 잔액을 확인합니다 금액___>";
	cin >> tmpAmo;
	manValue.setAmount(tmpAmo); //값만 매개변수로 넘겨줬기 때문에 원래 자료에는 변화가 없다.
	manValue.setBalance(manValue.getBalance() - manValue.getAmount());
	cout << "   <<<<   예상 출금액 : " << manValue.getAmount() << " | 예상 잔액 : " << manValue.getBalance() << "   >>>>\n\n\n";
}
void withdraw(Account &ac)
{
	int tmpAmo;
	cout << "실제 출금을 진행합니다. 금액___>";
	cin >> tmpAmo;
	ac.setAmount(tmpAmo); // 참조형 포인터기 때문에 넘겨줬던 자료값도 같이 변한다.
	ac.setBalance(ac.getBalance() - ac.getAmount());
	cout << "   <<<<   실제 출금액 : " << ac.getAmount() << " | 실제 잔액 : " << ac.getBalance() << "   >>>>\n\n\n";
}