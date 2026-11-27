// Copyright 2023 ZSA Technology Labs, Inc <@zsa>
// Copyright 2023 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    USR_NAME = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Keypad num row?
    // gui / control key
    // alt / x
    // swap to numpad layer + double tap to shortcuts
    [0] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_B,    KC_L,    KC_D,    KC_C,    KC_V,                         KC_J,    KC_Y,    KC_O,    KC_U,    KC_SCLN, KC_BSLS,
        SH_OS,   LGUI_T(KC_N),LALT_T(KC_R),LCTL_T(KC_T),LSFT_T(KC_S),KC_G,         KC_P,RSFT_T(KC_H),RCTL_T(KC_A),RALT_T(KC_E),RGUI_T(KC_I),KC_QUOTE,
        KC_LCTL, KC_X,    KC_Q,    KC_M,    KC_W,    KC_Z,                         KC_K,    KC_F,    KC_COMMA,KC_DOT,  KC_SLSH, KC_RCTL,
                                LT(1,KC_SPACE), LT(3, KC_TAB),           LT(2, KC_ENTER), LSFT_T(KC_BSPC)
    ),
    [1] = LAYOUT(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, KC_GRV,  KC_LABK, KC_RABK, KC_MINS, KC_PIPE,                      KC_QUES, KC_LCBR, KC_RCBR, KC_DLR,  KC_BSLS, KC_F12,
        _______, KC_EXLM, KC_ASTR, KC_SLASH,KC_EQL,  KC_AMPR,                      KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, KC_UNDS,
        _______, KC_TILD, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                      KC_AT,   KC_COLN, KC_COMMA,KC_DOT,  KC_QUOTE,KC_CIRC,
                                                     _______, _______,    _______, _______
    ),
    // username macro
    // rgb controls
    [2] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                                        _______, _______, _______, _______, _______, QK_BOOT,
        _______, _______, KC_MEDIA_PLAY_PAUSE,LCTL(KC_A),LCTL(KC_C),LCTL(KC_V),                      KC_PGUP, KC_HOME, KC_UP,   KC_END,  _______, KC_CAPS,
        _______, USR_NAME, LSFT(KC_LEFT_GUI),LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),LGUI(LSFT(KC_S)),        KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
        _______, _______, KC_LEFT_ALT,LALT(LSFT(KC_TAB)),LALT(KC_TAB),LGUI(LSFT(KC_T)),              _______, _______, _______, _______, _______, _______,
                                                     _______, _______,    _______, _______
    ),
    [3] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
        _______, KC_KP_SLASH, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_ASTERISK,           _______, _______, _______, _______, _______, _______,
        _______, KC_KP_MINUS, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_PLUS,               _______, _______, _______, _______, _______, _______,
        _______, KC_KP_0,     KC_KP_1, KC_KP_2, KC_KP_3, KC_PERC,                  _______, _______, _______, _______, _______, _______,
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
    &override_0
};

// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
//   [0] = LAYOUT_voyager(
//     KC_ESCAPE,      KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_4,        KC_KP_5,                                        KC_KP_6,        KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_0,        TD(DANCE_2),    
//     MT(MOD_LSFT, KC_TAB),KC_B,           KC_L,           KC_D,           KC_C,           KC_V,                                           KC_J,           KC_Y,           KC_O,           KC_U,           KC_SCLN,        KC_BSLS,        
//     LT(4, KC_BSPC), KC_N,           KC_R,           KC_T,           KC_S,           KC_G,                                           KC_P,           KC_H,           KC_A,           KC_E,           KC_I,           MT(MOD_RSFT, KC_QUOTE),
//     TD(DANCE_0),    MT(MOD_LALT, KC_X),KC_Q,           KC_M,           KC_W,           KC_Z,                                           KC_K,           KC_F,           KC_COMMA,       KC_DOT,         MT(MOD_RALT, KC_SLASH),KC_RIGHT_CTRL,  
//                                                     LT(1, KC_SPACE),TD(DANCE_1),                                    LT(2, KC_ENTER),MT(MOD_LSFT, KC_BSPC)
//   ),
//   [1] = LAYOUT_voyager(
//     KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
//     KC_TRANSPARENT, KC_GRAVE,       KC_LABK,        KC_RABK,        KC_MINUS,       KC_PIPE,                                        KC_QUES,        KC_LCBR,        KC_RCBR,        KC_DLR,         KC_BSLS,        KC_F12,         
//     KC_TRANSPARENT, KC_EXLM,        KC_ASTR,        KC_SLASH,       KC_EQUAL,       KC_AMPR,                                        KC_HASH,        KC_LPRN,        KC_RPRN,        KC_SCLN,        KC_DQUO,        KC_UNDS,        
//     KC_TRANSPARENT, KC_TILD,        KC_PLUS,        KC_LBRC,        KC_RBRC,        KC_PERC,                                        KC_AT,          KC_COLN,        KC_COMMA,       KC_DOT,         KC_QUOTE,       KC_CIRC,        
//                                                     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
//   ),
//   [2] = LAYOUT_voyager(
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PLAY_PAUSE,LCTL(KC_A),     LCTL(KC_C),     LCTL(KC_V),                                     KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_CAPS,        
//     KC_TRANSPARENT, ST_MACRO_0,     LSFT(KC_LEFT_GUI),LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   LGUI(LSFT(KC_S)),                                KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       RGB_TOG,        TOGGLE_LAYER_COLOR,
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_LEFT_ALT,    LALT(LSFT(KC_TAB)),LALT(KC_TAB),   LGUI(LSFT(KC_T)),                                KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RGB_SLD,        RGB_MODE_FORWARD,
//                                                     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
//   ),
//   [3] = LAYOUT_voyager(
//     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
//     KC_TRANSPARENT, KC_KP_SLASH,    KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK,                                 KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT, 
//     KC_TRANSPARENT, KC_KP_MINUS,    KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,                                     KC_TRANSPARENT, KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
//     KC_TRANSPARENT, KC_KP_0,        KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_PERC,                                        KC_TRANSPARENT, KC_MS_WH_DOWN,  KC_MS_BTN3,     KC_MS_WH_UP,    KC_TRANSPARENT, KC_TRANSPARENT, 
//                                                     KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_MS_BTN1,     KC_MS_BTN2
//   ),
//   [4] = LAYOUT_voyager(
//     KC_MINUS,       KC_0,           KC_9,           KC_8,           KC_7,           KC_6,                                           KC_5,           KC_4,           KC_3,           KC_2,           KC_1,           DUAL_FUNC_0,    
//     KC_TRANSPARENT, KC_SCLN,        KC_U,           KC_O,           KC_Y,           KC_J,                                           KC_V,           KC_C,           KC_D,           KC_L,           KC_B,           KC_TAB,         
//     KC_TRANSPARENT, KC_I,           KC_E,           KC_A,           KC_H,           KC_P,                                           KC_G,           KC_S,           KC_T,           KC_R,           KC_N,           MT(MOD_LSFT, KC_BSPC),
//     KC_RIGHT_CTRL,  MT(MOD_RALT, KC_SLASH),KC_DOT,         KC_COMMA,       KC_F,           KC_K,                                           KC_Z,           KC_W,           KC_M,           KC_Q,           MT(MOD_LALT, KC_X),DUAL_FUNC_1,    
//                                                     KC_BSPC,        KC_ENTER,                                       KC_TRANSPARENT, KC_SPACE
//   ),
//   [5] = LAYOUT_voyager(
//     KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_3),    
//     KC_T,           KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
//     KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
//     KC_B,           KC_G,           KC_Z,           KC_X,           KC_C,           KC_V,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
//                                                     KC_SPACE,       KC_LEFT_ALT,                                    KC_TRANSPARENT, KC_TRANSPARENT
//   ),
// };
