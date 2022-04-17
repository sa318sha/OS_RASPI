#pragma once
#include "common.h"
void mmio_write(vol64 reg, vol32 val);
unsigned int mmio_read(vol32 reg);
