#pragma once
#include "Object2D.h"
#include "Line2D.h"
#include <math.h>

class Spaceship:public Object2D
{
	
public:
	Spaceship(Point2D center, float radius)
	{
		color.r = color.b = color.g = 1;
		fill = false;
		type = 4;
		centru = new Point2D();
		centru->x = center.x;
		centru->y = center.y;
		lungime = radius;

		//construim lista de puncte tinand cont de centru si raza
		float u;
		float du = 30;
		float u_rad;
		for (u = 0; u <= 180; u+=du){
			Point2D *p = new Point2D();
			u_rad = (float) (u * 3.14159 / 180);
			p->x = center.x + radius * cos(u_rad);
			p->y = center.y + radius * sin(u_rad);
			points.push_back(p);
			transf_points.push_back(new Point2D(p->x,p->y));
		}
		/*Point2D *p1 = new Point2D(); p1->x = center.x-2*radius ;  p1->y = center.y-radius/2;
		points.push_back(p1);
		transf_points.push_back(p1);
		Point2D *p2 = new Point2D(); p2->x = center.x+2*radius ;  p2->y = center.y-radius/2;
		points.push_back(p2);
		transf_points.push_back(p2);*/


	}
	Spaceship(Point2D center, float radius, Color _color, bool _fill)
	{
		fill = _fill;
		color.r = _color.r;
		color.g = _color.g;
		color.b = _color.b;
		type = 4;
		centru = new Point2D();
		centru->x = center.x;
		centru->y = center.y;
		lungime = radius;
		
		//construim lista de puncte tinand cont de centru si raza
		float u;
		float du = 30;
		float u_rad;
		Point2D first, last;
		for (u = 0; u <= 180; u+=du){
			Point2D *p = new Point2D();
			u_rad = (float) (u * 3.14159 / 180);
			p->x = center.x + radius * cos(u_rad);
			p->y = center.y + radius * sin(u_rad);
			if(u==0){
				first.x= p->x;
				first.y= p->y;
			}
			if(u==180){
				last.x= p->x;
				last.y= p->y;
			}
			points.push_back(p);
			transf_points.push_back(new Point2D(p->x,p->y));
		}

		/*Point2D *p1 = new Point2D(); p1->x = center.x-radius ;  p1->y = center.y-radius/2;
		points.push_back(p1);
		transf_points.push_back(p1);
		Point2D *p2 = new Point2D(); p2->x = center.x+radius ;  p2->y = center.y-radius/2;
		points.push_back(p2);
		transf_points.push_back(p2);*/
		
	}

	~Spaceship() {}
};