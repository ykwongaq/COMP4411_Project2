#include <FL/gl.h>
#include <cmath>

#include "model.h"
#include "modelerview.h"
#include "modelerdraw.h"
#include "modelerglobals.h"
#include "modelerapp.h"
#include "modelerapp.h"
#include "camera.h"

int Model::LEFT_SHOULDER_MOVEMENT	= 1;
int Model::RIGHT_SHOULDER_MOVEMENT	= 1;
int Model::LEFT_LEG_MOVEMENT	= 1;
int Model::RIGHT_LEG_MOVEMENT	= -1;

// Draw uppper body of the robot
void Model::drawUpperBody() {
	drawTriangle(4, 0, -6, 2, 0, -2, 0, 3, -4.3);
	drawTriangle(-4, 0, -6, -2, 0, -2, 0, 3, -4.3);
	drawTriangle(-4, 0, -6,	0, -3, -7, 0, 3, -4.3);
	drawTriangle(4, 0, -6, 0, -3, -7, 0, 3, -4.3);
	drawTriangle(0, -2, -1.5, 2, 0, -2, 0, 3, -4.3);
	drawTriangle(0, -2, -1.5, -2, 0, -2, 0, 3, -4.3);
	drawTriangle(4, 0, -6, 2, 0, -2, 0, -3.5, -5);
	drawTriangle(-4, 0, -6, -2, 0, -2, 0, -3.5, -5);
	drawTriangle(-4, 0, -6, 0, -3, -7, 0, -3.5, -5);
	drawTriangle(4, 0, -6, 0, -3, -7, 0, -3.5, -5);
	drawTriangle(0, -1.75, -2, 2, 0, -2, 0, -3.5, -5);
	drawTriangle(0, -1.75, -2, -2, 0, -2, 0, -3.5, -5);
	drawTriangle(0, -1.75, -2, 0, -2, -1.5, 2, 0, -2);
	drawTriangle(0, -1.75, -2, 0, -2, -1.5, -2, 0, -2);
}

// Draw the head of the robot
void Model::drawHead() {
	drawSphere(0.3);
	drawTriangle(0, 0, -2.6, 0.8, 0, 0, 0, 3.5, 0);
	drawTriangle(0, 0, -2.6, 0, 3.5, 0, -0.8, 0, 0);
	drawTriangle(0.8, 0, -2, 0, 0, -1.5, 0, 3.5, 0);
	drawTriangle(-0.8, 0, -2, 0, 0, -1.5, 0, 3.5, 0);
	drawTriangle(0.8, 0, -2, 1.6, -1, -0.1, 0, 3.5, 0);
	drawTriangle(-0.8, 0, -2, -1.6, -1, -0.1, 0, 3.5, 0);
	drawTriangle(-0.8, 0, -2, -1.6, -1, -0.1, 0, -1.5, 0);
	drawTriangle(0.8, 0, -2, 1.6, -1, -0.1, 0, -1.5, 0);
	drawTriangle(-0.8, 0, -2, 0.8, 0, -2, 0, -1.5, 0);
	drawTriangle(0, 0, 0.45, 1.6, -1, -0.1, 0, 3.5, 0);
	drawTriangle(-1.6, -1, -0.1, 0, 0, 0.45, 0, 3.5, 0);
}

// Draw the horn of the robot
void Model::drawHorn() {
	drawTriangle(-0.25, -1.5, -0.75, 0.25, -1.5, -0.75, 0, -1.5, -3);
	drawTriangle(-0.25, -1.5, -0.75, -1.4, -1.4, -1.5, 0, -1.5, -1.5);
	drawTriangle(0.25, -1.5, -0.75, 1.4, -1.4, -1.5, 0, -1.5, -1.5);
	drawTriangle(1.6, -1.25, -3.5, 1.4, -1.4, -1.5, 0.25, -1.5, -0.75);
	drawTriangle(-1.6, -1.25, -3.5, -1.4, -1.4, -1.5, -0.25, -1.5, -0.75);
}

// Draw the left arm of the robot
void Model::drawLeftUpperArm() {
	drawTriangle(-0.15, 0, -1.5, 0.2, 0.25, 0.5, 0.6, 0, 0.5);
	drawTriangle(-0.15, 0, -1.5, 0.2, -0.25, 0.5, 0.6, 0, 0.5);
	drawTriangle(0.4, 0, 1.25, 0.2, -0.25, 0.5, 0.6, 0, 0.5);
	drawTriangle(0.4, 0, 1.25, 0.2, 0.25, 0.5, 0.6, 0, 0.5);
	drawTriangle(0, 0, -0.5, 0.2, 0.25, 0.5, 0, 1.5, 0.6);
	drawTriangle(0, 0, -0.5, 0.2, -0.25, 0.5, 0, -1.5, 0.6);
	drawTriangle(0.4, 1.2, 0.85, 0.2, 0.25, 0.5, 0, 1.5, 0.6);
	drawTriangle(0.4, -1.2, 1, 0.2, -0.25, 0.5, 0, -1.5, 0.6);
	drawTriangle(0.4, 1.2, 0.85, 0.2, 0.25, 0.5, 0.4, 0, 1.25);
	drawTriangle(0.4, -1.2, 1, 0.2, -0.25, 0.5, 0.4, 0, 1.25);
	drawTriangle(0.4, -1.2, 1, 0.2, 0, 3.25, 0.4, 0, 1.25);
	drawTriangle(0.4, 1.2, 0.85, 0.2, 0, 3.25, 0.4, 0, 1.25);
	drawTriangle(0.4, 1.2, 0.85, 0.2, 0, 3.25, 0.6, 0.9, 3.4);
	drawTriangle(0.4, 1.2, 0.85, 0.8, 1.4, 2.4, 0.6, 0.9, 3.4);
	drawTriangle(0.4, -1.2, 1, 0.2, 0, 3.25, 0.4, -1, 3);
	drawTriangle(0.75, -0.8, 3.3, 0.2, 0, 3.25, 0.4, -1, 3);
	drawTriangle(0.75, -0.8, 3.3, 0.2, 0, 3.25, 0.65, -0.4, 3.6);
	drawTriangle(1.2, 0, 4, 0.2, 0, 3.25, 0.65, -0.4, 3.6);
	drawTriangle(1.2, 0, 4, 0.6, 0.9, 3.4, 0.2, 0, 3.25);
	drawTriangle(1.2, 0, 4, 0.6, 0.9, 3.4, 1.4, 0, 3.4);
	drawTriangle(1.2, 0, 4, 0.65, 0.4, 3.6, 1.4, 0, 3.4);
	drawTriangle(1.2, 0, 4, 0.65, 0.4, 3.6, 1.4, 0, 3.4);
	drawTriangle(0.75, -0.8, 3.3, 0.65, -0.4, 3.6, 1.4, 0, 3.4);
	drawTriangle(1.2, 0, 4, 0.65, -0.4, 3.6, 1.4, 0, 3.4);
	drawTriangle(0.75, -0.8, 3.3, 0.4, -1.2, 1, 1.4, 0, 3.4);
	drawTriangle(0.9, 1, 2.7, 0.6, 0.9, 3.4, 1.4, 0, 3.4);
	drawTriangle(0.9, 1, 2.7, 0.4, 1.2, 0.75, 1.4, 0, 3.4);
	drawTriangle(0.75, -0.8, 3.3, 0.4, -1.2, 1, 0.4, -1, 3);
	drawTriangle(0.8, 1.4, 2.4, 0.9, 1, 2.7, 0.6, 0.9, 3.4);
	drawTriangle(0.8, 1.4, 2.4, 0.9, 1, 2.7, 0.4, 1.2, 0.85);
	drawTriangle(0.4, 1.2, 0.85, 0.9, 1, 2.7, 0.3, 0, 1);
	drawTriangle(1.5, 0, 1, 1.4, 0, 3.4, 0.4, 1.2, 0.85);
	drawTriangle(1.5, 0, 1, 1.4, 0, 3.4, 0.4, -1.2, 1);
	drawTriangle(1.5, 0, 1, 2, 0, 0.2, 0.4, -1.2, 1);
	drawTriangle(1.5, 0, 1, 2, 0, 0.2, 0.4, 1.2, 0.85);
	drawTriangle(0, 1.5, 0.6, 2, 0, 0.2, 0.4, 1.2, 0.85);
	drawTriangle(0, 1.5, 0.6, 2, 0, 0.2, 0, 0, -0.5);
	drawTriangle(0, -1.5, 0.6, 2, 0, 0.2, 0, 0, -0.5);
	drawTriangle(0, -1.5, 0.6, 2, 0, 0.2, 0.4, -1.2, 1);
}

void Model::drawLeftLowerArm() {
	drawTriangle(0.2, 0, -0.2, 0.8, 0, 1, 0, 0.6, 0.65);
	drawTriangle(0.2, 0, -0.2, 0.8, 0, 1, 0, -0.6, 0.65);
	drawTriangle(0.2, 0, -0.2, -0.3, 0, 0.5, 0, 0.6, 0.65);
	drawTriangle(0.2, 0, -0.2, -0.3, 0, 0.5, 0, -0.6, 0.65);
	drawTriangle(-0.5, 0, 3.25, 0.8, 0, 1, 0, 0.6, 0.65);
	drawTriangle(-0.5, 0, 3.25, 0.8, 0, 1, 0, -0.6, 0.65);
	drawTriangle(-0.5, 0, 3.25, -0.3, 0, 0.5, 0, 0.6, 0.65);
	drawTriangle(-0.5, 0, 3.25, -0.3, 0, 0.5, 0, -0.6, 0.65);
}

void Model::drawRightUpperArm() {
	drawTriangle(0.15, 0, -1.5, -0.2, 0.25, 0.5, -0.6, 0, 0.5);
	drawTriangle(0.15, 0, -1.5, -0.2, -0.25, 0.5, -0.6, 0, 0.5);
	drawTriangle(-0.4, 0, 1.25, -0.2, -0.25, 0.5, -0.6, 0, 0.5);
	drawTriangle(-0.4, 0, 1.25, -0.2, 0.25, 0.5, -0.6, 0, 0.5);
	drawTriangle(-0, 0, -0.5, -0.2, 0.25, 0.5, -0, 1.5, 0.6);
	drawTriangle(-0, 0, -0.5, -0.2, -0.25, 0.5, -0, -1.5, 0.6);
	drawTriangle(-0.4, 1.2, 0.85, -0.2, 0.25, 0.5, -0, 1.5, 0.6);
	drawTriangle(-0.4, -1.2, 1, -0.2, -0.25, 0.5, -0, -1.5, 0.6);
	drawTriangle(-0.4, 1.2, 0.85, -0.2, 0.25, 0.5, -0.4, 0, 1.25);
	drawTriangle(-0.4, -1.2, 1, -0.2, -0.25, 0.5, -0.4, 0, 1.25);
	drawTriangle(-0.4, -1.2, 1, -0.2, 0, 3.25, -0.4, 0, 1.25);
	drawTriangle(-0.4, 1.2, 0.85, -0.2, 0, 3.25, -0.4, 0, 1.25);
	drawTriangle(-0.4, 1.2, 0.85, -0.2, 0, 3.25, -0.6, 0.9, 3.4);
	drawTriangle(-0.4, 1.2, 0.85, -0.8, 1.4, 2.4, -0.6, 0.9, 3.4);
	drawTriangle(-0.4, -1.2, 1, -0.2, 0, 3.25, -0.4, -1, 3);
	drawTriangle(-0.75, -0.8, 3.3, -0.2, 0, 3.25, -0.4, -1, 3);
	drawTriangle(-0.75, -0.8, 3.3, -0.2, 0, 3.25, -0.65, -0.4, 3.6);
	drawTriangle(-1.2, 0, 4, -0.2, 0, 3.25, -0.65, -0.4, 3.6);
	drawTriangle(-1.2, 0, 4, -0.6, 0.9, 3.4, -0.2, 0, 3.25);
	drawTriangle(-1.2, 0, 4, -0.6, 0.9, 3.4, -1.4, 0, 3.4);
	drawTriangle(-1.2, 0, 4, -0.65, 0.4, 3.6, -1.4, 0, 3.4);
	drawTriangle(-1.2, 0, 4, -0.65, 0.4, 3.6, -1.4, 0, 3.4);
	drawTriangle(-0.75, -0.8, 3.3, -0.65, -0.4, 3.6, -1.4, 0, 3.4);
	drawTriangle(-1.2, 0, 4, -0.65, -0.4, 3.6, -1.4, 0, 3.4);
	drawTriangle(-0.75, -0.8, 3.3, -0.4, -1.2, 1, -1.4, 0, 3.4);
	drawTriangle(-0.9, 1, 2.7, -0.6, 0.9, 3.4, -1.4, 0, 3.4);
	drawTriangle(-0.9, 1, 2.7, -0.4, 1.2, 0.75, -1.4, 0, 3.4);
	drawTriangle(-0.75, -0.8, 3.3, -0.4, -1.2, 1, -0.4, -1, 3);
	drawTriangle(-0.8, 1.4, 2.4, -0.9, 1, 2.7, -0.6, 0.9, 3.4);
	drawTriangle(-0.8, 1.4, 2.4, -0.9, 1, 2.7, -0.4, 1.2, 0.85);
	drawTriangle(-0.4, 1.2, 0.85, -0.9, 1, 2.7, -0.3, 0, 1);
	drawTriangle(-1.5, 0, 1, -1.4, 0, 3.4, -0.4, 1.2, 0.85);
	drawTriangle(-1.5, 0, 1, -1.4, 0, 3.4, -0.4, -1.2, 1);
	drawTriangle(-1.5, 0, 1, -2, 0, 0.2, -0.4, -1.2, 1);
	drawTriangle(-1.5, 0, 1, -2, 0, 0.2, -0.4, 1.2, 0.85);
	drawTriangle(-0, 1.5, 0.6, -2, 0, 0.2, -0.4, 1.2, 0.85);
	drawTriangle(-0, 1.5, 0.6, -2, 0, 0.2, -0, 0, -0.5);
	drawTriangle(-0, -1.5, 0.6, -2, 0, 0.2, -0, 0, -0.5);
	drawTriangle(-0, -1.5, 0.6, -2, 0, 0.2, -0.4, -1.2, 1);
}

void Model::drawRightLowerArm() {
	drawTriangle(-0.2, 0, -0.2, -0.8, 0, 1, -0, 0.6, 0.65);
	drawTriangle(-0.2, 0, -0.2, -0.8, 0, 1, -0, -0.6, 0.65);
	drawTriangle(-0.2, 0, -0.2, +0.3, 0, 0.5, -0, 0.6, 0.65);
	drawTriangle(-0.2, 0, -0.2, +0.3, 0, 0.5, -0, -0.6, 0.65);
	drawTriangle(+0.5, 0, 3.25, -0.8, 0, 1, -0, 0.6, 0.65);
	drawTriangle(+0.5, 0, 3.25, -0.8, 0, 1, -0, -0.6, 0.65);
	drawTriangle(+0.5, 0, 3.25, +0.3, 0, 0.5, -0, 0.6, 0.65);
	drawTriangle(+0.5, 0, 3.25, +0.3, 0, 0.5, -0, -0.6, 0.65);
}

void Model::drawLowerBody() {
	glRotated(90, 1.0, 0.0, 0.0);
	glTranslated(0.0, 0.0, -3.5f);
	drawCylinder(3.25, 1.05, 0.85);
	drawCylinder(2.65, 1.75, 0.85);
	glTranslated(-0.55, -0.55, 2.0);
	glScaled(1.1, 1.1, 2.5);
	drawBox(1, 1, 1);
}

void Model::drawRightUpperLeg() {
	drawTriangle(0.56, 0, 0.75, 0.8, 0, 1.6, 0.57, 1.5, 1.3);
	drawTriangle(0.56, 0, 2.5, 0.8, 0, 1.6, 0.57, 1.5, 1.3);
	drawTriangle(0.56, 0, 0.75, 0.8, 0, 1.6, 0.52, -1.5, 1.2);
	drawTriangle(0.4, -1.2, 1.9, 0.8, 0, 1.6, 0.52, -1.5, 1.2);
	drawTriangle(0.4, -1.2, 1.9, 0.8, 0, 1.6, 0.57, 0, 2.5);
	drawTriangle(0.57, 1.5, 1.3, 0.3, 1.8, 3.5, 0.57, 0, 2.5);
	drawTriangle(0.7, 1.6, 4.5, 0.3, 1.8, 3.5, 0.57, 0, 2.5);
	drawTriangle(0.7, 1.6, 4.5, 0.5, 1.4, 4.3, 0.57, 0, 2.5);
	drawTriangle(0.5, 1.4, 4.3, 0.9, -0.3, 3, 0.57, 0, 2.5);
	drawTriangle(0.5, -0.7, 2.6, 0.9, -0.3, 3, 0.57, 0, 2.5);
	drawTriangle(0.5, -0.7, 2.6, 0.4, -1.2, 1.9, 0.57, 0, 2.5);
	drawTriangle(0.56, 0, 0.75, 2.5, 0, 1.25, 0.57, 1.5, 1.3);
	drawTriangle(0.56, 0, 0.75, 2.5, 0, 1.25, 0.52, -1.5, 1.2);
	drawTriangle(0.4, -1.2, 1.9, 2.5, 0, 1.25, 0.52, -1.5, 1.2);
	drawTriangle(0.3, 1.8, 3.5, 0.7, 1.6, 4.5, 0.57, 1.5, 1.3);
	drawTriangle(0.7, 1.6, 4.5, 2.5, 0, 1.25, 1.5, 1, 4);
	drawTriangle(0.5, -0.7, 2.6, 0.4, -1.2, 1.9, 0.9, -0.3, 3);
	drawTriangle(2.5, 0, 1.25, 0.4, -1.2, 1.9, 0.9, -0.3, 3);
	drawTriangle(2.5, 0, 1.25, 1.5, 1, 4, 0.9, -0.3, 3);
	drawTriangle(0.57, 1.5, 1.3, 2.5, 0, 1.25, 0.7, 1.6, 4.5);
	drawTriangle(0.5, 1.4, 4.3, 1.5, 1, 4, 0.7, 1.6, 4.5);
	drawTriangle(0.5, 1.4, 4.3, 1.5, 1, 4, 0.9, -0.3, 3);
}

void Model::drawRightLowerLeg() {
	drawTriangle(0, 1, -0.5, -0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, 1, -0.5, 0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, -1, 0.8, -0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, -1, 0.8, 0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, 1, -0.5, -0.5, 0.1, 0.2, 0, -1, 0.8);
	drawTriangle(0, 1, -0.5, 0.5, 0.1, 0.2, 0, -1, 0.8);
}

void Model::drawRightFoot() {
	drawTriangle(-0.5, 0, 0, 0, 0, -0.75, 0, 3, 0);
	drawTriangle(0.5, 0, 0, 0, 0, -0.75, 0, 3, 0);
	drawTriangle(0.5, 0, 0, 0, -0.5, 0, 0, 0, -0.75);
	drawTriangle(-0.5, 0, 0, 0, -0.5, 0, 0, 0, -0.75);
}

void Model::drawLeftUpperLeg() {
	drawTriangle(-0.56, 0, 0.75, -0.8, 0, 1.6, -0.57, 1.5, 1.3);
	drawTriangle(-0.56, 0, 2.5, -0.8, 0, 1.6, -0.57, 1.5, 1.3);
	drawTriangle(-0.56, 0, 0.75, -0.8, 0, 1.6, -0.52, -1.5, 1.2);
	drawTriangle(-0.4, -1.2, 1.9, -0.8, 0, 1.6, -0.52, -1.5, 1.2);
	drawTriangle(-0.4, -1.2, 1.9, -0.8, 0, 1.6, -0.57, 0, 2.5);
	drawTriangle(-0.57, 1.5, 1.3, -0.3, 1.8, 3.5, -0.57, 0, 2.5);
	drawTriangle(-0.7, 1.6, 4.5, -0.3, 1.8, 3.5, -0.57, 0, 2.5);
	drawTriangle(-0.7, 1.6, 4.5, -0.5, 1.4, 4.3, -0.57, 0, 2.5);
	drawTriangle(-0.5, 1.4, 4.3, -0.9, -0.3, 3, -0.57, 0, 2.5);
	drawTriangle(-0.5, -0.7, 2.6, -0.9, -0.3, 3, -0.57, 0, 2.5);
	drawTriangle(-0.5, -0.7, 2.6, -0.4, -1.2, 1.9, -0.57, 0, 2.5);
	drawTriangle(-0.56, 0, 0.75, -2.5, 0, 1.25, -0.57, 1.5, 1.3);
	drawTriangle(-0.56, 0, 0.75, -2.5, 0, 1.25, -0.52, -1.5, 1.2);
	drawTriangle(-0.4, -1.2, 1.9, -2.5, 0, 1.25, -0.52, -1.5, 1.2);
	drawTriangle(-0.3, 1.8, 3.5, -0.7, 1.6, 4.5, -0.57, 1.5, 1.3);
	drawTriangle(-0.7, 1.6, 4.5, -2.5, 0, 1.25, -1.5, 1, 4);
	drawTriangle(-0.5, -0.7, 2.6, -0.4, -1.2, 1.9, -0.9, -0.3, 3);
	drawTriangle(-2.5, 0, 1.25, -0.4, -1.2, 1.9, -0.9, -0.3, 3);
	drawTriangle(-2.5, 0, 1.25, -1.5, 1, 4, -0.9, -0.3, 3);
	drawTriangle(-0.57, 1.5, 1.3, -2.5, 0, 1.25, -0.7, 1.6, 4.5);
	drawTriangle(-0.5, 1.4, 4.3, -1.5, 1, 4, -0.7, 1.6, 4.5);
	drawTriangle(-0.5, 1.4, 4.3, -1.5, 1, 4, -0.9, -0.3, 3);
}

void Model::drawLeftLowerLeg() {
	drawTriangle(0, 1, -0.5, -0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, 1, -0.5, 0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, -1, 0.8, -0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, -1, 0.8, 0.5, 0.1, 0.2, 0, -1, 3.75);
	drawTriangle(0, 1, -0.5, -0.5, 0.1, 0.2, 0, -1, 0.8);
	drawTriangle(0, 1, -0.5, 0.5, 0.1, 0.2, 0, -1, 0.8);
}

void Model::drawLeftFoot() {
	drawTriangle(-0.5, 0, 0, 0, 0, -0.75, 0, 3, 0);
	drawTriangle(0.5, 0, 0, 0, 0, -0.75, 0, 3, 0);
	drawTriangle(0.5, 0, 0, 0, -0.5, 0, 0, 0, -0.75);
	drawTriangle(-0.5, 0, 0, 0, -0.5, 0, 0, 0, -0.75);
}

void Model::rotate(const double &x, const double &y, const double &z) {
	glRotated(x, 1.0, 0.0, 0.0);
	glRotated(y, 0.0, 1.0, 0.0);
	glRotated(z, 0.0, 0.0, 1.0);
}

void Model::back_rotate(const double &x, const double &y, const double &z) {
	glRotated(z, 0.0, 0.0, 1.0);
	glRotated(y, 0.0, 1.0, 0.0);
	glRotated(x, 1.0, 0.0, 0.0);
}


Model::Model(int x, int y, int w, int h, char *label) : ModelerView(x, y, w, h, label) {}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void Model::draw()
{	
	if (VAL(FRAME_ALL) == 1) {
		this->m_camera->frameAll(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
		ModelerApplication::Instance()->SetControlValue(FRAME_ALL, 0);
	}

    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();

	// Handle animation
	if (VAL(ANIMATION) == 1) {
		ModelerApplication *app = ModelerApplication::Instance();
		
		// Handle left shoulder movement
		double left_shoulder_rotate = app->GetControlValue(LEFT_SHOULDER_X_ROTATE);
		if (left_shoulder_rotate >= Model::LEFT_SHOULDER_X_ROTATE_MAX) Model::LEFT_SHOULDER_MOVEMENT = -1;
		if (left_shoulder_rotate <= Model::LEFT_SHOULDER_X_ROTATE_MIN) Model::LEFT_SHOULDER_MOVEMENT = 1;
		app->SetControlValue(LEFT_SHOULDER_X_ROTATE, left_shoulder_rotate + Model::LEFT_SHOULDER_MOVEMENT);

		// Handle right shoulder movement
		double right_shoulder_rotate = app->GetControlValue(RIGHT_SHOULDER_X_ROTATE);
		if (right_shoulder_rotate >= Model::RIGHT_SHOULDER_X_ROTATE_MAX) Model::RIGHT_SHOULDER_MOVEMENT = -1;
		if (right_shoulder_rotate <= Model::RIGHT_SHOULDER_X_ROTATE_MIN) Model::RIGHT_SHOULDER_MOVEMENT = 1;
		app->SetControlValue(RIGHT_SHOULDER_X_ROTATE, right_shoulder_rotate + Model::RIGHT_SHOULDER_MOVEMENT);

		// Handle left leg movement
		double left_leg_rotate = app->GetControlValue(LEFT_LEG_X_ROTATE);
		if (left_leg_rotate >= Model::LEFT_LEG_X_ROTATE_MAX) Model::LEFT_LEG_MOVEMENT = -1;
		if (left_leg_rotate <= Model::LEFT_LEG_X_ROTATE_MIN) Model::LEFT_LEG_MOVEMENT = 1;
		app->SetControlValue(LEFT_LEG_X_ROTATE, left_leg_rotate + Model::LEFT_LEG_MOVEMENT);

		// Handle right leg movment
		double right_leg_rotate = app->GetControlValue(RIGHT_LEG_X_ROTATE);
		if (right_leg_rotate >= Model::RIGHT_LEG_X_ROTATE_MAX) Model::RIGHT_LEG_MOVEMENT = -1;
		if (right_leg_rotate <= Model::RIGHT_LEG_X_ROTATE_MIN) Model::RIGHT_LEG_MOVEMENT = 1;
		app->SetControlValue(RIGHT_LEG_X_ROTATE, right_leg_rotate + Model::RIGHT_LEG_MOVEMENT);
	}

	// Determine adjust body component or not
	bool isAdjust = VAL(ADJUST_BODY) == 1;

	// draw the floor and center
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_RED);
	glPushMatrix();
	drawSphere(0.2f);
	//downward by 10
	glTranslated(-5,-10.01f,-5);
	//drawBox(10,0.01f,10);
	glPopMatrix();

	// draw the sample model
	setAmbientColor(.1f,.1f,.1f);
	setDiffuseColor(COLOR_GREEN);
	glPushMatrix();
	glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));	// Get the value from slider

		//draw the upper body
		// need the whole body rotation
		glPushMatrix();
		glRotated(90, 1.0, 0.0, 0.0);
		glTranslated(0.0, 0.0, -VAL(HEIGHT));

		/***this 0 can be changed as "upper body rotation"***/
		glRotated(VAL(WHOLE_UPPER_BODY_ROTATE), 0.0, 0.0, 1.0);
		
		if (isAdjust) {
			// Draw sphere body
			glTranslated(0.0, 0.0, -3.0);
			drawSphere(2);
			glTranslated(0.0, 0.0, 3.0);
		} else {
			// Draw triangular body
			Model::drawUpperBody();
		}

		//draw the head
		glTranslated(0, 0, -6);
		this->rotate(VAL(HEAD_X_ROTATE), VAL(HEAD_Y_ROTATE), VAL(HEAD_Z_ROTATE));

		Model::drawHead();
		Model::drawHorn();

		glTranslated(0, 0, -5);
		drawTorus(1.5, 0.5);
		glTranslated(0, 0, 5);

		//translate back
		this->back_rotate(-VAL(HEAD_X_ROTATE), -VAL(HEAD_Y_ROTATE), -VAL(HEAD_Z_ROTATE));
		glRotated(0, 0.0, 0.0, 1.0);
		glTranslated(0, 0, 6.5);

		//draw the left arm
		glTranslated(3.8, 0.0, -6.5);
		/*** here can add XYZ " left showder rotation"***/
		this->rotate(VAL(LEFT_SHOULDER_X_ROTATE), VAL(LEFT_SHOULDER_Y_ROTATE), VAL(LEFT_SHOULDER_Z_ROTATE));

		//for picking
		glRotated(VAL(PICKING), 0.0, 0.0, 1.0);

		if (isAdjust) {
			// Draw cylinder arm
			glTranslated(0.9, 0.0, 0.0);
			drawCylinder(3, 0.4, 0.4);
			glTranslated(-0.9, 0.0, 0.0);
		} else {
			// Draw triangular arm
			Model::drawLeftUpperArm();
		}

		// albow
		glTranslated(0.8, 0.0, 4);
		/*** here can add XYZ "left albow rotation"***/
		this->rotate(VAL(LEFT_ELBOW_X_ROTATE), VAL(LEFT_ELBOW_Y_ROTATE), VAL(LEFT_ELBOW_Z_ROTATE));
		
		//for picking
		glRotated(VAL(PICKING), 0.0, 1.0, 0.0);

		setDiffuseColor(COLOR_RED);

		drawSphere(0.25f);
		setDiffuseColor(COLOR_GREEN);

		// left fore arm
		if (isAdjust) {
			// Draw cylinder arm
			glTranslated(0.0, 0.0, 0.6);
			glRotated(-9, 0.0, 1.0, 0.0);
			drawCylinder(2, 0.3, 0.3);
			glRotated(9, 0.0, 1.0, 0.0);
			glTranslated(0.0, 0.0, -0.6);
		} else {
			// Draw triangular arm
			Model::drawLeftLowerArm();
		}
		

		//left wrist
		glTranslated(-0.5, 0.0, 3.25);
		/*** here can add XYZ "left wrist rotation"***/
		this->rotate(VAL(LEFT_WRIST_X_ROTATE), VAL(LEFT_WRIST_Y_ROTATE), VAL(LEFT_WRIST_Z_ROTATE));

		//for picking
		glRotated(VAL(PICKING), 0.0, 1.0, 0.0);
		
		setDiffuseColor(COLOR_RED);

		drawSphere(0.15f);
		setDiffuseColor(COLOR_GREEN);

		//left paw
		glRotated(7, 0.0, 1.0, 0.0);
		glTranslated(0, -0.35, 0);
		drawBox(0.1f, 0.7, 0.7);
		glTranslated(0, +0.35, 0);
		glTranslated(0 , -0.35, 0.7);
		glRotated(-25, 0.0, 1.0, 0.0);
		drawBox(0.1f, 0.7, 0.7);
		glTranslated(0, +0.35, -0.7);
		glRotated(+25, 0.0, 1.0, 0.0);
		glRotated(-15, 0.0, 1.0, 0.0);

		glTranslated(-0.4, -0.2, 0);
		drawBox(0.1f, 0.4, 0.6);


		//translate back
		glTranslated(+0.4, +0.2, 0);
		glRotated(15, 0.0, 1.0, 0.0);
		glRotated(-25, 0.0, 1.0, 0.0);
		glTranslated(0, -0.35, +0.7);
		glRotated(+25, 0.0, 1.0, 0.0);
		glTranslated(0, +0.35, -0.7);
		glTranslated(0, -0.35, 0);
		glTranslated(0, +0.35, 0);
		glRotated(-7, 0.0, 1.0, 0.0);

		/*** here can add XYZ "left wrist rotation"***/
		glRotated(-VAL(PICKING), 0.0, 1.0, 0.0);
		this->back_rotate(-VAL(LEFT_WRIST_X_ROTATE), -VAL(LEFT_WRIST_Y_ROTATE), -VAL(LEFT_WRIST_Z_ROTATE));
		glTranslated(0.5, 0.0, -3.25);
		/*** here can add XYZ "left albow rotation"***/
		glRotated(-VAL(PICKING), 0.0, 1.0, 0.0);
		this->back_rotate(-VAL(LEFT_ELBOW_X_ROTATE), -VAL(LEFT_ELBOW_Y_ROTATE), -VAL(LEFT_ELBOW_Z_ROTATE));
		glTranslated(-0.8, 0.0, -4);
		/***translate back the left shoulder rotation***/
		glRotated(-VAL(PICKING), 0.0, 0.0, 1.0);
		this->back_rotate(-VAL(LEFT_SHOULDER_X_ROTATE), -VAL(LEFT_SHOULDER_Y_ROTATE), -VAL(LEFT_SHOULDER_Z_ROTATE));
		glTranslated(-3.8, 0.0, 6.5);

		//draw the right arm
		glTranslated(-3.8, 0.0, -6.5);
		/*** here can add XYZ " right showder rotation"***/
		this->rotate(-VAL(RIGHT_SHOULDER_X_ROTATE), -VAL(RIGHT_SHOULDER_Y_ROTATE), -VAL(RIGHT_SHOULDER_Z_ROTATE));

		//for picking
		glRotated(-VAL(PICKING), 0.0, 0.0, 1.0);

		if (isAdjust) {
			// Draw cylinder arm
			glTranslated(-0.9, 0.0, 0.0);
			drawCylinder(3, 0.4, 0.4);
			glTranslated(0.9, 0.0, 0.0);
		} else {
			// Draw triangular arm
			Model::drawRightUpperArm();
		}
		

		// albow
		glTranslated(-0.8, 0.0, 4);
		/*** here can add XYZ "right albow rotation"***/
		this->rotate(-VAL(RIGHT_ELBOW_X_ROTATE), -VAL(RIGHT_ELBOW_Y_ROTATE), -VAL(RIGHT_ELBOW_Z_ROTATE));

		//for picking
		glRotated(-VAL(PICKING), 0.0, 1.0, 0.0);

		setDiffuseColor(COLOR_RED);

		drawSphere(0.25f);
		setDiffuseColor(COLOR_GREEN);

		//right fore arm
		if (isAdjust) {
			// Draw cylinder arm
			glTranslated(0.0, 0.0, 0.6);
			glRotated(9, 0.0, 1.0, 0.0);
			drawCylinder(2, 0.3, 0.3);
			glRotated(-9, 0.0, 1.0, 0.0);
			glTranslated(0.0, 0.0, -0.6);
		} else {
			// Draw triangular arm
			Model::drawRightLowerArm();
		}

		//right wrist
		glTranslated(0.5, 0.0, 3.25);
		/*** here can add XYZ "left wrist rotation"***/
		this->rotate(-VAL(RIGHT_WRIST_X_ROTATE), -VAL(RIGHT_WRIST_Y_ROTATE), -VAL(RIGHT_WRIST_Z_ROTATE));

		//for picking
		glRotated(-VAL(PICKING), 0.0, 1.0, 0.0);

		setDiffuseColor(COLOR_RED);

		drawSphere(0.15f);
		setDiffuseColor(COLOR_GREEN);

		//right paw
		glRotated(-7, 0.0, 1.0, 0.0);
		glTranslated(0, -0.35, 0);
		drawBox(-0.1f, 0.7, 0.7);
		glTranslated(0, +0.35, 0);
		glTranslated(0, -0.35, 0.7);
		glRotated(25, 0.0, 1.0, 0.0);
		drawBox(-0.1f, 0.7, 0.7);
		glTranslated(0, +0.35, -0.7);
		glRotated(-25, 0.0, 1.0, 0.0);
		glRotated(+15, 0.0, 1.0, 0.0);

		glTranslated(0.4, -0.2, 0);
		drawBox(-0.1f, 0.4, 0.6);

		glPopMatrix();

		//draw the down body 
		glPushMatrix();
		if (!isAdjust)
			Model::drawLowerBody();
		glPopMatrix();

		// draw the right leg
		glPushMatrix();
		glRotated(90, 1.0, 0.0, 0.0);

		glRotated(20, 0.0, 1.0, 0.0);
		glRotated(25, 1.0, 0.0, 0.0);
		/***here can add X Y Z rotation and counted as " right leg roation"***/
		this->rotate(VAL(RIGHT_LEG_X_ROTATE), VAL(RIGHT_LEG_Y_ROTATE), VAL(RIGHT_LEG_Z_ROTATE));

		if (isAdjust) {
			// Draw cylinder leg
			glRotated(-20, 0.0, 1.0, 0.0);
			glRotated(-25, 1.0, 0.0, 0.0);
			glTranslated(1.9, -0.5, 0.0);
			drawCylinder(2.5, 0.4, 0.4);
			glTranslated(-1.9, 0.5, -0.0);
			glRotated(20, 0.0, 1.0, 0.0);
			glRotated(25, 1.0, 0.0, 0.0);
		} else {
			// Draw triangular leg
			Model::drawRightUpperLeg();
		}
		

		// knee 
		//go to the place it rotate
		// the knee's center
		glTranslated(0.5, 1.3, 4.4);
		setDiffuseColor(COLOR_RED);
		drawSphere(0.3f);
		setDiffuseColor(COLOR_GREEN);
		glRotated(-20, 0.0, 1.0, 0.0);
		glRotated(-25, 1.0, 0.0, 0.0);
		/***here can add X Y Z rotation and counted as "right ankle roation"***/
		this->rotate(VAL(RIGHT_CALF_X_ROTATE), VAL(RIGHT_CALF_Y_ROTATE), VAL(RIGHT_CALF_Z_ROTATE));
		if (isAdjust) {
			// Draw cylinder leg
			glRotated(13, 1.0, 0.0, 0.0);
			glTranslated(0.0, 0.0, 1.0);
			drawCylinder(2, 0.3, 0.3);
			glTranslated(0.0, 0.0, -1.0);
			glRotated(-13, 1.0, 0.0, 0.0);
		} else {
			// Draw triangular leg
			Model::drawRightLowerLeg();
		}
		

		//ankle
		glRotated(-2, 1.0, 0.0, 0.0);
		glTranslated(0, -0.9, 3.65);
		setDiffuseColor(COLOR_RED);

		drawSphere(0.3f);

		glTranslated(0, 0, 0.75);
		setDiffuseColor(COLOR_GREEN);
		/***here can add X Y Z rotation and counted as "right ankle roation"***/
		this->rotate(VAL(RIGHT_FOOT_X_ROTATE), VAL(RIGHT_FOOT_Y_ROTATE), VAL(RIGHT_FOOT_Z_ROTATE));
		Model::drawRightFoot();

		glPopMatrix();

		// draw the left leg
		glPushMatrix();
		glRotated(90, 1.0, 0.0, 0.0);

		glRotated(-20, 0.0, 1.0, 0.0);
		glRotated(25, 1.0, 0.0, 0.0);
		/***here can add X Y Z rotation and counted as " left leg roation"***/
		this->rotate(VAL(LEFT_LEG_X_ROTATE), VAL(LEFT_LEG_Y_ROTATE), VAL(LEFT_LEG_Z_ROTATE));
		if (isAdjust) {
			// Draw cylinder leg
			glRotated(20, 0.0, 1.0, 0.0);
			glRotated(-25, 1.0, 0.0, 0.0);
			glTranslated(-1.9, -0.5, 0.0);
			drawCylinder(2.5, 0.4, 0.4);
			glTranslated(1.9, 0.5, -0.0);
			glRotated(-20, 0.0, 1.0, 0.0);
			glRotated(25, 1.0, 0.0, 0.0);
		} else {
			// Draw triangular leg
			Model::drawLeftUpperLeg();
		}

		// knee 
		//go to the place it rotate
		// the knee's center
		glTranslated(-0.5, 1.3, 4.4);
		setDiffuseColor(COLOR_RED);

		drawSphere(0.3f);
		setDiffuseColor(COLOR_GREEN);
		glRotated(20, 0.0, 1.0, 0.0);
		glRotated(-25, 1.0, 0.0, 0.0);
		/***here can add X Y Z rotation and counted as "right ankle roation"***/
		this->rotate(VAL(LEFT_CALF_X_ROTATE), VAL(LEFT_CALF_Y_ROTATE), VAL(LEFT_CALF_Z_ROTATE));
		if (isAdjust) {
			// Draw cylinder leg
			glRotated(13, 1.0, 0.0, 0.0);
			glTranslated(0.0, 0.0, 1.0);
			drawCylinder(2, 0.3, 0.3);
			glTranslated(0.0, 0.0, -1.0);
			glRotated(-13, 1.0, 0.0, 0.0);
		} else {
			// Draw triangular leg
			Model::drawLeftLowerLeg();
		}
		

		glRotated(-2, 1.0, 0.0, 0.0);
		glTranslated(0, -0.9, 3.65);
		setDiffuseColor(COLOR_RED);

		drawSphere(0.3f);

		glTranslated(0, 0, 0.75);
		setDiffuseColor(COLOR_GREEN);
		/***here can add X Y Z rotation and counted as "right ankle roation"***/
		this->rotate(VAL(LEFT_FOOT_X_ROTATE), VAL(LEFT_FOOT_Y_ROTATE), VAL(LEFT_FOOT_Z_ROTATE));
		Model::drawLeftFoot();

		glPopMatrix();

	glPopMatrix();
}