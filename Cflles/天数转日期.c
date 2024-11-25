#include <stdio.h>

void split_date(int day_of_year, int years, int *month, int *day);
void split_date(int day_of_year, int years, int *month, int *day){
	int bool = (years % 4) ==0;  // 闰年二月份加1天
	if(day_of_year > 334+bool){*month = 12;*day = day_of_year - (334+bool);return ;}
	if(day_of_year > 304+bool){*month = 11;*day = day_of_year - (304+bool);return ;}
	if(day_of_year > 273+bool){*month = 10;*day = day_of_year - (273+bool);return ;}
	if(day_of_year > 243+bool){*month = 9;*day = day_of_year - (243+bool);return ;}
	if(day_of_year > 212+bool){*month = 8;*day = day_of_year - (212+bool);return ;}
	if(day_of_year > 181+bool){*month = 7;*day = day_of_year - (181+bool);return ;}
	if(day_of_year > 151+bool){*month = 6;*day = day_of_year - (151+bool);return ;}
	if(day_of_year > 120+bool){*month = 5;*day = day_of_year - (120+bool);return ;}
	if(day_of_year > 90+bool){*month = 4;*day = day_of_year - (90+bool);return ;}
	if(day_of_year > 59+bool){*month = 3;*day = day_of_year - (59+bool);return ;}
	if(day_of_year > 31+bool){*month = 2;*day = day_of_year - (31+bool);return ;}
	else{*month = 1;*day = day_of_year;return ;}
	
}

int main(){
	int years,days,month,date;
	printf("Enter years:");
	scanf("%d",&years);
	printf("Enter days:");
	scanf("%d",&days);
	if(days>=1 &&days <=365+(years%4==0))
	{split_date(days, years, &month, &date);
	printf("%4d-%2d-%2d",years,month,date);}
	else printf("You input illegal date!");
	return 0;
	
}
