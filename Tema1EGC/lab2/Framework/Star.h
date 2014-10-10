#pragma once
#include "Object2D.h"

class Star:public Object2D
{
public:
	Star(Point2D p, float l)
	{
		fill = false;
		color.r = color.b = color.r = 0;
		type = 4;	// e de tip poligon
		centru= new Point2D();
		centru->x= p.x;
		centru->y= p.y;
		lungime= l/2;

		//adauga cele zece puncte ale stelei
		Point2D *p1 = new Point2D(); p1->x = p.x ;  p1->y = p.y+l/2;
		points.push_back(p1);
		transf_points.push_back(p1);
		Point2D *p2 = new Point2D(); p2->x = p.x +l/8;  p2->y = p.y+l/8;
		points.push_back(p2);
		transf_points.push_back(p2);
		Point2D *p3 = new Point2D(); p3->x = p.x+l/2; p3->y = p.y;
		points.push_back(p3);
		transf_points.push_back(p3);
		Point2D *p4 = new Point2D(); p4->x = p.x+l/8; p4->y = p.y-l/8;
		points.push_back(p4);
		transf_points.push_back(p4);
		Point2D *p5 = new Point2D(); p5->x = p.x+l/4; p5->y = p.y-l/2;
		points.push_back(p5);
		transf_points.push_back(p5);
		Point2D *p6 = new Point2D(); p6->x = p.x; p6->y = p.y-l/8;
		points.push_back(p6);
		transf_points.push_back(p6);
		Point2D *p7 = new Point2D(); p7->x = p.x-l/4; p7->y = p.y-l/2;
		points.push_back(p7);
		transf_points.push_back(p7);
		Point2D *p8 = new Point2D(); p8->x = p.x-l/8; p8->y = p.y-l/8;
		points.push_back(p8);
		transf_points.push_back(p8);
		Point2D *p9 = new Point2D(); p9->x = p.x-l/2; p9->y = p.y;
		points.push_back(p9);
		transf_points.push_back(p9);
		Point2D *p10 = new Point2D(); p10->x = p.x-l/8; p10->y = p.y+l/8;
		points.push_back(p10);
		transf_points.push_back(p10);
	}


	Star(Point2D p, float l, Color _color, bool _fill)
	{
		fill = _fill;
		color.r = _color.r;
		color.g = _color.g;
		color.b = _color.b;
		type = 4;
		centru= new Point2D();
		centru->x= p.x;
		centru->y= p.y;
		lungime= l;

		//adauga cele zece puncte ale stelei
		Point2D *p1 = new Point2D(); p1->x = p.x ;  p1->y = p.y+l/2;
		points.push_back(p1);
		transf_points.push_back(p1);
		Point2D *p2 = new Point2D(); p2->x = p.x +l/8;  p2->y = p.y+l/8;
		points.push_back(p2);
		transf_points.push_back(p2);
		Point2D *p3 = new Point2D(); p3->x = p.x+l/2; p3->y = p.y;
		points.push_back(p3);
		transf_points.push_back(p3);
		Point2D *p4 = new Point2D(); p4->x = p.x+l/8; p4->y = p.y-l/8;
		points.push_back(p4);
		transf_points.push_back(p4);
		Point2D *p5 = new Point2D(); p5->x = p.x+l/4; p5->y = p.y-l/2;
		points.push_back(p5);
		transf_points.push_back(p5);
		Point2D *p6 = new Point2D(); p6->x = p.x; p6->y = p.y-l/8;
		points.push_back(p6);
		transf_points.push_back(p6);
		Point2D *p7 = new Point2D(); p7->x = p.x-l/4; p7->y = p.y-l/2;
		points.push_back(p7);
		transf_points.push_back(p7);
		Point2D *p8 = new Point2D(); p8->x = p.x-l/8; p8->y = p.y-l/8;
		points.push_back(p8);
		transf_points.push_back(p8);
		Point2D *p9 = new Point2D(); p9->x = p.x-l/2; p9->y = p.y;
		points.push_back(p9);
		transf_points.push_back(p9);
		Point2D *p10 = new Point2D(); p10->x = p.x-l/8; p10->y = p.y+l/8;
		points.push_back(p10);
		transf_points.push_back(p10);
	}

	~Star() {}

};