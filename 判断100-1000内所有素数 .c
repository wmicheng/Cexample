//判断100-1000内所有素数 
#include <stdio.h>
int main()
{
    int m, i, h = 0, leap;
    for (m = 100; m <= 1000; m++)
    {
        leap = 1;

        for (i = 2; i * i <= m; i++)
            if (m % i == 0)
            {
                leap = 0;
                break;
            }
        if (leap)
        {
            printf("%-4d", m);
            h++;
            if (h % 8 == 0)
                printf("\n");
        }
    }
    printf("\n总计%d\n", h);
    return 0;
}
