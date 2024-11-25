#include <stdio.h>
#include <stdbool.h>

struct point{int x,y;};
struct rectangle{struct point upper_left,lower_right;};
int area(struct rectangle r){
	return (r.lower_right.x-r.upper_left.x)*(r.upper_left.y-r.upper_left.y);
}

struct point center(struct rectangle r){
	struct point center;
	center.x = (r.lower_right.x-r.upper_left.x)/2;
	center.y = (r.upper_left.y-r.upper_left.y)/2;
	return center;
}

struct rectangle move(int x,int y,struct rectangle r){
	r.upper_left.x += x;
	r.lower_right.x += x;
	r.upper_left.y += y;
	r.lower_right.y +=y;
	return r;
}

bool is_inner(struct point p,struct rectangle r){
	return (p.y<=r.upper_left.y)&&(p.y>=r.lower_right.y)&&(p.x>=r.upper_left.x)&&(p.x<=r.lower_right.x) ? true : false;
}

int main(){
	return 0;
}


