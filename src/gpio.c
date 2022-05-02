#include "peripherals/gpio.h"
#include "util/common.h"
#include "mm/basic_mm.h"
#include "peripherals/addresses/io_addresses.h"

#if defined(WAY1)
//value offset will push teh
u32 gpio_general(u8 pinNumber, u8 value, u8 field_size, u32 baseAddress){
    u32 field_mask = (1<< field_size) -1;
  
    if (value > field_mask) return 0; 

    u32 num_fields = 32 / field_size;                          //gets the number of fields in the register since each are always teh same size
    u32 reg = baseAddress + ((pinNumber / num_fields) * 4);    //gets address if the pinnumber is > the number of fields then the address increment by 4
    u32 shift = (pinNumber % num_fields) * field_size;

    u32 curval = mm_read(reg);
    curval &= ~(field_mask << shift);
    curval |= value << shift;
    mm_write(reg, curval);

    return 1;
}
u32 gpio_select_alternate(u8 pinNumber, GPIO_func value){
    return gpio_general(pinNumber,value ,3,&GPIOR->GPFSEL[0]);

}

// gpio_select_alternate((u8)4 , GFAlt5);
u32 gpio_select(u8 pinNumber, GPIO_func value){
    int returnVal =gpio_pull(pinNumber,0);
    if(returnVal ==0) return 0;
    return gpio_select_alternate(pinNumber,value);
}
u32 gpio_set(u8 pinNumber, u8 value){
    return gpio_general(pinNumber,value,1, &GPIOR->GPFSET.data[0]);
}
u32 gpio_clear(u8 pinNumber, u8 value){
    return gpio_general(pinNumber,value,1,&GPIOR->GPCLR.data[0]);
}
u32 gpio_pull(u8 pinNumber, GPIO_PUPDCTNL value ){
    return gpio_general(pinNumber,value,2,&GPIOR->GPIO_PUP_PDN_CNTRL_REG[0]);
}

#else 
#define NUM_OF_PINS 53

void gpio_general_func(u8 pinNumber, u8 value, u8 fieldSize, u32 baseAddress){
    u8 mask =((1<<fieldSize)-1);
    if(value > mask)return;

    u32 num_fields = 32 / fieldSize;  
    u32 reg = baseAddress + ((pinNumber / num_fields) * 4);    //gets address if the pinnumber is > the number of fields then the address increment by 4
    u32 shift = (pinNumber % num_fields) * fieldSize;

    u32 curval = mm_read(reg);
    curval &= ~(mask << shift);
    curval |= value << shift;
    mm_write(reg, curval);


}

void gpio_pin_set_func(u8 pinNumber, GPIO_func func){
    u8 bitStart = (pinNumber*3)%30;
    u8 reg = pinNumber/10;
    u32 val = GPIOR->GPFSEL[reg];
    val &= ~(7 << bitStart);
    val |= (func << bitStart);
    GPIOR->GPFSEL[reg] = val;
}

void gpio_pin_resistor_enable(u8 pinNumber, GPIO_PUPDCTNL resistor_val){
    u8 bitStart = (pinNumber*2)%32;
    u8 reg = pinNumber/16;
    u32 val = GPIOR->GPIO_PUP_PDN_CNTRL_REG[reg];
    val &= ~(3 << bitStart);
    val |= (resistor_val << bitStart);
    GPIOR->GPIO_PUP_PDN_CNTRL_REG[reg] = val;
}

void gpio_pin_output_set(u8 pinNumber, u8 newVal){
    u8 bitStart = (pinNumber)%32;
    u8 reg = pinNumber/32;
    u32 val = GPIOR->GPFSET.data[reg];
    val &= ~(1 << bitStart);
    val |= (newVal << bitStart);
    GPIOR->GPFSET.data[reg] = val;
}

//tobe added
// void gpio_pin_output_clear(u8 pinNumber);
// void gpio_pin_level(u8 pinNumber);
// void gpio_pin_event_status(u8 pinNumber);
// void gpio_pin_rising_edge_detect(u8 pinNumber);
// void gpio_pin_falling_edge_detect(u8 pinNumber);
// void gpio_pin_high_detect(u8 pinNumber);
// void gpio_pin_low_detect(u8 pinNumber);
// void gpio_pin_async_rising_edge_detect(u8 pinNumber);
// void gpio_pin__asyncfalling_edge_detect(u8 pinNumber);


 
#endif