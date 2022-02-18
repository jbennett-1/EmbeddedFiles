CC := arm-none-eabi-gcc
LD := arm-none-eabi-ld
OBJDUMP := arm-none-eabi-objdump
OBJCOPY := arm-none-eabi-objcopy
CONFIGS := -DCONFIG_HEAP_SIZE=4096

CFLAGS := -O0 -ffreestanding -fno-pie -fno-stack-protector -g3 -march=armv7e-m -mthumb -Wall -mgeneral-regs-only -ffp-contract=off -Iinclude/  $(CONFIGS)


ODIR = obj
SDIR = src

OBJS = \
	test.o \
	junk.o \


OBJ = $(patsubst %,$(ODIR)/%,$(OBJS))

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c -g -o $@ $^

$(ODIR)/%.o: $(SDIR)/%.s
	$(CC) $(CFLAGS) -c -g -o $@ $^


all: bin rootfs.img

bin: $(OBJ)
	$(LD) obj/* -Tkernel.ld -o kernel8.img -e _start
	cp kernel8.img kernel8.elf
	$(OBJCOPY) -O binary kernel8.img

clean:
	rm -f obj/*
	rm -f rootfs.img
	rm -f rootfs.img
	rm -f kernel8.img
	rm -f kernel8.elf
	killall screen

debug:
#	screen -S qemu-x86_64 -d -m ./qemu-system-arm -machine lm3s811vb -cpu cortex-m4 -kernel kernel8.img -hda rootfs.img -S -s -serial null -serial stdio -monitor none -nographic -k en-us 
	screen -S qemu-x86_64 -d -m qemu-system-arm -machine netduino2 -cpu cortex-m3 -kernel kernel8.img -S -s -monitor stdio -k en-us 
	TERM=xterm gdb-multiarch -x gdb_init_prot_mode.txt

run:
	qemu-system-arm -machine netduino2 -cpu cortex-m4 -kernel kernel8.img -serial null -monitor stdio -k en-us

disassemble:
	$(OBJDUMP) -d kernel8.elf

rootfs.img:
	dd if=/dev/zero of=rootfs.img bs=1M count=16
	mkfs.fat -F16 rootfs.img
	sudo mount rootfs.img /mnt
	sudo mkdir -p /mnt/boot/firmware
	sudo mkdir /mnt/bin
	sudo mkdir /mnt/etc
	sudo umount /mnt
