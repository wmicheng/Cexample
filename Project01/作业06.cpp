//������?����ѧ������������
#include<iostream>
#include<cstring>
#define N 6
#define M 10
using namespace std;
//˳�����
void Select(char s[N][M])
{
	bool flag = false;
	char name[M];
	cout << "������Ҫ���ҵ�����" << endl;
	cin >> name;
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (strcmp(s[i], name) == 0)
				flag = true;
	if (flag)
		cout << "�ҵ��ˣ�Name=" << name << endl;
	else
		cout << "�Ҳ���" << endl;
}
//ð������
void Sort(char s[N][M])
{
	for (int i = 0; i < N; i++) //��������С��������
		for (int j = i; j < N; j++)
			if (strcmp(s[i], s[j]) > 0) {
				char tmp[M];
				strcpy_s(tmp, s[i]);
				strcpy_s(s[i], s[j]);
				strcpy_s(s[j], tmp);
			}
}
//������
void Sout(char s[N][M]) {
	//��ʼ����ָ��
	char* p[N]{ NULL };
	//����ά����ÿ�����±��ַ��������ָ��
	for (int i = 0; i < N; i++)
		p[i] = s[i];
	cout << "����������ĸ��С��������" << endl;
	//������ά����ÿ���ַ����������������
	for (int i = 0; i < N; i++) {
		cout << " -------- " << endl;
		cout << " \| " << p[i] << " \|" << endl;
		cout << " --------" << endl;
	}
}
int main() {
	char s[N][M] = { "С��","����","��ǿ","����","����","Alice" };
	Sort(s);//��������
	Sout(s);//���������
	Select(s);//���ò���
	return 0;
}