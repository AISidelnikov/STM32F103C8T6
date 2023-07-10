#include "app_main.h"

extern TIM_HandleTypeDef htim1;

char cc1[] = {0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};
char mpu_str[16] = {0};

void app_main(void) {
    HAL_TIM_Base_Start(&htim1);

    lcd_init ();
    lcd_put_cur(0, 4);
    lcd_send_string("STM32");
    lcd_write_from_CGRAM(cc1, 0);
    lcd_put_cur(1, 0);
    lcd_read_from_CGRAM(0);
    HAL_Delay(250);
    mpu_t *mpu = mpu6050_init();
    lcd_clear();
    for(;;) {
        // lcd_put_cur(0, 0);
        // mpu_read_temp(mpu);
        // sprintf(mpu_str, "temp: %+d", mpu->temp);
        // lcd_clear();
        // lcd_send_string(mpu_str);
        // HAL_Delay(100);
        btn_read_state();
    }
}