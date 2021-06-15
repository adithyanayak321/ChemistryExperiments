#include<Windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
#include<MMSystem.h>
#include<string.h>
#include<math.h>
#define PI 3.1416

float color1 = 0.25f;
float color2 = 0.25f;
float color3 = 0.25f;
float a12=1.0f, b12=1.0f, c12=1.0f;
float a72=1.0f, b72=1.0f, c72=1.0f;
float a82=1.0f, b82=1.0f, c82=1.0f;
float a31=1.0f, b31=0.0f, c31=1.0f;
float a41=1.0f, b41=0.0f, c41=1.0f;
float a51=1.0f, b51=0.96f, c51=0.93f;
float ax1=0.04, ax2=0.04;

int j=0,bac1=1,ij=0,ji=1,flag1=0,r1=0, flag2=0;
GLfloat x1a=-0.90,y1a=0.70,x2a=-0.85,y2a=0.30, a1=0.1, b1=0,x3a=0,y3a=0,x4a=0,y4a=0,prev=1,a2=1,b2=0.843,c2=0,z11=0,y11=-0.915,z22=0,y22=0.50,z33=0,y33=0.803;
GLclampf a11=0.4,b11=0.8,c11=1.0;
GLfloat de1=0.0, de2=0.0;
static float cloudleftx=0,cloudmiddlex=0,cloudrightx=0;
void *font;
void *currentfont;
    char *str1="NMAMIT NITTE,KARKALA";
    //char *str2="";
	char *str3="DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING";
	char *str4="COMPUTER GRAPHICS";
	char *str5="MINI PROJECT ON";
	char *str6="CHEMISTRY EXPERIMENT SIMULATION";
	char *str7="SUBMITTED BY:";
	char *str8="GURUPRASAD  4NM18CS061";
	char *str9="JASON LARA D'SOUZA  4NM18CS067";
	char *str10="ADITHYA NAYAK 4NM18CS082";
	char *str11="6TH B CSE";
    char *str12="Click here to continue";
    char *str13="EXPERIMENTS";
    char *str14="1. Litmus paper test(Press 1 to start)";
    char *str15="2. Acid base neutralization(Press 2 to start)";
    char *str16="3. Rusting of iron(Press 3 to start)";
    char *str17="4. Demonstration of Osmosis using Grape(Press 4 to start)";
    char *str18="LITMUS TEST";

void drawstring(float x,float y,float z,char *string)
{
char *c;
glRasterPos3f(x,y,z);
for(c=string;*c!='\0';c++)
{
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,*c);
}
}

void circle(float radius_x, float radius_y)
{
    int i = 0;
    float angle1 = 0.0;

    glBegin(GL_POLYGON);

    for(i = 0; i < 100; i++)
    {
        angle1 = 2 * PI * i / 100;
        glVertex3f (cos(angle1) * radius_x, sin(angle1) * radius_y, 0);
    }

    glEnd();
}

void timer( int value )
{

    ij=(ij+1)%6;
    //printf("%d",ij);
    //changeColor?
    color1 += 0.039f;
    color2 += 0.017f;
    color3 -= 0.014f;
    if(ij<3)
    {
    a11=0;
    b11=0;
    c11=0;
    a2=1;
    b2=1;
    c2=1;
    }
    else
    {
        a11=0.4;b11=0.8;c11=1.0;
        a2=1,b2=0.843,c2=0;
    }
    glutPostRedisplay();
if(color1>=0.6)
{
  ij=0;
}else
    glutTimerFunc( 2000, timer, 0);


}

void timer1(int value)
{
   //printf("%f\t",y11);
    if(r1==0)
    {
        //y11<0.378&&
      z11=z11+0.001;
      if(y11>0.377)
          r1=1;
   // printf("\n%d",r1);
      glutPostRedisplay();
    }
    else if(r1==1)
    {
        //&&y22>0.36
        //r1=2;
      z22=z22-0.001;
      if(y22<0.37)
        r1=2;
    //printf("%f\t",z22);
      glutPostRedisplay();
    }
    else if(r1==2)
    {
        b12=0.0f;
        z33=z33-0.0001;
        if(y33<0.7893)
        {
            b31=1.0f;
            b72=0.0f;
        }
        if(y33<0.7691)
            b82=0.0f;
        if(y33<0.7491)
        {
            r1=3;
            b12=1.0f;
            b72=1.0f;
            b82=1.0f;
            b41=1.0f;
            b51=0.0f;
            c51=1.0f;
        }
        //printf("%f\t",y33);
        glutPostRedisplay();
    }
    else if(r1==3)
    {
       z22=z22+0.001;
       if(y22>0.511)
         r1=4;
    //printf("\n%d",r1);
       glutPostRedisplay();
    }
    else if(r1==4)
    {
        z11=z11-0.001;
      if(y11<-0.003)
          r1=5;
         //printf("%f\t",y11);
   // printf("\n%d",r1);
      glutPostRedisplay();
    }
    else if(r1==5)
    {
      z22=z22-0.001;
      if(y22<-0.143)
        r1=6;
    //printf("%d\t",r1);
      glutPostRedisplay();
    }
    else if(r1==6)
    {
        z33=z33+0.0001;
       if(y33>0.7676)
        {
            b41=0.96f;
            c41=0.93f;
        }
        if(y33>0.8103)
        {
            r1=7;
            b31=0.96f;
            c31=0.93f;
        }
        //printf("%d\t",r1);
        glutPostRedisplay();
    }
    else if(r1==7)
    {
        z22=z22+0.001;
      if(y22>0.444)
        r1=8;
        //printf("%d\t",r1);
      glutPostRedisplay();
    }
    else if(r1==8)
    {
       z11=z11+0.001;
      if(y11>0.377)
          r1=9;
   // printf("\n%d",r1);
      glutPostRedisplay();
    }
    else if(r1==9)
    {
        z22=z22-0.001;
      if(y22<0.37)
        r1=10;
    //printf("%f\t",z22);
      glutPostRedisplay();
    }
    else if(r1==10)
    {
        b12=0.96f;
        c12=0.93f;
        z33=z33-0.0001;
        if(y33<0.7893)
        {
            b31=1.0f;
            b72=0.96f;
            c72=0.93f;
        }
        if(y33<0.7691)
           {
             b82=0.96f;
            c82=0.93f;
           }
        if(y33<0.7491)
        {
            r1=11;
            b12=1.0f;
            c12=1.0f;
            b72=1.0f;
            c72=1.0f;
            b82=1.0f;
            c82=1.0f;
            b41=1.0f;
            b51=0.96f;
            c51=0.93f;
        }
        //printf("%f\t",y33);
        glutPostRedisplay();
    }
    else{
        flag1=1;
     //glutPostRedisplay();
    }
if(flag1==1)
{

}else
    glutTimerFunc( 1, timer1, 0);

}

void timer2(int value)
{
    if(ax1<=0.053368)
    {
        ax1=ax1+0.00001;
        ax2=ax2-0.00001;
        de1=de1-0.4;
        de2=de2-0.8;
        //printf("%f\n",ax1);
        glutPostRedisplay();
    }
    else
        flag2=1;
    if(flag2==1)
{

}else
    glutTimerFunc( 1, timer2, 0);
}

void myinit(void)
{
	glClearColor(0.5,1.0,0.5,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,500,0,500);
	glMatrixMode(GL_MODELVIEW);
}
void mydisplay()
{
    glColor3f(0.2,0.4,0.1);
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(185,475);
	for(j=0;j<strlen(str1);j++)
	{
		glColor3f(0,0,1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str1[j]);
	}

	glRasterPos2f(130,440);

	for(j=0;j<strlen(str3);j++)
	{
		glColor3f(0,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str3[j]);
	}
	glRasterPos2f(190,405);

	for(j=0;j<strlen(str4);j++)
	{glColor3f(0,0.65,0.20);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str4[j]);
	}
	glRasterPos2f(198,370);
	for(j=0;j<strlen(str5);j++)
	{glColor3f(1,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str5[j]);
	}
	glRasterPos2f(155,332);
	for(j=0;j<strlen(str6);j++)
	{
		glColor3f(1,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str6[j]);
	}
	glRasterPos2f(198,205);
	for(j=0;j<strlen(str7);j++)
	{
		glColor3f(0,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str7[j]);
	}
	glRasterPos2f(178,180);
	for(j=0;j<strlen(str8);j++)
	{
		glColor3f(0,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str8[j]);
	}
	glRasterPos2f(160,155);
	for(j=0;j<strlen(str9);j++)
	{
		glColor3f(0,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str9[j]);
	}
	glRasterPos2f(170,130);
	for(j=0;j<strlen(str10);j++)
	{
		glColor3f(1,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str10[j]);
	}
	glRasterPos2f(210,105);
	for(j=0;j<strlen(str11);j++)
	{
		glColor3f(1,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str11[j]);
	}
    glRasterPos2f(195,70);
	for(j=0;j<strlen(str12);j++)
	{
		glColor3f(1,0,0);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str12[j]);
	}
	glEnd();
	glutPostRedisplay();
	glFlush();
}

void display1(){
    glClearColor(0.47,0.54,0.60,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //glMatrixMode(GL_PROJECTION);

glPushMatrix();
   glTranslatef(0,0,0);
       //cupboard
glColor3f(0.4,0.3,1.0);
glBegin(GL_POLYGON);
glVertex2f(-0.74,0.43);
glVertex2f(-0.74,0.90);
glVertex2f(-0.25,0.90);
glVertex2f(-0.25,0.43);
glEnd();
//compartment 1
glColor3f(0.4,0.3,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.73,0.67);
glVertex2f(-0.73,0.88);
glVertex2f(-0.26,0.88);
glVertex2f(-0.26,0.67);
glEnd();
//compartment 2
glColor3f(0.4,0.3,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.73,0.45);
glVertex2f(-0.73,0.66);
glVertex2f(-0.26,0.66);
glVertex2f(-0.26,0.45);
glEnd();
// beaker1
   glColor3f(1,1,1);    // coloring rect
   glRectf(-0.70f,0.67f,-0.65f,0.77f);

   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.70, 0.77, 0);
        glVertex3f(-0.70, 0.763, 0);
        glVertex3f(-0.72, 0.77, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.65, 0.77, 0);
        glVertex3f(-0.65, 0.763, 0);
        glVertex3f(-0.63, 0.77, 0);
        glEnd();
        // beaker2
   glColor3f(255,255,255);    // coloring rect
   glRectf(-0.58f,0.67f,-0.53f,0.77f);

   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.58, 0.77, 0);
        glVertex3f(-0.58, 0.763, 0);
        glVertex3f(-0.60, 0.77, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.53, 0.77, 0);
        glVertex3f(-0.53, 0.763, 0);
        glVertex3f(-0.51, 0.77, 0);
        glEnd();
//testtube stand
glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.70f,0.45f,-0.65f,0.47f);

  glRectf(-0.35f,0.45f,-0.30f,0.47f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.67f,0.47f,-0.677f,0.6f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.33f,0.47f,-0.325f,0.6f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.675f,0.55f,-0.33f,0.56f);
  //testtube
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.63f,0.48f,-0.618f,0.59f);
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.57f,0.48f,-0.558f,0.59f);
 glColor3f(1,1,1);    // coloring rect
  glRectf(-0.51f,0.48f,-0.498f,0.59f);
 glColor3f(1,1,1);    // coloring rect
  glRectf(-0.45f,0.48f,-0.438f,0.59f);
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.39f,0.48f,-0.378f,0.59f);
  //conical flask
  glColor3f(0.64, 0.16, 0.16);
    glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.41, 0.67, 0);
        glVertex3f(-0.35, 0.67, 0);
        glVertex3f(-0.38, 0.75, 0);
        glEnd();
        glColor3f(1,1,1);    // coloring rect
  glRectf(-0.386f,0.72f,-0.375f,0.80f);
   glPopMatrix();


   glColor3f(0,255,255);    // coloring rect
   glRectf(0.27f,0.10f,0.53f,-0.30f);
   glColor3f(0,1,0);
   drawstring(-0.1,0.9,0.0,"Litmus Test");
   glColor3f(0,1,0);
   drawstring(-0.4,-0.85,0.0,"Note: Blue litmus turn red when dipped in acidic solution");
   glColor3f(1,0,0);
   drawstring(-0.9,-0.95,0.0,"Press F3 to go back");
   glColor3f(1,0,1);
   drawstring(-0.9,-0.1,0.0,"Procedure:");
   glColor3f(1,0,1);
   drawstring(-0.9,-0.2,0.0,"1.Move the litmus paper using arrow keys");
   glColor3f(1,0,1);
   drawstring(-0.9,-0.3,0.0,"2.Dip the litmus paper in the acidic solution");
   glColor3f(1,0,1);
   drawstring(-0.9,-0.4,0.0,"3.Observe the colour change");
   glColor3f(1.5,1.5,0);
   drawstring(0.632, -0.12,0.0,"Acidic solution");
    glColor3f(1,1,1);
   glRectf(0.27f,0.15f,0.53f,0.0f);
   glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
        glVertex3f(0.27, 0.15, 0);
        glVertex3f(0.30, 0.10, 0);
        glVertex3f(0.20, 0.15, 0);
        glEnd();
    glColor3f(0.7,0.7,1.0);    // coloring rect
   glRectf(0.15,-0.33f,0.17,0.-0.73f);
     glColor3f(0.7,0.7,1.0); // coloring rect
   glRectf(0.65,-0.33f,0.67,-0.73f);
    glColor3f(0.7,0.7,1.0);  // coloring rect
   glRectf(0.10,-0.30f,0.72,-0.33f);
   glColor3f(0,0,0.5);    // coloring rect
   glRectf(x1a,y1a,x2a,y2a);
   glColor3f(b1,0,0);
   glRectf(x3a,y3a,x4a,y4a);
   glColor3f(1.5,1.5,0);
   glBegin(GL_LINES);
    glVertex2f(0.532, -0.1);
    glVertex2f(0.55, -0.07);
    glEnd();
    glColor3f(1.5,1.5,0);
   glBegin(GL_LINES);
    glVertex2f(0.532, -0.1);
    glVertex2f(0.55, -0.13);
    glEnd();
    glColor3f(1.5,1.5,0);
   glBegin(GL_LINES);
    glVertex2f(0.532, -0.1);
    glVertex2f(0.63, -0.1);
    glEnd();
    // draw rect
   glFlush();
   glutSwapBuffers();
   glutPostRedisplay();
}

void display2()
{
    glClearColor(1.0,1.0,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
   glTranslatef(0,0,0);
       //cupboard
glColor3f(0.4,0.3,1.0);
glBegin(GL_POLYGON);
glVertex2f(-0.74,0.43);
glVertex2f(-0.74,0.90);
glVertex2f(-0.25,0.90);
glVertex2f(-0.25,0.43);
glEnd();
//compartment 1
glColor3f(0.4,0.3,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.73,0.67);
glVertex2f(-0.73,0.88);
glVertex2f(-0.26,0.88);
glVertex2f(-0.26,0.67);
glEnd();
//compartment 2
glColor3f(0.4,0.3,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.73,0.45);
glVertex2f(-0.73,0.66);
glVertex2f(-0.26,0.66);
glVertex2f(-0.26,0.45);
glEnd();
// beaker1
   glColor3f(1,1,1);    // coloring rect
   glRectf(-0.70f,0.67f,-0.65f,0.77f);

   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.70, 0.77, 0);
        glVertex3f(-0.70, 0.763, 0);
        glVertex3f(-0.72, 0.77, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.65, 0.77, 0);
        glVertex3f(-0.65, 0.763, 0);
        glVertex3f(-0.63, 0.77, 0);
        glEnd();
        // beaker2
   glColor3f(255,255,255);    // coloring rect
   glRectf(-0.58f,0.67f,-0.53f,0.77f);

   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.58, 0.77, 0);
        glVertex3f(-0.58, 0.763, 0);
        glVertex3f(-0.60, 0.77, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.53, 0.77, 0);
        glVertex3f(-0.53, 0.763, 0);
        glVertex3f(-0.51, 0.77, 0);
        glEnd();
//testtube stand
glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.70f,0.45f,-0.65f,0.47f);

  glRectf(-0.35f,0.45f,-0.30f,0.47f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.67f,0.47f,-0.677f,0.6f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.33f,0.47f,-0.325f,0.6f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.675f,0.55f,-0.33f,0.56f);
  //testtube
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.63f,0.48f,-0.618f,0.59f);
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.57f,0.48f,-0.558f,0.59f);
 glColor3f(1,1,1);    // coloring rect
  glRectf(-0.51f,0.48f,-0.498f,0.59f);
 glColor3f(1,1,1);    // coloring rect
  glRectf(-0.45f,0.48f,-0.438f,0.59f);
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.39f,0.48f,-0.378f,0.59f);
  //conical flask
  glColor3f(0.64, 0.16, 0.16);
    glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.41, 0.67, 0);
        glVertex3f(-0.35, 0.67, 0);
        glVertex3f(-0.38, 0.75, 0);
        glEnd();
        glColor3f(1,1,1);    // coloring rect
  glRectf(-0.386f,0.72f,-0.375f,0.80f);
   glPopMatrix();



   glColor3f(0,1,0);
   drawstring(-0.1,0.9,0.0,"Acid Base Neutralization");
   glColor3f(1,0,0);
   drawstring(-0.9,-0.95,0.0,"Press F3 to go back");
    glColor3f(0,1,0);
   drawstring(-0.4,-0.85,0.0,"Note: Phenolphthalein turns pink in basic solution and colourless in acidic");
   glColor3f(1,0,1);
   drawstring(-0.9,-0.1,0.0,"Procedure:");
   glColor3f(1,0,1);
   drawstring(-0.9,-0.2,0.0,"1.Take basic solution in a test tube. Add Phenolphthalein.");
   glColor3f(1,0,1);
   drawstring(-0.9,-0.3,0.0,"2.Observe the colour change. Now add acidic solution.");
   glColor3f(1,0,1);
   drawstring(-0.9,-0.4,0.0,"3.Observe the colour change");

    //first beaker
  glColor3f(255,255,255);    // coloring rect
   glRectf(-0.08f,-0.15f,0.02f,-0.30f);
   glColor3f(1,0.96,0.93);    // coloring rect
   glRectf(-0.07f,-0.16f,0.01f,-0.29f);
    glColor3f(255,255,255);
   glRectf(-0.08f,-0.08f,0.02f,-0.15f);
   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(0.01, -0.08, 0);
        glVertex3f(0.01, -0.10, 0);
        glVertex3f(0.06, -0.08, 0);
        glEnd();

// glTranslatef(50, 50, 0);
//syringe
     glColor3f(0,0,0.5);    // coloring rect
   glRectf(-0.95f+z11,0.95+z22+z33,-0.91+z11,0.93+z22+z33);
   glColor3f(0,0,0.5);    // coloring rect
   glRectf(-0.935f+z11,0.93+z22+z33,-0.93+z11,0.80+z22+z33);
   glColor3f(0,0,0.5);
   y33=0.803+z33;   // coloring rect
   glRectf(-0.96f+z11,0.81+z22,-0.905+z11,0.80+z22);
    glColor3f(1,1,1);    // coloring rect
   glRectf(-0.95f+z11,0.80+z22,-0.915+z11,0.55+z22);
   y11=-0.915+z11;
    glColor3f(a31,b31,c31);    // coloring rect
   glRectf(-0.95f+z11,0.60+z22,-0.915+z11,0.55+z22);
   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.95+z11, 0.55+z22, 0);
        glVertex3f(-0.932+z11, 0.50+z22, 0);
        y22=0.50+z22;
        glVertex3f(-0.915+z11, 0.55+z22, 0);

        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(a41,b41,c41);
        glVertex3f(-0.95+z11, 0.55+z22, 0);
        glVertex3f(-0.932+z11, 0.495+z22, 0);
        glVertex3f(-0.915+z11, 0.55+z22, 0);

        glEnd();

    //stand
   glColor3f(0,0,0.5);    // coloring rect
   glRectf(0.25,0.40f,0.26,-0.30f);
   glColor3f(0,0,0.5);    // coloring rect
   glRectf(0.22,-0.25f,0.29,-0.30f);
   glColor3f(0,0,0.5);    // coloring rect
   glRectf(0.22,0.20f,0.33,0.22f);
    glColor3f(0,0,0.5);    // coloring rect
   glRectf(0.24,0.23f,0.27,0.19f);
   glColor3f(0,0,0.5);    // coloring rect
   glRectf(0.33,0.23f,0.34,0.19f);
    glColor3f(0,0,0.5);    // coloring rect
   glRectf(0.39,0.23f,0.40,0.19f);
   //testtube
   glColor3f(1,1,1);    // coloring rect
   glRectf(0.34f,0.35f,0.39f,-0.10f);
   glColor3f(a51,b51,c51);    // coloring rect
   glRectf(0.345f,0.0f,0.385f,-0.10f);
   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(0.35, 0.35, 0);
        glVertex3f(0.35, 0.33, 0);
        glVertex3f(0.32, 0.35, 0);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(0.38, 0.35, 0);
        glVertex3f(0.38, 0.33, 0);
        glVertex3f(0.41, 0.35, 0);
        glEnd();

//second beaker
   glColor3f(255,255,255);    // coloring rect
   glRectf(0.74f,-0.15f,0.84f,-0.30f);
    glColor3f(1,0.96,0.93);    // coloring rect
   glRectf(0.75f,-0.16f,0.83f,-0.29f);
    glColor3f(1,1,1);
   glRectf(0.74f,-0.08f,0.84f,-0.15f);
   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(0.75, -0.08, 0);
        glVertex3f(0.75, -0.10, 0);
        glVertex3f(0.70, -0.08, 0);
        glEnd();
        glColor3f(0.7,0.7,1.0);    // coloring rect
        //table
   glRectf(-0.05,-0.33f,-0.03,0.-0.73f);
     glColor3f(0.7,0.7,1.0); // coloring rect
   glRectf(0.80,-0.33f,0.82,-0.73f);
    glColor3f(0.7,0.7,1.0);  // coloring rect
   glRectf(-0.15,-0.30f,0.92,-0.33f);
   // draw rect
   glPushMatrix();
   glTranslatef(0.365,0.3,0);
   glColor3f(a12,b12,c12);
    circle(0.008,0.015);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.365,0.18,0);
    glColor3f(a72,b72,c72);
    circle(0.008,0.015);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0.365,0.06,0);
   glColor3f(a82,b82,c82);
    circle(0.008,0.015);
     glPopMatrix();

     glColor3f(0,0,1);
   glBegin(GL_LINES);
    glVertex2f(0.021, -0.22);
    glVertex2f(0.041, -0.19);
    glEnd();
    glColor3f(0,0,1);
   glBegin(GL_LINES);
    glVertex2f(0.021, -0.22);
    glVertex2f(0.041, -0.25);
    glEnd();
    glColor3f(0,0,1);
   glBegin(GL_LINES);
    glVertex2f(0.021, -0.22);
    glVertex2f(0.071, -0.22);
    glEnd();

    glColor3f(0,0,1);
   drawstring(0.071,-0.24,0.0,"Acid");

   glColor3f(0,0,1);
   glBegin(GL_LINES);
    glVertex2f(0.739, -0.22);
    glVertex2f(0.719, -0.19);
    glEnd();
    glColor3f(0,0,1);
   glBegin(GL_LINES);
    glVertex2f(0.739, -0.22);
    glVertex2f(0.719, -0.25);
    glEnd();
    glColor3f(0,0,1);
   glBegin(GL_LINES);
    glVertex2f(0.739, -0.22);
    glVertex2f(0.689, -0.22);
    glEnd();

    glColor3f(0,0,1);
   drawstring(0.629,-0.24,0.0,"Base");

    glFlush();
    glutSwapBuffers();
}

void display3()
{
    glClearColor(1.0,1.0,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
   glTranslatef(0,0,0);
       //cupboard
glColor3f(0.4,0.3,1.0);
glBegin(GL_POLYGON);
glVertex2f(-0.74,0.43);
glVertex2f(-0.74,0.90);
glVertex2f(-0.25,0.90);
glVertex2f(-0.25,0.43);
glEnd();
//compartment 1
glColor3f(0.4,0.3,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.73,0.67);
glVertex2f(-0.73,0.88);
glVertex2f(-0.26,0.88);
glVertex2f(-0.26,0.67);
glEnd();
//compartment 2
glColor3f(0.4,0.3,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.73,0.45);
glVertex2f(-0.73,0.66);
glVertex2f(-0.26,0.66);
glVertex2f(-0.26,0.45);
glEnd();
// beaker1
   glColor3f(1,1,1);    // coloring rect
   glRectf(-0.70f,0.67f,-0.65f,0.77f);

   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.70, 0.77, 0);
        glVertex3f(-0.70, 0.763, 0);
        glVertex3f(-0.72, 0.77, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.65, 0.77, 0);
        glVertex3f(-0.65, 0.763, 0);
        glVertex3f(-0.63, 0.77, 0);
        glEnd();
        // beaker2
   glColor3f(255,255,255);    // coloring rect
   glRectf(-0.58f,0.67f,-0.53f,0.77f);

   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.58, 0.77, 0);
        glVertex3f(-0.58, 0.763, 0);
        glVertex3f(-0.60, 0.77, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.53, 0.77, 0);
        glVertex3f(-0.53, 0.763, 0);
        glVertex3f(-0.51, 0.77, 0);
        glEnd();
//testtube stand
glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.70f,0.45f,-0.65f,0.47f);

  glRectf(-0.35f,0.45f,-0.30f,0.47f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.67f,0.47f,-0.677f,0.6f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.33f,0.47f,-0.325f,0.6f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.675f,0.55f,-0.33f,0.56f);
  //testtube
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.63f,0.48f,-0.618f,0.59f);
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.57f,0.48f,-0.558f,0.59f);
 glColor3f(1,1,1);    // coloring rect
  glRectf(-0.51f,0.48f,-0.498f,0.59f);
 glColor3f(1,1,1);    // coloring rect
  glRectf(-0.45f,0.48f,-0.438f,0.59f);
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.39f,0.48f,-0.378f,0.59f);
  //conical flask
  glColor3f(0.64, 0.16, 0.16);
    glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.41, 0.67, 0);
        glVertex3f(-0.35, 0.67, 0);
        glVertex3f(-0.38, 0.75, 0);
        glEnd();
        glColor3f(1,1,1);    // coloring rect
  glRectf(-0.386f,0.72f,-0.375f,0.80f);
   glPopMatrix();



    //text
     glColor3f(0,0,1);
   drawstring(-0.1,0.9,0.0,"Rusting of Iron");
   glColor3f(1,0,0);
   drawstring(-0.9,-0.95,0.0,"Press F3 to go back");
    glColor3f(0,0,1);
   drawstring(-0.4,-0.85,0.0,"Note: Iron turns to Iron Oxide(rust) when exposed to air/water");
   glColor3f(1,0,1);
   drawstring(-0.9,0.2,0.0,"Procedure:");
   glColor3f(1,0,1);
   drawstring(-0.9,0.1,0.0,"1.Place the iron rod in water");
   glColor3f(1,0,1);
   drawstring(-0.9,0.0,0.0,"2.Observe the rusting of iron dipped in water over time.");

//window
glColor3f(0.63,0.16,0.16);    // coloring rect
   glRectf(0.20f,0.95f,0.70f,0.45f);
   glColor3f(a11,b11,c11);    // coloring rect
   glRectf(0.22f,0.93f,0.68f,0.48f);
   glPushMatrix();
   glTranslatef(0.45,0.8,0);
   glColor3f(a2,b2,c2);
   circle(0.06,0.08);
   glPopMatrix();
// beaker
   glColor3f(255,255,255);    // coloring rect
   glRectf(-0.15f,0.10f,0.15f,-0.30f);
    //glColor3f(1,0.96,0.93);
    glColor3f(0.52,0.80,0.92);    // coloring rect
   glRectf(-0.14f,-0.05f,0.14f,-0.29f);
   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.15, 0.10, 0);
        glVertex3f(-0.15, 0.08, 0);
        glVertex3f(-0.20, 0.10, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(0.15, 0.10, 0);
        glVertex3f(0.15, 0.08, 0);
        glVertex3f(0.20, 0.10, 0);
        glEnd();
        //table
        glColor3f(0.7,0.7,1.0);    // coloring rect
   glRectf(-0.35,-0.33f,-0.33,0.-0.73f);
     glColor3f(0.7,0.7,1.0); // coloring rect
   glRectf(0.35,-0.33f,0.37,-0.73f);
    glColor3f(0.7,0.7,1.0);  // coloring rect
   glRectf(-0.45,-0.30f,0.47,-0.33f);
   //iron rod
  glPushMatrix();
//glTranslatef(1, 0.4, 0);
glRotatef(15, 0, 0, 1);
  glColor3f(0.25,0.25,0.25);    // coloring rect
   glRectf(-0.12f,0.16f,-0.07f,-0.27f);
   glColor3f(color1,color2,color3);    // coloring rect
   glRectf(-0.12f,-0.03f,-0.07f,-0.27f);
glPopMatrix();
   // draw rect
   glFlush();
   glutSwapBuffers();
}

void display4()
{
    glClearColor(0.68,1.0,0.18,1.0);
    glClear(GL_COLOR_BUFFER_BIT);


    glPushMatrix();
   glTranslatef(0,0.05,0);
       //cupboard
glColor3f(0.4,0.3,1.0);
glBegin(GL_POLYGON);
glVertex2f(-0.74,0.43);
glVertex2f(-0.74,0.90);
glVertex2f(-0.25,0.90);
glVertex2f(-0.25,0.43);
glEnd();
//compartment 1
glColor3f(0.4,0.3,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.73,0.67);
glVertex2f(-0.73,0.88);
glVertex2f(-0.26,0.88);
glVertex2f(-0.26,0.67);
glEnd();
//compartment 2
glColor3f(0.4,0.3,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.73,0.45);
glVertex2f(-0.73,0.66);
glVertex2f(-0.26,0.66);
glVertex2f(-0.26,0.45);
glEnd();
// beaker1
   glColor3f(1,1,1);    // coloring rect
   glRectf(-0.70f,0.67f,-0.65f,0.77f);

   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.70, 0.77, 0);
        glVertex3f(-0.70, 0.763, 0);
        glVertex3f(-0.72, 0.77, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.65, 0.77, 0);
        glVertex3f(-0.65, 0.763, 0);
        glVertex3f(-0.63, 0.77, 0);
        glEnd();
        // beaker2
   glColor3f(255,255,255);    // coloring rect
   glRectf(-0.58f,0.67f,-0.53f,0.77f);

   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.58, 0.77, 0);
        glVertex3f(-0.58, 0.763, 0);
        glVertex3f(-0.60, 0.77, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.53, 0.77, 0);
        glVertex3f(-0.53, 0.763, 0);
        glVertex3f(-0.51, 0.77, 0);
        glEnd();
//testtube stand
glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.70f,0.45f,-0.65f,0.47f);

  glRectf(-0.35f,0.45f,-0.30f,0.47f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.67f,0.47f,-0.677f,0.6f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.33f,0.47f,-0.325f,0.6f);
  glColor3f(0.64, 0.16, 0.16);    // coloring rect
  glRectf(-0.675f,0.55f,-0.33f,0.56f);
  //testtube
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.63f,0.48f,-0.618f,0.59f);
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.57f,0.48f,-0.558f,0.59f);
 glColor3f(1,1,1);    // coloring rect
  glRectf(-0.51f,0.48f,-0.498f,0.59f);
 glColor3f(1,1,1);    // coloring rect
  glRectf(-0.45f,0.48f,-0.438f,0.59f);
  glColor3f(1,1,1);    // coloring rect
  glRectf(-0.39f,0.48f,-0.378f,0.59f);
  //conical flask
  glColor3f(0.64, 0.16, 0.16);
    glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.41, 0.67, 0);
        glVertex3f(-0.35, 0.67, 0);
        glVertex3f(-0.38, 0.75, 0);
        glEnd();
        glColor3f(1,1,1);    // coloring rect
  glRectf(-0.386f,0.72f,-0.375f,0.80f);
   glPopMatrix();


    glColor3f(0,0,1);
   drawstring(-0.1,0.9,0.0,"OSMOSIS");
   glColor3f(1,0,0);
   drawstring(-0.9,-0.95,0.0,"Press F3 to go back");
    glColor3f(0,0,1);
   drawstring(-0.85,-0.85,0.0,"Note: Osmosis is a process in which molecules of a solvent(grape) pass from a less concentrated solution into a more concentrated one.");
   glColor3f(1,0,1);
   drawstring(-0.9,0.5,0.0,"Procedure:");
   glColor3f(1,0,1);
   drawstring(-0.9,0.4,0.0,"1.Place a grape each in water and sugar solution");
   glColor3f(1,0,1);
   drawstring(-0.9,0.3,0.0,"2.Observe the grape swelling in water over time");
   glColor3f(1,0,1);
   drawstring(-0.9,0.2,0.0,"3.Observe the grape shrinking in sugar solution over time");

    glPushMatrix();
  glTranslatef(0.5,0.6,0);
   glColor3f(0.63,0.16,0.16);
    circle(0.10,0.11);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.5,0.6,0);
    glColor3f(1.0,1.0,1.0);
    circle(0.08,0.09);
    glPopMatrix();

     glPushMatrix();
      glTranslatef(0.5,0.6,0);
    glRotatef(de1,0,0,1);
     glTranslatef(-0.5,-0.6,0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0.5, 0.6);
    glVertex2f(0.54, 0.6);
    glEnd();
     glPopMatrix();

     glPushMatrix();
      glTranslatef(0.5,0.6,0);
    glRotatef(de2,0,0,1);
     glTranslatef(-0.5,-0.6,0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINES);
    glVertex2f(0.5, 0.6);
    glVertex2f(0.5, 0.67);
    glEnd();
    glPopMatrix();

// beaker1
   glColor3f(255,255,255);    // coloring rect
   glRectf(-0.45f,0.10f,-0.15f,-0.30f);
    glColor3f(0.52,0.80,0.92);    // coloring rect
   glRectf(-0.44f,-0.05f,-0.16f,-0.29f);
   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.45, 0.10, 0);
        glVertex3f(-0.45, 0.08, 0);
        glVertex3f(-0.50, 0.10, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(-0.15, 0.10, 0);
        glVertex3f(-0.15, 0.08, 0);
        glVertex3f(-0.10, 0.10, 0);
        glEnd();

        glColor3f(0,0,0);
        glBegin(GL_LINES);
    glVertex2f(-0.451, -0.10);
    glVertex2f(-0.47, -0.12);
    glEnd();

    glColor3f(0,0,0);
        glBegin(GL_LINES);
    glVertex2f(-0.451, -0.10);
    glVertex2f(-0.47, -0.08);
    glEnd();

    glColor3f(0,0,0);
        glBegin(GL_LINES);
    glVertex2f(-0.451, -0.10);
    glVertex2f(-0.50, -0.10);
    glEnd();

        glColor3f(0.63,0.16,0.16);
   drawstring(-0.58,-0.11,0.0,"Water");

        // beaker2
   glColor3f(255,255,255);    // coloring rect
   glRectf(0.15f,0.10f,0.45f,-0.30f);
    glColor3f(0.52,0.80,0.92);    // coloring rect
   glRectf(0.16f,-0.05f,0.44f,-0.29f);
   glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(0.15, 0.10, 0);
        glVertex3f(0.15, 0.08, 0);
        glVertex3f(0.10, 0.10, 0);
        glEnd();
         glBegin(GL_TRIANGLES);
        glColor3f(1,1,1);
        glVertex3f(0.45, 0.10, 0);
        glVertex3f(0.45, 0.08, 0);
        glVertex3f(0.50, 0.10, 0);
        glEnd();

        glColor3f(0,0,0);
        glBegin(GL_LINES);
    glVertex2f(0.451, -0.10);
    glVertex2f(0.47, -0.12);
    glEnd();

    glColor3f(0,0,0);
        glBegin(GL_LINES);
    glVertex2f(0.451, -0.10);
    glVertex2f(0.47, -0.08);
    glEnd();

    glColor3f(0,0,0);
        glBegin(GL_LINES);
    glVertex2f(0.451, -0.10);
    glVertex2f(0.50, -0.10);
    glEnd();

    glColor3f(0.63,0.16,0.16);
   drawstring(0.50,-0.12,0.0,"Sugar solution");

        //table
        glColor3f(0.7,0.7,1.0);    // coloring rect
   glRectf(-0.60,-0.33f,-0.58,0.-0.73f);
     glColor3f(0.7,0.7,1.0); // coloring rect
   glRectf(0.60,-0.33f,0.62,-0.73f);
    glColor3f(0.7,0.7,1.0);  // coloring rect
   glRectf(-0.75,-0.30f,0.77,-0.33f);

   glPushMatrix();
  glTranslatef(-0.30,-0.19,0);
   glColor3f(0.5,0.0,0.5);
    circle(ax1,0.10);
    glPopMatrix();

    glPushMatrix();
  glTranslatef(-0.30,-0.11,0);
   glColor3f(0.7,0.0,0.7);
    circle(0.007,0.014);
    glPopMatrix();

    glPushMatrix();
  glTranslatef(0.30,-0.15,0);
   glColor3f(0.5,0.0,0.5);
    circle(ax2,0.10);
    glPopMatrix();

    glPushMatrix();
  glTranslatef(0.30,-0.07,0);
   glColor3f(0.7,0.0,0.7);
    circle(0.007,0.014);
    glPopMatrix();

   //iron rod
   // glPushMatrix();
//glTranslatef(1, 0.4, 0);
//glRotatef(15, 0, 0, 1);
 // glColor3f(0,0,255);    // coloring rect
 //  glRectf(-0.12f,0.16f,-0.07f,-0.27f);
//glPopMatrix();
   // draw rect

    glFlush();
    glutSwapBuffers();
}

void page2();

void specialkey(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_UP:
        y1a=y1a+a1;
        y2a=y2a+a1;
        y3a=y3a+a1;
        y4a=y4a+a1;
        if(y2a<=0.10&&x1a>=0.27&&y4a<prev)
        {
            x3a=x1a;
            x4a=x2a;
            y3a=0;
            y4a=y2a;
            b1=1;
            prev=y4a;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        y1a=y1a-a1;
        y2a=y2a-a1;
        y3a=y3a-a1;
        y4a=y4a-a1;
       if(y2a<=0.10&&x1a>=0.27&&y4a<prev)
        {
            x3a=x1a;
            x4a=x2a;
            y3a=0;
            y4a=y2a;
            b1=1;
             prev=y4a;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_LEFT:
        x1a=x1a-a1;
        x2a=x2a-a1;
        x3a=x3a-a1;
        x4a=x4a-a1;
         if(y2a<=0.10&&x1a>=0.27&&y4a<prev)
        {
            x3a=x1a;
            x4a=x2a;
            y3a=0;
            y4a=y2a;
            b1=1;
             prev=y4a;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        x1a=x1a+a1;
        x2a=x2a+a1;
        x3a=x3a+a1;
        x4a=x4a+a1;
         if(y2a<=0.10&&x1a>=0.27&&y4a<prev)
        {
            x3a=x1a;
            x4a=x2a;
            y3a=0;
            y4a=y2a;
            b1=1;
             prev=y4a;
        }
        glutPostRedisplay();
        break;
    case GLUT_KEY_F3 :
        x1a=-0.90;
        y1a=0.70;x2a=-0.85;y2a=0.30;
        x3a=0;y3a=0;x4a=0;y4a=0;
        glutDestroyWindow(bac1);
    }
}

void page3()
{
    //glutInit(&argc,argv);
	//glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	bac1++;
	glutInitWindowSize(3200, 1200);
    glutInitWindowPosition(0,0);
	glutCreateWindow("LITMUS PAPER TEST");
	//init3();
	glutDisplayFunc(display1);
	glutSpecialFunc(specialkey);
	glutMainLoop();
}

void page4()
{
    bac1++;
	glutInitWindowSize(3200, 1200);
    glutInitWindowPosition(0,0);
	glutCreateWindow("Acid Base Neutralization");
	//init3();
	glutDisplayFunc(display2);
	glutSpecialFunc(specialkey);
	glutTimerFunc( 1, timer1, 0);
	glutMainLoop();
}

void page5()
{
    bac1++;
	glutInitWindowSize(3200, 1200);
    glutInitWindowPosition(0,0);
	glutCreateWindow("Rusting Of Iron");
	//init3();
	glutDisplayFunc(display3);
	glutSpecialFunc(specialkey);
	glutTimerFunc( 2000, timer, 0);
	glutMainLoop();
}

void page6()
{
     bac1++;
	glutInitWindowSize(3200, 1200);
    glutInitWindowPosition(0,0);
	glutCreateWindow("Demonstration of Osmosis using Grape");
	//init3();
	glutDisplayFunc(display4);
	glutSpecialFunc(specialkey);
	glutTimerFunc( 1, timer2, 0);
	glutMainLoop();
}

void keyPressed (unsigned char key, int x, int y) {
    if (key == '1')
       glutDisplayFunc(page3);
    else if(key== '2')
       glutDisplayFunc(page4);
    else if(key== '3')
       glutDisplayFunc(page5);
    else if(key=='4')
       glutDisplayFunc(page6);
}

void page2()
{
    glClearColor(1.0,1.0,0.5,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(215,475);
	for(j=0;j<strlen(str13);j++)
	{
		glColor3f(1,0,1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str13[j]);
	}

	glRasterPos2f(30,440);

	for(j=0;j<strlen(str14);j++)
	{
		glColor3f(1,0,1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str14[j]);
	}
	glRasterPos2f(30,340);

	for(j=0;j<strlen(str15);j++)
	{
	    glColor3f(1,0,1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str15[j]);
	}

    glRasterPos2f(30,240);
    for(j=0;j<strlen(str16);j++)
	{
	    glColor3f(1,0,1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str16[j]);
	}

    glRasterPos2f(30,140);
    for(j=0;j<strlen(str17);j++)
	{
	    glColor3f(1,0,1);
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,str17[j]);
	}

	glutKeyboardFunc(keyPressed);
	glEnd();
	glutPostRedisplay();
	glFlush();
}

void onmouse1(int btn,int st, int x, int y){
    if(btn==GLUT_LEFT_BUTTON && st==GLUT_DOWN)
        glutDisplayFunc(page2);
}

//void hello()
//{
//}

int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(3200,1200);
	glutInitWindowPosition(0,0);
	glutCreateWindow("CHEMISTRY EXPERIMENT SIMULATION");
    myinit();
	glutDisplayFunc(mydisplay);
	glutMouseFunc(onmouse1);
	glutMainLoop();
	return 0;
}
