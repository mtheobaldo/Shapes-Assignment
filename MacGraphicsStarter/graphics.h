//
//  shapes.h
//  MacGraphicsStarter
//
//  Created by Maxwell Theobald on 11/11/15.
//
//

#ifndef shapes_h
#define shapes_h


void DrawCircle(double x1, double y1, double radius);
void DrawRectangle(double x1, double y1, double x2, double y2);
void DrawTriangle(double x1, double y1, double x2, double y2, double x3, double y3);
void DrawText(double x, double y, const char *string);
void display(void);
void keyboard(unsigned char c, int x, int y);
void reshape(int w, int h);
void mouse(int mouse_button, int state, int x, int y);
void InitializeMyStuff();

#endif /* shapes_h */
