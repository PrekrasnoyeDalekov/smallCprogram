#include <stdio.h>

int main(){
	int find_int();
	printf("%d",find_int("a.txt"));
	return 0;
}
int find_int(const char *filename)
{
	FILE *fp = fopen(filename, "r");
	int n;
	if (fp == NULL)
		return -1; /* can't open file */
	while (fscanf(fp, "%d", &n) != 1) {
		if (ferror(fp)) {
			fclose(fp);
			return -2; /* input error */
		}
		if (feof(fp)) {
			fclose(fp);
			return -3; /* integer not found */
		}
		fscanf(fp, "%*[^\n]"); /* skips rest of line */
	}
	fclose(fp);
	return n;
}
