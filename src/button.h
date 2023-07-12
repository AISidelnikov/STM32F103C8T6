#ifndef __BUTTON_H
#define __BUTTON_H
#include "main.h"
#include "menu.h"

typedef enum {
    BTN1,
    BTN2,
    all_BTN,
    BTN0,
}BTN;

typedef enum {
    no_press,
    press,
    all_state,
}btn_state;

typedef struct {
    BTN btn;
    GPIO_TypeDef* port;
    uint16_t pin;
    btn_state prev_state;
    btn_state cur_state;
}button_t;

void btn_read_state(void);

#endif