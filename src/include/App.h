#ifndef D_App_H
#define D_App_H

#define I2C_SCA_PIN 4
#define I2C_CLK_PIN 5
#define BAUDRATE (400 * 1000)

void app_main(void);
void i2c_setup(i2c_inst_t*, uint, uint, uint);
void initialize_display(i2c_inst_t*);

#endif  /* D_FakeApp_H */
