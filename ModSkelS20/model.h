#ifndef MODEL_H
#define MODEL_H

#include "modelerview.h"

// To make a Model, we inherit off of ModelerView
class Model : public ModelerView {

public:
	Model(int x, int y, int w, int h, char *label)
		: ModelerView(x, y, w, h, label) {}

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

private:
	void rotate(const double &x, const double &y, const double &z);	// Rotate the body
	void back_rotate(const double &x, const double &y, const double &z); // Back rotate the body
};

#endif