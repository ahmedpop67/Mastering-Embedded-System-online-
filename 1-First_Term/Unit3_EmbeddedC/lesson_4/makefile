#prepared by Ahmed Hassan (learn_in_depth)

project name=learn-in-depth_lap_4

CC=arm-none-eabi-
CFLAGS=-g -gdwarf-2 -mcpu=cortex-m4
INCS=-I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As  = $(wildcard *.s)
AsOBJ = $(As:.s=.o)

all:$(project name).bin 
	@echo ">>>>>>>>>>>>>Duild is Done<<<<<<<<<<<<<"
	
%.o: %.c	
	$(CC)gcc.exe -c  $(CFLAGS) $(INCS) $< -o $@
	
%.o: %.s
	$(CC)as.exe  -c  $(CFLAGS) $(INCS) $< -o $@
	
$(project name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ)  -o $@ -Map=output.map
	cp $(project name).elf $(project name).axf

$(project name).bin: $(project name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.elf *.bin *.map map.asm
	
clean: 
	rm *.elf *.elf
