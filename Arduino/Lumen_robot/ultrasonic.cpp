/*
Ultrasonic sensor functions
*/
#include <MinimalUltrasonic.h>


#define UL1_TRIG 32
#define UL1_ECHO 33

#define UL2_TRIG 34
#define UL2_ECHO 35

#define UL3_TRIG 36
#define UL3_ECHO 37

#define UL4_TRIG 38
#define UL4_ECHO 39

#define UL5_TRIG 40
#define UL5_ECHO 41

#define UL6_TRIG 42
#define UL6_ECHO 43

void ultrasonic_setup() {
    MinimalUltrasonic front_L(UL1_TRIG, UL1_ECHO);
    MinimalUltrasonic front_M(UL2_TRIG, UL2_ECHO);
    MinimalUltrasonic front_R(UL3_TRIG, UL3_ECHO);
    MinimalUltrasonic left(UL4_TRIG, UL4_ECHO);
    MinimalUltrasonic right(UL5_TRIG, UL5_ECHO);
    MinimalUltrasonic back(UL6_TRIG, UL6_ECHO);
}
