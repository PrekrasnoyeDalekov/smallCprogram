#include <stdio.h>
#include <string.h>
#define MAX_LEN 20
int main(){
	char word[MAX_LEN]={'\0'},smallest_word[MAX_LEN]={'\0'},largest_word[MAX_LEN]={'\0'};
	printf("Enter word:");
	gets(word);
	strcpy(smallest_word,word);
	strcpy(largest_word,word);
	while(*word){
		if(strcmp(word,smallest_word) < 0)strcpy(smallest_word,word);
		else if(strcmp(word,largest_word) >0)strcpy(largest_word,word);
		printf("Enter word:");
		gets(word);
	}
	printf("The smallest word is:%s\n",smallest_word);
	printf("The largest word is:%s\n",largest_word);
	
}
