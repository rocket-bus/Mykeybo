#define GRAVE_ESC_GUI_OVERRIDE    # Always send Escape if GUI is pressed



// time in ms that counts as a "tap" for various features
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#endif
#define TAPPING_TERM 180
// #define PERMISSIVE_HOLD
