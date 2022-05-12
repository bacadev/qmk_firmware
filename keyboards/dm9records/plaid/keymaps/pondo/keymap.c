#include QMK_KEYBOARD_H

enum plaid_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST
};

enum plaid_keycodes {
    QWERTY = SAFE_RANGE,
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_9,
    LED_0
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

// array of keys considered modifiers for led purposes
const uint16_t modifiers[] = {
    KC_LCTL,
    KC_RCTL,
    KC_LALT,
    KC_RALT,
    KC_LSFT,
    KC_RSFT,
    KC_LGUI,
    KC_RGUI,
    LOWER,
    RAISE
};

//Setup consts for LED modes
#define LEDMODE_ON 1 //always on
#define LEDMODE_OFF 0 //always off
#define LEDMODE_MODS 2 //On with modifiers
#define LEDMODE_BLINKIN 3 //blinkinlights - % chance toggle on keypress
#define LEDMODE_KEY 4 //On with any keypress, off with key release
#define LEDMODE_ENTER 5 // On with enter key

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |Space | Bspc |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_plaid_grid(
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_DEL ,
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_ENT ,
    KC_LCTL, KC_RALT, KC_LALT, KC_LGUI, LOWER  , KC_SPC , KC_BSPC, RAISE  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |Space | Bspc |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_plaid_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |Space | Bspc |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_plaid_grid(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |Reset |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | RAlt | Alt  | GUI  |Lower |Space | Bspc |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_plaid_grid(
    RESET  , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};

//Setup config struct for LED
typedef union {
    uint32_t raw;
    struct {
        uint8_t  red_mode :8;
        uint8_t  green_mode :8;
    };
} led_config_t;
led_config_t led_config;

//Set leds to saved state during powerup
void keyboard_post_init_user(void) {
    // set LED pin modes
    setPinOutput(LED_RED);
    setPinOutput(LED_GREEN);

    // Call the post init code.
    led_config.raw = eeconfig_read_user();

    if(led_config.red_mode == LEDMODE_ON) {
        writePinHigh(LED_RED);
    }

    if(led_config.green_mode == LEDMODE_ON) {
        writePinHigh(LED_GREEN);
    }
}

void eeconfig_init_user(void) {  // EEPROM is getting reset! 
    led_config.raw = 0;
    led_config.red_mode = LEDMODE_ON;
    led_config.green_mode = LEDMODE_MODS;
        eeconfig_update_user(led_config.raw);
    eeconfig_update_user(led_config.raw);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

void led_keypress_update(uint8_t led, uint8_t led_mode, uint16_t keycode, keyrecord_t *record) {
    switch (led_mode) {
      case LEDMODE_MODS:
        for (int i = 0; i < sizeof(modifiers) / sizeof(modifiers[0]); i++) {
            if (keycode == modifiers[i]) {
                if (record->event.pressed) writePinHigh(led);
                else writePinLow(led);
            }
        }
        break;

      case LEDMODE_BLINKIN:
        if (!record->event.pressed) return;

        if (rand() % 2 == 1) {
            if (rand() % 2 == 0) writePinLow(led);
            else writePinHigh(led);
        }
        break;

      case LEDMODE_KEY:
        if (record->event.pressed) writePinHigh(led);
        else writePinLow(led);
        break;

      case LEDMODE_ENTER:
        if (keycode == KC_ENT) writePinHigh(led);
        else writePinLow(led);
        break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    /* If the either led mode is keypressed based, call the led updater
        then let it fall through the keypress handlers. Just to keep 
        the logic out of this procedure */
    if (led_config.red_mode >= LEDMODE_MODS && led_config.red_mode <= LEDMODE_ENTER) {
        led_keypress_update(LED_RED, led_config.red_mode, keycode, record);
    }

    if (led_config.green_mode >= LEDMODE_MODS && led_config.green_mode <= LEDMODE_ENTER) {
        led_keypress_update(LED_GREEN, led_config.green_mode, keycode, record);
    }

    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case LED_1:
            if (record->event.pressed) {
                    if (led_config.red_mode == LEDMODE_ON) {
                        led_config.red_mode = LEDMODE_OFF;
                        writePinLow(LED_RED);
                    } else {
                        led_config.red_mode=LEDMODE_ON;
                        writePinHigh(LED_RED);
                    }
            }
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_2:
            if (record->event.pressed) {
                if (led_config.green_mode==LEDMODE_ON) {
                    led_config.green_mode=LEDMODE_OFF;
                    writePinLow(LED_GREEN);
                }
                else {
                    led_config.green_mode=LEDMODE_ON;
                    writePinHigh(LED_GREEN);
                }
            }
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_3:
            led_config.red_mode = LEDMODE_MODS;
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_4:
            led_config.green_mode = LEDMODE_MODS;
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_5:
            led_config.red_mode = LEDMODE_BLINKIN;
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_6:
            led_config.green_mode = LEDMODE_BLINKIN;
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_7:
            led_config.red_mode = LEDMODE_KEY;
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_8:
            led_config.green_mode = LEDMODE_KEY;
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_9:
            led_config.red_mode = LEDMODE_ENTER;
            eeconfig_update_user(led_config.raw);
            return false;

        case LED_0:
            led_config.green_mode = LEDMODE_ENTER;
            eeconfig_update_user(led_config.raw);
            return false;
    }

    return true;
}
