#ifndef __APP_MAIN_H
#define __APP_MAIN_H
#include "main.h"
#include "lcd1602.h"
#include "button.h"
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
    MENUS name_menu;
    uint8_t col;
    uint8_t row;
    char *str;
    MENUS prev_menu;
    MENUS next_menu;
}menu_t;

void menu_action(void);

#endif