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
	XPOS, YPOS, ZPOS, HEIGHT, 
	HEAD_X_ROTATE,HEAD_Y_ROTATE,HEAD_Z_ROTATE,
	LEFT_SHOULDER_X_ROTATE, LEFT_SHOULDER_Y_ROTATE, LEFT_SHOULDER_Z_ROTATE,
	LEFT_ALBOW_X_ROTATE, LEFT_ALBOW_Y_ROTATE, LEFT_ALBOW_Z_ROTATE,
	LEFT_WRIST_X_ROTATE, LEFT_WRIST_Y_ROTATE, LEFT_WRIST_Z_ROTATE,
	RIGHT_SHOULDER_X_ROTATE, RIGHT_SHOULDER_Y_ROTATE, RIGHT_SHOULDER_Z_ROTATE,
	RIGHT_ALBOW_X_ROTATE, RIGHT_ALBOW_Y_ROTATE, RIGHT_ALBOW_Z_ROTATE,
	RIGHT_WRIST_X_ROTATE, RIGHT_WRIST_Y_ROTATE, RIGHT_WRIST_Z_ROTATE,
	WHOLE_UPPER_BODY_ROTATE, PICKING, 
	
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