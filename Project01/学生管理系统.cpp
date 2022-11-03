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
    cout << "请输入查找的学号："; cin >> xh;
    student* p2;
    p2 = head;
    while (p2 != NULL) {
        if (p2->xh == xh)
        {
            cout << setw(5) << "学号" << setw(12) << "姓名" << setw(5) << "性别" << setw(5) << "身高" << setw(10) << "入学成绩";
            cout << endl;
            cout << setw(5) << p2->xh << setw(12) << p2->xm << setw(5) << p2->sex << setw(5) << p2->sg << setw(10) << p2->cj;
            cout << endl; break;
        }
        else p2 = p2->next;
    }if (p2 == NULL)cout << "不存在" << endl;
}
student* addlink(student* head, int& wz0)
{
    student* p, * pr, * p0; int i = 1;
    p0 = head;
    p = (struct student*)malloc(sizeof(struct student));

    cout << endl;
    cout << "输入学号："; cin >> p->xh;
    cout << "输入姓名："; cin >> p->xm;
    cout << "输入性别："; cin >> p->sex;
    cout << "输入身高："; cin >> p->sg;
    cout << "输入入校成绩："; cin >> p->cj;
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
    cout << endl << "得到的链表数据为：" << endl;
    cout << setw(5) << "学号" << setw(12) << "姓名" << setw(5) << "性别" << setw(5) << "身高" << setw(10) << "入学成绩";
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
    //输出界面
    student* p0, * p_last, * p;
    p0 = (struct student*)malloc(sizeof(struct student));//表头永远唯一
    p_last = p0;
    while (judge0 == 'y') {
        cout << "数据录入—1" << "      " << "数据查询—2" << endl;
        cout << "数据添加—3" << "      " << "数据删除—4" << endl;
        cout << "退出操作—0" << endl;
        cout << "请选择操作：";

        int  jud, num = 1; char judge = 'y', pjudge = 'n';
        cin >> jud;

        //数据录入
        if (jud == 1) {
            while (judge != 'n')
            {
                p = (struct student*)malloc(sizeof(struct student));
                cout << "输入学号："; cin >> p->xh;
                cout << "输入姓名："; cin >> p->xm;
                cout << "输入性别："; cin >> p->sex;
                cout << "输入身高："; cin >> p->sg;
                cout << "输入入校成绩："; cin >> p->cj;
                cout << endl;
                p_last->next = p;
                p_last = p;
                num = num + 1;//统计人数
                cout << "是否继续（y/n）"; cin >> judge;
            }
            p_last->next = NULL;
            p_last = p0->next;
            cout << endl << "是否输出得到的链表数据(y/n)："; cin >> pjudge;
            if (pjudge == 'y') stuprintf(p_last);
        }
        //数据查找
        p_last = p0->next;
        if (jud == 2)
        {
            searchlink(p_last);
        }
        //数据插入

        if (jud == 3)
        {
            int wz = 0;
            cout << "请输入需要添加的位置："; cin >> wz;
            if (wz<1 || wz>num + 2)
            {
                cout << endl << "您输入的位置过小或溢出，出现错误,请重新输入："; cin >> wz;
            }
            p_last = addlink(p_last, wz);
            cout << endl << "是否输出得到的链表数据(y/n)："; cin >> pjudge;
            if (pjudge == 'y') stuprintf(p_last);
        }
        //数据删除
        if (jud == 4) {
            student* p_delast; p_delast = p_last;
            int xh, xh_ex = 0;
            cout << "请输入要删除学生的学号："; cin >> xh;
            while (p_delast != NULL)
            {
                if (p_delast->xh == xh) {
                    deletelink(p_last, xh);
                    xh_ex = 1;
                }
                p_delast = p_delast->next;
            }if (xh_ex == 0)cout << endl << "学号输入有误！";
            cout << endl << "是否输出得到的链表数据(y/n)："; cin >> pjudge;
            if (pjudge == 'y') stuprintf(p_last);
        }
        //退出
        if (jud == 0) { break; }
        cout << endl << "是否重新操作(y/n)："; cin >> judge0;
    }
}