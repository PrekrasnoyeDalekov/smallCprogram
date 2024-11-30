#include "stdio.h"
#include <locale.h>
int main(){
	
	if(!setlocale(LC_ALL,"Russian")){
		fprintf(stdout,"%c",*setlocale(LC_ALL,NULL));
		return 1;
	}
	else {
		struct lconv *l;
		l = localeconv();
		printf("%d",l->p_sep_by_space);
		return 0;
	}
//	printf("%ul",sizeof(struct lconv));
}
