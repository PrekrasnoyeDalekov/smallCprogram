#include <stdbool.h>

bool search(const int a[], int n, int key);
bool search(const int a[], int n, int key){
	for(int *p = a;p < &a[n];p++){
		if(*p == key) return true;
	}
	return false;
}

int main(){
	return search((int []){1,2,3},3,1);
}
