// OpenGL/GLUT starter kit for Windows 7 and Visual Studio 2010
// Created spring, 2011
//
// This is a starting point for OpenGl applications.
// Add code to the "display" function below, or otherwise
// modify this file to get your desired results.
//
// For the first assignment, add this file to an empty Windows Console project
//		and then compile and run it as is.
// NOTE: You should also have glut.h,
// glut32.dll, and glut32.lib in the directory of your project.
// OR, see GlutDirectories.txt for a better place to put them.


#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include "point.h"
#include "shape.h"
#include "line.h"
#include "button.h"
#include "rectangle.h"
#include "octagon.h"
#include "triangle.h"
#include "pentagon.h"
#include "slider.h"
#include "circle.h"
#include "color.h"
#include <fstream>
#ifdef _WIN32
  #include "glut.h"
#else
  #ifdef __APPLE__
    #include <GLUT/glut.h>
  #else
    #include <GL/glut.h>
  #endif
#endif


// Global Variables (Only what you need!)
double screen_x = 700;
double screen_y = 500;
const int TRIANGLE = 1;
const int RECTANGLE = 2;
const int CIRCLE = 3;
const int OCTAGON = 4;
const int LINE = 5;
const int PENTAGON = 6;
int MODE = 0;
int OUTLINE_TOGGLE = 0;
Color curr_color;
std::vector<Point> points;
std::vector<Button> buttons;
std::vector<Shape *> shapes;
std::vector<Slider> sliders;
std::vector<Shape *> redos;


// 
// Functions that draw basic primitives
//
void DrawCircle(double x1, double y1, double radius)
{
  glBegin(GL_POLYGON);
  for(int i=0; i<32; i++)
    {
      double theta = (double)i/32.0 * 2.0 * 3.1415926;
      double x = x1 + radius * cos(theta);
      double y = y1 + radius * sin(theta);
      glVertex2d(x, y);
    }
  glEnd();
}

void DrawRectangle(double x1, double y1, double x2, double y2)
{
  glBegin(GL_QUADS);
  glVertex2d(x1,y1);
  glVertex2d(x2,y1);
  glVertex2d(x2,y2);
  glVertex2d(x1,y2);
  glEnd();
}

void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3)
{
  glBegin(GL_TRIANGLES);
  glVertex2d(x1,y1);
  glVertex2d(x2,y2);
  glVertex2d(x3,y3);
  glEnd();
}

// Outputs a string of text at the specified location.
void DrawText(double x, double y, const char *string)
{
  void *font = GLUT_BITMAP_9_BY_15;

  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
  glEnable(GL_BLEND);
	
  int len, i;
  glRasterPos2d(x, y);
  len = (int) strlen(string);
  for (i = 0; i < len; i++) 
    {
      glutBitmapCharacter(font, string[i]);
    }

  glDisable(GL_BLEND);
}


//
// GLUT callback functions
//
// Your initialization code goes here.
void InitializeMyStuff()
{

  Color c = Color(0.6, 0.6, 0.6);
  buttons.push_back(Button(Point(10, 10), Point(100,35), c ));
  buttons.push_back(Button(Point(10, 40), Point(100,65), c ));
  buttons.push_back(Button(Point(10, 70), Point(100,95), c ));
  buttons.push_back(Button(Point(590, 10), Point(690,35), c ));
  buttons.push_back(Button(Point(590, 40), Point(690,65), c ));
  buttons.push_back(Button(Point(10, 190), Point(100,215), c ));
  buttons.push_back(Button(Point(10, 220), Point(100,245), c ));
  buttons.push_back(Button(Point(10, 250), Point(100,275), c ));
  buttons.push_back(Button(Point(10, 280), Point(100,305), c ));
  buttons.push_back(Button(Point(110, 10), Point(200,35), c ));
  buttons.push_back(Button(Point(110, 70), Point(200,95), c ));
  buttons.push_back(Button(Point(110, 100), Point(200,125), c ));
  buttons.push_back(Button(Point(110, 40), Point(200,65), c ));

  sliders.push_back(Slider(Point(10, 100), Point(100,125), curr_color ));
  sliders.push_back(Slider(Point(10, 130), Point(100,155), curr_color ));
  sliders.push_back(Slider(Point(10, 160), Point(100,185), curr_color ));
}



// This callback function gets called by the Glut
// system whenever it decides things need to be redrawn.
void display(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3d(0,1,0);
  for (int i = 0; i<shapes.size(); i++)
  {
	shapes[i]->paint();
  }

  glColor3d(0.6,0.6,0.6);
  for (int i=0; i<points.size(); i++)
  {
	points[i].paint();
  }

  for (int i=0; i < buttons.size(); i++)
  {
	buttons[i].paint();
  }

  for (int i=0; i < sliders.size(); i++)
  {
	sliders[i].paint();
  }
  glColor3d(0,0,0);
  DrawText(15,15,"Circle");
  DrawText(15,45,"Rectangle");
  DrawText(15,75,"Triangle");
  DrawText(595,15,"Quit");
  DrawText(595,45,"Clear");
  DrawText(15,195,"Undo");
  DrawText(15,225,"Redo");
  DrawText(15,255,"Load");
  DrawText(15,285,"Save");
  DrawText(115,15,"Octagon");
  DrawText(115,45,"Pentagon");
  DrawText(115,75,"Line");
  DrawText(115,105,"Outline");

  glColor3d(0.9,0.9,0.9);
  DrawText(15,105,"Red");
  DrawText(15,135,"Green");
  DrawText(15,165,"Blue");

  glColor3d(0,0,0);

  glutSwapBuffers();
}


void load()
{
	std::ifstream fin("save_file.log");
	if(!fin)
	{
		std::cout << "save_file.log did not open." << std::endl;
	}
	Shape * tmp;
	std::string keyword;
	while (fin)
	{
		fin >> keyword;
		if(fin)
		{
			if(keyword == "Triangle")
			{
				Point p1;
				Point p2;
				Point p3;
				Color tmp_color;
				int tmp_outline;

				fin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
				fin >> tmp_color.r >> tmp_color.g >> tmp_color.b >> tmp_outline;

				tmp = new Triangle(p1, p2, p3, tmp_color, tmp_outline);
				shapes.push_back(tmp);
			}
			else if(keyword == "Pentagon")
			{
				Point p1;
				Point p2;
				Point p3;
				Point p4;
				Point p5;
				Color tmp_color;
				int tmp_outline;

				fin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y >> p5.x >> p5.y;
				fin >> tmp_color.r >> tmp_color.g >> tmp_color.b >> tmp_outline;

				tmp = new Pentagon(p1, p2, p3, p4, p5, tmp_color, tmp_outline);
				shapes.push_back(tmp);
			}
			else if(keyword == "Rectangle")
			{
				Point p1;
				Point p2;
				Color tmp_color;
				int tmp_outline;
				fin >> p1.x;
				fin >> p1.y;
				fin >> p2.x;
				fin >> p2.y;
				fin >> tmp_color.r;
				fin >> tmp_color.g;
				fin >> tmp_color.b;
				fin >> tmp_outline;
				tmp = new Rectangle(p1, p2, tmp_color, tmp_outline);
				shapes.push_back(tmp);
			}
			else if(keyword == "Circle")
			{
				Point p1;
				Color tmp_color;
				double tmp_rad;
				int tmp_outline;
				fin >> p1.x;
				fin >> p1.y;
				fin >> tmp_rad;
				fin >> tmp_color.r;
				fin >> tmp_color.g;
				fin >> tmp_color.b;
				fin >> tmp_outline;
				tmp = new Circle(p1, tmp_rad, tmp_color, tmp_outline);
				shapes.push_back(tmp);
			}
			else if(keyword == "Octagon")
			{
				Point p1;
				Color tmp_color;
				double tmp_rad;
				int tmp_outline;
				fin >> p1.x;
				fin >> p1.y;
				fin >> tmp_rad;
				fin >> tmp_color.r;
				fin >> tmp_color.g;
				fin >> tmp_color.b;
				fin >> tmp_outline;
				tmp = new Octagon(p1, tmp_rad, tmp_color, tmp_outline);
				shapes.push_back(tmp);
			}
			else if(keyword == "Line")
			{
				Point p1;
				Point p2;
				Color tmp_color;
				fin >> p1.x;
				fin >> p1.y;
				fin >> p2.x;
				fin >> p2.y;
				fin >> tmp_color.r;
				fin >> tmp_color.g;
				fin >> tmp_color.b;
				tmp = new Line(p1, p2, tmp_color);
				shapes.push_back(tmp);
			}
		}
	}
}

void save()
{
	std::ofstream fout("save_file.log");
	if(!fout)
	{
		std::cout << "save_file.log did not open." << std::endl;
	}
	for (int i = 0; i < shapes.size(); i++)
	{
		fout << *shapes[i] << std::endl;
	}
	fout.close();
}

// This callback function gets called by the Glut
// system whenever any mouse button goes up or down.
void mouse(int mouse_button, int state, int x, int y)
{
  // translate pixel coordinates to display coordinates
  int xdisplay = x;
  int ydisplay = screen_y - y;
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
		Point p = Point(xdisplay, ydisplay);
		Color c_on = Color(0.4, 0.4, 0.4);
		Color c_off = Color(0.6, 0.6, 0.6);
		if (buttons[0].contains(p))
		{
			MODE = CIRCLE;
			buttons[0].col = c_on;
			buttons[1].col = c_off;
			buttons[2].col = c_off;
			buttons[9].col = c_off;
			buttons[10].col = c_off;
			buttons[12].col = c_off;
			points.clear();
		}
		else if (buttons[1].contains(p))
		{
			MODE = RECTANGLE;
			buttons[0].col = c_off;
			buttons[1].col = c_on;
			buttons[2].col = c_off;
			buttons[9].col = c_off;
			buttons[10].col = c_off;
			buttons[12].col = c_off;
			points.clear();
		}
		else if (buttons[2].contains(p))
		{
			MODE = TRIANGLE;
			buttons[0].col = c_off;
			buttons[1].col = c_off;
			buttons[2].col = c_on;
			buttons[9].col = c_off;
			buttons[10].col = c_off;
			buttons[12].col = c_off;
			points.clear();
		}
		else if (buttons[3].contains(p))
		{
			exit(0);
		}
		else if (buttons[4].contains(p))
		{
			points.clear();
			shapes.clear();
		}
		else if (buttons[5].contains(p))
		{
			if (shapes.size() > 0)
			{
				redos.push_back(shapes.back());
				shapes.pop_back();
			}
		}
		else if (buttons[6].contains(p))
		{
			if (redos.size() > 0)
			{
				shapes.push_back(redos.back());
				redos.pop_back();
			}
		}
		else if (buttons[7].contains(p))
		{
			//load code.
			load();
		}
		else if (buttons[8].contains(p)) {
			//save code.
			save();
		}
		else if (buttons[9].contains(p))
		{
			MODE = OCTAGON;
			buttons[0].col = c_off;
			buttons[1].col = c_off;
			buttons[2].col = c_off;
			buttons[9].col = c_on;
			buttons[10].col = c_off;
			buttons[12].col = c_off;
			points.clear();
		}
		else if (buttons[10].contains(p))
		{
			MODE = LINE;
			buttons[0].col = c_off;
			buttons[1].col = c_off;
			buttons[2].col = c_off;
			buttons[9].col = c_off;
			buttons[10].col = c_on;
			buttons[12].col = c_off;
			points.clear();
		}
		else if (buttons[11].contains(p))
		{
			if (OUTLINE_TOGGLE == 0)
			{
				OUTLINE_TOGGLE = 1;
				buttons[11].col = c_on;
			}
			else
			{
				OUTLINE_TOGGLE = 0;
				buttons[11].col = c_off;
			}
			points.clear();
		}
		else if (buttons[12].contains(p))
		{
			MODE = PENTAGON;
			buttons[0].col = c_off;
			buttons[1].col = c_off;
			buttons[2].col = c_off;
			buttons[9].col = c_off;
			buttons[10].col = c_off;
			buttons[12].col = c_on;
			points.clear();
		}
		else if (sliders[0].contains(p))
		{
			sliders[0].adjust(p);
			curr_color.r = sliders[0].adjustment;
			for (int i=0;i<sliders.size();i++)
			{
				sliders[i].setColor(curr_color);
			}
		}
		else if (sliders[1].contains(p))
		{
			sliders[1].adjust(p);
			curr_color.g = sliders[1].adjustment;
			for (int i=0;i<sliders.size();i++)
			{
				sliders[i].setColor(curr_color);
			}
		}
		else if (sliders[2].contains(p))
		{
			sliders[2].adjust(p);
			curr_color.b = sliders[2].adjustment;
			for (int i=0;i<sliders.size();i++)
			{
				sliders[i].setColor(curr_color);
			}
		}
		else if (MODE == CIRCLE)
		{
			if (points.size() == 1)
			{
				//sqrt( (x1-x2)^2 + (y1-y2)^2 );
				double rad;
				rad = sqrt( pow(points[0].x - p.x, 2.0) + pow(points[0].y - p.y, 2.0) );
				Shape * tmp = new Circle(points[0], rad, curr_color, OUTLINE_TOGGLE);
				shapes.push_back(tmp);
				points.clear();
			}
			else if (points.size() < 1)
			{
				points.push_back(p);
			}
		}
		else if (MODE == OCTAGON)
		{
			if (points.size() == 1)
			{
				//sqrt( (x1-x2)^2 + (y1-y2)^2 );
				double rad;
				rad = sqrt( pow(points[0].x - p.x, 2.0) + pow(points[0].y - p.y, 2.0) );
				Shape * tmp = new Octagon(points[0], rad, curr_color, OUTLINE_TOGGLE);
				shapes.push_back(tmp);
				points.clear();
			}
			else if (points.size() < 1)
			{
				points.push_back(p);
			}
		}
		else if (MODE == LINE)
		{
			if (points.size() == 1)
			{
				//sqrt( (x1-x2)^2 + (y1-y2)^2 );
				Shape * tmp = new Line(points[0], p, curr_color);
				shapes.push_back(tmp);
				points.clear();
			}
			else if (points.size() < 1)
			{
				points.push_back(p);
			}
		}
		else if (MODE == RECTANGLE)
		{
			if (points.size() == 1)
			{
				//sqrt( (x1-x2)^2 + (y1-y2)^2 );
				Shape * tmp = new Rectangle(points[0], p, curr_color, OUTLINE_TOGGLE);
				shapes.push_back(tmp);
				points.clear();
			}
			else if (points.size() == 0)
			{
				points.push_back(p);
			}
		}
		else if (MODE == TRIANGLE)
		{
			if (points.size() == 2)
			{
				//sqrt( (x1-x2)^2 + (y1-y2)^2 );
				Shape * tmp = new Triangle(points[0], points[1], p, curr_color, OUTLINE_TOGGLE);
				shapes.push_back(tmp);
				points.clear();
			}
			else if (points.size() < 2)
			{
				points.push_back(p);
			}
		}
		else if (MODE == PENTAGON)
		{
			if (points.size() == 4)
			{
				//sqrt( (x1-x2)^2 + (y1-y2)^2 );
				Shape * tmp = new Pentagon(points[0], points[1], points[2], points[3], p, curr_color, OUTLINE_TOGGLE);
				shapes.push_back(tmp);
				points.clear();
			}
			else if (points.size() < 4)
			{
				points.push_back(p);
			}
		}
		else
		{
			points.clear();
		}
    }
  if (mouse_button == GLUT_LEFT_BUTTON && state == GLUT_UP) 
    {
    }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_DOWN) 
    {
    }
  if (mouse_button == GLUT_MIDDLE_BUTTON && state == GLUT_UP) 
    {
    }
  glutPostRedisplay();
}

// This callback function gets called by the Glut
// system whenever a key is pressed.
void keyboard(unsigned char c, int x, int y)
{
  switch (c) 
    {
    case 'q':
    case 27: // escape character means to quit the program
      exit(0);
      break;
    case 't':
	  MODE = TRIANGLE;
      break;
    case 'r':
	  MODE = RECTANGLE;
      break;
    case 'e':
	  MODE = CIRCLE;
      break;
    case 'c':
	  shapes.clear();
      break;
    case 's':
	  save();
      break;
    case 'l':
	  load();
      break;
    case ' ':
	  mouse(GLUT_LEFT_BUTTON, GLUT_DOWN, x, y);
      break;
    default:
      return; // if we don't care, return without glutPostRedisplay()
    }

  glutPostRedisplay();
}


// This callback function gets called by the Glut
// system whenever the window is resized by the user.
void reshape(int w, int h)
{
  // Reset our global variables to the new width and height.
  screen_x = w;
  screen_y = h;

  // Set the pixel resolution of the final picture (Screen coordinates).
  glViewport(0, 0, w, h);

  // Set the projection mode to 2D orthographic, and set the world coordinates:
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, 0, h);
  glMatrixMode(GL_MODELVIEW);

}

int main(int argc, char **argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(screen_x, screen_y);
  glutInitWindowPosition(50, 50);

  int fullscreen = 0;
  if (fullscreen) 
    {
      glutGameModeString("800x600:32");
      glutEnterGameMode();
    } 
  else 
    {
      glutCreateWindow("Shapes 3.0");
    }

  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  glutReshapeFunc(reshape);
  glutMouseFunc(mouse);

  glColor3d(0,0,0); // forground color
  glClearColor(1, 1, 1, 0); // background color
  InitializeMyStuff();
  display();
  glutMainLoop();

  return 0;
}
