#include <iostream>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <Windows.h>
#include <MMSystem.h>
#define PI 3.14

using namespace std;

GLfloat position = 0.0;
GLfloat speed = 0.8;
GLfloat position1 = 0.0;
GLfloat speed1 = 0.4;
GLfloat position2 = 0.0;
GLfloat position4 = 0.0;
GLfloat position5 = 0.0;
GLfloat position6 = 0.0;
GLfloat speed2 = 0.3;
GLfloat speed3 = 0.8;
GLfloat speed9 = 1.2;
GLfloat _rain = 0.0;
GLfloat _nt = 0.0;
GLfloat _mor = 0.0;
GLfloat _surp = 0.0;
GLfloat bird_y = 14.0f;



GLfloat rainday = false;
GLfloat night = false;
GLfloat surprising = false;
GLfloat morning_rain = false;
GLfloat day_rain = false;




void update(int value)
{
    if(position > 10.0)
        position = -20.0;
        position += speed;
        glutPostRedisplay();
        glutTimerFunc(100, update, 1);
}
void update1(int value)
{
    if(position1 > 25.0)
        position1 = -20.0;
        position1 += speed1;
        glutPostRedisplay();
        glutTimerFunc(100, update1, 1);
}
void update2(int value){
    if(position2 > 32.0)
        position2 = -10.0;
        position2 += speed2;
        glutPostRedisplay();
        glutTimerFunc(100, update2, 1);
}

//-------------Mubashir
void update4(int value)
{
    if(position4 > 10)
        position4 = -30.0;
        position4 += speed3;
        glutPostRedisplay();
        glutTimerFunc(100, update4, 1);
}

void update5(int value)
{
    if(position5 > 30)
        position5 = -20.0;
        position5 += speed3;
        glutPostRedisplay();
        glutTimerFunc(100, update5, 1);
}

void update6(int value) {
    if (position6 > 30) {
        position6 = -9.0;
    }
    position6 += speed9;
    glutPostRedisplay();
    glutTimerFunc(100, update6, 1);

    // compute the current time
    float time = glutGet(GLUT_ELAPSED_TIME) / 1000.0f;

    // update the bird's y position
    bird_y += 0.1f * sin(time);
}

//-------------Mubashir


//-------------Saifee
void sun(bool sunny){

        ///Conditions for sun

        if(!night && !rainday){
            glPushMatrix();
            glTranslatef(7.0f, 15.0f, 0.0f);
            GLfloat radius = 2.0f;
            GLfloat twicePi = 2.0f * PI;

            glBegin(GL_TRIANGLE_FAN);
            glColor3f(1.0f, 0.8f, 0.2f);
            glVertex2f(0.0f, 0.0f);
            int num_segments = 100;
                for (int i = 0; i <= num_segments; i++) {
                    GLfloat theta = i * twicePi / num_segments;
                    GLfloat x = radius * cos(theta);
                    GLfloat y = radius * sin(theta);
                    glColor3f(1.0f, 0.8f - 0.6f * y / radius, 0.2f - 0.2f * y / radius);
                    glVertex2f(x, y);
                }
            glEnd();

            glPopMatrix();
        }
}
//-------------Saifee


//-------------Saifee
void moon(bool moony){

///Condition for moon

    if(night && !rainday){
        glPushMatrix();
        glTranslatef(7.0f, 15.0f, 0.0f);
        GLfloat radius = 2.0f;
        GLfloat twicePi = 2.0f * PI;

        glBegin(GL_TRIANGLE_FAN);
        glColor4f(0.91, 0.89, 0.77, 1.0); // set the moon color to white
        glVertex2f(0.0f, 0.0f);
        int num_segments = 100;
        for (int i = 0; i <= num_segments; i++) {
            GLfloat theta = i * twicePi / num_segments;
            GLfloat x = radius * cos(theta);
            GLfloat y = radius * sin(theta);
            glVertex2f(x, y);
        }
        glEnd();

        glPopMatrix();
    }

}
//-------------Saifee



//-------------Mubashir
void wheel(int x, int y)
{
    float theta;
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.1, 0.0);
    for(int i=0; i<360; i++)
    {
        theta = i*PI/180;
        glVertex2f(x+0.02*6*cos(theta),y+0.02*6*sin(theta));
    }
    glEnd();
}

void myCars(float l, float r,float t, float b, int rr1, int gg1, int bb1, int rr2, int gg2, int bb2)
{

    float car_left = l;
    float car_right = r;
    float car_bottom = t;
    float car_top = b;

    glBegin(GL_POLYGON);
    glColor3ub(rr1,gg1,bb1);
    glVertex2f(car_left, car_bottom);
    glVertex2f(car_right, car_bottom);
    glVertex2f(car_right, car_top);
    glVertex2f(car_left, car_top);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(rr2,gg2,bb2);
    glVertex2f(car_left + 0.15, car_top);
    glVertex2f(car_right - 0.15, car_top);
    glVertex2f(car_right - 0.25, car_top + 0.25);
    glVertex2f(car_left + 0.25, car_top + 0.25);
    glEnd();

    // Draw the wheels
    wheel(car_left+1.2, car_bottom);
    wheel(car_right-0.4, car_bottom);
}

/// Drawing Trees
void drawTree(float x, float y, float height) {
    glColor3f(0.0, 0.5, 0.0); // set color to green
    glBegin(GL_TRIANGLES);
    glVertex2f(x, y + height);
    glVertex2f(x - height/2, y );
    glVertex2f(x + height/2, y );

    glEnd();

    glColor3f(0.6, 0.3, 0.0); // set color to brown
    glBegin(GL_POLYGON);
    glVertex2f(x - height/12, y);
    glVertex2f(x + height/12, y);
    glVertex2f(x + height/12, y - height/2);
    glVertex2f(x - height/12, y - height/2);
    glEnd();
}


/// Drawing Birds
void bird(float x, float y, bool bol, float time) {
    if(bol){
    // set color to black
    glColor3f(0.0, 0.0, 0.0);

    // compute the bird's y position based on a sine wave
    y = y - 2.5f * sin(time);

    // draw the body
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x+0.5, y+0.5);
    glVertex2f(x, y+0.20);
    glVertex2f(x-0.5, y+0.5);
    glEnd();
    }


}




/// Function Morning
void Morning(int _mor){

    glClearColor (0.77, 0.95, 1.00, 1.0);
    sun(true);

    if(!night && !rainday){
        glPushMatrix();
        glTranslatef(position6, 0.0f, 0.0f);
        bird(9.0, 14.0, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(8.8, 15.3, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(7.7, 15.9, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(7.5, 14.0, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(8.3, 15.6, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(7.2, 15.2, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        bird(8.5, 14.2, true, glutGet(GLUT_ELAPSED_TIME) / 1000.0);
        glPopMatrix();
    }

}

//-------------Mubashir


void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    //-------------Zobayer


    /// clouds

    glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);

    float theta;

    //c1
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(10+1*cos(theta),15+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(12.5+1.2*cos(theta),16+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(11+1.5*cos(theta),16+1.5*sin(theta));
    }
    glEnd();

    //c
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(18+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(20.5+1.2*cos(theta),11+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(19+1.5*cos(theta),11+1.5*sin(theta));
    }
    glEnd();
    glPopMatrix();

    //c1c
    glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(-2+1*cos(theta),15+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(0.5+1.2*cos(theta),16+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(-1+1.5*cos(theta),16+1.5*sin(theta));
    }
    glEnd();

    //c
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(14+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(15.5+1.8*cos(theta),11+1.2*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(15+1.2*cos(theta),11+1.5*sin(theta));
    }
    glEnd();
    //c3
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(5+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6+1*cos(theta),10+1*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6.5+.6*cos(theta),11+.5*sin(theta));
    }
    glEnd();
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(6+.7*cos(theta),11+.7*sin(theta));
    }
    glEnd();

    glPopMatrix();
    //-------------Zobayer


    //-------------Zobayer

    ///Buildings
	glBegin(GL_QUADS);

    glColor3f (0, 0, 0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 5.0, 0.0);
	glVertex3f(5.0, 5.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);

    glColor3f (0.31, 0.09, 0.48);
	glVertex3f(5.0, 3.0, 0.0);
	glVertex3f(6.0, 3.0, 0.0);
	glVertex3f(6.0, 0.0, 0.0);
    glVertex3f(5.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(6.0, 0.0, 0.0);
	glVertex3f(6.0, 8.0, 0.0);
	glVertex3f(11.0, 8.0, 0.0);
    glVertex3f(11.0, 0.0, 0.0);

    glColor3f (0.31, 0.09, 0.48);
	glVertex3f(11.0, 0.0, 0.0);
	glVertex3f(11.0, 4.5, 0.0);
	glVertex3f(12.0, 4.5, 0.0);
    glVertex3f(12.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(12.0, 0.0, 0.0);
	glVertex3f(12.0, 6.0, 0.0);
	glVertex3f(16.0, 6.0, 0.0);
    glVertex3f(16.0, 0.0, 0.0);

    glColor3f (0.31, 0.09, 0.48);
	glVertex3f(16.0, 0.0, 0.0);
	glVertex3f(16.0, 3.5, 0.0);
	glVertex3f(17.0, 3.5, 0.0);
    glVertex3f(17.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(17.0, 0.0, 0.0);
	glVertex3f(17.0, 7.0, 0.0);
	glVertex3f(21.0, 7.0, 0.0);
    glVertex3f(21.0, 0.0, 0.0);

    glColor3f (0.31, 0.09, 0.48);
	glVertex3f(21.0, 0.0, 0.0);
	glVertex3f(21.0, 5.75, 0.0);
	glVertex3f(24.0, 5.75, 0.0);
    glVertex3f(24.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(22.0, 0.0, 0.0);
	glVertex3f(22.0, 5.0, 0.0);
	glVertex3f(26.0, 5.0, 0.0);
    glVertex3f(26.0, 0.0, 0.0);

    glColor3f (0.31, 0.09, 0.48);
	glVertex3f(26.0, 0.0, 0.0);
	glVertex3f(26.0, 3.25, 0.0);
	glVertex3f(27.0, 3.25, 0.0);
    glVertex3f(27.0, 0.0, 0.0);

    glColor3f (0, 0, 0);
	glVertex3f(27.0, 0.0, 0.0);
	glVertex3f(27.0, 8.0, 0.0);
	glVertex3f(31.0, 8.0, 0.0);
    glVertex3f(31.0, 0.0, 0.0);

    glVertex3f(29.5, 8.0, 0.0);
	glVertex3f(29.25, 8.5, 0.0);
	glVertex3f(30, 8.75, 0.0);
    glVertex3f(30.75, 8.0, 0.0);

    glColor3f (0.329, 0.329, 0.329);
	glVertex3f(24.5, 5.0, 0.0);
	glVertex3f(24.5, 7.0, 0.0);
	glVertex3f(25.5, 7.0, 0.0);
    glVertex3f(25.5, 5.0, 0.0);

    glVertex3f(24, 7.0, 0.0);
	glVertex3f(24, 8.0, 0.0);
	glVertex3f(26, 8.0, 0.0);
    glVertex3f(26, 7.0, 0.0);

    glVertex3f(26, 7.0, 0.0);
	glVertex3f(26, 8.0, 0.0);
	glVertex3f(27, 9.0, 0.0);
    glVertex3f(28, 9.0, 0.0);

    glVertex3f(24, 7.0, 0.0);
	glVertex3f(24, 8.0, 0.0);
	glVertex3f(23, 9.0, 0.0);
    glVertex3f(22, 9.0, 0.0);

    glVertex3f(3.5, 5.0, 0.0);
	glVertex3f(3.5, 7.0, 0.0);
	glVertex3f(4.5, 7.0, 0.0);
    glVertex3f(4.5, 5.0, 0.0);

    glVertex3f(3, 7.0, 0.0);
	glVertex3f(3, 8.0, 0.0);
	glVertex3f(5, 8.0, 0.0);
    glVertex3f(5, 7.0, 0.0);

    glVertex3f(5, 7.0, 0.0);
	glVertex3f(5, 8.0, 0.0);
	glVertex3f(6, 9.0, 0.0);
    glVertex3f(7, 9.0, 0.0);

    glVertex3f(3, 7.0, 0.0);
	glVertex3f(3, 8.0, 0.0);
	glVertex3f(2, 9.0, 0.0);
    glVertex3f(1, 9.0, 0.0);

    glVertex3f(0, 9.0, 0.0);
	glVertex3f(0, 9.25, 0.0);
	glVertex3f(32, 9.25, 0.0);
    glVertex3f(32, 9.0, 0.0);

    glVertex3f(0, 11.75, 0.0);
	glVertex3f(0, 11.85, 0.0);
	glVertex3f(32, 11.85, 0.0);
    glVertex3f(32, 11.75, 0.0);

    glColor3f (0.31, 0.09, 0.48);
	glVertex3f(31.0, 0.0, 0.0);
	glVertex3f(31.0, 6, 0.0);
	glVertex3f(32.0, 6, 0.0);
    glVertex3f(32.0, 0.0, 0.0);

    glColor3f (0.89, 1, 0.83);
    glVertex3f(0.25, 0.25, 0.0);
	glVertex3f(0.25, 1.75, 0.0);
	glVertex3f(1, 1.75, 0.0);
    glVertex3f(1, 0.25, 0.0);

    glVertex3f(1.25, 0.25, 0.0);
	glVertex3f(1.25, 1.75, 0.0);
	glVertex3f(1.75, 1.75, 0.0);
    glVertex3f(1.75, 0.25, 0.0);

    glVertex3f(2, 0.25, 0.0);
	glVertex3f(2, 1.75, 0.0);
	glVertex3f(2.5, 1.75, 0.0);
    glVertex3f(2.5, 0.25, 0.0);

    glVertex3f(2.75, 0.25, 0.0);
	glVertex3f(2.75, 1.75, 0.0);
	glVertex3f(3.25, 1.75, 0.0);
    glVertex3f(3.25, 0.25, 0.0);

    glVertex3f(3.5, 0.25, 0.0);
	glVertex3f(3.5, 1.75, 0.0);
	glVertex3f(4, 1.75, 0.0);
    glVertex3f(4, 0.25, 0.0);

    glVertex3f(4.25, 0.25, 0.0);
	glVertex3f(4.25, 1.75, 0.0);
	glVertex3f(4.75, 1.75, 0.0);
    glVertex3f(4.75, 0.25, 0.0);
    //
    glVertex3f(0.25, 3, 0.0);
	glVertex3f(0.25, 4.75, 0.0);
	glVertex3f(1, 4.75, 0.0);
    glVertex3f(1, 3, 0.0);

    glVertex3f(1.25, 3, 0.0);
	glVertex3f(1.25, 4.75, 0.0);
	glVertex3f(1.75, 4.75, 0.0);
    glVertex3f(1.75, 3, 0.0);

    glVertex3f(2, 3, 0.0);
	glVertex3f(2, 4.75, 0.0);
	glVertex3f(2.5, 4.75, 0.0);
    glVertex3f(2.5, 3, 0.0);

    glVertex3f(2.75, 3, 0.0);
	glVertex3f(2.75, 4.75, 0.0);
	glVertex3f(3.25, 4.75, 0.0);
    glVertex3f(3.25, 3, 0.0);

    glVertex3f(3.5, 3, 0.0);
	glVertex3f(3.5, 4.75, 0.0);
	glVertex3f(4, 4.75, 0.0);
    glVertex3f(4, 3, 0.0);

    glVertex3f(4.25, 3, 0.0);
	glVertex3f(4.25, 4.75, 0.0);
	glVertex3f(4.75, 4.75, 0.0);
    glVertex3f(4.75, 3, 0.0);

    glVertex3f(0.25, 2, 0.0);
	glVertex3f(0.25, 2.75, 0.0);
	glVertex3f(4.75, 2.75, 0.0);
    glVertex3f(4.75, 2, 0.0);

    glEnd();
    // buildings end

    //-------------Zobayer


    //-------------Bishakh

    /// Metro Rail
    glPushMatrix();
    glTranslatef(-position,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3f (0, 1, 0);
	glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(20, 9.25, 0.0);
	glVertex3f(20, 11, 0.0);
    glVertex3f(11.75, 11, 0.0);

    glColor3f (1, 0, 0);
	glVertex3f(14, 9.25, 0.0);
	glVertex3f(16, 9.25, 0.0);
	glVertex3f(16, 11, 0.0);
    glVertex3f(14.75, 11, 0.0);

    glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(11, 9.5, 0.0);
	glVertex3f(11,10.25 , 0.0);
    glVertex3f(11.75, 11, 0.0);

    glVertex3f(20, 9.25, 0.0);
	glVertex3f(20.25, 9.5, 0.0);
	glVertex3f(20.25,10.75 , 0.0);
    glVertex3f(20, 11, 0.0);

    glColor3f (0,0,0);
	glVertex3f(11.25, 9.5, 0.0);
	glVertex3f(12.75, 9.5, 0.0);
	glVertex3f(12.75, 9.75, 0.0);
    glVertex3f(11.25, 9.75, 0.0);

    glVertex3f(11.25, 10, 0.0);
	glVertex3f(11.75, 10, 0.0);
	glVertex3f(11.75, 10.75, 0.0);
    glVertex3f(11.25, 10.25, 0.0);

    glVertex3f(12, 10, 0.0);
	glVertex3f(12.75, 10, 0.0);
	glVertex3f(12.75, 10.75, 0.0);
    glVertex3f(12, 10.75, 0.0);

    glVertex3f(13, 9.25, 0.0);
	glVertex3f(13.5, 9.25, 0.0);
	glVertex3f(13.5, 10.5, 0.0);
    glVertex3f(13, 10.5, 0.0);

    glVertex3f(13.75, 9.75, 0.0);
	glVertex3f(14, 9.75, 0.0);
	glVertex3f(14, 10.75, 0.0);
    glVertex3f(13.75, 10.75, 0.0);

    glVertex3f(14.25, 9.75, 0.0);
	glVertex3f(14.5, 9.75, 0.0);
	glVertex3f(14.5, 10.75, 0.0);
    glVertex3f(14.25, 10.75, 0.0);

    glVertex3f(14.75, 9.25, 0.0);
	glVertex3f(15.25, 9.25, 0.0);
	glVertex3f(15.25, 10.5, 0.0);
    glVertex3f(14.75, 10.5, 0.0);

    glVertex3f(15.5, 9.75, 0.0);
	glVertex3f(15.75, 9.75, 0.0);
	glVertex3f(15.75, 10.75, 0.0);
    glVertex3f(15.5, 10.75, 0.0);

    glVertex3f(16, 9.75, 0.0);
	glVertex3f(16.25, 9.75, 0.0);
	glVertex3f(16.25, 10.75, 0.0);
    glVertex3f(16, 10.75, 0.0);

    glVertex3f(16.5, 9.25, 0.0);
	glVertex3f(17, 9.25, 0.0);
	glVertex3f(17, 10.5, 0.0);
    glVertex3f(16.5, 10.5, 0.0);

    glVertex3f(17.25, 9.75, 0.0);
	glVertex3f(17.5, 9.75, 0.0);
	glVertex3f(17.5, 10.75, 0.0);
    glVertex3f(17.25, 10.75, 0.0);

    glVertex3f(17.75, 9.75, 0.0);
	glVertex3f(18, 9.75, 0.0);
	glVertex3f(18, 10.75, 0.0);
    glVertex3f(17.75, 10.75, 0.0);

    glVertex3f(18.25, 9.25, 0.0);
	glVertex3f(18.75, 9.25, 0.0);
	glVertex3f(18.75, 10.5, 0.0);
    glVertex3f(18.25, 10.5, 0.0);

    glVertex3f(19, 9.75, 0.0);
	glVertex3f(19.25, 9.75, 0.0);
	glVertex3f(19.25, 10.75, 0.0);
    glVertex3f(19, 10.75, 0.0);

    glVertex3f(19.5, 9.5, 0.0);
	glVertex3f(19.75, 9.5, 0.0);
	glVertex3f(19.75, 10.75, 0.0);
    glVertex3f(19.5, 10.75, 0.0);

    glVertex3f(19.75, 9.5, 0.0);
	glVertex3f(20, 9.5, 0.0);
	glVertex3f(20, 10.5, 0.0);
    glVertex3f(19.75, 10.75, 0.0);

    glEnd();


	/// Metro Rail border
	glBegin(GL_LINES);
    glColor3f (0, 0, 0);
    glVertex3f(11.5, 9.25, 0.0);
	glVertex3f(11, 9.5, 0.0);

	glVertex3f(11, 9.5, 0.0);
	glVertex3f(11,10.25 , 0.0);

	glVertex3f(11,10.25 , 0.0);
    glVertex3f(11.75, 11, 0.0);

    glVertex3f(11.75, 11, 0.0);
    glVertex3f(20, 11, 0.0);

    glVertex3f(20, 9.25, 0.0);
	glVertex3f(20.25, 9.5, 0.0);

	glVertex3f(20.25, 9.5, 0.0);
	glVertex3f(20.25,10.75 , 0.0);

	glVertex3f(20.25,10.75 , 0.0);
    glVertex3f(20, 11, 0.0);

    glVertex3f(14.25,11 , 0.0);
    glVertex3f(15, 11.25, 0.0);

    glVertex3f(14.5, 11.25 , 0.0);
    glVertex3f(16.75,11.25, 0.0);

    glVertex3f(14.5,11.25 , 0.0);
    glVertex3f(14.25, 11.5, 0.0);

    glVertex3f(14.25,11.5 , 0.0);
    glVertex3f(14.25, 11.75, 0.0);

    glVertex3f(15.5,11 , 0.0);
    glVertex3f(15.75, 11.25, 0.0);

    glVertex3f(15.5,11 , 0.0);
    glVertex3f(15.5, 11.25, 0.0);

    glVertex3f(15.75,11 , 0.0);
    glVertex3f(15.75, 11.25, 0.0);

    glVertex3f(16.25,11.25 , 0.0);
    glVertex3f(17, 11, 0.0);

    glVertex3f(16.75,11.25 , 0.0);
    glVertex3f(17, 11.5, 0.0);

    glVertex3f(17,11.5 , 0.0);
    glVertex3f(17, 11.75, 0.0);

	glEnd();
	glPopMatrix();
	//-------------Bishakh



    //-------------Mubashir

    /// Metro Rail Railing
    glColor4f(0.41, 0.91, 1.00, 0.7);
    glBegin(GL_QUADS);
    glVertex2f(0.0, 9.2);
    glVertex2f(32.0, 9.2);
    glVertex2f(32.0, 10.5);
    glVertex2f(0.0, 10.5);
    glEnd();
    glColor4f(0.35, 0.18, 0.13, 0.8);
    glBegin(GL_QUADS);
    glVertex2f(32.0, 10.5);
    glVertex2f(0.0, 10.5);
    glVertex2f(0.0, 10.6);
    glVertex2f(32.0, 10.6);
    glEnd();


	/// Road
	glBegin(GL_QUADS);
    glColor3f (0.29, 0.29, 0.29);
	glVertex2f(0.0, 0.0);
	glVertex2f(32.0, 0.0);
	glVertex2f(32.0, 1.8);
	glVertex2f(0.0, 1.8);
	glEnd();
	/// Road divider lines
    glBegin(GL_LINES);
    glColor3f(1.0, 0.93, 0.0);
    for (int i = 1; i < 32; i+=2) {
        glVertex2f(i, 0.9);
        glVertex2f(i+1, 0.9);
    }
    glEnd();

    /// Footpath
    glBegin(GL_QUADS);
    glColor3f (0.48, 0.34, 0.26);
    glVertex2f(0.0, 1.8);
    glVertex2f(32.0, 1.8);
    glVertex2f(32.0, 2.2);
    glVertex2f(0.0, 2.2);
    glEnd();

    /// Trees on footpath

    drawTree(3.5, 3.0, 2.0);
    drawTree(11.5, 3.0, 2.0);
    drawTree(18.5, 3.0, 2.0);
    drawTree(27.5, 3.0, 2.0);

    /// Zebra-crossing
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);

    float y = 0.0;
    float y_increment = 0.15;

    while (y <= 1.75) {
        glBegin(GL_QUADS);
        glColor3f(1.0, 1.0, 1.0);
        glVertex2f(10.0, y);
        glVertex2f(11.0, y);
        glVertex2f(11.0, y + 0.08);
        glVertex2f(10.0, y + 0.08);
        glEnd();
        y += y_increment;
    }

    glEnd();


    /// Cars

    glPushMatrix();
    glTranslatef(-position4, 0.0f, 0.0f);

    myCars(4.8, 6.3, 1.0, 1.3, 13, 93, 88, 0, 111, 248);
    myCars(8.8, 10.3, 1.0, 1.3, 93, 13, 40, 55, 139, 90);

    glPopMatrix();

    glPushMatrix();
    glTranslatef(position5, 0.0f, 0.0f);

    myCars(2.8, 4.6, 0.05, 0.3, 13, 93, 88, 0, 111, 248);
    myCars(6.8, 8.6, 0.05, 0.3, 93, 13, 40, 55, 139, 90);

    glPopMatrix();
    ///------------------------------------///

    //-------------Mubashir

    /// Birds

    Morning(_mor);


glFlush ();
}




//-------------Zobayer
/// Function Night
void Night(int _nt){
if(night){

    moon(true);

    glClearColor(0.00, 0.11, 0.36, 1.0);
    glutTimerFunc(8, Night, 0);

    ///Owlman
    glBegin(GL_QUADS);
    glColor4f (1, 0.984, 0.102, 0.2);
	glVertex3f(29.25, 8.5, 0.0);
	glVertex3f(30, 8.75, 0.0);
	glVertex3f(27.5, 15, 0.0);
    glVertex3f(24.50, 13.75, 0.0);
    glEnd();
	float theta;
    glBegin(GL_POLYGON);
    glColor4f(1, 0.984, 0.102, 0.6);
    for(int i=0; i<360; i++)
    {
    theta = i*PI/180;
    glVertex2f(25.75+2*cos(theta),15+2*sin(theta));
    }
    glEnd();
    glBegin(GL_QUADS);

    //-------------Zobayer




    //-------------Bishakh
    /// Owl signal logo
    glColor3f (0, 0, 0);
	glVertex3f(26.0, 16, 0.0);
	glVertex3f(26.25, 16.25, 0.0);
	glVertex3f(26.25, 15.50, 0.0);
    glVertex3f(26, 15.5, 0.0);

	glVertex3f(26, 15.5, 0.0);
	glVertex3f(25.5, 15.5, 0.0);
	glVertex3f(25.5, 16, 0.0);
    glVertex3f(26, 16, 0.0);

    glVertex3f(25.25, 15.5, 0.0);
	glVertex3f(25.5, 15.5, 0.0);
	glVertex3f(25.5, 16, 0.0);
    glVertex3f(25.25, 16, 0.0);

    glVertex3f(25.25, 15.5, 0.0);
	glVertex3f(25.25, 15, 0.0);
	glVertex3f(26.25, 15, 0.0);
    glVertex3f(26.25, 15.5, 0.0);

    glVertex3f(26.25, 15.5, 0.0);
    glVertex3f(26.5, 15.25, 0.0);
    glVertex3f(26.5, 15, 0.0);
    glVertex3f(26.25, 15, 0.0);

    glVertex3f(25.25, 15.5, 0.0);
    glVertex3f(25, 15.25, 0.0);
    glVertex3f(25, 15, 0.0);
    glVertex3f(25.25, 15, 0.0);

    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(25.25, 16, 0.0);
	glVertex3f(25.25, 16.25, 0.0);
    glVertex3f(25.50, 16, 0.0);

    glVertex3f(25, 15, 0.0);
	glVertex3f(26.5, 15, 0.0);
    glVertex3f(25.75, 13.75, 0.0);

    glVertex3f(25, 15, 0.0);
	glVertex3f(26.5, 15, 0.0);
    glVertex3f(26.75, 14, 0.0);

    glVertex3f(25, 15, 0.0);
	glVertex3f(26.5, 15, 0.0);
    glVertex3f(24.75, 14, 0.0);


    glEnd();
    glFlush();
    }
    //-------------Bishakh
}


//-------------Bishakh
/// Function for Rainy weather
void Rain(int rainy){

if(rainday){

    sun(false);

    _rain += 0.001f;



    glBegin(GL_POINTS);
    for(int i=1;i<=70;i++)
    {
        if(day_rain == true){
            glClearColor (0.259, 0.569, 0.8, 0.82);
        }

        if(morning_rain == true ){
            glClearColor (0.839, 0.596, 0.42, 0.82);
        }

        int x=rand(),y=rand();
        x%=32; y%=18;
        glBegin(GL_LINES);
        glColor3f(1, 1, 1);
        glVertex2d(x,y);
        glVertex2d(x+.25,y+.55);
        glEnd();
    }

	glutPostRedisplay();
	glutTimerFunc(5, Rain, 0);

    glFlush();
}
}

void Surprise(int surp){
    if(surprising){
        sndPlaySound("Surprise.wav", SND_ASYNC);
    }


}
//-------------Bishakh



//-------------Zobayer

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
        case 's':
        speed = 0.0f;
        break;

        case 'a':
        speed += 0.1f;
        break;

        case 'r':
        rainday = true;
        Rain(_rain);
        break;

        case 't':
        rainday = false;
        Rain(false);
        break;

        case 'n':
        day_rain=false;
        morning_rain=false;
        night = true;
        Night(_nt);
        break;

        case 'd':
        day_rain = true;
        morning_rain= false;
        night = false;
        sun(true);
        glClearColor (0.77, 0.95, 1.00, 1.0);
        break;

        case 'm':
        morning_rain = true;
        day_rain = false;
        night = false;

        Morning(_mor);

        sun(true);
        glClearColor(1,1,0,1.0);
        break;

        case 'k':
        surprising = true;
        Surprise(_surp);
        break;


        glutPostRedisplay();
	}
}
//-------------Zobayer




//-------------Saifee
void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed3 += 1.1f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}
if (button == GLUT_RIGHT_BUTTON)
	{
		if (state == GLUT_DOWN)
		{
			speed3 -= 0.3f;
			printf("clicked at (%d, %d)\n", x, y);
		}
	}

	glutPostRedisplay();
}
//-------------Saifee


void init (void)
{
    glClearColor (0.77, 0.95, 1.00, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 32.0, 0.0, 18.0, -10.0, 10.0);

}

int main(int argc, char** argv)
{

    //-------------Saifee

    cout << endl << "*********** View of MRT-6 Dhaka Metro Rail ************" << endl << endl;

    cout << "Press S : To Stop the Train" << endl << endl;
    cout << "Press A : To Speed-up the Train" << endl << endl;

    cout << "Press R : For Rain " << endl << endl;
    cout << "Press T : For Stopping Rain" << endl << endl;

    cout << "Press N : For Night " << endl << endl;
    cout << "Press D : For Day" << endl << endl;
    cout << "Press M : For Morning" << endl << endl;

    cout << "Press K : For Surprise" << endl << endl;

    cout << "Press LEFT Button on Mouse : For Increase Car Speed" << endl << endl;
    cout << "Press RIGHT Button on Mouse : For Decrease Car Speed" << endl << endl;

//-------------Saifee


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 720);
    glutInitWindowPosition (600, 100);
    glutCreateWindow ("Metro Rail Scenario");

    // Enable alpha blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    init ();
    glutDisplayFunc(display);
    glutKeyboardFunc(handleKeypress);
    glutMouseFunc(handleMouse);
    glutTimerFunc(100, update, 0);
    glutTimerFunc(100, update1, 0);
    glutTimerFunc(100, update2, 0);
    glutTimerFunc(100, update4, 0);
    glutTimerFunc(100, update5, 0);
    glutTimerFunc(100, update6, 0);

    glutMainLoop();
    return 0;
}

