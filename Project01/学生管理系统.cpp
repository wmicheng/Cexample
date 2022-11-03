#include <iostream> 
#include <iomanip>
using namespace std;

struct student
{
    int xh; char xm[12]; char sex[5]; int sg; int cj; struct student* next;
};
void searchlink(student* head)
{
    int xh = 0;
    cout << "��������ҵ�ѧ�ţ�"; cin >> xh;
    student* p2;
    p2 = head;
    while (p2 != NULL) {
        if (p2->xh == xh)
        {
            cout << setw(5) << "ѧ��" << setw(12) << "����" << setw(5) << "�Ա�" << setw(5) << "���" << setw(10) << "��ѧ�ɼ�";
            cout << endl;
            cout << setw(5) << p2->xh << setw(12) << p2->xm << setw(5) << p2->sex << setw(5) << p2->sg << setw(10) << p2->cj;
            cout << endl; break;
        }
        else p2 = p2->next;
    }if (p2 == NULL)cout << "������" << endl;
}
student* addlink(student* head, int& wz0)
{
    student* p, * pr, * p0; int i = 1;
    p0 = head;
    p = (struct student*)malloc(sizeof(struct student));

    cout << endl;
    cout << "����ѧ�ţ�"; cin >> p->xh;
    cout << "����������"; cin >> p->xm;
    cout << "�����Ա�"; cin >> p->sex;
    cout << "������ߣ�"; cin >> p->sg;
    cout << "������У�ɼ���"; cin >> p->cj;
    cout << endl;
    while (p0 != NULL) {
        if (i == wz0 - 1)
        {
            pr = p0->next;
            p0->next = p;
            p->next = pr; return head;
        }
        else {
            p0 = p0->next;
        }
        i = i + 1;
    }
    if (wz0 == 1)
    {
        head = p;
        return head;
    }
}
student* deletelink(student* head, int& xh0)
{
    student* p, * p0; p0 = head; p = p0;
    while (p0 != NULL)
    {
        if (p0->xh == xh0) {
            p->next = p0->next; return head;
        }
        p = p0;
        p0 = p0->next;
    }
}
void stuprintf(student* head)
{
    student* p; p = head;
    cout << endl << "�õ�����������Ϊ��" << endl;
    cout << setw(5) << "ѧ��" << setw(12) << "����" << setw(5) << "�Ա�" << setw(5) << "���" << setw(10) << "��ѧ�ɼ�";
    cout << endl;
    while (p != NULL)
    {
        cout << setw(5) << p->xh << setw(12) << p->xm << setw(5) << p->sex << setw(5) << p->sg << setw(10) << p->cj;
        cout << endl;
        p = p->next;
    }
}
int main()
{
    srand((unsigned)time(NULL)); char judge0 = 'y';
    //�������
    student* p0, * p_last, * p;
    p0 = (struct student*)malloc(sizeof(struct student));//��ͷ��ԶΨһ
    p_last = p0;
    while (judge0 == 'y') {
        cout << "����¼�롪1" << "      " << "���ݲ�ѯ��2" << endl;
        cout << "������ӡ�3" << "      " << "����ɾ����4" << endl;
        cout << "�˳�������0" << endl;
        cout << "��ѡ�������";

        int  jud, num = 1; char judge = 'y', pjudge = 'n';
        cin >> jud;

        //����¼��
        if (jud == 1) {
            while (judge != 'n')
            {
                p = (struct student*)malloc(sizeof(struct student));
                cout << "����ѧ�ţ�"; cin >> p->xh;
                cout << "����������"; cin >> p->xm;
                cout << "�����Ա�"; cin >> p->sex;
                cout << "������ߣ�"; cin >> p->sg;
                cout << "������У�ɼ���"; cin >> p->cj;
                cout << endl;
                p_last->next = p;
                p_last = p;
                num = num + 1;//ͳ������
                cout << "�Ƿ������y/n��"; cin >> judge;
            }
            p_last->next = NULL;
            p_last = p0->next;
            cout << endl << "�Ƿ�����õ�����������(y/n)��"; cin >> pjudge;
            if (pjudge == 'y') stuprintf(p_last);
        }
        //���ݲ���
        p_last = p0->next;
        if (jud == 2)
        {
            searchlink(p_last);
        }
        //���ݲ���

        if (jud == 3)
        {
            int wz = 0;
            cout << "��������Ҫ��ӵ�λ�ã�"; cin >> wz;
            if (wz<1 || wz>num + 2)
            {
                cout << endl << "�������λ�ù�С����������ִ���,���������룺"; cin >> wz;
            }
            p_last = addlink(p_last, wz);
            cout << endl << "�Ƿ�����õ�����������(y/n)��"; cin >> pjudge;
            if (pjudge == 'y') stuprintf(p_last);
        }
        //����ɾ��
        if (jud == 4) {
            student* p_delast; p_delast = p_last;
            int xh, xh_ex = 0;
            cout << "������Ҫɾ��ѧ����ѧ�ţ�"; cin >> xh;
            while (p_delast != NULL)
            {
                if (p_delast->xh == xh) {
                    deletelink(p_last, xh);
                    xh_ex = 1;
                }
                p_delast = p_delast->next;
            }if (xh_ex == 0)cout << endl << "ѧ����������";
            cout << endl << "�Ƿ�����õ�����������(y/n)��"; cin >> pjudge;
            if (pjudge == 'y') stuprintf(p_last);
        }
        //�˳�
        if (jud == 0) { break; }
        cout << endl << "�Ƿ����²���(y/n)��"; cin >> judge0;
    }
}