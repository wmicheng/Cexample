//判断三角形的类型函数完成

#include<iostream>
#include <cmath>
using namespace std;
void Triangle(float a, float b, float c);
int main() {
	float a, b, c;
	cout << "输入a、b、c三条边\n";
	cin >> a >> b >> c;
	Triangle(a, b, c);
}
void Triangle(float a, float b, float c) {
	if (a > (c + b) && (a - c) && c > (a + b))
		cout << "这不是三角形";
	else if (fabs(a - b) < 1e-6 && fabs(a - c) < 1e-6)
		cout << "其为等边三角形";
	else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)
	{
		if (fabs(pow(a, 2) + pow(b, 2) - pow(c, 2)) < 1e-6 || fabs(pow(a, 2) + pow(c, 2) - pow(b, 2)) < 1e-6 || fabs(pow(b, 2) + pow(c, 2) - pow(a, 2)) < 1e-6)
			cout << "其为等腰直角三角形";
		else
			cout << "其为等腰三角形";
	}
	else if (fabs(pow(a, 2) + pow(b, 2) - pow(c, 2)) < 1e-6 || fabs(pow(a, 2) + pow(c, 2) - pow(b, 2)) < 1e-6 || fabs(pow(b, 2) + pow(c, 2) - pow(a, 2)) < 1e-6)
		cout << "其为直角三角形";
	else
		cout << "其为普通三角形";
}