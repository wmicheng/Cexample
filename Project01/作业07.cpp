//��new������̬����, ������ݲ��롢��Ӻ�ɾ���Ĳ���
#include<iostream>
using namespace std;
//ʹ��typedefΪstruct node ����������student
typedef struct node {//��ʼ���ṹ��
	int id = 0;
	string name = "";
	int age = 0;
	string sex = "";
	struct node* next = NULL;
}student;
//��������Ϊn����
student* Create()
{
	int n;
	cout << "�������ʼ�ڵ�����" << endl;
	cin >> n;
	student* head = new student;
	student* pre = head;
	cout << "ѧ����Ϣ��ʽ��|  ѧ��  |  ����  |  ����  |  �Ա�  |" << endl;
	for (int i = 0; i < n; i++)
	{
		student* p = new student;
		cout << "�������" << i + 1 << "��ͬѧ��Ϣ" << endl;//i��0�±꣬��i+1��
		p->next = NULL;//�����β��nextָ���
		cin >> p->id >> p->name >> p->age >> p->sex;//data
		pre->next = p;
		pre = p;
	}
	return head;
}
//���ҽڵ�
student* SelectNode(student* head, int n)
{
	student* p = head;
	for (int j = 1; j < n && p != NULL; j++)//�����������ҵ���i���ڵ�
		p = p->next;
	if (p == NULL)
		cout << "�Ҳ���/(��o��)/~~" << endl;
	else
		cout << "---�鵽�ˣ�" << endl;
	return p;
}
//��ӡ�ڵ�
void PrintNode(student* head) {
	student* p = head->next;
	while (p != NULL)
	{
		cout << "|   " << p->id << "   |   " << p->name << "   |   " << p->age << "   |   " << p->sex << "   |   " << endl;
		p = p->next;
	}
}
//��ӽڵ�
void AddNode(student* head) {// ����β������Ԫ��
	{
		student* newNode = new student();
		newNode->next = NULL;
		cout << "������Ҫ��ӵĽڵ�����:|  ѧ��  |  ����  |  ����  |  �Ա�  |" << endl;
		cin >> newNode->id >> newNode->name >> newNode->age >> newNode->sex;
		student* p = new student();
		p = head; //ͷ���
		if (head == NULL)
			head = newNode; //�½ڵ�Ϊ����ͷ�ڵ�
		else {
			while (p->next != NULL)//�ҵ�β�ڵ�
				p = p->next;
			p->next = newNode; //��β�ڵ��������½ڵ�
		}
	}
}
//����ڵ�
void InsertNode(student* head, int n)
{
	student* p = head;
	student* in = new student;
	for (int i = 1; i < n && p != NULL; i++) {
		p = p->next;
	}
	if (p != NULL) {
		cout << "������Ҫ����Ľڵ�����:|  ѧ��  |  ����  |  ����  |  �Ա�  |" << endl;
		cin >> in->id >> in->name >> in->age >> in->sex;
		in->next = p->next;
		p->next = in;
	}
	else cout << "�Ҳ���/(��o��)/~~" << endl;
}
//ɾ���ڵ�
void DeleteNode(student* head, int i)
{
	//���ҵ���i���ڵ���ɾ��
	student* p1 = SelectNode(head, i);
	student* p2 = p1->next;
	student* p3 = p2->next;
	//������ɾ��p2
	p1->next = p3;
	delete p2;
	cout << "ɾ���ɹ�!" << endl;
}
//�������
void Panel(student* head) {
	int i = 0, j = 0, k = 0;
	PrintNode(head);//��������
	while (true)//����ѭ�����ж�����
	{
		int f;
		cout << "��������ƹ���|  1�����  |  2������  |  3��ɾ��  |  4���˳�ϵͳ  |" << endl;
		cin >> f;
		switch (f) {
		case 1:	cout << "��������Ҫ���Ԫ��" << endl;
			AddNode(head);//��ӽڵ�
			PrintNode(head);//��������
			break;
		case 2:
			cout << "��������Ҫ����λ��" << endl;
			cin >> i;
			InsertNode(head, i);//����ڵ�
			PrintNode(head); //��������
			break;
		case 3:
			cout << "��������Ҫɾ��λ��" << endl;
			cin >> j;
			DeleteNode(head, j);//ɾ���ڵ�
			PrintNode(head); //��������
			break;
		case 4:
			if (f == 4) {//�ж�����
				cout << "�ɹ��˳���" << endl;
				exit(0);
			}
		default: break;
		}
	}
}
int main() {
	student* head = Create();//���ɽڵ�
	Panel(head);//�������
	return 0;
}
