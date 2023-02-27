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

vex::competition Competition;

extern controller Controller1;
extern motor Left1;
extern motor Left2;
extern motor Right1;
extern motor Right2;
extern motor_group flywheel;
extern motor intakeb;
extern motor intaket;

extern digital_out pneum;

void pneum_test()
{
  while (1)
  {
    if (Controller1.ButtonA.pressing())
    {
      pneum.set(false);
    }
    else if (Controller1.ButtonB.pressing())
    {
      pneum.set(true);
    }
  }
}

void test()
{
  while (1)
  {
    if (Controller1.ButtonA.pressing())
    {
      Left1.spin(reverse, 100, pct);
      Left2.spin(reverse, 100, pct);
      Right1.spin(reverse, 100, pct);
      Right2.spin(reverse, 100, pct);
      intakeb.spin(reverse, 100, pct);
      wait(1000, msec);
      Left1.stop();
      Left2.stop();
      Right1.stop();
      Right2.stop();
      wait(5000, msec);
      intakeb.stop();
    }
  }
}

void driveControl()
{
  double speed = -Controller1.Axis3.value();
  double turn = Controller1.Axis1.value();
  double strafe = Controller1.Axis4.value();

  Left1.spin(reverse, speed + turn + strafe, pct);
  Left2.spin(reverse, speed + turn - strafe, pct);
  Right1.spin(reverse, speed - turn - strafe, pct);
  Right2.spin(reverse, speed - turn + strafe, pct);
  if (Controller1.ButtonA.pressing())
  {
    intakeb.spin(reverse, 100, pct);
    intaket.spin(reverse, 100, pct);
    flywheel.spin(forward, 100, pct);
  }
  else if (Controller1.ButtonX.pressing())
  {
    intakeb.spin(forward, 100, pct);
    intaket.stop();
  }
  else
  {
    intakeb.stop();
    intaket.stop();
    flywheel.stop();
  }

  if (Controller1.ButtonY.pressing())
  {
    pneum.set(true);
  }
  else
  {
    pneum.set(false);
  }
}
void userControl()
{
  while (1)
  {
    driveControl();
  }
}

void auton()
{
  Left1.spin(reverse, 100, pct);
  Left2.spin(reverse, 100, pct);
  Right1.spin(reverse, 100, pct);
  Right2.spin(reverse, 100, pct);
  intakeb.spin(reverse, 100, pct);
  wait(1000, msec);
  Left1.stop();
  Left2.stop();
  Right1.stop();
  Right2.stop();
  wait(5000, msec);
  intakeb.stop();
}

int main()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  // test();
  Competition.autonomous(auton);
  Competition.drivercontrol(userControl);
  // userControl();
  // pneum_test();
}
