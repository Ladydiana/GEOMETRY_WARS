#pragma once
#include "Object2D.h"
#include <math.h>

class Hero:public Object2D
{
	
public:
	Hero(Point2D center, float radius, Color _color)
	{
		color.r = _color.r;
		color.g = _color.g;
		color.b = _color.b;
		fill = false;
		type = 3;
		centru= new Point2D();
		centru->x= center.x;
		centru->y= center.y;
		lungime= radius;
		
		//construim lista de puncte tinand cont de centru si raza

		float u;
		float du = 10;
		float u_rad;
		for (u = 0; u <= 360; u+=du)
		{
			Point2D *p = new Point2D();
			u_rad = (float)(u * 3.14159 / 180);
			p->x = center.x + radius * cos(u_rad);
			p->y = center.y + radius * sin(u_rad);
			points.push_back(p);
			transf_points.push_back(new Point2D(p->x,p->y));
		}

		Point2D *p1 = new Point2D();
		p1->x = (float)(centru->x - lungime);
		p1->y= centru->y;
		points.push_back(p1);
		transf_points.push_back(new Point2D(p1->x,p1->y));

		Point2D *p2 = new Point2D();
		p2->x = centru->x;
		p2->y= (float)(centru->y + lungime);
		points.push_back(p2);
		transf_points.push_back(new Point2D(p2->x,p2->y));

		Point2D *p3 = new Point2D();
		p3->x = (float)(centru->x + lungime);
		p3->y= centru->y;
		points.push_back(p3);
		transf_points.push_back(new Point2D(p3->x,p3->y));

		Point2D *p4 = new Point2D();
		p4->x = centru->x;
		p4->y= (float)(centru->y - lungime);
		points.push_back(p4);
		transf_points.push_back(new Point2D(p4->x,p4->y));

		Point2D *p5 = new Point2D();
		p5->x = (float)(centru->x - lungime);
		p5->y= centru->y;
		points.push_back(p5);
		transf_points.push_back(new Point2D(p5->x,p5->y));
	}

	

	~Hero(){}
};