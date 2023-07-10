#include "button.h"

static button_t btn[all_BTN] = {
    {
        .btn = BTN1,
        .port = BTN1_GPIO_Port,
        .pin = BTN1_Pin,
        .prev_state = no_press,
        .cur_state = no_press,
    },
    {
        .btn = BTN2,
        .port = BTN2_GPIO_Port,
        .pin = BTN2_Pin,
        .prev_state = no_press,
        .cur_state = no_press,
    },
};

BTN btn_read_state(void) {
    for(uint8_t i = 0; i < all_BTN; i++) {
        btn_state b = HAL_GPIO_ReadPin(btn[i].port, btn[i].pin);
        btn[i].prev_state = btn[i].cur_state;
        btn[i].cur_state = b;
        
        if(btn[i].prev_state == no_press && btn[i].cur_state == press) {
            HAL_GPIO_TogglePin(LED_GPIO_Port, LED_Pin);
            return btn[i].btn;
        }
        else {
            return BTN0;
        }
    }
}