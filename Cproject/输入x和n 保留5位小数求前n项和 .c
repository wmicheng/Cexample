// 输入x和n 保留5位小数求前n项和 
#include <stdio.h>
#include "math.h"
int main()
{
    int i,n,x;
    float k=1,sum=1,sign=0;
    scanf("%d%d",&x,&n);
    k=(n*(n+1));
    for ( i=0;i<=n;i++)
    {
        sign = pow(1.0*x,i)/k;  
		sum+=sign;  
    }
    printf("%.5f",sum);
    return 0;
}
