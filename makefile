CC = arm-none-eabi-gcc
CFLAGS = -c -mcpu=$(MACH) -std=gnu11 -mthumb
MACH = cortex-m4
LDFLAGS = -T STM32F446RE_LS.ld -nostdlib -Wl,-Map=final.map 

main.o:main.c
	$(CC) $(CFLAGS) $^ -o $@ 
gpio.o:gpio.c
	$(CC) $(CFLAGS) $^ -o $@
STM32F446RE_startup_code.o:STM32F446RE_startup_code.c
	$(CC) $(CFLAGS) $^ -o $@ 
RCC.o:RCC.c
	$(CC) $(CFLAGS) $^ -o $@
final.elf:main.o gpio.o STM32F446RE_startup_code.o RCC.o
	$(CC) $(LDFLAGS) $^ -o $@
all:main.o gpio.o STM32F446RE_startup_code.o RCC.o final.elf
clean:
	rm -rf *.o *.elf
load:
	openocd -f board/st_nucleo_f4.cfg