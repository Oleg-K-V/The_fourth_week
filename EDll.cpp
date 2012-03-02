// EDll.cpp: определяет экспортированные функции для приложения DLL.
//
#include "stdafx.h"
#include <iostream>
#define DE extern "C" __declspec(dllexport)
struct Point
{
	double x,y;
};
//---------------------------------------------------------
struct Line
{
	Point a, b;
};
//---------------------------------------------------------
DE void PointPut(const double& x, const double& y, Point& p)
{
	p.x = x;
	p.y = y;//записуєм дані
}
//--------------------------------------------------------
DE void PointShow(const Point& p )
{
	std::cout << '(' << p.x << ';' << p.y << ')';
}
//--------------------------------------------------------
int PointEqualX(const Point& a, const Point& b)
{
	if (abs(a.x - b.x) < 0.01l)
		return 1;
	return 0;
}
//--------------------------------------------------------
int PointEqualY(const Point& a, const Point& b)
{
	if (abs(a.y - b.y) < 0.01l)
		return 1;
	return 0;
}
//--------------------------------------------------------
DE void LinePut(const Point& a, const Point& b, Line& p)
{
	p.a = a;
	p.b = b;//записуєм лінію
}
//--------------------------------------------------------
double Length(const Point& a, const Point& b)
{
	double zm1, zm2;
	zm1 = (double) ((a.x - b.x) * (a.x - b.x));
	zm2 = (double) ((a.y - b.y) * (a.y - b.y));
	return pow(zm1 + zm2, 0.5);//визначаєм довжину
}
//--------------------------------------------------------
DE void LineShow(const Line& l)
{
	std::cout << '(' << l.a.x << ';' << l.a.y << ')' << '-' << '(' << l.b.x << ';' << l.b.y << ')' ;
}
//--------------------------------------------------------
DE double LineLength(const Line& l)
{
	return Length(l.a,l.b);//визначаєм довжину відрізка
}
//--------------------------------------------------------
int Point_Line(const Line& l, const Point& p)
{
	double X,Y;
	X = (p.x - l.a.x) / (l.b.x - l.a.x);
	Y = (p.y - l.a.y) / (l.b.y - l.a.y);
	if ((abs(X - Y)) < 0.01)
		return 0;
	return 1;//перевіка чи лінія лежить на одній прямій з точкою
}
//--------------------------------------------------------
DE int PointOnLine(const Line& l, const Point& p)
{
	if ((l.b.x - l.a.x) == 0)
	{
		if (PointEqualX(l.a, p))
			return 0;
	}
	else if ((l.b.y - l.a.y) == 0)
	{
		if (PointEqualY(l.a, p))
			return 0;
	}
	else 
	{
		return Point_Line(l, p);
	}
	return 1;//Перевіряєм всі варіанти попадання точки на пряму
}
//--------------------------------------------------------
DE int PointInLine(const Line& l, const Point& p)//Point a,Point b,Point p)
{
	if ((l.b.x - l.a.x) == 0)
	{
		if (((l.a.y <= p.y && p.y <= l.b.y) || (l.a.y >= p.y && p.y >= l.b.y)) && (PointEqualX(l.a, p)))
			return 0;
	}
	else if ((l.b.y - l.a.y) == 0)
	{
		if (((l.a.x <= p.x && p.x <= l.b.x) || (l.a.x >= p.x && p.x >= l.b.x)) && (PointEqualY(l.a, p)))
			return 0;
	}
	else if( !(p.x > l.a.x && p.x > l.b.x) || !(p.y > l.a.y && p.y > l.b.y)) 
	{
		return Point_Line(l, p);
	}
	return 1;//перевіряєм всі варіанти попадання точки на відрізок
}
//--------------------------------------------------------
double Perimeter(const double& A, const double& B, const double& C)
{
	return A + B + C;//шукаєм перимтр
}
//--------------------------------------------------------
double Area(const Point& a, const Point& b,const Point& p)
{
	double A, B, C;
	A = Length(a, b);
	B = Length(b, p);
	C = Length(p, a);	
	double Per = Perimeter(A, B, C) / 2;
	return sqrt(Per * (Per - A) * (Per - B) * (Per - C));//шукаєм площу
}
//--------------------------------------------------------
DE double LineArea(const Line& l, const Point& p)
{
	return Area(l.a, l.b, p);//площа лінії і точки 
}
