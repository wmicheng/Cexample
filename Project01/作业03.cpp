//��ŵ��
//��������n�����Ӵ�A�����Ƶ�C������Ҫ������
//
//��1����A�ϵ�n - 1�����ӽ���C�����Ƶ�B���ϣ�
//
//��2����A����ʣ�µ�һ�������Ƶ�C���ϣ�
//
//��3����n - 1���̴�B���Ͻ�����A�Ƶ�C���ϡ�
#include <iostream>
using namespace std;
void move(char x, char y);
void hanoi(int n, char one, char two, char three);
int main()
{
	int n;
	cout << "�����̵ĸ���" << endl;
	cin >> n;
	cout << "���̵Ĳ��裺" << endl;
	hanoi(n, 'A', 'B', 'C');
}
void move(char    x, char y)	//������̷���

{
	cout << x << "->" << y << endl;
}
void hanoi(int n, char one, char two, char three)		//����
{
	if (n == 1)
		move(one, three);		//�����1���̣�ֱ�Ӵӵ�һ�����Ƶ���3������
	else
	{
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}