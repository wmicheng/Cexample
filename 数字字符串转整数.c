#include <stdio.h>    // 把一个数字字符串转换为一个整数。
int main()
{
    char* numStr = "4562";
    int value=0;
    while( *numStr >= '0' && *numStr <= '9' ){ // 逐个把字符串的字符转换为数字。
        value *= 10;
        value += *numStr - '0';
        numStr++;
    }
    printf("%d\n",value); 
    return 0;
}
