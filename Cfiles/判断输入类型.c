#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 1000
#define MAX_VALUES 100 // 假设最多支持100个输入值

// 函数声明
void determineType(const char *str, char *result);

int main() {
	int n;
	char results[MAX_VALUES][7]; 
	
	if (scanf("%d", &n) != 1 || n <= 0 || n > MAX_VALUES) {
		return 1;
	}
	getchar();
	
	for (int i = 0; i < n; i++) {
		char str[MAX_LEN];
		
		if (fgets(str, MAX_LEN, stdin) == NULL) {
			return 1;
		}
		
		str[strcspn(str, "\n")] = '\0';
		
		determineType(str, results[i]);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%s\n",results[i]);
	}
	
	return 0;
}

void determineType(const char *str, char *result) {
	int isInteger = 1;
	int isFloat = 0;
	
	for (int i = 0; str[i] != '\0'; i++) {
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
			isInteger = 0;
			break;
		}
		if (str[i] == '.') {
			isFloat = 1;
		}
	}
	
	if (isFloat) {
		int dotCount = 0;
		for (int i = 0; str[i] != '\0'; i++) {
			if (str[i] == '.') {
				dotCount++;
			}
		}
		isFloat = (dotCount == 1); // 只有一个小数点
	}
	
	if (isInteger) {
		if (str[0] == '-' && strlen(str) > 1) {
			strcpy(result, "Int");
		} else if (isdigit(str[0])) {
			strcpy(result, "Int");
		} else {
			strcpy(result, "String");
		}
	} else if (isFloat) {
		strcpy(result, "Float");
	} else {
		strcpy(result, "String");
	}
}


//#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <stdlib.h>
//#define MAX_LEN 1000
//static char *buf;
//
//void type(char *str){
//	extern char *buf;
//	if(!isdigit(str[0])){sprintf(buf,"String\n");return ;}
//	
//	for(;*str!='\0';str++){
//			if(*str=='.'){sprintf(buf,"Float\n");return ;}
//	}
//	sprintf(buf,"Int\n");return ;
//}
//
//int main(){
//	int n;
//	scanf("%d",&n);
//	getchar();
//	extern char *buf=(char *)calloc(n,7);
//	setvbuf(stdout,buf,_IOLBF,7*n);
//	for(int i=0;i<n;i++){
//		char *str=(char *)malloc(MAX_LEN);
//		gets(str);
//		type(str);
//	}
//	fflush(stdout);
//	return 0;
//}
