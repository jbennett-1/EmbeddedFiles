/* test program */
#include ""://update later

//states
#define IDLE_STATE 0
#define RUN_STATE 1
#define STOP_STATE 2

//functions
void SystemInit(void);
void SystemCoreClockUpdate(void);
void DisplayTime(void);
void SetClockFreq(void);
void SysTick_Handler(void);
 
//variables
uint32_t SysTick_Config(uint32_t ticks) /* SysTick */
uint32_t SystemCoreClock;
volatile int CurrState;
volatile unsigned long TickCounter;
volatile int userInput;

void main(void){
	SystemInit();
	SystemCoreClockUpdate();
	
	uint32_t returnC;
	returnC=SysTick_Config(SystemCoreClockUpdate/1000); //generate interrupt every ms

	if(returnC!=0){
	//error functions
	}
}

typedef struct {
	volatile unsigned long CTRL;
	volatile unsigned long LOAD;
	volatile unsigned long VAL;
	volatile unsigned long CALIB; 
} SysTick_Type; //for SysTick config

SysTick->VAL=0; //clear current value to 0
SysTick->LOAD=0x1023; //count down from 1023
SysTick->CTRL=0x7;

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
