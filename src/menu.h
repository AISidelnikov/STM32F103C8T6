#ifndef __APP_MAIN_H
#define __APP_MAIN_H
#include "main.h"

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
}MENUS;

typedef struct {
    uint8_t col;
    uint8_t row;
    MENUS prev_menu;
    MENUS cur_menu;
}menu_t;



#endif