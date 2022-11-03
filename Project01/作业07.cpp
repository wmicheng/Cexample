//用new创建动态数组, 完成数据插入、添加和删除的操作
#include<iostream>
using namespace std;
//使用typedef为struct node 定义新类型student
typedef struct node {//初始化结构体
	int id = 0;
	string name = "";
	int age = 0;
	string sex = "";
	struct node* next = NULL;
}student;
//创建长度为n链表
student* Create()
{
	int n;
	cout << "请输入初始节点数量" << endl;
	cin >> n;
	student* head = new student;
	student* pre = head;
	cout << "学生信息格式：|  学号  |  姓名  |  年龄  |  性别  |" << endl;
	for (int i = 0; i < n; i++)
	{
		student* p = new student;
		cout << "请输入第" << i + 1 << "名同学信息" << endl;//i从0下标，第i+1名
		p->next = NULL;//链表的尾部next指向空
		cin >> p->id >> p->name >> p->age >> p->sex;//data
		pre->next = p;
		pre = p;
	}
	return head;
}
//查找节点
student* SelectNode(student* head, int n)
{
	student* p = head;
	for (int j = 1; j < n && p != NULL; j++)//根据输入结果找到第i个节点
		p = p->next;
	if (p == NULL)
		cout << "找不到/(ㄒoㄒ)/~~" << endl;
	else
		cout << "---查到了！" << endl;
	return p;
}
//打印节点
void PrintNode(student* head) {
	student* p = head->next;
	while (p != NULL)
	{
		cout << "|   " << p->id << "   |   " << p->name << "   |   " << p->age << "   |   " << p->sex << "   |   " << endl;
		p = p->next;
	}
}
//添加节点
void AddNode(student* head) {// 链表尾加入新元素
	{
		student* newNode = new student();
		newNode->next = NULL;
		cout << "请输入要添加的节点数据:|  学号  |  姓名  |  年龄  |  性别  |" << endl;
		cin >> newNode->id >> newNode->name >> newNode->age >> newNode->sex;
		student* p = new student();
		p = head; //头结点
		if (head == NULL)
			head = newNode; //新节点为链表头节点
		else {
			while (p->next != NULL)//找到尾节点
				p = p->next;
			p->next = newNode; //在尾节点后面加入新节点
		}
	}
}
//插入节点
void InsertNode(student* head, int n)
{
	student* p = head;
	student* in = new student;
	for (int i = 1; i < n && p != NULL; i++) {
		p = p->next;
	}
	if (p != NULL) {
		cout << "请输入要插入的节点数据:|  学号  |  姓名  |  年龄  |  性别  |" << endl;
		cin >> in->id >> in->name >> in->age >> in->sex;
		in->next = p->next;
		p->next = in;
	}
	else cout << "找不到/(ㄒoㄒ)/~~" << endl;
}
//删除节点
void DeleteNode(student* head, int i)
{
	//先找到第i个节点再删除
	student* p1 = SelectNode(head, i);
	student* p2 = p1->next;
	student* p3 = p2->next;
	//链表中删除p2
	p1->next = p3;
	delete p2;
	cout << "删除成功!" << endl;
}
//控制面板
void Panel(student* head) {
	int i = 0, j = 0, k = 0;
	PrintNode(head);//遍历链表
	while (true)//无限循环＋中断条件
	{
		int f;
		cout << "请输入控制功能|  1、添加  |  2、插入  |  3、删除  |  4、退出系统  |" << endl;
		cin >> f;
		switch (f) {
		case 1:	cout << "请输入需要添加元素" << endl;
			AddNode(head);//添加节点
			PrintNode(head);//遍历链表
			break;
		case 2:
			cout << "请输入需要插入位置" << endl;
			cin >> i;
			InsertNode(head, i);//插入节点
			PrintNode(head); //遍历链表
			break;
		case 3:
			cout << "请输入需要删除位置" << endl;
			cin >> j;
			DeleteNode(head, j);//删除节点
			PrintNode(head); //遍历链表
			break;
		case 4:
			if (f == 4) {//中断条件
				cout << "成功退出！" << endl;
				exit(0);
			}
		default: break;
		}
	}
}
int main() {
	student* head = Create();//生成节点
	Panel(head);//控制面板
	return 0;
}
