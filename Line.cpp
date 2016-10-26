#include "Line.h"
#include "Point.h"
#include<iostream>
#include <math.h>
#include<fstream>
using namespace std;
Line::Line()
{
	p1.x=0;
	p1.y=0;
	p2.x=0;
	p2.y=0;
}
Line::Line(Point a,Point b)
{
	p1=a;
	p2=b;
}
Line::Line(const Line &l)
{
	obj_id=l.obj_id;
	p1=l.p1;
	p2=l.p2;
	len=l.len;
}
float Line::Area()
{
	float dx=p1.x-p2.x;
	float dy=p1.y-p2.y;
	len=sqrt(dx*dx+dy*dy);
	return len;
}
void Line::setdata(float xx1,float yy1,float xx2,float yy2)
{
	p1.x=xx1;
	p1.y=yy1;
	p2.x=xx2;
	p2.y=yy2;
}
ostream& operator<<(ostream& o,const Line& l)
{
	o<<"id:"<<l.obj_id<<" "<<"p1:"<<"("<<l.p1.x<<","<<l.p1.y<<")"<<" "<<"p2:"<<"("<<l.p2.x<<","<<l.p2.y<<")";
	return o;
 } 
 istream& operator>>(istream& i,Line& l)
{
	int id;
	string des="null"; 
	float xx1,xx2,yy1,yy2;
	i>>l.obj_id>>xx1>>yy1>>xx2>>yy2>>l.len;
	l.setdata(xx1,yy1,xx2,yy2);
	return i;
}
float Line::Distance(const Line&l2)
{
	float d[4];
	d[0]=p1.Distance(l2.p1);
	d[1]=p1.Distance(l2.p2);
	d[2]=p2.Distance(l2.p1);
	d[3]=p2.Distance(l2.p2);
	int mini=0;
	for(int i=0;i<4;i++)
	{
		if(d[mini]>d[i])
			mini=i;
	}
	return d[mini];
}
void Line::WriteToFile(ofstream& o)
{
	o<<obj_id<<" "<<"("<<p1.x<<","<<p1.y<<")"<<" "<<"("<<p2.x<<","<<p2.y<<")"<<" "<<len<<endl; 
}
operator <(Line &l1,Line &l2)
{
	if(l1.len<l2.len)
		return 1;
	else 
		return 0; 
}
