#ifndef CONFIG_USER_H
#define CONFIG_USER_H

/* USB Device descriptor parameter */



#undef VENDOR_ID
#undef PRODUCT_ID
#undef MANUFACTURER
#undef PRODUCT
#undef DESCRIPTION
#undef MATRIX_ROWS
#undef MATRIX_COLS
#undef MATRIX_ROW_PINS
#undef MATRIX_COL_PINS
#undef UNUSED_PINS
#undef BACKLIGHT_PIN
#undef BACKLIGHT_LEVELS
#undef QMK_LED
#undef QMK_SPEAKER
#undef QMK_ESC_OUTPUT
#undef QMK_ESC_INPUT



#define VENDOR_ID       0x7371
#define PRODUCT_ID      0x1337
#define MANUFACTURER    IvoGoman
#define PRODUCT         Handwired_Planck
#define DESCRIPTION     A compact ortholinear keyboard using a pro micro|

#define QMK_LED  D3
/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

#define MATRIX_ROW_PINS { D1, D0, D4, C6 }
#define MATRIX_COL_PINS { D7, E6, B4, B5, B6, B2, B3, B1, F7, F6, F5, F4 }
#define UNUSED_PINS


#define BOOTMAGIC_LITE_ROW 1
#define BOOTMAGIC_LITE_COLUMN 0

/* number of backlight levels */
#define BACKLIGHT_LEVELS 0



#define MY_KEYMAP( \
	K000, K001, K002, K003, K004, K005, K006, K007, K008, K009, K010, K011, \
	K100, K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, \
	K200, K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, \
	K300, K301, K302, K303, K304,       K306, K307, K308, K309, K310, K311  \
) \
{ \
	{ K000,  K001,  K002,  K003,  K004,  K005,  K006,  K007,  K008,  K009,  K010,  K011 }, \
	{ K100,  K101,  K102,  K103,  K104,  K105,  K106,  K107,  K108,  K109,  K110,  K111 }, \
	{ K200,  K201,  K202,  K203,  K204,  K205,  K206,  K207,  K208,  K209,  K210,  K211 }, \
	{ K300,  K301,  K302,  K303,  K304,  KC_NO, K306,  K307,  K308,  K309,  K310,  K311 }  \
}

    /*
    k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b, \
    k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b, \
    k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b, \
    k30, k31, k32, k33, k34,    k36,   k37, k38, k39, k3a, k3b \
) \
{ \
    { k00, k01, k02, k03, k04, k05, k06, k07, k08, k09, k0a, k0b }, \
    { k10, k11, k12, k13, k14, k15, k16, k17, k18, k19, k1a, k1b }, \
    { k20, k21, k22, k23, k24, k25, k26, k27, k28, k29, k2a, k2b }, \
    { k30, k31, k32, k33, k34, KptC_NO, k36, k37, k38, k39, k3a, k3b } \
}
*/
#endif
