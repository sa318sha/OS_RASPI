#pragma once
// #include "util/common.h"
#define PAGE_SHIFT	 	    	12
#define TABLE_SHIFT 			9
#define SECTION_SHIFT			(PAGE_SHIFT + TABLE_SHIFT)

#define PAGE_SIZE   			(1 << PAGE_SHIFT)	
#define SECTION_SIZE			(1 << SECTION_SHIFT)	

#define LOW_MEMORY              	(2 * SECTION_SIZE)

#ifndef __ASSEMBLER__
#include "util/common.h"
// void memzero(unsigned long src, unsigned long n);
// unsigned long allocPage();
// void freePage(unsigned long);

// extern int numPages;

// void memcpy(unsigned char *dest, unsigned char *src, int size);

// void mm_write(u32 reg, u32 data);
// u32 mm_read(u32 reg);

#endif


