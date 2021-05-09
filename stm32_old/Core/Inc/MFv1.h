#ifndef MF1_H
#define MF1_H

#include "StepMotorParams.h"

#define PHI1_START_POSITION -PI_HALF_URAD
#define PHI2_START_POSITION 0
#define PHI3_START_POSITION 0

#define GEAR_0_LEADING_NUM_TEETH    11
#define GEAR_0_SLAVE_NUM_TEETH      45

#define GEAR_1_LEADING_NUM_TEETH    11
#define GEAR_1_SLAVE_NUM_TEETH      45

#define GEAR_2_LEADING_NUM_TEETH    21
#define GEAR_2_SLAVE_NUM_TEETH      45

// All directions of rotation, including motors, 
// are determined by the rule of the right screw

#define MOTOR_0_DIRECTION_ROTATION +1
#define MOTOR_1_DIRECTION_ROTATION -1
#define MOTOR_2_DIRECTION_ROTATION +1

void MFv1_Collibrate_Direction ();

#endif // MF1_H