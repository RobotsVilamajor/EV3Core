#ifndef _DEFINES
#define _DEFINES

#define Fwd -1
#define Bwd 1
#define Lft -1
#define Rgt 1

#if defined(ROBOPRO)

// 0 1 2 3 4 5 6 7 8 9
#define REGRESSION_ARRAY { -7.07, -7.07, -7.07, -7.07, -7.07, -7.07, -7.07, -7.07, -7.07, -7.07 }
//#define RECTA_REGRESSION -7.07 // estava a zero
#define ALIGN_MIN_WHITE 70
#define ALIGN_MIN_BLACK 30
#define ALIGN_TARGET_LEFT 50
#define ALIGN_TARGET_RIGHT 50
//#define TURN_CONVERSION 165.0

#elif defined(VEATRIZ)

// 0 1 2 3 4 5 6 7 8 9
#define REGRESSION_ARRAY { 2.0, 2.0, 2.0, 2.0, 2.4, 2.4, 2.4, 2.4, 2.4, 2.4 }
//#define RECTA_REGRESSION 2.4
#define ALIGN_MIN_WHITE 70
#define ALIGN_MIN_BLACK 30
#define ALIGN_TARGET_LEFT 50
#define ALIGN_TARGET_RIGHT 50
//#define TURN_CONVERSION 152.0

#else

#error "No valid robot selected"

#endif

#endif
