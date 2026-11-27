#include QMK_KEYBOARD_H

enum custom_keycodes {
    USR_NAME = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Left hand to shortcuts?
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_B,    KC_L,    KC_D,    KC_C,    KC_V,                         KC_J,    KC_Y,    KC_O,    KC_U,    KC_SCLN, KC_BSLS,
        SH_OS,   LGUI_T(KC_N),LALT_T(KC_R),LCTL_T(KC_T),LSFT_T(KC_S),KC_G,         KC_P,RSFT_T(KC_H),RCTL_T(KC_A),RALT_T(KC_E),RGUI_T(KC_I),KC_QUOTE,
        KC_LCTL, KC_X,    KC_Q,    KC_M,    KC_W,    KC_Z,                         KC_K,    KC_F,    KC_COMMA,KC_DOT,  KC_SLSH, KC_RCTL,
                                LT(1,KC_SPACE), LT(3, OSL(2)),           LT(2, KC_ENTER), LSFT_T(KC_BSPC)
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_GRV,  KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      KC_QUES, KC_LCBR, KC_RCBR, KC_DLR,  KC_BSLS, KC_F12,
        _______, KC_EXLM, KC_ASTR, KC_SLASH,KC_EQL,  KC_AMPR,                      KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, KC_UNDS,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      KC_AT,   KC_COLN, KC_COMMA,KC_DOT,  KC_QUOTE,KC_CIRC,
                                                     _______, _______,    _______, _______
    ),
    // rgb controls
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, KC_VOLD, KC_MUTE, KC_VOLU, _______,                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_CAPS,
        _______, USR_NAME,KC_MPRV, KC_MPLY, KC_MNXT, KC_WAKE,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, KC_BRID, _______, KC_BRIU, KC_SLEP,                      _______, _______, _______, _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_KP_SLASH, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK,           _______, MS_BTN1, MS_UP,   MS_BTN2, _______, _______,
        _______, KC_KP_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,               _______, MS_LEFT, MS_DOWN, MS_RGHT, _______, _______,
        _______, KC_KP_0,     KC_KP_1, KC_KP_2, KC_KP_3, KC_PERC,                  _______, MS_WHLU, MS_BTN3, MS_WHLD, _______, _______,
                                                     _______, _______,    _______, _______
    ),
    [4] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
        KC_T,    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    _______,
        KC_LCTL, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,                         KC_H,    KC_J,    KC_K,    KC_L,    _______, _______,
        KC_B,    KC_G,    KC_Z,    KC_X,    KC_C,    KC_V,                         KC_N,    KC_M,    KC_COMMA,KC_DOT,  _______, _______,
                                                     KC_SPC,  KC_LALT,    _______, _______
    ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    // "Timeless" home row mods
    if (record->event.key.row == 2 || record->event.key.row == 8) {
        return TAPPING_TERM + 50;
    }

    return TAPPING_TERM;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case USR_NAME:
            if (record->event.pressed) {
                SEND_STRING("TheNamel3s5One");
            }
            return false; 
    }
    return true;
}


// Note COMBO_ONLY_FROM_LAYER config could reduce these to one combo
const uint16_t PROGMEM GAM_ON[]  = {KC_Q, KC_M, KC_W, COMBO_END};
const uint16_t PROGMEM GAM_OFF[] = {KC_Z, KC_X, KC_C, COMBO_END};
combo_t key_combos[] = {
    COMBO(GAM_ON, TG(4)),
    COMBO(GAM_OFF, TG(4)),
};


const key_override_t override_1 = ko_make_basic(MOD_MASK_SHIFT, KC_1, KC_1);
const key_override_t override_2 = ko_make_basic(MOD_MASK_SHIFT, KC_2, KC_2);
const key_override_t override_3 = ko_make_basic(MOD_MASK_SHIFT, KC_3, KC_3);
const key_override_t override_4 = ko_make_basic(MOD_MASK_SHIFT, KC_4, KC_4);
const key_override_t override_5 = ko_make_basic(MOD_MASK_SHIFT, KC_5, KC_5);
const key_override_t override_6 = ko_make_basic(MOD_MASK_SHIFT, KC_6, KC_6);
const key_override_t override_7 = ko_make_basic(MOD_MASK_SHIFT, KC_7, KC_7);
const key_override_t override_8 = ko_make_basic(MOD_MASK_SHIFT, KC_8, KC_8);
const key_override_t override_9 = ko_make_basic(MOD_MASK_SHIFT, KC_9, KC_9);
const key_override_t override_0 = ko_make_basic(MOD_MASK_SHIFT, KC_0, KC_0);

const key_override_t override_bspc = ko_make_basic(MOD_MASK_SHIFT, KC_BSPC, KC_DEL);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
	&override_1,
    &override_2,
    &override_3,
    &override_4,
    &override_5,
    &override_6,
    &override_7,
    &override_8,
    &override_9,
    &override_0,
    &override_bspc
};
