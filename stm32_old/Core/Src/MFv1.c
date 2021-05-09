#include "MFv1.h"
#include "axis.h"
#include "main.h"

void MFv1_Collibrate_Direction () {
    const uint32_t time_rotate  = 300; // msec
    const  int32_t angle_rotate = PI_QUAD_URAD;

    for (uint16_t i = 0; i < NUMBER_STEP_MOTORS; ++i) {
        AxisRotate (i, +angle_rotate, time_rotate * 1000);
        LL_mDelay (20 * time_rotate);

        AxisRotate (i, -angle_rotate, time_rotate * 1000);
        LL_mDelay (20 * time_rotate);
    }
}