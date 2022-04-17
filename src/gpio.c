#include "gpio.h"
#include "io.h"

//value offset will push teh
unsigned int gpio_general(unsigned int pinNumber, unsigned int value, unsigned int field_size, unsigned int baseAddress){
    unsigned int field_mask = (1<< field_size) -1;
  
    if (value > field_mask) return 0; 

    unsigned int num_fields = 32 / field_size;                          //gets the number of fields in the register since each are always teh same size
    unsigned int reg = baseAddress + ((pinNumber / num_fields) * 4);    //gets address if the pinnumber is > the number of fields then the address increment by 4
    unsigned int shift = (pinNumber % num_fields) * field_size;

    unsigned int curval = mmio_read(reg);
    curval &= ~(field_mask << shift);
    curval |= value << shift;
    mmio_write(reg, curval);

    return 1;
}
unsigned int gpio_select_alternate(unsigned int pinNumber, unsigned int value){
    
    

    if(value ==0){
        return gpio_general(pinNumber,5,3,GPFSEL0);
    }
    else if(value ==1){
        return gpio_general(pinNumber,6,3,GPFSEL0);
    }
    else if(value ==2){
        return gpio_general(pinNumber,7,3,GPFSEL0);
    }
    else if(value ==3){
        return gpio_general(pinNumber,8,3,GPFSEL0);
    }
    else if(value ==4){
        return gpio_general(pinNumber,3,3,GPFSEL0);
    }
    else {
        return gpio_general(pinNumber,2,3,GPFSEL0);
    }
}
unsigned int gpio_select(unsigned int pinNumber, unsigned int value){
    int returnVal =gpio_pull(pinNumber,0);
    if(returnVal ==0) return 0;
    return gpio_select_alternate(pinNumber,value);
}
unsigned int gpio_set(unsigned int pinNumber, unsigned int value){
    return gpio_general(pinNumber,value,1,GPSET0);
}
unsigned int gpio_clear(unsigned int pinNumber, unsigned int value){
    return gpio_general(pinNumber,value,1,GPCLR0);
}
unsigned int gpio_pull(unsigned int pinNumber, unsigned int value){
    return gpio_general(pinNumber,value,2,GPIO_PUP_PDN_CNTRL_REG0);
}
