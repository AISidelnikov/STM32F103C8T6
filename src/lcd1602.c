#include "lcd1602.h"

extern TIM_HandleTypeDef htim1;

void delay(uint16_t us) {
	__HAL_TIM_SET_COUNTER(&htim1, 0);
	while (__HAL_TIM_GET_COUNTER(&htim1) < us);
}

void send_to_lcd(char data, int rs) {
	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, rs);
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, ((data >> 3) & 0x01));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, ((data >> 2) & 0x01));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, ((data >> 1) & 0x01));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, ((data >> 0) & 0x01));

	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, 1);
	delay(20);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, 0);
	delay(20);
}

void lcd_send_cmd(char cmd) {
    char cmdtosend;
    cmdtosend = ((cmd >> 4) & 0x0f);
    send_to_lcd(cmdtosend,0);
    cmdtosend = ((cmd) & 0x0f);
	send_to_lcd(cmdtosend, 0);
}

void lcd_send_data(char data) {
	char datatosend;
	datatosend = ((data >> 4) & 0x0f);
	send_to_lcd(datatosend, 1);
	datatosend = ((data) & 0x0f);
	send_to_lcd(datatosend, 1);
}

void lcd_clear(void) {
	lcd_send_cmd(0x01);
	HAL_Delay(2);
}

void lcd_put_cur(int row, int col) {
    switch (row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }
    lcd_send_cmd (col);
}


void lcd_init(void) {
	HAL_Delay(50);
	lcd_send_cmd (0x30);
	HAL_Delay(5);
	lcd_send_cmd (0x30);
	HAL_Delay(1);
	lcd_send_cmd (0x30);
	HAL_Delay(10);
	lcd_send_cmd (0x20);
	HAL_Delay(10);

	lcd_send_cmd(0x28); 
	HAL_Delay(1);
	lcd_send_cmd(0x08);
	HAL_Delay(1);
	lcd_send_cmd(0x01);
	HAL_Delay(1);
	lcd_send_cmd(0x06);
	HAL_Delay(1);
	lcd_send_cmd(0x0C);
}

void lcd_send_string(char *str) {
	while (*str) {
		lcd_send_data(*str++);
	}
}

void lcd_write_from_CGRAM(char *str, uint8_t addr) {
	lcd_send_cmd(0x40 + addr);
	for(uint8_t i = 0; i < 8; i++) {
		lcd_send_data(str[i]);
	}
}

void lcd_read_from_CGRAM(uint8_t addr) {
	lcd_send_data(addr);
}


