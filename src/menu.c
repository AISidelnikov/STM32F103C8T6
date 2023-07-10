#include "menu.h"

static menu_t menu[ALL_MENU] = {
    {
        .name_menu = MAIN_MENU,
        .prev_menu = NO_MENU,
        .next_menu = ACCELX,
        .str = "MAIN MENU",
        .row = 0,
        .col = 3,
    },
    {
        .name_menu = ACCELX,
        .prev_menu = MAIN_MENU,
        .next_menu = ACCELY,
        .str = "ACCELX: ",
        .row = 0,
        .col = 0,
    },
};

static MENUS cur_menu = MAIN_MENU;
void menu_action(void) {
    lcd_put_cur(menu[cur_menu].col, menu[cur_menu].row);
    lcd_send_string(menu[cur_menu].str);
}