/*LEARN_IN_DEPTH
UNIT2_LESSON2_LAP2
ENG: AHMED HASSAN
*/
#include "STD_TYPES.H"

extern uint32 stack_top;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;
extern uint32 _E_text;


extern int main(void);
void Rest_Handler();
void init_sect(void);

void Default_handler(void)
{
	Rest_Handler();
}

void NMI_Handler(void)         __attribute__((weak , alias("Default_handler")));;
void H_Fault_Handler(void)     __attribute__((weak , alias("Default_handler")));;
void MM_Handler(void)          __attribute__((weak , alias("Default_handler")));;
void Bus_Handler(void)         __attribute__((weak , alias("Default_handler")));;
void Usage_Fault_Handler(void) __attribute__((weak , alias("Default_handler")));;

uint32 vectors[] __attribute__((section(".vectors")))=
{
	(uint32) &stack_top,
	(uint32) &Rest_Handler,
	(uint32) &NMI_Handler,
	(uint32) &H_Fault_Handler,
	(uint32) &MM_Handler,
	(uint32) &Bus_Handler,
	(uint32) &Usage_Fault_Handler,
};
void Rest_Handler(void)
{
	init_sect();
	main();
}
void init_sect(void)
{
	uint32 DATA_size = (uint32*)&_E_DATA - (uint32*)&_S_DATA;
	uint8 *P_src = (uint8*)&_E_text;
	uint8 *P_dst = (uint8*)&_S_DATA;
	
	for (uint32 i=0;i<DATA_size;i++)
	{
		*((uint8*)P_dst++) = *((uint8*)P_src++);
	}
	
	uint32 bss_size = (uint32*)&_E_BSS - (uint32*)&_S_BSS;
	P_dst =(uint8*)&_S_BSS;
	for (uint32 i=0;i<bss_size;i++)
	{
		*((uint8*)P_dst++) = (uint8)0;
	}
	
}