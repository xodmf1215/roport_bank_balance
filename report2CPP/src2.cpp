#include <iostream>
#include <stdlib.h>

using namespace std;

class Account //���� ������ ����ִ� Ŭ����
{
public: //private�� �ڷḦ �а� ���� ���� �Լ���
	void setName(char *na) {name=na;} // ���� ���� �Լ���
	void setBalance(int bal) { balance=bal; }
	void setAmount(int amo) { amount=amo; }

	char* getName() {return name;} // �б� ���� �Լ���
	int getBalance() { return balance; }
	int getAmount() { return amount; }
	~Account() {
		//free(name);
	}
private:
	char *name=(char *)malloc(sizeof(char)*50); // �Ա�,��ݾ�, �ܾ�, �׸��� �̸� ����
	//char *name;
	//name = new char[50];
	int balance;
	int amount;
};

void deposit(Account &); //�Ա�, �Ű������� ������ Ŭ���� ������
void testWithdraw(Account); //��� �׽�Ʈ, Ŭ���� ��ü�� �Ű�����
void withdraw(Account &); //���, �Ű������� ������ Ŭ���� ������

void main()
{
	int switchVal; //�ݺ������� ���Ǵ� ������
	bool repeat = true;

	Account man; //���� Ŭ���� ����

	char tmpName[50]; //�Է��� ���� �ӽ÷� �̸��� �ܾ��� �����ϴ� ����
	int tmpBal;
	cout << "���¸� �����մϴ�\n"; // ���� �����ϴ� �ʱ�ȭ �κ�
	cout << "������ �Է��ϼ���______>";
	cin >> tmpName;
	man.setName(tmpName);
	cout << "�ʱ� �ܾ��� �Է��ϼ���.______>";
	cin >> tmpBal;
	man.setBalance(tmpBal);

	while (repeat) // repeat�� false�� �ɶ����� �ݺ��Ѵ�.
	{
		cout << man.getName() << "�� ___________________���� �ܾ� : " << man.getBalance() << "\n";
		cout << "1. �Ա� �� �ܾ� Ȯ�� / 2. ��ݽ� ���� �ܾ� Ȯ�� / 3. ��� �� �ܾ� Ȯ�� / �� ��. ���� ___>";
		cin >> switchVal;

		switch (switchVal) //switchVal�� ���� ����ġ �������� �˸��� �Լ��� ã�ư���.
		{
		case 1://call by reference
			deposit(man); //������ �������� Ŭ������ �Ű������� �Ѵ�
			break;
		case 2://call by value
			testWithdraw(man); //Ŭ���� ��ü�� �Ű������� �Ѱ��ش�.
			break;
		case 3://call by reference
			withdraw(man); //������ �������� Ŭ������ �Ű������� �Ѵ�.
			break;
		default:
			printf("���α׷��� �����մϴ�.\n");
			repeat = false;
			break;
		}
	}
}
void deposit(Account &ac)
{
	int tmpAmo;
	cout << "���� �Ա��� �����մϴ�. �ݾ�___>";
	cin >> tmpAmo;
	ac.setAmount(tmpAmo); //������ �����ͱ� ������ �Ѱ���� �ڷᰪ�� ���� ���Ѵ�.
	ac.setBalance(ac.getAmount() + ac.getBalance());
	cout << "   <<<<   ���� �Աݾ� : " << ac.getAmount() << " | ���� �ܾ� : " << ac.getBalance() << "   >>>>\n\n\n";
}
void testWithdraw(Account manValue)
{
	int tmpAmo;
	cout << "��ݽ� ���� �ܾ��� Ȯ���մϴ� �ݾ�___>";
	cin >> tmpAmo;
	manValue.setAmount(tmpAmo); //���� �Ű������� �Ѱ���� ������ ���� �ڷῡ�� ��ȭ�� ����.
	manValue.setBalance(manValue.getBalance() - manValue.getAmount());
	cout << "   <<<<   ���� ��ݾ� : " << manValue.getAmount() << " | ���� �ܾ� : " << manValue.getBalance() << "   >>>>\n\n\n";
}
void withdraw(Account &ac)
{
	int tmpAmo;
	cout << "���� ����� �����մϴ�. �ݾ�___>";
	cin >> tmpAmo;
	ac.setAmount(tmpAmo); // ������ �����ͱ� ������ �Ѱ���� �ڷᰪ�� ���� ���Ѵ�.
	ac.setBalance(ac.getBalance() - ac.getAmount());
	cout << "   <<<<   ���� ��ݾ� : " << ac.getAmount() << " | ���� �ܾ� : " << ac.getBalance() << "   >>>>\n\n\n";
}