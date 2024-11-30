#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
	char letter = 'A',m[10][10];
	// creat a 10*10 dot matrix 
	for(int i = 0;i < 10;i++){
		for(int j =0;j< 10;j++){
			m[i][j] = '.';
		}
	}
	m[0][0] = letter;
	srand((unsigned) time(NULL));  // random seed 
	
	for(int direction, i = 0, j = 0;letter < 90;){
		if((m[i-1][j] !='.' && m[i+1][j] !='.')
			&& (m[i][j-1] !='.' && m[i][j+1] !='.')) break;
		direction = rand() % 4;
		/*  We set 
		    direction = 0 to move upward    ↑
		    direction = 1 to move leftward  ←
			direction = 2 to move downward  ↓
			direction = 3 to move rightward →
		*/
		switch(direction){
		case 0:
			if(i >= 1 && m[i-1][j] == '.') {m[--i][j] = ++letter;}break;
		case 1:
			if(j >= 1 && m[i][j-1] == '.') {m[i][--j] = ++letter;}break;
		case 2:
			if(i <= 9 && m[i+1][j] == '.') {m[++i][j] = ++letter;}break;
		case 3:
			if(j <= 9 && m[i][j+1] == '.') {m[i][++j] = ++letter;}break;
		}
		
	}
	
	//print the matrix
	for(int i = 0;i < 10;i++){
		for(int j =0;j< 10;j++){
			printf("%c ",m[i][j]);
			if(j == 9)printf("\n");
		}
	}
	
	return 0;
}
