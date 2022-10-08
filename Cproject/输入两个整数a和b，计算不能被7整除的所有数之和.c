//输入两个整数a和b，计算不能被7整除的所有数之和
#include <stdio.h>
int fun(int n)
{
    int i, sum = 0;
    for (i = 0; i <= n; ++i)
        if (i % 7 != 0)
            sum += i;
    return sum;
}
int main()
{
    int a, b, sum = 0;
    scanf("%d%d", &a, &b);
    sum = fun(a) + fun(b);
    printf("%d", sum); 
    return 0;
}
