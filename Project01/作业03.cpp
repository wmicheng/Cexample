//汉诺塔
#include <iostream>
using namespace std;
void move(char x, char y);
void hanoi(int n, char one, char two, char three);
int main()
{
	int n;
	cout << "输入盘的个数" << endl;
	cin >> n;
	cout << "移盘的步骤：" << endl;
	hanoi(n, 'A', 'B', 'C');
}
void move(char x, char y)	//输出移盘方案
{
	cout << x << "->" << y << endl;
}
void hanoi(int n, char one, char two, char three)		//移盘
{
	if (n == 1)
		move(one, three);		//如果是1个盘，直接从第一个座移到第3个座上
	else
	{
		hanoi(n - 1, one, three, two);
		move(one, three);
		hanoi(n - 1, two, one, three);
	}
}