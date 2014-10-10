#pragma once
#include "Object2D.h"

class Asteroid:public Object2D
{
public:
	Asteroid(Point2D p, float l)
	{
		fill = false;
		color.r = color.b = color.r = 0;
		type = 4;	// e de tip poligon
		centru= new Point2D();
		centru->x= p.x;
		centru->y= p.y;
		lungime= l/2;

		//adauga punctele
		Point2D *p1 = new Point2D(); p1->x = p.x ;  p1->y = p.y+l/2;
		points.push_back(p1);
		transf_points.push_back(p1);
		Point2D *p3 = new Point2D(); p3->x = p.x+l/2; p3->y = p.y;
		points.push_back(p3);
		transf_points.push_back(p3);
		Point2D *p5 = new Point2D(); p5->x = p.x+l/4; p5->y = p.y-l/2;
		points.push_back(p5);
		transf_points.push_back(p5);
		Point2D *p7 = new Point2D(); p7->x = p.x-l/4; p7->y = p.y-l/2;
		points.push_back(p7);
		transf_points.push_back(p7);
		Point2D *p9 = new Point2D(); p9->x = p.x-l/2; p9->y = p.y;
		points.push_back(p9);
		transf_points.push_back(p9);
	}


	Asteroid(Point2D p, float l, Color _color, bool _fill)
	{
		fill = _fill;
		color.r = _color.r;
		color.g = _color.g;
		color.b = _color.b;
		type = 4;
		centru= new Point2D();
		centru->x= p.x;
		centru->y= p.y;
		lungime= l/2;

		//adauga punctele
		Point2D *p1 = new Point2D(); p1->x = p.x ;  p1->y = p.y+l/2;
		points.push_back(p1);
		transf_points.push_back(p1);
		Point2D *p3 = new Point2D(); p3->x = p.x+l/2; p3->y = p.y;
		points.push_back(p3);
		transf_points.push_back(p3);
		Point2D *p5 = new Point2D(); p5->x = p.x+l/4; p5->y = p.y-l/2;
		points.push_back(p5);
		transf_points.push_back(p5);
		Point2D *p7 = new Point2D(); p7->x = p.x-l/4; p7->y = p.y-l/2;
		points.push_back(p7);
		transf_points.push_back(p7);
		Point2D *p9 = new Point2D(); p9->x = p.x-l/2; p9->y = p.y;
		points.push_back(p9);
		transf_points.push_back(p9);
	}

	~Asteroid() {}

};