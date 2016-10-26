#include "Rect.h"
#include"Point.h"
#include <iostream>
#include<math.h>
#include<string>
#include<fstream>
using namespace std;
Rect::Rect()
{
	lp.x=0;
	lp.y=0;
	rp.x=0;
	rp.y=0;
}
Rect::Rect(Point a,Point b)
{
	lp=a;
	rp=b;
}
float Rect::Area()
{
	float dx=rp.x-lp.x;
	float dy=rp.y-lp.y;
	return dx*dy;
}
Rect::Rect(const Rect &r)
{
	obj_id=r.obj_id;
	lp=r.lp;
	rp=r.rp;
	des=r.des;
}
void Rect::setdata(float xx1,float yy1,float xx2,float yy2)
{
	lp.x=xx1;
	lp.y=yy1;
	rp.x=xx2;
	rp.y=yy2;
}
ostream& operator<<(ostream& o,const Rect& r)
{
	o<<"id:"<<r.obj_id<<" "<<"lp:"<<"("<<r.lp.x<<","<<r.lp.y<<")"<<" "<<"rp:"<<"("<<r.rp.x<<","<<r.rp.y<<")"<<" "<<r.des;
	return o;
}
istream& operator>>(istream& i,Rect& r)
{
	int id;
	string des; 
	float area;
	float xx1,xx2,yy1,yy2;
	i>>r.obj_id>>xx1>>yy1>>xx2>>yy2>>area>>r.des;
	r.setdata(xx1,yy1,xx2,yy2);
	return i;
}
Rect r3;
Rect &operator+(Rect &r1,Rect &r2)
{
	if(r1.lp<r2.lp)
		r3.lp=r1.lp;
	else
		r3.lp=r2.lp;
	if(r1.rp<r2.rp)
		r3.rp=r2.rp;
	else 
		r3.rp=r1.rp;
	return r3;
}
float Rect::Distance(const Rect&r2)
{

	float d[16];
	Point lp2(lp.x,rp.y);
	Point rp2(rp.x,lp.y);
	Point lp3(r2.lp.x,r2.rp.y);
	Point rp3(r2.rp.x,r2.lp.y);
	d[0]=lp.Distance(lp3);
	d[1]=lp.Distance(r2.lp);
	d[2]=lp.Distance(r2.rp);
	d[3]=lp.Distance(rp3);
	d[4]=lp2.Distance(lp3);
	d[5]=lp2.Distance(r2.lp);
	d[6]=lp2.Distance(r2.rp);
	d[7]=lp2.Distance(rp3);
	d[8]=rp.Distance(r2.lp);
	d[9]=rp.Distance(lp3);
	d[10]=rp.Distance(r2.rp);
	d[11]=rp.Distance(rp3);
	d[12]=rp2.Distance(r2.lp);
	d[13]=rp2.Distance(r2.rp);
	d[14]=rp2.Distance(lp3);
	d[15]=rp2.Distance(rp3);
	int mini=0;
	for(int i=0;i<16;i++)
	{
		if(d[mini]>d[i])
			mini=i;
	}
	return d[mini];
}
void Rect::WriteToFile(ofstream& o)
{
	o<<obj_id<<" "<<"("<<lp.x<<","<<lp.y<<")"<<" "<<"("<<rp.x<<","<<rp.y<<")"<<" "<<des<<endl;
}
bool operator<(Rect &r1,Rect &r2)
{
	if(r1.getdes()<r2.getdes())
		return true;
	else 
		return false;
}
