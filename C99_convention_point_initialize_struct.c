#include<stdio.h>
#include<stdlib.h>

struct point{
	int pa;
	int pb;
};

struct pointTest{
	struct point* (*a)(struct pointTest*);
	int b;
	int c;
};

struct point* funcp(struct pointTest* pt);

struct pointTest pp = {
	.a = funcp,
	.b = 2,
};

int main(void){
	struct point* testa = pp.a(&pp);
	
	printf("pa = %d, pb = %d\n", testa->pa, testa->pb);	
	printf("b = %d, c = %d\n", pp.b, pp.c);
	
	return 0;
}

struct point* funcp(struct pointTest* pt){
	struct point* return_struct_point = (struct point*)malloc(sizeof(struct point));
	pt->c = 10;
	return_struct_point->pa = 99;
	return_struct_point->pb = 100;
	return return_struct_point;
}
