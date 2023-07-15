#include "app_main.h"

extern TIM_HandleTypeDef htim1;
extern SPI_HandleTypeDef hspi2;
extern UART_HandleTypeDef huart1;

char cc1[] = {0x00, 0x00, 0x0A, 0x00, 0x11, 0x0E, 0x00, 0x00};
char mpu_str[16] = {0};
char rx_data = 0;
int tx_data[7] = {0};

void app_main(void) {
    HAL_TIM_Base_Start(&htim1);
    lcd_init ();
    lcd_write_from_CGRAM(cc1, 0);
    lcd_put_cur(0, 0);
    lcd_send_string("HELLO");
    lcd_put_cur(5, 0);
    lcd_read_from_CGRAM(0);
    HAL_Delay(1000);
    mpu6050_init();
    lcd_clear();
    HAL_SPI_Receive_IT(&hspi2, &rx_data, sizeof(rx_data));
    for(;;) {
        menu_handle();
        btn_read_state();
        // HAL_Delay(250);
        lcd_clear();
        HAL_UART_Transmit(&huart1, "Hello", 6, 1000);
    }
}

// void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
// {
//     HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
//     mpu_read_all(tx_data);
//     HAL_SPI_Transmit(&hspi2, &tx_data, sizeof(tx_data), 1000);
//     HAL_SPI_Receive_IT(&hspi2, &rx_data, sizeof(rx_data));
// }