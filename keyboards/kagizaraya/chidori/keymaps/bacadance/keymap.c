/* Copyright 2019 ENDO Katsuhiro <ka2hiro@kagizaraya.jp>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#include "board.h"

#define KC_MAC_UNDO LGUI(KC_Z)
#define KC_MAC_CUT LGUI(KC_X)
#define KC_MAC_COPY LGUI(KC_C)
#define KC_MAC_PASTE LGUI(KC_V)

enum layer_number { _QWERTY = 0, _COLEMAK, _DVORAK, _LOWER, _RAISE, _ADJUST };

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes { QWERTY = SAFE_RANGE, COLEMAK, DVORAK };

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)



// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Esc  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  *   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |Tab   |  A   |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |  ;:  |  '"  | ?tap/hold  ;: '" when poss
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |  /   | Enter| ?tap/hold Ent/Shift when poss
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |CAPSWd| Alt  | Cmd  | Cmd  |LOWER |Space |             | Bkspc| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_QWERTY] = LAYOUT(
      KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,       KC_Y,    KC_U,  KC_I,    KC_O,    KC_P,     KC_PAST,
      KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,  KC_G,       KC_H,    KC_J,  KC_K,     KC_L,   KC_SCLN,  KC_QUOTE,
      KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,       KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH,  KC_ENTER,
      KC_CAPS,   KC_LALT, KC_LGUI, KC_LGUI, LOWER, KC_SPC,     KC_BSPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,    KC_RGHT
    ),
  /* Colemak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   F  |   P  |   G  |             |   J  |   L  |   U  |   Y  |   ;  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   R  |   S  |   T  |   D  |             |   H  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   K  |   M  |   ,  |   .  |   /  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |ADJUST| Esc  | Alt  | GUI  |LOWER |Space |             | Space| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_COLEMAK] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,              KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
      KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,              KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,              KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
      ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,            KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

  /* Dvorak
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   '  |   ,  |   .  |   P  |   Y  |             |   F  |   G  |   C  |   R  |   L  | Bksp |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |   A  |   O  |   E  |   U  |   I  |             |   D  |   H  |   T  |   N  |   S  |  /   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   ;  |   Q  |   J  |   K  |   X  |             |   B  |   M  |   W  |   V  |   Z  |Enter |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |ADJUST| Esc  | Alt  | GUI  |LOWER |Space |             | Space| RAISE| Left | Down |  Up  | Right|
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_DVORAK] = LAYOUT(
      KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,              KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
      KC_LCTL, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,              KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
      KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,              KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT,
      ADJUST,  KC_ESC,  KC_LALT, KC_LGUI, LOWER,   KC_SPC,            KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

  /* Lower
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |  (   |   )  |  *   | ? tap/hold ()[] when poss
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |      |   _  |   =  |   0  |   -  |             |   +  |   1  |   .  |   [  |   ]  |  |   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|  6   |   7  |   8  |   9  |      |             |      |   2  |   3  |   4  |   5  |   \  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |Space |             | BkSp |      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_LOWER] = LAYOUT(

      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,  KC_RPRN,   KC_PAST, 
      KC_GRV,  KC_TRNS, KC_UNDS, KC_PEQL, KC_P0,   KC_PMNS,       KC_PPLS, KC_P1,   KC_PDOT, KC_LBRC,  KC_RBRC,   KC_PIPE,
      KC_LSFT, KC_P6,   KC_P7,   KC_P8,   KC_P9,   KC_TRNS,       KC_TRNS, KC_P2,   KC_P3,   KC_P4,    KC_P5,     KC_NUBS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SPC,        KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,   KC_TRNS
    ),

  /* Raise
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |      |      |      |      |      |             | Play |BrtUp |BrtDwn|      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Ctrl |      |      |      |      |      |             | Mute | Vol+ | Vol- |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |Shift |      |      |      |      |      |             |      | Prev | Next |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_RAISE] = LAYOUT(
      KC_TAB,  KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,           KC_MPLY, KC_BRIU, KC_BRID, KC_NO, KC_NO, KC_NO,
      KC_LCTL, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,           KC_MUTE, KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO,
      KC_LSFT, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,           KC_NO,   KC_MPRV, KC_MNXT, KC_NO, KC_NO, KC_NO,
      KC_NO,   KC_NO, KC_NO, KC_NO, KC_TRNS, KC_NO,           KC_NO,   KC_TRNS, KC_NO,   KC_NO, KC_NO, KC_NO
    ),

  /* Adjust (Lower + Raise)
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |      |      |      |      |      |      |             |      |Qwerty|Colemk|Dvorak|      |Reset |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * `-----------------------------------------'             `-----------------------------------------'
   */
    [_ADJUST] = LAYOUT(
      _______, _______, _______, _______, _______, _______,          _______, QWERTY,  COLEMAK, DVORAK,  _______, RESET,
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______
    )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
    }
    return true;
}

bool led_update_user(led_t led_state) {
    board_set_led_by_index(0, LED_YELLOW, led_state.caps_lock);
    board_set_led_by_index(1, LED_YELLOW, led_state.scroll_lock);

    return false;
}
