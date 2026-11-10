#ifndef FAKE_I2C_H
#define FAKE_I2C_H

#include <stdint.h>

typedef unsigned int uint;
typedef unsigned int i2c_inst_t; 
static i2c_inst_t* fake_i2c_address = (i2c_inst_t*) 0x11223344;
static i2c_inst_t* i2c_default = (i2c_inst_t*) 0x11223344;
static uint fake_baudrate = 400 * 1000;


uint i2c_init(i2c_inst_t *i2c, uint baudrate);

#endif