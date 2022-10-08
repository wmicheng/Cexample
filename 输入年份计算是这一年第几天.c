// 输入年份计算是这一年第几天
#include <stdio.h>
main()
{
    struct date
    {
        int y;
        int m;
        int d;
    };
    struct date dt;
    int i, count, mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    printf("请输入年 月 日：");
    scanf("%d%d%d", &dt.y, &dt.m, &dt.d);
    count = dt.d;
    for (i = 0; i < dt.m; i++)//累加天数 
    {
        count += mon[i];
    }
    if (dt.m > 2 && (dt.y % 4 == 0 && dt.y % 100 != 0 || dt.y % 400 == 0))//判断是否为闰年 闰年+1天数 
    {
        count += 1;
    }
    printf("这一日是这一年的第%d天\n", count);
	return 0;
}
