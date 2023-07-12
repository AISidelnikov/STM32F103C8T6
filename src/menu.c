#include "menu.h"

char string_func[16] = {0};
string_t main_menu_str[] = {
    {
        .str 	= "   MAIN  MENU   ",
        .str_p  = NULL,
        .x	 	= 0,
        .y		= 0,
    },
    {
        .str 	= "======NEXT=====>",
        .str_p  = NULL,
        .x	 	= 0,
        .y		= 1,
    },
};

string_t accelx_menu_str[] = {
    {
        .str = "Accelrometr X:  ",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};
string_t accely_menu_str[] = {
    {
        .str = "Accelrometr Y:  ",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};
string_t accelz_menu_str[] = {
    {
        .str = "Accelrometr Z:  ",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};

string_t gyrox_menu_str[] = {
    {
        .str = "Gyroscope X:    ",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};
string_t gyroy_menu_str[] = {
    {
        .str = "Gyroscope Y:    ",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};

string_t gyroz_menu_str[] = {
    {
        .str = "Gyroscope Z:    ",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};


string_t tempc_menu_str[] = {
    {
        .str = "Temp Celsius:   ",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};
string_t tempk_menu_str[] = {
    {
        .str = "Temp Kelvin:    ",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};
string_t tempf_menu_str[] = {
    {
        .str = "Temp Fahrenheit:",
        .str_p  = NULL,
        .x = 0,
        .y = 0,
    },
    {
        .str_p = string_func,
        .x = 0,
        .y = 1,
    },
};

menu_t all_menu[ALL_MENU] = {
    [MAIN_MENU] = {
        .str = main_menu_str,
        .num_of_string = calc_len(main_menu_str),
        .prev_menu = TEMPC,
        .next_menu = ACCELX,
        .prev_pos = MAIN_MENU,
        .next_pos = MAIN_MENU,
        .func = &main_menu,
    },
    [ACCELX] = {
        .str = accelx_menu_str,
        .num_of_string = calc_len(accelx_menu_str),
        .prev_menu = MAIN_MENU,
        .next_menu = GYROX,
        .prev_pos = ACCELZ,
        .next_pos = ACCELY,
        .func = &mpu_str_accelx,
    },
    [ACCELY] = {
        .str = accely_menu_str,
        .num_of_string = calc_len(accely_menu_str),
        .prev_menu = MAIN_MENU,
        .next_menu = GYROX,
        .prev_pos = ACCELX,
        .next_pos = ACCELZ,
        .func = &mpu_str_accely,
    },
    [ACCELZ] = {
        .str = accelz_menu_str,
        .num_of_string = calc_len(accelz_menu_str),
        .prev_menu = MAIN_MENU,
        .next_menu = GYROX,
        .prev_pos = ACCELY,
        .next_pos = ACCELX,
        .func = &mpu_str_accelz,
    },
    [GYROX] = {
        .str = gyrox_menu_str,
        .num_of_string = calc_len(gyrox_menu_str),
        .prev_menu = ACCELX,
        .next_menu = TEMPC,
        .prev_pos =GYROZ,
        .next_pos = GYROY,
        .func = &mpu_str_gyrox,
    },
    [GYROY] = {
        .str = gyroy_menu_str,
        .num_of_string = calc_len(gyroy_menu_str),
        .prev_menu = ACCELX,
        .next_menu = TEMPC,
        .prev_pos =GYROX,
        .next_pos = GYROZ,
        .func = &mpu_str_gyroy,
    },
    [GYROZ] = {
        .str = gyroz_menu_str,
        .num_of_string = calc_len(gyroz_menu_str),
        .prev_menu = ACCELX,
        .next_menu = TEMPC,
        .prev_pos =GYROY,
        .next_pos = GYROX,
        .func = &mpu_str_gyroz,
    },
    [TEMPC] = {
        .str = tempc_menu_str,
        .num_of_string = calc_len(tempc_menu_str),
        .prev_menu = GYROZ,
        .next_menu = MAIN_MENU,
        .prev_pos = TEMPK,
        .next_pos = TEMPF,
        .func = &mpu_str_tempc,
    },
    [TEMPF] = {
        .str = tempf_menu_str,
        .num_of_string = calc_len(tempf_menu_str),
        .prev_menu = GYROZ,
        .next_menu = MAIN_MENU,
        .prev_pos = TEMPC,
        .next_pos = TEMPK,
        .func = &mpu_str_tempf,
    },
    [TEMPK] = {
        .str = tempk_menu_str,
        .num_of_string = calc_len(tempk_menu_str),
        .prev_menu = GYROZ,
        .next_menu = MAIN_MENU,
        .prev_pos = TEMPF,
        .next_pos = TEMPC,
        .func = &mpu_str_tempk,
    },
};


MENUS cur_menu = MAIN_MENU;
MENUS cur_pos = MAIN_MENU;
void menu_handle(void) {
    menu_t *menu_p = &all_menu[cur_menu];
    menu_p->func();
    for(uint8_t i = 0; i < menu_p->num_of_string; i++) {
        string_t *str_p = &menu_p->str[i];
        lcd_put_cur(str_p->y, str_p->x);
        lcd_send_string(str_p->str);
        lcd_send_string(str_p->str_p);
    }
}

void main_menu(void) {

}