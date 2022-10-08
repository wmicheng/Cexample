//char s1[20]="abcd";
//char s2[20]="1234;
#include <stdio.h>
main(){
	int i,j; 
	char s1[20]="abcd";
	char s2[20]="1234";
    for(i = 0; s1[i] != '\0'; ++i); /*移动到s1尾*/
    for(j = 0; s2[j] != '\0'; ++j, ++i)
    {
        s1[i] = s2[j];//将s2接到s1末
    }
    s1[i] = '\0';//拼接完成，手动为s1末添上结束标记
    printf("连接后: %s", s1);
	return 0;
} 
