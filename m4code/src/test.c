/* test program */

int main(){
	int a,b,c;
	a=1;
	b=2;
	c=0;
	c=a+b;

}


#if 0
void _start(){
	while(1){
		main();
	}
}
#endif

void dummyvec() {
	while(1);
}

void _start();
__attribute__ ((section(".vectors")))
void *VectorTable[]={0x20000400,
	             _start,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
                     dummyvec,
};
