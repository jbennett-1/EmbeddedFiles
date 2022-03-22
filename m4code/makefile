CC := arm-none-eabi-gcc
LD := arm-none-eabi-ld
SIZE := arm-none-eabi-size
OBJDUMP := arm-none-eabi-objdump
OBJCOPY := arm-none-eabi-objcopy
CONFIGS := -DCONFIG_HEAP_SIZE=4096

CFLAGS := -O0 -ffreestanding -fno-pie -fno-stack-protector -g3 -march=armv7-m -mthumb -Wall -mgeneral-regs-only -ffp-contract=off -Iinclude/  $(CONFIGS)
CFLAGS += -I/home/juliabennett/Desktop/OBG/m4code/Include

ODIR = obj
SDIR = src

OBJS = \
	startup_ARMCM7.o \
	system_ARMCM7.o \


OBJ = $(patsubst %,$(ODIR)/%,$(OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -g -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.s
	$(CC) $(CFLAGS) -c -g -o $@ $^


all: bin

bin: $(OBJ)
	$(LD) obj/* -Tgcc_arm.ld -o kernel8.img -e _start
	cp kernel8.img kernel8.elf
	$(OBJCOPY) -O binary kernel8.img

clean:
	rm -f obj/*
	rm -f kernel8.elf

debug:
	openocd -d -m openocd -f /usr/share/openocd/scripts/board/atmel_same54_xplained.cfg
	gdb-multiarch kernel8.elf 
	TERM=xterm gdb-multiarch -x gdb_init_prot_mode.txt

run:
	openocd -d -m openocd -f /usr/share/openocd/scripts/board/atmel_same54_explained.cfg -kernel kernel8.img -serial null -monitor stdio 

disassemble:
	$(OBJDUMP) -d kernel8.elf


