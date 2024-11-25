#include <stdio.h>

int main(){
	printf("Enter a sentence:");
	char sentence[100],letter;
	int len = 0;
	// len是句子的长度
	do{	
		letter = getchar();
		if(len<=999)sentence[len++] = letter;
	}while(letter != '.' && letter != '?' && letter !='!');
	// 反向搜索数组,j是空格的位置,index是切片数组的索引
	int index = 1, space[100] = {len-1}; // space = {stopmark, lastspace, ..., -1};
	for(int j = len-1;j >= 0 ;j--){
		if(sentence[j] == ' '){space[index] = j;index++;}
	}
	space[index] = -1;
	// 输出反向句子
	for(int i = 1;i <= index;i++){
		for(int out = space[i]+1;out<= space[i-1]-1;out++){printf("%c",sentence[out]);}
		printf(" ");		
	}
	printf("%c",sentence[len - 1]);
	return 0;
 }
