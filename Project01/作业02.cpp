//作业2:输入三角形三条边, 
//判断三角形的类型(等边、普通等腰, 等腰直角, 普通直角, 普通, 不是
//float(double) a, b, c: == b & 是b = C && a = C, 实数数据相等判断, 


//首先判断其两边之和是否大于第三边，若大于则判断可以构成三角形，
// 再进一步判断该三角形是什么三角形，并计算这个三角形的面积；否则不能构成三角形。

//① 从键盘输入三角形的三条边。

//② 判断两边之和是否大于第三边。

//③ 若条件成立则判断可构成三角形，判断其类型；否则判断其不能构成三角形。

//④ 在类型判断中首先判断其是否三边相等，条件成立则判断其为等边三角形；
//否则判断其是否有两边相等，条件成立则判断其为等腰三角形；
//否则判断其是否有两边的平方和等于第三边的平方，条件成立则判断其为直角三角形；
//否则判断其为普通三角形。
//注意！！不能直接用 == 进行判断   要用fabs(XXX) < 1E-6

#include<iostream>
#include <cmath>
using namespace std;
int main() {
	float a, b, c;
	cout << "输入a、b、c三条边\n";
	cin >> a >> b >> c;
	if (a > (c + b) && (a - c) && c > (a + b))
		cout << "这不是三角形";
	else if (fabs(a - b) < 1e-6 && fabs(a - c) < 1e-6)
		cout << "其为等边三角形";
	else if (fabs(a - b) < 1e-6 || fabs(a - c) < 1e-6 || fabs(b - c) < 1e-6)
	{
		if (fabs(a * a + b * b - c * c) < 1e-6 || fabs(a * a + c * c - b * b) < 1e-6 || fabs(b * b + c * c - a * a) < 1e-6)
			cout << "其为等腰直角三角形";
		else
			cout << "其为等腰三角形";
	}
	else if (fabs(a * a + b * b - c * c) < 1e-6 || fabs(a * a + c * c - b * b) < 1e-6 || fabs(b * b + c * c - a * a) < 1e-6)
		cout << "其为直角三角形";
	else
		cout << "其为普通三角形";
}
