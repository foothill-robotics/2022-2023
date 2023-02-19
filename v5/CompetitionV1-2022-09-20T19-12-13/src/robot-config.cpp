#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller = controller(primary);
motor Right1 = motor(PORT1, ratio18_1, false);
motor Right2 = motor(PORT2, ratio18_1, false);
motor Left1 = motor(PORT11, ratio18_1, true);
motor Left2 = motor(PORT12, ratio18_1, true);

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