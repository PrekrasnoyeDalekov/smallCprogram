#include <stdio.h>
int main(){
	char message[80],ch;
	int len,shiftamount;
	printf("Enter message to be encrypted:");
	ch = getchar();
	// 'len' is the length of the message.
	for(len = 0;ch != '\n';len++){
		message[len] = ch;
		ch = getchar();
	}
	printf("Enter shift amount(1-25):");
	scanf("%d",&shiftamount);
	// shift 
	for(int i = 0;i <= len;i++){
		if(message[i] >= 'A' && message[i] <= 'Z'){
			message[i] = ((message[i] -'A') + shiftamount)%26 + 'A';}
		else if(message[i] >= 'a' && message[i] <= 'z'){
			message[i] = ((message[i] -'a') + shiftamount)%26 + 'a';
		}
	}
	// output
	for(int i = 0;i <=len;i++){
		printf("%c",message[i]);
	}
	return 0;
 }
