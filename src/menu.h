#ifndef __APP_MAIN_H
#define __APP_MAIN_H
#include "main.h"
#include "lcd1602.h"
#include "mpu6050.h"
#include "button.h"

#define calc_len(array) sizeof(array)/sizeof(array[0])
typedef enum {
    MAIN_MENU,
    ACCELX,
    ACCELY,
    ACCELZ,

    GYROX,
    GYROY,
    GYROZ,

    TEMP,

    ALL_MENU,
    NO_MENU,
}MENUS;

typedef struct {
    const char 	str[16];
	char*		str_p;
	uint8_t 	x;
	uint8_t 	y;
}string_t;

typedef struct {
    string_t *str;
    uint8_t num_of_string;
    MENUS prev_menu;
    MENUS next_menu;
    void (*func)(void);
}menu_t;

void menu_handle(void);

#endif