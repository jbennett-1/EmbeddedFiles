/* test program */
typedef struct 
{
	volatile unsigned long CTRL;
	volatile unsigned long LOAD;
	volatile unsigned long VAL;
	volatile unsigned long CALIB; 
} SysTick_Type;

#define SysTick((SysTick_Type* )*0xE000E010) /*SysTick struct */

SysTick->VAL=0x0;
SysTick->LOAD=0xFFFFF; //clock cycles/reload val
SysTick->CTRL=0x5;


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
void *VectorTable[]={0x20005000,
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
