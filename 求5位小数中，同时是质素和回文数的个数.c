//求5位整数中，既是质素又是回文数的个数 
#include <stdio.h>
int main()
{
    int i,j,ge,shi,qian,wan,flag,count;
    for (i = 10000; i <= 99999; i++)
    {//获取每一个5位数，然后得到它的个位，十位，千位，万位
       	ge = i%10;	
		shi = i/10%10;
		qian = i/10/10/10%10;
		wan = i/10/10/10/10%10;
        flag = 1;
        if ((ge==wan) && (shi==qian))//把满足条件的数据输出
        {//判断是否为质素 
            for (j = 2; j * j < i; j++)
                if (i % j == 0)
                {
                    flag = 0;
                    break;   
                }
            if (flag){
            	printf("%d\t", i);
                count++;
			}    
        }
    }
    printf("总计%d", count);
    printf("\n");
}
