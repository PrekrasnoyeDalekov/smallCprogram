#include <stdio.h>
#include <ctype.h>

int main(){
	char letter;
	int alphabet[26] = {0};
	printf("Enter the first word:");
	letter = getchar();
	while(letter != '\n'){
		if(isalpha(letter = tolower(letter))){
			alphabet[letter - 'a'] ++;
		}
		letter = getchar();
	}
	
	
	printf("Enter the second word:");
	letter = getchar();
	while(letter != '\n'){
		if(isalpha(letter = tolower(letter))){
			alphabet[letter - 'a'] --;
		}
		letter = getchar();
	}
	
	// test whether the alphabet array is {0}
	for(int i = 0;i <= 25;i++){
		if(alphabet[i] == 1){
			printf("The words are not anagrams.");
			break;
		}
		else if(i == 25){
			printf("The words are anagrams.");
		}
	}
	return 0;
}
