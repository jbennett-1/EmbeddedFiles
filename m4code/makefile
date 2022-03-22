CC := arm-none-eabi-gcc
LD := arm-none-eabi-ld
OBJDUMP := arm-none-eabi-objdump
OBJCOPY := arm-none-eabi-objcopy
CONFIGS := -DCONFIG_HEAP_SIZE=4096

CFLAGS := -O0 -ffreestanding -fno-pie -fno-stack-protector -g3 -march=armv7-m -mthumb -Wall -mgeneral-regs-only -ffp-contract=off -Iinclude/  $(CONFIGS)


ODIR = obj
SDIR = src

OBJS = \
	test.o \


OBJ = $(patsubst %,$(ODIR)/%,$(OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -g -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.s
	$(CC) $(CFLAGS) -c -g -o $@ $^


all: bin

bin: $(OBJ)
	$(LD) obj/* -Tkernel.ld -o kernel8.img -e _start

clean:
	rm -f obj/*
	rm -f kernel8.elf

debug:
	screen -S openocd -d -m openocd -f /usr/share/openocd/scripts/board/atmel_same54_xplained.cfg
#	gdb-multiarch kernel8.elf
#	screen -S qemu-x86_64 -d -m ./qemu-system-arm -machine lm3s811vb -cpu cortex-m4 -kernel kernel8.img -hda rootfs.img -S -s -serial null -serial stdio -monitor none -nographic -k en-us 
#	screen -S qemu-x86_64 -d -m qemu-system-arm -machine lm3s6965evb -cpu cortex-m3 -kernel kernel8.img -S -s -monitor stdio 
	TERM=xterm gdb-multiarch -x gdb_init_prot_mode.txt


run:
	qemu-system-arm -machine lm3s6965evb -cpu cortex-m3 -kernel kernel8.img -serial null -monitor stdio 

disassemble:
	$(OBJDUMP) -d kernel8.elf


