#ifndef MODEL_H
#define MODEL_H

#include <FL/gl.h>
#include <GL/glu.h>

#include "modelerview.h"

// To make a Model, we inherit off of ModelerView
class Model : public ModelerView {

public:
	Model(int x, int y, int w, int h, char *label);

	virtual void draw();

	// Functions drawing different part of the model
	void drawUpperBody();
	void drawHead();
	void drawHorn();
	void drawLeftUpperArm();
	void drawLeftLowerArm();
	void drawRightUpperArm();
	void drawRightLowerArm();
	void drawLowerBody();
	void drawRightUpperLeg();
	void drawRightLowerLeg();
	void drawRightFoot();
	void drawLeftUpperLeg();
	void drawLeftLowerLeg();
	void drawLeftFoot();

	// Angle rotated in each flame in animation
	static int LEFT_SHOULDER_MOVEMENT;
	static int RIGHT_SHOULDER_MOVEMENT;
	static int LEFT_LEG_MOVEMENT;
	static int RIGHT_LEG_MOVEMENT;
	
	// Max angle of rotate of different parts of body
	const static int LEFT_SHOULDER_X_ROTATE_MAX		=  68;
	const static int LEFT_SHOULDER_X_ROTATE_MIN		= -52;
	const static int RIGHT_SHOULDER_X_ROTATE_MAX	=  68;
	const static int RIGHT_SHOULDER_X_ROTATE_MIN	= -52;
	const static int LEFT_LEG_X_ROTATE_MAX			=  85;
	const static int LEFT_LEG_X_ROTATE_MIN			= -35;
	const static int RIGHT_LEG_X_ROTATE_MAX			=  85;
	const static int RIGHT_LEG_X_ROTATE_MIN			= -35;
private:

	unsigned char *textureImg;
	int textImgWidth;
	int textImgHeight;
	GLuint tex;
	bool firstTime;

	void rotate(const double &x, const double &y, const double &z);	// Rotate the body
	void back_rotate(const double &x, const double &y, const double &z); // Back rotate the body
	void prepare_texture();
};

#endif