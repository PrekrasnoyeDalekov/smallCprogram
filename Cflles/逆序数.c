#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 定义一个结构体来存储逆序数和数组
struct InverseResult {
	int inverse;
	int *array;
};

// 计算逆序数的函数
struct InverseResult inverse_num(int array[], int n) {
	struct InverseResult result;
	if (n <= 1) {
		result.inverse = 0;
		result.array = (int *)malloc(sizeof(int));
		result.array[0] = array[0];
		return result;
	}
	
	int mid = n / 2;
	struct InverseResult left = inverse_num(array, mid);
	struct InverseResult right = inverse_num(array + mid, n - mid);
	
	int nl = mid;
	int nr = n - mid;
	
	int *arr_l = left.array;
	int *arr_r = right.array;
	
	// 插入最大的int作为标兵
	arr_l = (int *)realloc(arr_l, sizeof(int) * (nl + 1));
	arr_r = (int *)realloc(arr_r, sizeof(int) * (nr + 1));

	
	int i = 0, j = 0;
	int inverse = left.inverse + right.inverse;
	
	int *new_arr = (int *)malloc(sizeof(int) * n);
	int k = 0;
	while (i < nl || j < nr) {
		if (arr_l[i] <= arr_r[j]) {
			inverse += j;
			new_arr[k++] = arr_l[i++];
		} else {
			new_arr[k++] = arr_r[j++];
		}
	}
	
	result.inverse = inverse;
	result.array = new_arr;
	
	free(left.array);
	free(right.array);
	
	return result;
}

int main() {
	int array[] = {2, 2, 1, 3, 5};
	int n = sizeof(array) / sizeof(array[0]);
	
	struct InverseResult result = inverse_num(array, n);
	
	printf("Inverse number: %d\n", result.inverse);
	printf("Sorted array: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", result.array[i]);
	}
	printf("\n");
	
	free(result.array);
	
	return 0;
}

