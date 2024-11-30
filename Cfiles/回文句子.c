#include <ctype.h>
#include <stdio.h>
#define MAX_LEN 100

char sentence[MAX_LEN];
char *p = &sentence[0],*q = &sentence[0];
int isPalindrome();
int main(){
	char letter;
	printf("Enter a sentence(not longer than %d letter):",MAX_LEN);
	letter = getchar();
	while(letter != '\n'){
		if(isalpha(letter))*(p++) = tolower(letter);
		letter = getchar();
	}
	if(isPalindrome())printf("\nPalindrome.");
	else printf("\nNot palindrome.");
	return 0;
	
}
int isPalindrome(){
	for(p--;q < p;q++,p--){
		if(*p != *q)return 0;
	}
	return 1;
}
