#include "eadk.h"

static_assert(sizeof(EADK::Display::Color) == 2, "EADK::Display::Color should be 2 bytes long");
static_assert(sizeof(EADK::Display::Rect) == 8, "EADK::Display::Rect should be 4*2 bytes long");
static_assert(sizeof(EADK::Keyboard::State) == 8, "EADK::Display::State should be 64 bits long");

extern "C" {

// Display
void eadk_display_push_rect(EADK::Display::Rect rect, const EADK::Display::Color * pixels);
void eadk_display_push_rect_uniform(EADK::Display::Rect rect, EADK::Display::Color color);
void eadk_display_pull_rect(EADK::Display::Rect rect, EADK::Display::Color * pixels);
void eadk_display_draw_string(const char * text, EADK::Display::Point p, bool largeFont, EADK::Display::Color textColor, EADK::Display::Color backgroundColor);
uint8_t eadk_display_wait_for_vblank();

// Keyboard
uint64_t eadk_keyboard_scan();

// Timing
void eadk_timing_msleep(uint32_t ms);
uint64_t eadk_timing_millis();

// Misc
uint32_t eadk_random();

}

namespace EADK {

namespace Display {

void pushRect(Rect rect, const Color * pixels) {
  eadk_display_push_rect(rect, pixels);
}

void pushRectUniform(Rect rect, Color color) {
  eadk_display_push_rect_uniform(rect, color);
}

void pullRect(Rect rect, Color * pixels) {
  eadk_display_pull_rect(rect, pixels);
}

void drawString(const char * text, EADK::Display::Point p, bool largeFont, EADK::Display::Color textColor, EADK::Display::Color backgroundColor) {
  eadk_display_draw_string(text, p, largeFont, textColor, backgroundColor);
}

bool waitForVblank() {
  return eadk_display_wait_for_vblank() == 0;
}


}

namespace Keyboard {

State scan() {
  return State(eadk_keyboard_scan());
}

}

namespace Timing {

void msleep(uint32_t ms) {
  return eadk_timing_msleep(ms);
}

uint64_t millis() {
  return eadk_timing_millis();
}

}

uint32_t random() {
  return eadk_random();
}

}

