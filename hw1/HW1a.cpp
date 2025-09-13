// ===============================================================
// Computer Graphics Homework Solutions
// Copyright (C) 2022 by George Wolberg
//
// HW1a.cpp - HW1a class
//
// Written by: George Wolberg, 2022
// ===============================================================

#include "HW1a.h"
#include <iostream>

// init array of 16 vertices for letter 'P'
float Vertices[] = {
	-0.5f , -0.75f,
	-0.5f , -0.5f,
	-0.5f , -0.25f,
	-0.5f ,  0.0f,
	-0.5f ,  0.25f,
	-0.5f ,  0.5f,
	-0.25f,  0.75f,
	 0.0f ,  0.75f,
	 0.25f,  0.75f,
	 0.5f ,  0.75f,
	 0.75f,  0.5f,
	 0.75f,  0.25f,
	 0.5f ,  0.0f,
	 0.25f,  0.0f,
	 0.0f ,  0.0f,
	-0.25f,  0.0f
};

static int DrawModes[] = {
	GL_POINTS,
	GL_LINES,
	GL_LINE_STRIP,
	GL_LINE_LOOP,
	GL_TRIANGLES,
	GL_TRIANGLE_STRIP,
	GL_TRIANGLE_FAN,
	GL_QUADS,
	GL_POLYGON
};

int len = sizeof(Vertices) / sizeof(Vertices[0]);

typedef QVector2D vertex1;
std::vector<vertex1> vert_points;



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::HW1a:
//
// HW1a constructor.
//
HW1a::HW1a(const QGLFormat &glf, QWidget *parent)
	: HW(glf, parent)
{
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::initializeGL:
//
// Initialization routine before display loop.
// Gets called once before the first time resizeGL() or paintGL() is called.
//
void
HW1a::initializeGL()
{
	// PUT YOUR CODE HERE
	initializeGLFunctions();

	// init state variables
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);	// set background color
	glColor3f(1.0F, 1.0f, 1.0f);		// set foreground color
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::resizeGL:
//
// Resize event handler.
// The input parameters are the window width (w) and height (h).
//
void
HW1a::resizeGL(int w, int h)
{
	// PUT YOUR CODE HERE
	// compute aspect ratio
	float xmax, ymax;
	float ar = (float)w / h;
	if (ar > 1.0) {		// wide screen
		xmax = ar;
		ymax = 1.;
	}
	else {		// tall screen
		xmax = 1;
		ymax = 1 / ar;
	}

	// set viewport to occupy full canvas
	glViewport(0, 0, w, h);

	// init viewing coordinates for orthographic projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-xmax, xmax, -ymax, ymax, -1.0, 1.0);
}



void paintPoints() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for (i = 0; i < len; i += 2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

void paintLines() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	for (i = 0; i < len; i += 2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

void paintLineStrip() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < len; i += 2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

void paintLineLoop() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINE_LOOP);
	for (i = 0; i < len; i += 2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

void paintTriangles() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	for (i = 0; i < len; i+=2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

void paintTriangleStrip() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_STRIP);
	for (i = 0; i < len; i += 2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

void paintTriangleFan() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLE_FAN);
	for (i = 0; i < len; i += 2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

void paintQuads() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	for (i = 0; i < len; i += 2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

void paintPolygon() {
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	for (i = 0; i < len; i += 2) {
		glVertex2f(Vertices[i], Vertices[i + 1]);
	}
	glEnd();
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::paintGL:
//
// Update GL scene.
//
void
HW1a::paintGL()
{
	// PUT YOUR CODE HERE
	//paintPoints();
	//paintLines();
	//paintLineStrip();
	//paintLineLoop();
	//paintTriangles(); 
	//paintTriangleStrip();
	//paintTriangleFan();
	//paintQuads(); 
	//paintPolygon();
}



// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// HW1a::controlPanel:
//
// Create control panel groupbox.
//
QGroupBox*
HW1a::controlPanel()
{
	// init group box
	QGroupBox *groupBox = new QGroupBox("Homework 1a");
	groupBox->setStyleSheet(GroupBoxStyle);

	return(groupBox);
}
