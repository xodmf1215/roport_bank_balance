#include<stdio.h>

typedef struct { //���¸� ����ü�� �����Ѵ�.
	char name[50];
	int balance;
	int amount;
} Account;

void deposit(Account *); //�������� �Ű�����
void testWithdraw(Account); //����ü �Ű�����
void withdraw(Account *); //�������� �Ű�����
void main()
{
	int switchVal;
	
	Account man; // ����ü ���� ����
	Account *ac=&man; // �������� ����ü ���� �����ϰ� �ּҰ��� �Ȱ��� �����.
	printf("���¸� �����մϴ�\n");
	printf("������ �Է��ϼ���______>");
	while (1) //scanf�� �̸��� �Է¹޴´�.
	{
		static int cnt = 0;
		static char tmp;
		scanf("%c", &tmp);
		if (tmp == '\n' || cnt > 48) //����Ű�Է��̳� �������Ѽ��� ������ �ι��ڸ� �߰��� ��Ʈ������ �����.
		{
			man.name[cnt++] = '\0';
			break;
		}
		man.name[cnt++] = tmp;
	}
	printf("�ʱ� �ܾ��� �Է��ϼ���.______>");
	scanf("%d", &man.balance);

	while (1) // switchVal�� 1,2,3 ���� ���� ������ ������ �ݺ��Ѵ�.
	{
		printf("%s�� ___________________���� �ܾ� : %d\n", man.name, man.balance);
		printf("1. �Ա� �� �ܾ� Ȯ�� / 2. ��ݽ� ���� �ܾ� Ȯ�� / 3. ��� �� �ܾ� Ȯ�� / �� ��. ���� ___>");
		scanf("%d", &switchVal);
		switch (switchVal)
		{
		case 1 ://call by reference
			deposit(ac); // ����ü�� �ּҰ��� �Ѱ��־���.
			break;
		case 2 ://call by value
			testWithdraw(man); // ����ü ���� �Ѱ��־���.
			break;
		case 3 ://call by reference
			withdraw(ac); // ����ü�� �ּҰ��� �Ѱ��־���.
			break;
		default :
			printf("���α׷��� �����մϴ�.\n");
			return;
		}
	}
}

void deposit(Account *ac)
{
	printf("���� �Ա��� �����մϴ�. �ݾ�___>");
	scanf("%d", &(*ac).amount); //�ּҰ��� ����Ű�� ��, �� ���� ������ ������ amount ��ȭ
	ac->balance += ac->amount; //���� ������ ������ balance ��ȭ
	printf("   <<<<   ���� �Աݾ� : %8d | ���� �ܾ� : %8d   >>>>\n\n\n", ac->amount, ac->balance);
}
void testWithdraw(Account manValue)
{
	printf("��ݽ� ���� �ܾ��� Ȯ���մϴ� �ݾ�___>");
	scanf("%d", &manValue.amount); // �������� manValue ����ü�� amount ��ȭ
	manValue.balance -= manValue.amount; // �������� manValue ����ü�� balance ��ȭ
	printf("   <<<<   ���� ��ݾ� : %8d | ���� �ܾ� : %8d   >>>>\n\n\n", manValue.amount, manValue.balance);
}
void withdraw(Account *ac)
{
	printf("���� ����� �����մϴ�. �ݾ�___>");
	scanf("%d", &(*ac).amount); // �ּҰ��� ����Ű�� ��, �� ���� ������ ������ amount ��ȭ
	ac->balance -= ac->amount; // ���� ������ ������ balance ��ȭ
	printf("   <<<<   ���� ��ݾ� : %8d | ���� �ܾ� : %8d   >>>>\n\n\n", ac->amount, ac->balance);
}