#ifndef _DEFINES
#define _DEFINES

#define Fwd -1
#define Bwd 1
#define Lft -1
#define Rgt 1

#if defined(ROBOPRO)

#define RECTA_REGRESSION 0
#define ALIGN_MIN_WHITE 70
#define ALIGN_MIN_BLACK 30
#define ALIGN_TARGET_LEFT 50
#define ALIGN_TARGET_RIGHT 50
#define TURN_CONVERSION 165.0

#elif defined(VEATRIZ)

#define RECTA_REGRESSION 8.8
#define ALIGN_MIN_WHITE 70
#define ALIGN_MIN_BLACK 30
#define ALIGN_TARGET_LEFT 50
#define ALIGN_TARGET_RIGHT 50
#define TURN_CONVERSION 152

#else

#error "No valid robot selected"

#endif

#endif
