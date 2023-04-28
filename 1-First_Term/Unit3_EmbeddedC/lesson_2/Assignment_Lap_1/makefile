#prepared by Ahmed Hassan (learn_in_depth)

project name=learn-in-depth

CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
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
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=output.map

$(project name).bin: $(project name).elf
	$(CC)objcopy.exe -O binary $< $@
	
clean_all:
	rm *.o *.elf *.bin *.map
	
clean: 
	rm *.elf *.elf
