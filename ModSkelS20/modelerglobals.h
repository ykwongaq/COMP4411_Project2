#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ZPOS, HEIGHT, ROTATE, 
	RIGHT_LEG_X_ROTATE, RIGHT_LEG_Y_ROTATE, RIGHT_LEG_Z_ROTATE,
	RIGHT_CALF_X_ROTATE, RIGHT_CALF_Y_ROTATE, RIGHT_CALF_Z_ROTATE, 
	RIGHT_FOOT_X_ROTATE, RIGHT_FOOT_Y_ROTATE, RIGHT_FOOT_Z_ROTATE,
	LEFT_LEG_X_ROTATE, LEFT_LEG_Y_ROTATE, LEFT_LEG_Z_ROTATE,
	LEFT_CALF_X_ROTATE, LEFT_CALF_Y_ROTATE, LEFT_CALF_Z_ROTATE,
	LEFT_FOOT_X_ROTATE, LEFT_FOOT_Y_ROTATE, LEFT_FOOT_Z_ROTATE,
	NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f

// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif