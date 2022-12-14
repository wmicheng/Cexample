//题目：古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子， 
//小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（
//输出前40个月即可）
//（斐波那契数列）

#include<stdio.h>

int main()
{
	int cnt,i;
	int cnt1 = 1, cnt2 = 1;
	printf("第1个月：%d\n", cnt1);
	printf("第2个月：%d\n", cnt2);

	for ( i = 3; i < 41; ++i)
	{
		cnt = cnt1 + cnt2;
		printf("第%d个月：%d\n", i, cnt);
		cnt1 = cnt2;
		cnt2 = cnt;
	}
	return 0;
}
