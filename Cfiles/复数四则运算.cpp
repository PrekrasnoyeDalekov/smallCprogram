#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <cmath>


typedef struct complex{
	float re;
	float im;
	
}complex;
typedef struct link_node{
	complex *z=(complex *)malloc(sizeof(complex));
	struct link_node *next;
}link_node, *link_list;

link_list init_link(){
	link_list head = (link_list)malloc(sizeof(link_node));
	if(!head)exit(-1);
	else{
	head->next = NULL;
	return head;}
	
}

void set_color(short x){
	if(x>=0&&x<=15){
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),x);
	}
}

void hello() {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO scr;
	GetConsoleScreenBufferInfo(out, &scr);
	int length = scr.srWindow.Right;        // 窗口长度
	const char *word1 = "Complex Quadratic Calculator";
	int word_len = strlen(word1);
	int left_padding = (length - word_len) / 2;
	int right_padding = length - word_len - left_padding;	
	set_color(2);
	printf("%*s%s%*s\n", left_padding, "", word1, right_padding, "");  // 居中显示
	set_color(6);
	printf("\nCOMMAND:\n\t 0:Quit\n\t 1:Create Complex\n\t 2:Plus\n\t 3:Minus\n\t \
4:Dot Times\n\t 5:Division\n\t 6:Get Real Part\n\t 7:Get Imaginary Part\n\t \
8:Display Memory\n\t 9:Delete Complex\n\t10:Clear Memory\n\t11:Clean Window\n");
	set_color(15);
}


void insert_node(link_list &head,complex *z){// 注意&,避免了使用二重指针
// 在链表头部插入新元素*z
	link_list new_node = (link_list)malloc(sizeof(link_node));
	if(new_node){
		new_node->next = head;
		head = new_node;
		new_node->z = z;	
	}
	else exit(-1);
}

void clear_link(link_list &head){
	link_list p=head,temp;
	for(;p->next;){temp=p->next;free(p);p=temp;}
	head = p;
}

void del_complex(link_list &head,int n){
	link_node *p=head,*temp;
	if(n==0){temp=head->next;free(head);head=temp;}
	else{
	int i=0;
	for(;i<n-1&&p->next;p=p->next,i++);
	if(i>n||!(p->next))printf("Bad input\n");
	else{temp=p->next;p->next=temp->next;free(temp);}
	}
}
/* 
	head->complex_0,next->complex_1,next->complex_2,next->...->none,null
*/
void display_link(link_list head){
	void display_complex(complex *z);
	link_node *p = head;
	set_color(2);
	printf("Memory List:\n");
	set_color(15);
	for(int n=0;p->next;p=p->next,n++){
		printf("%d:  ",n);display_complex(p->z);printf("\n");
	}
}

complex *get_complex(link_list head,int n){
	complex *result;
	link_node *p=head;
	while(n--&&(p->next->next))p=p->next;
	if(n==-1){
	result=p->z;
	return result;}
	else return (complex *)NULL;
}
void display_complex(complex *z){
	set_color(4);
	if(!z)printf("None");
	else printf("(%g %+gi)",z->re,z->im);
	set_color(15);
}

void create_complex(complex *z){
	printf("Please enter real part:");
	scanf("%f",&(z->re));
	printf("Please enter imaginary part:");
	scanf("%f",&(z->im));
	display_complex(z);	
}
float get_re(complex *a){
	return a->re;
}

float get_im(complex *a){
	return a->im;
}

complex *plus(complex *a,complex *b){
	complex *result = (complex *)malloc(sizeof(complex));
	if(!result)exit(-1);
	else{
		result->re = a->re + b->re;
		result->im = a->im + b->im;
		return result;
	}
}

complex *dot(complex *a,complex*b){
	complex *result = (complex *)malloc(sizeof(complex));
	if(!result)exit(-1);
	else{
	result->re = a->re * b->re - a->im * b->im;
	result->im = a->im * b->re + a->re * b->im;
	return result;}
}

complex *div(complex *a,complex*b){
	complex *result = (complex *)malloc(sizeof(complex));
	if(!result)exit(-1);
	else{
	float d = pow(b->re,2)+pow(b->im,2); 
	if(d==0){
		printf("Division by 0!\n");
		return (complex *)NULL;
	}
	else{
		result->re = (a->re*b->re + a->im*b->im)/d;
		result->im = (a->im*b->re - a->re*b->im)/d;
	}
	return result;}
}

complex *minus(complex *a, complex *b){
	complex *result = (complex *)malloc(sizeof(complex));
	if(!result)exit(-1);
	else{
	result->re = a->re - b->re;
	result->im = a->im - b->im;
	return result;}
	
}

int main(){
	enum command_code{
		QUIT,CREATE_COMPLEX,PLUS,MINUS,DOT,DIV,GET_RE,
		GET_IM,DISPLAY_MEMORY,DEL_COMPLEX,CLEAR,CLEAN
	};
	link_list head = init_link();
	int command;
	hello();
	do{
		printf("Enter command code:");
		scanf("%d",&command);
		if(command==QUIT)return 0;
		else if(command==CREATE_COMPLEX){
			complex *z=(complex *)malloc(sizeof(complex));
			create_complex(z);
			printf("Save or not?[Y/N]:");
			char c;
			scanf(" %c",&c);
			if(c=='Y'||c=='y')insert_node(head,z);
			else free(z);
		}
		else if(command==PLUS){
			display_link(head);
			if(head->next&&head->next->next){
				printf("Please choose two complex number,separated by \",\":");
				int i,j;
				scanf(" %d , %d",&i,&j);
				complex *a = get_complex(head,i),*b = get_complex(head,j);
				if(a&&b){
					display_complex(a);printf(" + ");display_complex(b);printf(" = ");
					complex *result = plus(a,b);
					display_complex(result);printf("\n");
					insert_node(head,result);
				}
				else printf("Out of index\n");
			}
			else printf("Lack complex\n");
			
		}
		else if(command==MINUS){
			display_link(head);
			if(head->next&&head->next->next){
				printf("Please choose two complex number,separated by \",\":");
				int i,j;
				scanf(" %d , %d",&i,&j);
				complex *a = get_complex(head,i),*b = get_complex(head,j);
				if(a&&b){
					display_complex(a);printf(" - ");display_complex(b);printf(" = ");
					complex *result = minus(a,b);
					display_complex(result);printf("\n");
					insert_node(head,result);
				}
				else printf("Out of index\n");			
				
			}
			else printf("Lack complex\n");
			
		}
		else if(command==DOT){
			display_link(head);
			if(head->next&&head->next->next){
				printf("Please choose two complex number,separated by \",\":");
				int i,j;
				scanf(" %d , %d",&i,&j);
				complex *a = get_complex(head,i),*b = get_complex(head,j);
				if(a&&b){
					display_complex(a);printf(" * ");display_complex(b);printf(" = ");
					complex *result = dot(a,b);
					if(result){
						display_complex(result);printf("\n");
						insert_node(head,result);
					}
					
				}
				else printf("Out of index\n");
				
			}
			else printf("Lack complex\n");
			
		}
		else if(command==DIV){
			display_link(head);
			if(head->next&&head->next->next){
				printf("Please choose two complex number,separated by \",\":");
				int i,j;
				scanf(" %d , %d",&i,&j);
				complex *a = get_complex(head,i),*b = get_complex(head,j);
				if(a&&b){
					display_complex(a);printf(" / ");display_complex(b);printf(" = ");
					complex *result =div(a,b);
					if(result){
						display_complex(result);printf("\n");
						insert_node(head,result);
					}
					
				}
				else printf("Out of index\n");
					
			}
			else printf("Lack complex\n");
			
		}
		else if(command==GET_RE){
			display_link(head);
			if(head->next){
				printf("Please choose complex number:");
				int i;
				scanf("%d",&i);
				complex *z = get_complex(head,i);
				if(z)printf("The real part: %g\n",get_re(z));
				else printf("Out of index\n");
			}
			else printf("Lack complex\n");
		}
		else if(command==GET_IM){
			display_link(head);
			if(head->next){
				printf("Please choose complex number:");
				int i;
				scanf("%d",&i);
				complex *z = get_complex(head,i);
				if(z)printf("The imaginary part: %g\n",get_im(z));
				else printf("Out of index\n");
			}
			else printf("Lack complex\n");
		}
		else if(command==DISPLAY_MEMORY){
			display_link(head);
		}
		else if(command==DEL_COMPLEX){
			display_link(head);
			printf("Please choose complex number:");
			int i;
			scanf("%d",&i);
			del_complex(head,i);
		}
		else if(command==CLEAR){
			clear_link(head);
		}
		else if(command==CLEAN){
			fflush(stdout);
			system("cls");
			hello();
		}
		
	}while(true);
}
