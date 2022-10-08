#include <stdio.h>

int main()
{
    char str1[20]="abcd", str2[20]="1234", *p = str1,n = 0;
    while (*p++ != '\0');/*移动指针到str1尾*/
    --p;//回退一个单元，以便覆盖str1末的'\0p;//回退一个单元，以便覆盖str1末的'\0'
    while (str2[n] != '\0')
    {
        *p++ = str2[n];//将str2接到str1末
        ++n;
    };
    *p = '\0';//拼接完成，手动为str1末添上结束标记
    printf("结果为:\n%s\n\n",str1);
    return 0;
}
