#include "INFO_DISPLAY.h"

void set_color(short x){
	if(x>=0&&x<=15){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
}

void hello(){
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO scr;
	GetConsoleScreenBufferInfo(out, &scr);
	int length = scr.srWindow.Right;        // 窗口长度
	const char *word1 = "Bank Simulation";
	int word_len = strlen(word1);
	int left_padding = (length - word_len) / 2;
	int right_padding = length - word_len - left_padding;	
	set_color(2);
	printf("%*s%s%*s\n", left_padding, "", word1, right_padding, "");  // 居中显示
	set_color(6);
	printf("Information:\n\tBank Windows:%d\n\tOpening Time:%d\n\tMax Duration:%d\n\tMax Intertime:%d\n",Bank_Windows,CLOSE_TIME,Max_Duration,Max_Intertime);
	set_color(15);
}
