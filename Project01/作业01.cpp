//��Ŀ1�����֧����ɼ��ĵȼ�
#include<iostream>
using namespace std;
int main() {
	int score;
	cin >> score;
	if (score >= 90)
	{
		cout << "�ɼ����㣡";
	}
	else if (score >= 70)
	{
		cout << "�ɼ����ã�";
	}
	else if (score >= 60)
	{
		cout << "�ɼ�����";
	}
	else if (score < 60)
	{
		cout << "������";
	}
}