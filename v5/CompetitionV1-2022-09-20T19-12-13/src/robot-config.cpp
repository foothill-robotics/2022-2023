#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller1 = controller(primary);
motor Right1 = motor(PORT9, ratio18_1, false);
motor Right2 = motor(PORT10, ratio18_1, false);
motor Left1 = motor(PORT19, ratio18_1, true);
motor Left2 = motor(PORT20, ratio18_1, true);
motor fly1 = motor(PORT8, ratio18_1, true);
motor fly2 = motor(PORT7, ratio18_1, false);
motor intakeb = motor(PORT17, ratio18_1, false);
motor intaket = motor(PORT18, ratio18_1, false);

motor_group flywheel = motor_group(fly1, fly2);
digital_out pneum = digital_out(Brain.ThreeWirePort.A);

bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void)
{
  // Nothing to initialize
}