//�ж������ε����ͺ������

#include<iostream>
#include <cmath>
using namespace std;
void Triangle(float a, float b, float c);
int main() {
	float a, b, c;
	cout << "����a��b��c������\n";
	cin >> a >> b >> c;
	Triangle(a, b, c);
}
void Triangle(float a, float b, float c) {

	if (a > (c + b) && (a - c) && c > (a + b))
		cout << "�ⲻ��������";
	else if (fabs(a - b) < 1e-6 && fabs(a - c) < 1e-6)
		cout << "��Ϊ�ȱ�������";
	else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)
	{
		if (fabs(a * a + b * b - c * c) < 1e-6 || fabs(a * a + c * c - b * b) < 1e-6 || fabs(b * b + c * c - a * a) < 1e-6)
			cout << "��Ϊ����ֱ��������";
		else
			cout << "��Ϊ����������";
	}
	else if (fabs(a * a + b * b - c * c) < 1e-6 || fabs(a * a + c * c - b * b) < 1e-6 || fabs(b * b + c * c - a * a) < 1e-6)
		cout << "��Ϊֱ��������";
	else
		cout << "��Ϊ��ͨ������";
}