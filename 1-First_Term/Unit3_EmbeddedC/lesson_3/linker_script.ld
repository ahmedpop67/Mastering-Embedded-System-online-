/*LEARN_IN_DEPTH
UNIT2_LESSON2_LAP1
ENG: AHMED HASSAN
*/

ENTRY(Rest_Handler)

MEMORY
{
	flash (RX) : ORIGIN = 0X08000000, LENGTH = 512M
	sram (RWX)  : ORIGIN = 0x20000000, LENGTH = 512M
}

SECTIONS
{
		.text : 
		{
			*(.vectors*)
			*(.text*)
			*(.rodata*)
			. = ALIGN(4);
			_E_text = . ;
		}> flash
	.data :
		{
			_S_DATA = .;
			*(.data)
			. = ALIGN(4);
			_E_DATA = .;
		}> sram AT> flash
	.bss :
		{
			_S_BSS = .;
			*(.bss) *(.COMMON)
			. = ALIGN(4);
			_E_BSS = .;
		}> sram
    . = . + 0x1000;  /*4kB of stack memory*/
	stack_top = . ;
}