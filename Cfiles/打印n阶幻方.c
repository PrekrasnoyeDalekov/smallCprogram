#include<stdio.h>

int main(){
	/* 特点：每行、每列和每条对角线上的数的和都相等。
	   算法：把幻方存储在一个二维数组中。起始时把数1放在0行的中间，剩
	   下的数2,3,4,...依次向上移动一行并向右移动一列。当可能越过数组
	   边界时需要“绕回”到数组的另一端。例如，如果需要把下一个数放到
	   -1行，我们就将其存储到最后一行；如果需要把下一个数放到n列，我
	   们就将其存储到0列。如果某个特定的数组元素已被占用，那就把该数
	   存储在前一个数的正下方。
	*/
	printf("This program creates a magic square of a specified size.\n");
	printf("The size must be an odd number\n");
	int n;
	printf("\nEnter size of magic square:");
	scanf("%d",&n);
	
	int magic[99][99] = {0};     // 二维数组int magic[n][n] = {0};这样初始化好像有错误
	for(int i = 1, x = 0, y = n/2;i <= n*n; i++){
		magic[x][y] = i;
		if(x ==0 && y == n-1){x--;y++;goto right_under;}  // 右上角的下一个数在其正下方
		else{if(x == 0) x=n-1;else x--;
			 if(y == n-1)y=0;else y++;}
		if(magic[x][y] != 0){
			right_under: x += 2;y -= 1;
		}
		
	}
	
	// output the magic
	for(int x = 0;x<n;x++){
		for(int y = 0;y<n;y++){
			printf("%3d ",magic[x][y]);
			if(y == n-1)printf("\n");
		}
	}
	return 0;
}
