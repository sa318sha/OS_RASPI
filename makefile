# CFILES = $(wildcard *.c)
# OFILES = $(CFILES:.c=.o)
# -nostdinc -nostdlib
RPIVERSION ?= 4

BOOTMNT ?= /media/sasha/boot

ARMGNU ?= aarch64-linux-gnu

C_OPTIONS = -Wall -O2 -ffreestanding  -nostartfiles -mgeneral-regs-only -I include 

ASM_OPTIONS = -I include

BUILD_DIR = build
SRC_DIR = src

all: kernel8.img

clean:
	-rm -rfv ${BUILD_DIR}
	-rm kernel8.img


$(BUILD_DIR)/%_s.o: $(SRC_DIR)/%.S
	mkdir -p $(@D)
	$(ARMGNU)-gcc $(ASM_OPTIONS) -MMD -c $< -o $@


$(BUILD_DIR)/%_c.o: $(SRC_DIR)/%.c
#@echo fiuubefiashfbibfhsofisuuisfbie ${C_files}
	mkdir -p $(@D)

	$(ARMGNU)-gcc $(C_OPTIONS) -MMD -c $< -o $@

# they dont actually exists there just place holder for the kernel8.img
C_FILES = $(wildcard $(SRC_DIR)/*.c) 
ASM_FILES = $(wildcard $(SRC_DIR)/*.S)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%_c.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.S=$(BUILD_DIR)/%_s.o)

DEP_FILES = ${OBJ_FILES:%.o=%.d}


#fix this
kernel8.img: linker/linker.ld ${OBJ_FILES} #$(OFILES)
	$(ARMGNU)-ld -T linker/linker.ld -o ${BUILD_DIR}/kernel8.elf ${OBJ_FILES}  
	$(ARMGNU)-objcopy ${BUILD_DIR}/kernel8.elf -O binary kernel8.img
	cp kernel8.img ${BOOTMNT}/kernel8.img
	cp config.txt ${BOOTMNT}/config.txt


