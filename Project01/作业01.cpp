//题目1：多分支输出成绩的等级
#include<iostream>
using namespace std;
int main() {
	int score;
	cin >> score;
	if (score >= 90)
	{
		cout << "成绩优秀！";
	}
	else if (score >= 70)
	{
		cout << "成绩良好！";
	}
	else if (score >= 60)
	{
		cout << "成绩及格！";
	}
	else if (score < 60)
	{
		cout << "不及格！";
	}
}