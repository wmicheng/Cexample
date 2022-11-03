//按姓名?查找学生姓名并排序？
#include<iostream>
#include<cstring>
#define N 6
#define M 10
using namespace std;
//顺序查找
void Select(char s[N][M])
{
	bool flag = false;
	char name[M];
	cout << "请输入要查找的姓名" << endl;
	cin >> name;
	int count = 0;
	for (int i = 0; i < N; i++)
		for (int j = i; j < N; j++)
			if (strcmp(s[i], name) == 0)
				flag = true;
	if (flag)
		cout << "找到了，Name=" << name << endl;
	else
		cout << "找不到" << endl;
}
//冒泡排序
void Sort(char s[N][M])
{
	for (int i = 0; i < N; i++) //按姓名由小到大排序
		for (int j = i; j < N; j++)
			if (strcmp(s[i], s[j]) > 0) {
				char tmp[M];
				strcpy_s(tmp, s[i]);
				strcpy_s(s[i], s[j]);
				strcpy_s(s[j], tmp);
			}
}
//输出结果
void Sout(char s[N][M]) {
	//初始化行指针
	char* p[N]{ NULL };
	//将二维数组每个行下标地址赋给数组指针
	for (int i = 0; i < N; i++)
		p[i] = s[i];
	cout << "姓名按首字母由小到大排序" << endl;
	//遍历二维数组每个字符串（姓名）并输出
	for (int i = 0; i < N; i++) {
		cout << " -------- " << endl;
		cout << " \| " << p[i] << " \|" << endl;
		cout << " --------" << endl;
	}
}
int main() {
	char s[N][M] = { "小明","阿文","王强","张三","李四","Alice" };
	Sort(s);//调用排序
	Sout(s);//输出排序结果
	Select(s);//调用查找
	return 0;
}