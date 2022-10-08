#include <stdio.h>
int main(){
	//用来存储输入的字符串
	char str[10],ch = 0;
	int count[256] = {0},i,max = -1;
	printf("输入字符串：\n");
	scanf("%s", str);
	for(i=0; str[i]; i++) 
	    count[str[i]]++;
	    //初始化对应256个字符的ASCII值；
	for(i=0; i<256; i++){
		if(count[i] > max){
			max = count[i];
			ch = (char)i;
		}
	}
	printf("出现次数最多的是：%c", ch);
	return 0;
}
