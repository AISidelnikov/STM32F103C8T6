#include "menu.h"

string_t main_menu_str[] = {
    {
        .str = "MAIN MENU",
        .x = 3,
        .y = 0,
    },
    {
        .str = "                ",
        .x = 0,
        .y = 0,
    },
};

string_t accelx_menu_str[] = {
    {
        .str = "Acceleration X: ",
        .x = 0,
        .y = 0,
    },
    {
        .str_p = NULL,
        .x = 0,
        .y = 0,
    }
};

menu_t all_menu[ALL_MENU] = {
    [MAIN_MENU] = {
        .str = main_menu_str,
        .num_of_string = calc_len(main_menu_str),
        .prev_menu = ACCELX,
        .next_menu = ACCELX,
    },
        [ACCELX] = {
        .str = accelx_menu_str,
        .num_of_string = calc_len(accelx_menu_str),
        .prev_menu = MAIN_MENU,
        .next_menu = MAIN_MENU,
        .func = &mpu_read_accel,
    },
};

MENUS cur_menu = MAIN_MENU;
MENUS cur_pos = MAIN_MENU;
void menu_handle(void) {
    menu_t *menu_p = &all_menu[cur_menu];
    menu_p->func();
    for(uint8_t i = 0; i < menu_p->num_of_string; i++) {
        string_t *str_p = &menu_p->str[i];
        lcd_put_cur(str_p->x, str_p->y);
        lcd_send_string(str_p->str);
        lcd_send_string(str_p->str_p);
    }
}