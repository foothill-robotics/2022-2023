/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\socce                                            */
/*    Created:      Tue Sep 20 2022                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
extern controller Controller1;
extern motor Left1;
extern motor Left2;
extern motor Right1;
extern motor Right2;

void driveControl()
{
  double speed = -Controller1.Axis3.value();
  double turn = Controller1.Axis1.value();
  double strafe = Controller1.Axis4.value();

  Left1.spin(forward, speed + turn + strafe, pct);
  Left2.spin(forward, speed + turn - strafe, pct);
  Right1.spin(forward, speed - turn - strafe, pct);
  Right2.spin(forward, speed - turn + strafe, pct);
}

void userControl()
{
  while (1)
  {
    driveControl();
  }
}

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}
