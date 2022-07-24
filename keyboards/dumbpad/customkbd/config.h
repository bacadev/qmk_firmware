#pragma once

#include "config_common.h"

#define DEVICE_VER  0x0001

/* Column/Row IO definitions */
#define MATRIX_ROWS 4
#define MATRIX_COLS 5

#define MATRIX_ROW_PINS { F4, F5, F6, F7 }
#define MATRIX_COL_PINS { C6, D7, E6, B4, B5 }
#define UNUSED_PINS

/* Dual rotary encoders */
#define ENCODERS_PAD_A { B2, D0 }
#define ENCODERS_PAD_B { D4, D1 }

/* Column/Row IO definitions */
#define DIODE_DIRECTION COL2ROW

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Reduce tapdance required taps from 5 to 2 */
#define TAPPING_TOGGLE 2
