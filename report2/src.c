#include<stdio.h>

typedef struct { //계좌를 구조체로 생성한다.
	char name[50];
	int balance;
	int amount;
} Account;

void deposit(Account *); //포인터형 매개변수
void testWithdraw(Account); //구조체 매개변수
void withdraw(Account *); //포인터형 매개변수
void main()
{
	int switchVal;
	
	Account man; // 구조체 변수 생성
	Account *ac=&man; // 포인터형 구조체 변수 생성하고 주소값을 똑같이 맞춘다.
	printf("계좌를 개설합니다\n");
	printf("성함을 입력하세요______>");
	while (1) //scanf로 이름을 입력받는다.
	{
		static int cnt = 0;
		static char tmp;
		scanf("%c", &tmp);
		if (tmp == '\n' || cnt > 48) //엔터키입력이나 글자제한수가 넘으면 널문자를 추가해 스트링으로 만든다.
		{
			man.name[cnt++] = '\0';
			break;
		}
		man.name[cnt++] = tmp;
	}
	printf("초기 잔액을 입력하세요.______>");
	scanf("%d", &man.balance);

	while (1) // switchVal이 1,2,3 외의 값이 나오기 전까지 반복한다.
	{
		printf("%s님 ___________________현재 잔액 : %d\n", man.name, man.balance);
		printf("1. 입금 후 잔액 확인 / 2. 출금시 예상 잔액 확인 / 3. 출금 후 잔액 확인 / 그 외. 종료 ___>");
		scanf("%d", &switchVal);
		switch (switchVal)
		{
		case 1 ://call by reference
			deposit(ac); // 구조체의 주소값을 넘겨주었다.
			break;
		case 2 ://call by value
			testWithdraw(man); // 구조체 값을 넘겨주었다.
			break;
		case 3 ://call by reference
			withdraw(ac); // 구조체의 주소값을 넘겨주었다.
			break;
		default :
			printf("프로그램을 종료합니다.\n");
			return;
		}
	}
}

void deposit(Account *ac)
{
	printf("실제 입금을 진행합니다. 금액___>");
	scanf("%d", &(*ac).amount); //주소값이 가르키는 곳, 즉 원래 생성한 계좌의 amount 변화
	ac->balance += ac->amount; //원래 생성한 계좌의 balance 변화
	printf("   <<<<   실제 입금액 : %8d | 실제 잔액 : %8d   >>>>\n\n\n", ac->amount, ac->balance);
}
void testWithdraw(Account manValue)
{
	printf("출금시 예상 잔액을 확인합니다 금액___>");
	scanf("%d", &manValue.amount); // 지역변수 manValue 구조체의 amount 변화
	manValue.balance -= manValue.amount; // 지역변수 manValue 구조체의 balance 변화
	printf("   <<<<   예상 출금액 : %8d | 예상 잔액 : %8d   >>>>\n\n\n", manValue.amount, manValue.balance);
}
void withdraw(Account *ac)
{
	printf("실제 출금을 진행합니다. 금액___>");
	scanf("%d", &(*ac).amount); // 주소값이 가르키는 곳, 즉 원래 생성한 계좌의 amount 변화
	ac->balance -= ac->amount; // 원래 생성한 계좌의 balance 변화
	printf("   <<<<   실제 출금액 : %8d | 실제 잔액 : %8d   >>>>\n\n\n", ac->amount, ac->balance);
}