/* test program */
#include <stdio.h>

int main(int argc, char** argv){
	int a,b,c,*d;
	c=a+b;
	printf("cache of c=%p\n",&c);
	d=&c;
	printf("sum is %d, and cache of pointer is %p\n",c,d);
}


