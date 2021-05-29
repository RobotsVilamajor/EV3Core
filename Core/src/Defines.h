#ifndef _DEFINES
#define _DEFINES

#define Fwd -1
#define Bwd 1
#define Lft -1
#define Rgt 1

#if defined(ROBOPRO)

// 0 1 2 3 4 5 6 7 8 9
#define REGRESSION_ARRAY { -5, -5, -5., -5.1, -5.1, -5.1, -5, -5.55, -5.5, -5.45 }
//#define REGRESSION_ARRAY { -9, -9, -9, -8, -6.5, -5.8, -5.7, -5.55, -5.5, -5.45 }
//#define REGRESSION_ARRAY { -7, -7, -7, -7, -6.9, -6.6, -6.6, -6.6, -6.6, -6.6 }
//#define REGRESSION_ARRAY { -12, -12, -12, -10, -8, -7.5, -7.5, -6.7, -6.6, -6.6 }
//#define REGRESSION_ARRAY { -7.7, -7.7, -7.7, -6.6, -5.2, -4.9, -4.9, -4.7, -4.9, -4.5 }
//#define RECTA_REGRESSION -7.07 // estava a zero
#define ALIGN_MIN_WHITE 70
#define ALIGN_MIN_BLACK 30
#define ALIGN_TARGET_LEFT 50
#define ALIGN_TARGET_RIGHT 50
//#define TURN_CONVERSION 165.0
#define LINE_WHITE_MIN 70

#elif defined(VEATRIZ)

// 0 1 2 3 4 5 6 7 8 9
#define REGRESSION_ARRAY {5.1, 5.1, 5, 4, 4.6, 4.4, 3.7, 3.8, 3.4, 3.4 }
//{4, 5.4, 5.1, 5.1, 4.8, 5.8, 2.3, 2.8, 3.3, 3.4 }
//#define RECTA_REGRESSION 2.4 {5.4, 5.4, 5.1, 5.1, 5.4, 5.6, 3.6, 4, 4.75, 5.8 }
#define ALIGN_MIN_WHITE 70
#define ALIGN_MIN_BLACK 30
#define ALIGN_TARGET_LEFT 50
#define ALIGN_TARGET_RIGHT 50
//#define TURN_CONVERSION 152.0
#define LINE_WHITE_MIN 50

#else

#error "No valid robot selected"

#endif

#endif
