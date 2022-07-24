#pragma once
#include "quantum.h"

#define LAYOUT( \
	       k01, k02, k03, k04, \
	       k11, k12, k13, k14, \
	       k21, k22, k23, k24, \
	  k30, k31, k32, k33, k34 \
) \
{ \
    { KC_NO, k01, k02, k03, k04 }, \
    { KC_NO, k11, k12, k13, k14 }, \
    { KC_NO, k21, k22, k23, k24 }, \
    {   k30, k31, k32, k33, k34 }, \
}
