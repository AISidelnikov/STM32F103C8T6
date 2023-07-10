#ifndef _LCD1602_H_
#define _LCD1602_H_
#include "main.h"

void lcd_init (void);
void lcd_send_cmd (char cmd);
void lcd_send_data (char data);
void lcd_send_string (char *str);
void lcd_put_cur(int row, int col);
void lcd_write_from_CGRAM(char *str, uint8_t addr);
void lcd_read_from_CGRAM(uint8_t addr);

#endif
