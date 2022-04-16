# CFILES = $(wildcard *.c)
# OFILES = $(CFILES:.c=.o)
# -nostdinc -nostdlib
GCCFLAGS = -Wall -O2 -ffreestanding  -nostartfiles -mgeneral-regs-only
GCCPATH = ~/compiler/gcc-arm-10.3-2021.07-x86_64-aarch64-none-elf/bin


HEADER_DIR = -I include 


BUILD_DIR = build
SRC_DIR = src
INCLUDE = include

all: kernel8.img

clean:
	-rm -rfv ${BUILD_DIR}
	-rm kernel8.img



C_FILES = $(wildcard src/*.c) 

ASM_FILES = $(wildcard $(SRC_DIR)/*.s)
OBJ_FILES = $(C_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
OBJ_FILES += $(ASM_FILES:$(SRC_DIR)/%.s=$(BUILD_DIR)/%.o)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.s
	@echo ${OBJ_FILES}
	mkdir -p $(@D)
	$(GCCPATH)/aarch64-none-elf-gcc ${HEADER_DIR} $(GCCFLAGS) -MMD -c $< -o $@


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
#@echo fiuubefiashfbibfhsofisuuisfbie ${C_files}
	mkdir -p $(@D)

	$(GCCPATH)/aarch64-none-elf-gcc ${HEADER_DIR} $(GCCFLAGS) -MMD -c $< -o $@



#fix this
kernel8.img: linker/linker.ld ${OBJ_FILES} #$(OFILES)
	$(GCCPATH)/aarch64-none-elf-ld -nostdlib -T linker/linker.ld -o ${BUILD_DIR}/kernel8.elf ${OBJ_FILES}  
	$(GCCPATH)/aarch64-none-elf-objcopy ${BUILD_DIR}/kernel8.elf -O binary kernel8.img

