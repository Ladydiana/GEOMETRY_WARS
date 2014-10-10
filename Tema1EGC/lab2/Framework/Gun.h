#pragma once
#include "Object2D.h"

class Gun:public Object2D
{
public:
	Gun(Point2D p, float l)
	{
		fill = false;
		color.r = color.b = color.r = 0;
		type = 4;	// e de tip poligon
		centru= new Point2D();
		centru->x= p.x+5*l/2;
		centru->y= p.y;
		lungime= l/2;

		//adauga cele 3 puncte
		Point2D *p1 = new Point2D(p.x+2*l, p.y+1/2*l);
		points.push_back(p1);
		transf_points.push_back(p1);
		Point2D *p2 = new Point2D(p.x+3*l, p.y);
		points.push_back(p2);
		transf_points.push_back(p2);
		Point2D *p3= new Point2D(p.x+2*l, p.y-1/2*l);
		points.push_back(p3);
		transf_points.push_back(p3);
		
	}


	Gun(Point2D p, float l, Color _color, bool _fill)
	{
		fill = _fill;
		color.r = _color.r;
		color.g = _color.g;
		color.b = _color.b;
		type = 4;
		centru= new Point2D();
		centru->x= (float)(p.x+2.5*l);
		centru->y= p.y;
		lungime= l/2;

		//adauga cele 3 puncte
		Point2D *p1 = new Point2D((float)(p.x+2*l), (float)(p.y+0.5*l));
		points.push_back(p1);
		transf_points.push_back(p1);
		Point2D *p2 = new Point2D((float)(p.x+3*l), (float)(p.y));
		points.push_back(p2);
		transf_points.push_back(p2);
		Point2D *p3= new Point2D((float)(p.x+2*l), (float)(p.y-0.5*l));
		points.push_back(p3);
		transf_points.push_back(p3);
		
	}

	~Gun() {}

};