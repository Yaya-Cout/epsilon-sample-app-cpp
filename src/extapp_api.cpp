#include <extapp_api.h>
#include <eadk.h>
#include <string.h>
#include <stdint.h>
#include <stdio.h>

uint64_t extapp_millis() {
    return EADK::Timing::millis();
}

void extapp_msleep(uint32_t ms) {
    EADK::Timing::msleep(ms);
}

uint64_t extapp_scanKeyboard() {
    // TODO: Improve this, it use a private member
    return EADK::Keyboard::scan().m_bitField;
}

void extapp_pushRect(int16_t x, int16_t y, uint16_t w, uint16_t h, const uint16_t * pixels) {
    EADK::Display::pushRect(EADK::Display::Rect(x, y, w, h), (EADK::Display::Color *) pixels);
}

void extapp_pushRectUniform(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t color) {
    EADK::Display::Color colors = (EADK::Display::Color) color;
    colors.m_value = color;
    EADK::Display::pushRectUniform(EADK::Display::Rect(x, y, w, h), colors);
}

void extapp_pullRect(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t * pixels) {
    // Not implemented yet by the EADK
}

const int16_t largeFontSize = 16;
const int16_t smallFontSize = 8;
int16_t extapp_drawTextLarge(const char *text, int16_t x, int16_t y, uint16_t fg, uint16_t bg, bool fake) {
    EADK::Display::Color fg_converted = (EADK::Display::Color) fg;
    fg_converted.m_value = fg;
    EADK::Display::Color bg_converted = (EADK::Display::Color) bg;
    bg_converted.m_value = bg;
    EADK::Display::drawString(text, EADK::Display::Point(x, y), true, fg_converted, bg_converted);
    return x + largeFontSize * strlen(text);
}

int16_t extapp_drawTextSmall(const char *text, int16_t x, int16_t y, uint16_t fg, uint16_t bg, bool fake) {
    EADK::Display::Color fg_converted = (EADK::Display::Color) fg;
    fg_converted.m_value = fg;
    EADK::Display::Color bg_converted = (EADK::Display::Color) bg;
    bg_converted.m_value = bg;
    EADK::Display::drawString(text, EADK::Display::Point(x, y), false, fg_converted, bg_converted);
    return x + smallFontSize * strlen(text);
}

bool extapp_waitForVblank() {
    return EADK::Display::waitForVblank();
}

void extapp_clipboardStore(const char *text) {
    // Not implemented yet by the EADK
    // TODO: Implement this, even if it's stored in a simple variable
}

const char * extapp_clipboardText() {
    // Not implemented yet by the EADK
    // TODO: Implement this, even if it's stored in a simple variable
    return "";
}

// All filesystem functions are not implemented yet by the EADK
// Implementing dummy functions
int extapp_fileListWithExtension(const char ** filenames, int maxrecords, const char * extension, int storage) {
    return 0;
}

bool extapp_fileExists(const char * filename, int storage) {
    return false;
}

bool extapp_fileErase(const char * filename, int storage) {
    return false;
}

const char * extapp_fileRead(const char * filename, size_t *len, int storage) {
    return nullptr;
}

bool extapp_fileWrite(const char * filename, const char * content, size_t len, int storage) {
    return false;
}

bool alphaActive = false;

void extapp_lockAlpha() {
    // Not implemented yet by the EADK, but we can fake it
    alphaActive = true;
}

void extapp_resetKeyboard() {
    // Not implemented yet by the EADK, but we can fake it
    alphaActive = false;
}

const int16_t translated_keys[] =
{
  // non shifted
  KEY_CTRL_LEFT,KEY_CTRL_UP,KEY_CTRL_DOWN,KEY_CTRL_RIGHT,KEY_CTRL_OK,KEY_CTRL_EXIT,
  KEY_CTRL_MENU,KEY_PRGM_ACON,KEY_PRGM_ACON,9,10,11,
  KEY_CTRL_SHIFT,KEY_CTRL_ALPHA,KEY_CTRL_XTT,KEY_CTRL_VARS,KEY_CTRL_CATALOG,KEY_CTRL_DEL,
  KEY_CHAR_EXPN,KEY_CHAR_LN,KEY_CHAR_LOG,KEY_CHAR_IMGNRY,',',KEY_CHAR_POW,
  KEY_CHAR_SIN,KEY_CHAR_COS,KEY_CHAR_TAN,KEY_CHAR_PI,KEY_CHAR_ROOT,KEY_CHAR_SQUARE,
  '7','8','9','(',')',-1,
  '4','5','6','*','/',-1,
  '1','2','3','+','-',-1,
  '0','.',KEY_CHAR_EXPN10,KEY_CHAR_ANS,KEY_CTRL_EXE,-1,
  // shifted
  KEY_SHIFT_LEFT,KEY_CTRL_PAGEUP,KEY_CTRL_PAGEDOWN,KEY_SHIFT_RIGHT,KEY_CTRL_OK,KEY_CTRL_EXIT,
  KEY_CTRL_MENU,KEY_PRGM_ACON,KEY_PRGM_ACON,9,10,11,
  KEY_CTRL_SHIFT,KEY_CTRL_ALPHA,KEY_CTRL_CUT,KEY_CTRL_CLIP,KEY_CTRL_PASTE,KEY_CTRL_AC,
  KEY_CHAR_LBRCKT,KEY_CHAR_RBRCKT,KEY_CHAR_LBRACE,KEY_CHAR_RBRACE,'_',KEY_CHAR_STORE,
  KEY_CHAR_ASIN,KEY_CHAR_ACOS,KEY_CHAR_ATAN,'=','<','>',
  KEY_CTRL_F7,KEY_CTRL_F8,KEY_CTRL_F9,KEY_CTRL_F13,KEY_CTRL_F14,-1,
  KEY_CTRL_F4,KEY_CTRL_F5,KEY_CTRL_F6,KEY_CHAR_FACTOR,'%',-1,
  KEY_CTRL_F1,KEY_CTRL_F2,KEY_CTRL_F3,KEY_CHAR_NORMAL,'\\',-1,
  KEY_CTRL_F10,KEY_CTRL_F11,KEY_CTRL_F12,KEY_SHIFT_ANS,KEY_CTRL_EXE,-1,
  // alpha
  KEY_CTRL_LEFT,KEY_CTRL_UP,KEY_CTRL_DOWN,KEY_CTRL_RIGHT,KEY_CTRL_OK,KEY_CTRL_EXIT,
  KEY_CTRL_MENU,KEY_PRGM_ACON,KEY_PRGM_ACON,9,10,11,
  KEY_CTRL_SHIFT,KEY_CTRL_ALPHA,':',';','"',KEY_CTRL_DEL,
  'a','b','c','d','e','f',
  'g','h','i','j','k','l',
  'm','n','o','p','q',-1,
  'r','s','t','u','v',-1,
  'w','x','y','z',' ',-1,
  '?','!',KEY_CHAR_EXPN10,KEY_CHAR_ANS,KEY_CTRL_EXE,-1,
  // alpha shifted
  KEY_SHIFT_LEFT,KEY_CTRL_PAGEUP,KEY_CTRL_PAGEDOWN,KEY_SHIFT_RIGHT,KEY_CTRL_OK,KEY_CTRL_EXIT,
  KEY_CTRL_MENU,KEY_PRGM_ACON,KEY_PRGM_ACON,9,10,11,
  KEY_CTRL_SHIFT,KEY_CTRL_ALPHA,':',';','\'','%',
  'A','B','C','D','E','F',
  'G','H','I','J','K','L',
  'M','N','O','P','Q',-1,
  'R','S','T','U','V',-1,
  'W','X','Y','Z',' ',-1,
  '?','!',KEY_CHAR_EXPN10,KEY_CHAR_ANS,KEY_CTRL_EXE,-1,
};

int extapp_getKey(int allowSuspend, bool *alphaWasActive) {
    // Not implemented yet by the EADK, but we can fake it
    if (alphaWasActive) {
        *alphaWasActive = alphaActive;
    }
    // return KEY_CTRL_RIGHT;
    // TODO: Add allowSuspend support EADK api add it
    // Get the key
    while (true) {
        uint64_t key = extapp_scanKeyboard();
        // There are 54 keys in the keyboard, but we have more with the alpha and shift modes
        // Shift mode is not implemented yet
        // TODO: Add support for the shift mode
        bool shiftActive = false;
        alphaActive = false;
        // Get the key number :
        // 1 << 14 will give us the key number 14
        // 1 << 20 will give us the key number 20
        // We need to find the shift bit from the scancode
        int shiftBit = 0;
        while (key != 1) {
            // Set a maximum 100 times to avoid an infinite loop
            if (shiftBit > 100) {
                return -1;
            }
            shiftBit++;
            key = key >> 1;
        }
        key = shiftBit;
        // key = 3;
        // return translated_keys[3];
        // Ignore if key is not in the list
        if (key < 0 || key > 54) {
            continue;
        }
        // Handle special keys
        // TODO: Backlight for power key ?
        if (key == SCANCODE_Backspace || key == SCANCODE_OK || key == SCANCODE_Back || key == SCANCODE_EXE) {
            extapp_resetKeyboard();
        }
        // Case 1: If the key is in the normal mode, we can return it directly
        if ((!alphaActive) && (!shiftActive)) {
            return translated_keys[key + (54 * 0)];
        }
        // Case 2: If the key is in the alpha mode, we need to translate it
        if (alphaActive && (!shiftActive)) {
            return translated_keys[key + (54 * 1)];
        }
        // Case 3: If the key is in the shift mode, we need to translate it
        if ((!alphaActive) && shiftActive) {
            return translated_keys[key + (54 * 2)];
        }
        // Case 4: If the key is in the alpha shift mode, we need to translate it
        if (alphaActive && shiftActive) {
            return translated_keys[key + (54 * 3)];
        }
    }
}

bool extapp_isKeydown(int key) {
    return EADK::Keyboard::scan().keyDown((EADK::Keyboard::Key)key);
}

int extapp_restorebackup(int mode) {
    // Not implemented yet by the EADK
    return 0;
}

bool extapp_erasesector(void * ptr) {
    // Not implemented yet by the EADK
    return false;
}

bool extapp_writesector(unsigned char * dest,const unsigned char * data,size_t length) {
    // Not implemented yet by the EADK
    return false;
}

bool extapp_inexammode() {
    // Not implemented yet by the EADK, but external apps are not allowed in exam mode
    return false;
}