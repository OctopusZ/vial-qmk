#include "quantum.h"

 #if defined(RGB_MATRIX_ENABLE)
 led_config_t g_led_config = {
     {
         // Key Matrix to LED Index for center 2u
     { 0,  1,  2,  3,  4,  5,  6,  7,  8,  9,  10,  11 },
 	{ 22,  21,  20,  19,  18,  17,  16,  15,  14,  13,  12,  NO_LED },
 	{ 23,  24,  25,  26,  27,  28,  29,  30,  31,  32,  33,  NO_LED },
 	{ 41,  40,  39,  38,  NO_LED, NO_LED, 37,  NO_LED, 36,  35,  34,  NO_LED }
     }, {
         // LED Index to Physical Position, more positions due to extra leds for other layout options
         {  0,  0},{ 20, 0},{ 41, 0},{ 61, 0},{ 81, 0},{102, 0},{122, 0},{143, 0},{163, 0},{183, 0},{204, 0},{224, 0},
         {216, 21},{188,21},{168,21},{147,21},{127,21},{106,21},{ 86,21},{ 66,21},{ 45,21},{ 25,21},{ 2, 21},
         {  8, 43},{ 35,43},{ 56,43},{ 76,43},{ 96,43},{117,43},{137,43},{157,43},{178,43},{198,43},{220,43},
         {224,64},{198,64},{173,64},{137,64},{ 86,64},{ 45,64},{ 25,64},{2, 64}

     }, {
         // LED Index to Flag
         1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
         8, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
         1, 4, 4, 4, 4, 4, 4, 4, 4, 4, 1,
         1,1,1,1,1,1,1,1
     }
 };
 #endif


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    for (uint8_t i = led_min; i < led_max; i++) {
        switch(get_highest_layer(layer_state|default_layer_state)) {
            case 2:
                rgb_matrix_set_color(i, RGB_RED);
                break;
            case 1:
                rgb_matrix_set_color(i, RGB_WHITE);
                break;
            default:
                break;
        }
    }
    return false;
}

bool rgb_matrix_indicators_kb(void) {
     if(host_keyboard_led_state().caps_lock){
         rgb_matrix_set_color(22,RGB_BLUE);
     }
     return false;
}
