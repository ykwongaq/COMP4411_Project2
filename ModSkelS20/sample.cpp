// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>
#include <cmath>

#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();

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

		//glPushMatrix();
		//glTranslated(-1.5, 0, -2);
		//glScaled(3, 1, 4);
		//drawBox(1,1,1);
		//glPopMatrix();


		//draw the upper body
		// need the whole body rotation
		glPushMatrix();
		glRotated(90, 1.0, 0.0, 0.0);
		/***this 0 can be changed as "upper body rotation"***/
		glRotated(0, 0.0, 0.0, 1.0);
		drawTriangle(
			4, 0, -6,
			2, 0, -2,
			0, 3, -4.3);
		drawTriangle(
			-4, 0, -6,
			-2, 0, -2,
			0, 3, -4.3);
		drawTriangle(
			-4, 0, -6,
			0, -3, -7,
			0, 3, -4.3);
		drawTriangle(
			4, 0, -6,
			0, -3, -7,
			0, 3, -4.3);
		drawTriangle(
			0, -2, -1.5,
			2, 0, -2,
			0, 3, -4.3);
		drawTriangle(
			0, -2, -1.5,
			-2, 0, -2,
			0, 3, -4.3);

		drawTriangle(
			4, 0, -6,
			2, 0, -2,
			0, -3.5, -5);
		drawTriangle(
			-4, 0, -6,
			-2, 0, -2,
			0, -3.5, -5);
		drawTriangle(
			-4, 0, -6,
			0, -3, -7,
			0, -3.5, -5);
		drawTriangle(
			4, 0, -6,
			0, -3, -7,
			0, -3.5, -5);
		drawTriangle(
			0, -1.75, -2,
			2, 0, -2,
			0, -3.5, -5);
		drawTriangle(
			0, -1.75, -2,
			-2, 0, -2,
			0, -3.5, -5);
		drawTriangle(
			0, -1.75, -2,
			0, -2, -1.5,
			2, 0, -2);
		drawTriangle(
			0, -1.75, -2,
			0, -2, -1.5,
			-2, 0, -2);

		//draw the head
		glTranslated(0, 0, -6);
		/***can add XYZ head rotation as "head rotation"***/
		glRotated(VAL(ROTATE), 0.0, 0.0, 1.0);
		drawSphere(0.3);


		drawTriangle(
			0, 0, -2.6,
			0.8, 0, 0,
			0, 3.5, 0);
		drawTriangle(
			0, 0, -2.6,
			0, 3.5, 0,
			-0.8, 0, 0);
		drawTriangle(
			0.8, 0, -2,
			0, 0, -1.5,
			0, 3.5, 0);
		drawTriangle(
			-0.8, 0, -2,
			0, 0, -1.5,
			0, 3.5, 0);
		drawTriangle(
			0.8, 0, -2,
			1.6, -1, -0.1,
			0, 3.5, 0);
		drawTriangle(
			-0.8, 0, -2,
			-1.6, -1, -0.1,
			0, 3.5, 0);
		drawTriangle(
			-0.8, 0, -2,
			-1.6, -1, -0.1,
			0, -1.5, 0);
		drawTriangle(
			0.8, 0, -2,
			1.6, -1, -0.1,
			0, -1.5, 0);
		drawTriangle(
			-0.8, 0, -2,
			0.8, 0, -2,
			0, -1.5, 0);		
		drawTriangle(
			0, 0, 0.45,
			1.6, -1, -0.1,
			0, 3.5, 0);
		drawTriangle(
			-1.6, -1, -0.1,
			0, 0, 0.45,
			0, 3.5, 0);

		//horn
		drawTriangle(
			-0.25, -1.5, -0.75,
			0.25, -1.5, -0.75,
			0, -1.5, -3);
		drawTriangle(
			-0.25, -1.5, -0.75,
			-1.4, -1.4, -1.5,
			0, -1.5, -1.5);
		drawTriangle(
			0.25, -1.5, -0.75,
			1.4, -1.4, -1.5,
			0, -1.5, -1.5);
		drawTriangle(
			1.6, -1.25, -3.5,
			1.4, -1.4, -1.5,
			0.25, -1.5, -0.75);
		drawTriangle(
			-1.6, -1.25, -3.5,
			-1.4, -1.4, -1.5,
			-0.25, -1.5, -0.75);


		//translate back
		glRotated(-VAL(ROTATE), 0.0, 0.0, 1.0);
		glTranslated(0, 0, 6.5);

		//draw the left arm
		glTranslated(3.8, 0.0, -6.5);
		/*** here can add XYZ " left showder rotation"***/
		glRotated(8, 1.0, 0.0, 0.0);
		//drawSphere(0.5);
		drawTriangle(
			-0.15, 0, -1.5,
			0.2, 0.25, 0.5,
			0.6, 0, 0.5);
		drawTriangle(
			-0.15, 0, -1.5,
			0.2, -0.25, 0.5,
			0.6, 0, 0.5);
		drawTriangle(
			0.4, 0, 1.25,
			0.2, -0.25, 0.5,
			0.6, 0, 0.5);
		drawTriangle(
			0.4, 0, 1.25,
			0.2, 0.25, 0.5,
			0.6, 0, 0.5);
		drawTriangle(
			0, 0, -0.5,
			0.2, 0.25, 0.5,
			0, 1.5, 0.6);
		drawTriangle(
			0, 0, -0.5,
			0.2, -0.25, 0.5,
			0, -1.5, 0.6);
		drawTriangle(
			0.4, 1.2, 0.85,
			0.2, 0.25, 0.5,
			0, 1.5, 0.6);
		drawTriangle(
			0.4, -1.2, 1,
			0.2, -0.25, 0.5,
			0, -1.5, 0.6);
		drawTriangle(
			0.4, 1.2, 0.85,
			0.2, 0.25, 0.5,
			0.4, 0, 1.25);
		drawTriangle(
			0.4, -1.2, 1,
			0.2, -0.25, 0.5,
			0.4, 0, 1.25);
		drawTriangle(
			0.4, -1.2, 1,
			0.2, 0, 3.25,
			0.4, 0, 1.25);
		drawTriangle(
			0.4, 1.2, 0.85,
			0.2, 0, 3.25,
			0.4, 0, 1.25);
		drawTriangle(
			0.4, 1.2, 0.85,
			0.2, 0, 3.25,
			0.6, 0.9, 3.4);
		drawTriangle(
			0.4, 1.2, 0.85,
			0.8, 1.4, 2.4,
			0.6, 0.9, 3.4);
		drawTriangle(
			0.4, -1.2, 1,
			0.2, 0, 3.25,
			0.4, -1, 3);
		drawTriangle(
			0.75, -0.8, 3.3,
			0.2, 0, 3.25,
			0.4, -1, 3);
		drawTriangle(
			0.75, -0.8, 3.3,
			0.2, 0, 3.25,
			0.65, -0.4, 3.6);
		drawTriangle(
			1.2, 0, 4,
			0.2, 0, 3.25,
			0.65, -0.4, 3.6);
		drawTriangle(
			1.2, 0, 4,
			0.6, 0.9, 3.4,
			0.2, 0, 3.25);
		drawTriangle(
			1.2, 0, 4,
			0.6, 0.9, 3.4,
			1.4, 0, 3.4);
		drawTriangle(
			1.2, 0, 4,
			0.65, 0.4, 3.6,
			1.4, 0, 3.4);
		drawTriangle(
			1.2, 0, 4,
			0.65, 0.4, 3.6,
			1.4, 0, 3.4);
		drawTriangle(
			0.75, -0.8, 3.3,
			0.65, -0.4, 3.6,
			1.4, 0, 3.4);
		drawTriangle(
			1.2, 0, 4,
			0.65, -0.4, 3.6,
			1.4, 0, 3.4);
		drawTriangle(
			0.75, -0.8, 3.3,
			0.4, -1.2, 1,
			1.4, 0, 3.4);
		drawTriangle(
			0.9, 1, 2.7,
			0.6, 0.9, 3.4,
			1.4, 0, 3.4);
		drawTriangle(
			0.9, 1, 2.7,
			0.4, 1.2, 0.75,
			1.4, 0, 3.4);
		drawTriangle(
			0.75, -0.8, 3.3,
			0.4, -1.2, 1,
			0.4, -1, 3);
		drawTriangle(
			0.8, 1.4, 2.4,
			0.9, 1, 2.7,
			0.6, 0.9, 3.4);
		drawTriangle(
			0.8, 1.4, 2.4,
			0.9, 1, 2.7,
			0.4, 1.2, 0.85);
		drawTriangle(
			0.4, 1.2, 0.85,
			0.9, 1, 2.7,
			0.3, 0, 1);
		drawTriangle(
			1.5, 0, 1,
			1.4, 0, 3.4,
			0.4, 1.2, 0.85);
		drawTriangle(
			1.5, 0, 1,
			1.4, 0, 3.4,
			0.4, -1.2, 1);
		drawTriangle(
			1.5, 0, 1,
			2, 0, 0.2,
			0.4, -1.2, 1);
		drawTriangle(
			1.5, 0, 1,
			2, 0, 0.2,
			0.4, 1.2, 0.85);
		drawTriangle(
			0, 1.5, 0.6,
			2, 0, 0.2,
			0.4, 1.2, 0.85);
		drawTriangle(
			0, 1.5, 0.6,
			2, 0, 0.2,
			0, 0, -0.5);
		drawTriangle(
			0, -1.5, 0.6,
			2, 0, 0.2,
			0, 0, -0.5);
		drawTriangle(
			0, -1.5, 0.6,
			2, 0, 0.2,
			0.4, -1.2, 1);
		// albow
		glTranslated(0.8, 0.0, 4);
		/*** here can add XYZ "left albow rotation"***/
		glRotated(-10, 1.0, 0.0, 0.0);
		setDiffuseColor(COLOR_RED);

		drawSphere(0.25f);
		setDiffuseColor(COLOR_GREEN);

		// left fore arm
		drawTriangle(
			0.2, 0, -0.2,
			0.8, 0, 1,
			0, 0.6, 0.65);
		drawTriangle(
			0.2, 0, -0.2,
			0.8, 0, 1,
			0, -0.6, 0.65);
		drawTriangle(
			0.2, 0, -0.2,
			-0.3, 0, 0.5,
			0, 0.6, 0.65);
		drawTriangle(
			0.2, 0, -0.2,
			-0.3, 0, 0.5,
			0, -0.6, 0.65);
		drawTriangle(
			-0.5, 0, 3.25,
			0.8, 0, 1,
			0, 0.6, 0.65);
		drawTriangle(
			-0.5, 0, 3.25,
			0.8, 0, 1,
			0, -0.6, 0.65);
		drawTriangle(
			-0.5, 0, 3.25,
			-0.3, 0, 0.5,
			0, 0.6, 0.65);
		drawTriangle(
			-0.5, 0, 3.25,
			-0.3, 0, 0.5,
			0, -0.6, 0.65);

		//left wrist
		glTranslated(-0.5, 0.0, 3.25);
		/*** here can add XYZ "left wrist rotation"***/
		glRotated(-5, 1.0, 0.0, 0.0);
		
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
		glRotated(5, 1.0, 0.0, 0.0);
		glTranslated(0.5, 0.0, -3.25);
		/*** here can add XYZ "left albow rotation"***/
		glRotated(10, 1.0, 0.0, 0.0);
		glTranslated(-0.8, 0.0, -4);
		/*** here can add XYZ " left showder rotation"***/
		glRotated(-8, 1.0, 0.0, 0.0);
		glTranslated(-3.8, 0.0, 6.5);

		//draw the right arm
		glTranslated(-3.8, 0.0, -6.5);
		/*** here can add XYZ " right showder rotation"***/
		glRotated(8, 1.0, 0.0, 0.0);
		//drawSphere(0.5);
		drawTriangle(
			0.15, 0, -1.5,
			-0.2, 0.25, 0.5,
			-0.6, 0, 0.5);
		drawTriangle(
			0.15, 0, -1.5,
			-0.2, -0.25, 0.5,
			-0.6, 0, 0.5);
		drawTriangle(
			-0.4, 0, 1.25,
			-0.2, -0.25, 0.5,
			-0.6, 0, 0.5);
		drawTriangle(
			-0.4, 0, 1.25,
			-0.2, 0.25, 0.5,
			-0.6, 0, 0.5);
		drawTriangle(
			-0, 0, -0.5,
			-0.2, 0.25, 0.5,
			-0, 1.5, 0.6);
		drawTriangle(
			-0, 0, -0.5,
			-0.2, -0.25, 0.5,
			-0, -1.5, 0.6);
		drawTriangle(
			-0.4, 1.2, 0.85,
			-0.2, 0.25, 0.5,
			-0, 1.5, 0.6);
		drawTriangle(
			-0.4, -1.2, 1,
			-0.2, -0.25, 0.5,
			-0, -1.5, 0.6);
		drawTriangle(
			-0.4, 1.2, 0.85,
			-0.2, 0.25, 0.5,
			-0.4, 0, 1.25);
		drawTriangle(
			-0.4, -1.2, 1,
			-0.2, -0.25, 0.5,
			-0.4, 0, 1.25);
		drawTriangle(
			-0.4, -1.2, 1,
			-0.2, 0, 3.25,
			-0.4, 0, 1.25);
		drawTriangle(
			-0.4, 1.2, 0.85,
			-0.2, 0, 3.25,
			-0.4, 0, 1.25);
		drawTriangle(
			-0.4, 1.2, 0.85,
			-0.2, 0, 3.25,
			-0.6, 0.9, 3.4);
		drawTriangle(
			-0.4, 1.2, 0.85,
			-0.8, 1.4, 2.4,
			-0.6, 0.9, 3.4);
		drawTriangle(
			-0.4, -1.2, 1,
			-0.2, 0, 3.25,
			-0.4, -1, 3);
		drawTriangle(
			-0.75, -0.8, 3.3,
			-0.2, 0, 3.25,
			-0.4, -1, 3);
		drawTriangle(
			-0.75, -0.8, 3.3,
			-0.2, 0, 3.25,
			-0.65, -0.4, 3.6);
		drawTriangle(
			-1.2, 0, 4,
			-0.2, 0, 3.25,
			-0.65, -0.4, 3.6);
		drawTriangle(
			-1.2, 0, 4,
			-0.6, 0.9, 3.4,
			-0.2, 0, 3.25);
		drawTriangle(
			-1.2, 0, 4,
			-0.6, 0.9, 3.4,
			-1.4, 0, 3.4);
		drawTriangle(
			-1.2, 0, 4,
			-0.65, 0.4, 3.6,
			-1.4, 0, 3.4);
		drawTriangle(
			-1.2, 0, 4,
			-0.65, 0.4, 3.6,
			-1.4, 0, 3.4);
		drawTriangle(
			-0.75, -0.8, 3.3,
			-0.65, -0.4, 3.6,
			-1.4, 0, 3.4);
		drawTriangle(
			-1.2, 0, 4,
			-0.65, -0.4, 3.6,
			-1.4, 0, 3.4);
		drawTriangle(
			-0.75, -0.8, 3.3,
			-0.4, -1.2, 1,
			-1.4, 0, 3.4);
		drawTriangle(
			-0.9, 1, 2.7,
			-0.6, 0.9, 3.4,
			-1.4, 0, 3.4);
		drawTriangle(
			-0.9, 1, 2.7,
			-0.4, 1.2, 0.75,
			-1.4, 0, 3.4);
		drawTriangle(
			-0.75, -0.8, 3.3,
			-0.4, -1.2, 1,
			-0.4, -1, 3);
		drawTriangle(
			-0.8, 1.4, 2.4,
			-0.9, 1, 2.7,
			-0.6, 0.9, 3.4);
		drawTriangle(
			-0.8, 1.4, 2.4,
			-0.9, 1, 2.7,
			-0.4, 1.2, 0.85);
		drawTriangle(
			-0.4, 1.2, 0.85,
			-0.9, 1, 2.7,
			-0.3, 0, 1);
		drawTriangle(
			-1.5, 0, 1,
			-1.4, 0, 3.4,
			-0.4, 1.2, 0.85);
		drawTriangle(
			-1.5, 0, 1,
			-1.4, 0, 3.4,
			-0.4, -1.2, 1);
		drawTriangle(
			-1.5, 0, 1,
			-2, 0, 0.2,
			-0.4, -1.2, 1);
		drawTriangle(
			-1.5, 0, 1,
			-2, 0, 0.2,
			-0.4, 1.2, 0.85);
		drawTriangle(
			-0, 1.5, 0.6,
			-2, 0, 0.2,
			-0.4, 1.2, 0.85);
		drawTriangle(
			-0, 1.5, 0.6,
			-2, 0, 0.2,
			-0, 0, -0.5);
		drawTriangle(
			-0, -1.5, 0.6,
			-2, 0, 0.2,
			-0, 0, -0.5);
		drawTriangle(
			-0, -1.5, 0.6,
			-2, 0, 0.2,
			-0.4, -1.2, 1);
		// albow
		glTranslated(-0.8, 0.0, 4);
		/*** here can add XYZ "right albow rotation"***/
		glRotated(-10, 1.0, 0.0, 0.0);
		setDiffuseColor(COLOR_RED);

		drawSphere(0.25f);
		setDiffuseColor(COLOR_GREEN);

		// left fore arm
		drawTriangle(
			-0.2, 0, -0.2,
			-0.8, 0, 1,
			-0, 0.6, 0.65);
		drawTriangle(
			-0.2, 0, -0.2,
			-0.8, 0, 1,
			-0, -0.6, 0.65);
		drawTriangle(
			-0.2, 0, -0.2,
			+0.3, 0, 0.5,
			-0, 0.6, 0.65);
		drawTriangle(
			-0.2, 0, -0.2,
			+0.3, 0, 0.5,
			-0, -0.6, 0.65);
		drawTriangle(
			+0.5, 0, 3.25,
			-0.8, 0, 1,
			-0, 0.6, 0.65);
		drawTriangle(
			+0.5, 0, 3.25,
			-0.8, 0, 1,
			-0, -0.6, 0.65);
		drawTriangle(
			+0.5, 0, 3.25,
			+0.3, 0, 0.5,
			-0, 0.6, 0.65);
		drawTriangle(
			+0.5, 0, 3.25,
			+0.3, 0, 0.5,
			-0, -0.6, 0.65);

		
		//left wrist
		glTranslated(0.5, 0.0, 3.25);
		/*** here can add XYZ "left wrist rotation"***/
		glRotated(-5, 1.0, 0.0, 0.0);

		setDiffuseColor(COLOR_RED);

		drawSphere(0.15f);
		setDiffuseColor(COLOR_GREEN);

		//left paw
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
		glRotated(90, 1.0, 0.0, 0.0);
		glTranslated(0.0, 0.0, -3.5f);
		drawCylinder(3.25, 1.05, 0.85);
		drawCylinder(2.65, 1.75, 0.85);
		glTranslated(-0.55, -0.55, 2.0);
		glScaled(1.1, 1.1, 2.5);
		drawBox(1,1,1);

		glPopMatrix();

		// draw the right leg
		glPushMatrix();
		glRotated(90, 1.0, 0.0, 0.0);

		glRotated(20, 0.0, 1.0, 0.0);
		glRotated(25, 1.0, 0.0, 0.0);
		/***here can add X Y Z rotation and counted as " right leg roation"***/
		drawTriangle(
			0.56, 0, 0.75,
			0.8, 0, 1.6,
			0.57, 1.5, 1.3);
		drawTriangle(
			0.56, 0, 2.5,
			0.8, 0, 1.6,
			0.57, 1.5, 1.3);
		drawTriangle(
			0.56, 0, 0.75,
			0.8, 0, 1.6,
			0.52, -1.5, 1.2);
		drawTriangle(
			0.4, -1.2, 1.9,
			0.8, 0, 1.6,
			0.52, -1.5, 1.2);
		drawTriangle(
			0.4, -1.2, 1.9,
			0.8, 0, 1.6,
			0.57, 0, 2.5);
		drawTriangle(
			0.57, 1.5, 1.3,
			0.3, 1.8, 3.5,
			0.57, 0, 2.5);
		drawTriangle(
			0.7, 1.6, 4.5,
			0.3, 1.8, 3.5,
			0.57, 0, 2.5);
		drawTriangle(
			0.7, 1.6, 4.5,
			0.5, 1.4, 4.3,
			0.57, 0, 2.5);
		drawTriangle(
			0.5, 1.4, 4.3,
			0.9, -0.3, 3,
			0.57, 0, 2.5);
		drawTriangle(
			0.5, -0.7, 2.6,
			0.9, -0.3, 3,
			0.57, 0, 2.5);
		drawTriangle(
			0.5, -0.7, 2.6,
			0.4, -1.2, 1.9,
			0.57, 0, 2.5);
		drawTriangle(
			0.56, 0, 0.75,
			2.5, 0, 1.25,
			0.57, 1.5, 1.3);
		drawTriangle(
			0.56, 0, 0.75,
			2.5, 0, 1.25,
			0.52, -1.5, 1.2);
		drawTriangle(
			0.4, -1.2, 1.9,
			2.5, 0, 1.25,
			0.52, -1.5, 1.2);
		drawTriangle(
			0.3, 1.8, 3.5,
			0.7, 1.6, 4.5,
			0.57, 1.5, 1.3);
		drawTriangle(
			0.7, 1.6, 4.5,
			2.5, 0, 1.25,
			1.5, 1, 4);
		drawTriangle(
			0.5, -0.7, 2.6,
			0.4, -1.2, 1.9,
			0.9, -0.3, 3);
		drawTriangle(
			2.5, 0, 1.25,
			0.4, -1.2, 1.9,
			0.9, -0.3, 3);
		drawTriangle(
			2.5, 0, 1.25,
			1.5, 1, 4,
			0.9, -0.3, 3);
		drawTriangle(
			0.57, 1.5, 1.3,
			2.5, 0, 1.25,
			0.7, 1.6, 4.5);
		drawTriangle(
			0.5, 1.4, 4.3,
			1.5, 1, 4,
			0.7, 1.6, 4.5);
		drawTriangle(
			0.5, 1.4, 4.3,
			1.5, 1, 4,
			0.9, -0.3, 3);

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
		glRotated(2, 1.0, 0.0, 0.0);
		drawTriangle(
			0, 1, -0.5,
			-0.5, 0.1, 0.2,
			0, -1, 3.75);
		drawTriangle(
			0, 1, -0.5,
			0.5, 0.1, 0.2,
			0, -1, 3.75);
		drawTriangle(
			0, -1, 0.8,
			-0.5, 0.1, 0.2,
			0, -1, 3.75);
		drawTriangle(
			0, -1, 0.8,
			0.5, 0.1, 0.2,
			0, -1, 3.75);
		drawTriangle(
			0, 1, -0.5,
			-0.5, 0.1, 0.2,
			0, -1, 0.8);
		drawTriangle(
			0, 1, -0.5,
			0.5, 0.1, 0.2,
			0, -1, 0.8);

		//ankle
		glRotated(-2, 1.0, 0.0, 0.0);
		glTranslated(0, -0.9, 3.65);
		setDiffuseColor(COLOR_RED);

		drawSphere(0.3f);

		glTranslated(0, 0, 0.75);
		setDiffuseColor(COLOR_GREEN);
		/***here can add X Y Z rotation and counted as "right ankle roation"***/
		glRotated(-18, 0.0, 0.0, 1.0);
		drawTriangle(
			-0.5, 0, 0,
			0, 0, -0.75,
			0, 3, 0);
		drawTriangle(
			0.5, 0, 0,
			0, 0, -0.75,
			0, 3, 0);
		drawTriangle(
			0.5, 0, 0,
			0, -0.5, 0,
			0, 0, -0.75);
		drawTriangle(
			-0.5, 0, 0,
			0, -0.5, 0,
			0, 0, -0.75);



		glPopMatrix();

		// draw the left leg
		glPushMatrix();
		glRotated(90, 1.0, 0.0, 0.0);

		glRotated(-20, 0.0, 1.0, 0.0);
		glRotated(25, 1.0, 0.0, 0.0);
		/***here can add X Y Z rotation and counted as " left leg roation"***/
		drawTriangle(
			-0.56, 0, 0.75,
			-0.8, 0, 1.6,
			-0.57, 1.5, 1.3);
		drawTriangle(
			-0.56, 0, 2.5,
			-0.8, 0, 1.6,
			-0.57, 1.5, 1.3);
		drawTriangle(
			-0.56, 0, 0.75,
			-0.8, 0, 1.6,
			-0.52, -1.5, 1.2);
		drawTriangle(
			-0.4, -1.2, 1.9,
			-0.8, 0, 1.6,
			-0.52, -1.5, 1.2);
		drawTriangle(
			-0.4, -1.2, 1.9,
			-0.8, 0, 1.6,
			-0.57, 0, 2.5);
		drawTriangle(
			-0.57, 1.5, 1.3,
			-0.3, 1.8, 3.5,
			-0.57, 0, 2.5);
		drawTriangle(
			-0.7, 1.6, 4.5,
			-0.3, 1.8, 3.5,
			-0.57, 0, 2.5);
		drawTriangle(
			-0.7, 1.6, 4.5,
			-0.5, 1.4, 4.3,
			-0.57, 0, 2.5);
		drawTriangle(
			-0.5, 1.4, 4.3,
			-0.9, -0.3, 3,
			-0.57, 0, 2.5);
		drawTriangle(
			-0.5, -0.7, 2.6,
			-0.9, -0.3, 3,
			-0.57, 0, 2.5);
		drawTriangle(
			-0.5, -0.7, 2.6,
			-0.4, -1.2, 1.9,
			-0.57, 0, 2.5);
		drawTriangle(
			-0.56, 0, 0.75,
			-2.5, 0, 1.25,
			-0.57, 1.5, 1.3);
		drawTriangle(
			-0.56, 0, 0.75,
			-2.5, 0, 1.25,
			-0.52, -1.5, 1.2);
		drawTriangle(
			-0.4, -1.2, 1.9,
			-2.5, 0, 1.25,
			-0.52, -1.5, 1.2);
		drawTriangle(
			-0.3, 1.8, 3.5,
			-0.7, 1.6, 4.5,
			-0.57, 1.5, 1.3);
		drawTriangle(
			-0.7, 1.6, 4.5,
			-2.5, 0, 1.25,
			-1.5, 1, 4);
		drawTriangle(
			-0.5, -0.7, 2.6,
			-0.4, -1.2, 1.9,
			-0.9, -0.3, 3);
		drawTriangle(
			-2.5, 0, 1.25,
			-0.4, -1.2, 1.9,
			-0.9, -0.3, 3);
		drawTriangle(
			-2.5, 0, 1.25,
			-1.5, 1, 4,
			-0.9, -0.3, 3);
		drawTriangle(
			-0.57, 1.5, 1.3,
			-2.5, 0, 1.25,
			-0.7, 1.6, 4.5);
		drawTriangle(
			-0.5, 1.4, 4.3,
			-1.5, 1, 4,
			-0.7, 1.6, 4.5);
		drawTriangle(
			-0.5, 1.4, 4.3,
			-1.5, 1, 4,
			-0.9, -0.3, 3);

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
		glRotated(2, 1.0, 0.0, 0.0);
		drawTriangle(
			0, 1, -0.5,
			-0.5, 0.1, 0.2,
			0, -1, 3.75);
		drawTriangle(
			0, 1, -0.5,
			0.5, 0.1, 0.2,
			0, -1, 3.75);
		drawTriangle(
			0, -1, 0.8,
			-0.5, 0.1, 0.2,
			0, -1, 3.75);
		drawTriangle(
			0, -1, 0.8,
			0.5, 0.1, 0.2,
			0, -1, 3.75);
		drawTriangle(
			0, 1, -0.5,
			-0.5, 0.1, 0.2,
			0, -1, 0.8);
		drawTriangle(
			0, 1, -0.5,
			0.5, 0.1, 0.2,
			0, -1, 0.8);

		glRotated(-2, 1.0, 0.0, 0.0);
		glTranslated(0, -0.9, 3.65);
		setDiffuseColor(COLOR_RED);

		drawSphere(0.3f);

		glTranslated(0, 0, 0.75);
		setDiffuseColor(COLOR_GREEN);
		/***here can add X Y Z rotation and counted as "right ankle roation"***/
		glRotated(18, 0.0, 0.0, 1.0);
		drawTriangle(
			-0.5, 0, 0,
			0, 0, -0.75,
			0, 3, 0);
		drawTriangle(
			0.5, 0, 0,
			0, 0, -0.75,
			0, 3, 0);
		drawTriangle(
			0.5, 0, 0,
			0, -0.5, 0,
			0, 0, -0.75);
		drawTriangle(
			-0.5, 0, 0,
			0, -0.5, 0,
			0, 0, -0.75);




		glPopMatrix();
		// draw cannon
		//glPushMatrix();
		//glRotated(VAL(ROTATE), 0.0, 1.0, 0.0);
		//glRotated(-90, 1.0, 0.0, 0.0);
		//rawCylinder(VAL(HEIGHT), 0.1, 0.1);

		//glTranslated(0.0, 0.0, VAL(HEIGHT));
		//drawCylinder(1, 1.0, 0.9);

		//glTranslated(0.0, 0.0, 0.5);
		//glRotated(90, 1.0, 0.0, 0.0);
		//drawCylinder(4, 0.1, 0.2);
		//glPopMatrix();

	glPopMatrix();
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[ROTATE] = ModelerControl("Rotate", -135, 135, 1, 0);

	
    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS); // Use the controls array to create the appropriate sliders.
    return ModelerApplication::Instance()->Run();	// Run the application.
}
