#include<stdio.h>
#include<stdlib.h>

struct point{	//점을 표현하는 구조체
	int pa;
	int pb;
};

struct pointTest{	// C99 기능을 테스트 해볼
	struct point* (*function)(struct pointTest*);	// 테스트 용으로써 a의 값이 C99 기능으로 초기화가 되는지,
													// 초기화가 되었다면 함수 기능을 제대로 수행하는지 확인용
	int b;
	int c;
};

struct point* funcp(struct pointTest* pt);	// pointTest 의 함수포인터 a를 테스트할 함수

int main(void){
	struct pointTest pp = {	// pointTest 변수 선언 및 초기화
		.function = funcp,	// 구조체내의 function을 funcp함수로 초기화 
		.b = 2				// 구조체내의 b 변수를 2로 초기화
	};

	struct point* testa = pp.function(&pp);		// pp의 초기화된 function 함수사용 
	
	printf("pa = %d, pb = %d\n", testa->pa, testa->pb);	// 함수에서 동적할당된 point 값 확인	
	printf("b = %d, c = %d\n", pp.b, pp.c);				// pointTest 구조체의 설정된 값 확인
	
	return 0;
}

struct point* funcp(struct pointTest* pt){
	struct point* return_struct_point = (struct point*)malloc(sizeof(struct point));	// point 동적 할당
	pt->c = 10;				// 초기화 하지 않았던 pt->c 값을 10으로 설정

	return_struct_point->pa = 99;	// 할당받은 point 변수에 값을 저장
	return_struct_point->pb = 100;

	return return_struct_point;		// 해당 주소를 리턴
}
