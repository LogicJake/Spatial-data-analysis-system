#include "Point.h"
#include "Rect.h"
#include "Line.h"
#include<string>
#include<iostream>
#include<fstream> 
#include<math.h>
#include <vector>
#include<iterator>
using namespace std;
Point::Point()
{
	x=y=0;
}
Point::Point(float xx,float yy)
{
	x=xx;
	y=yy;
}
Point::Point(const Point &p)
{
	obj_id=p.obj_id;
	x=p.x;
	y=p.y;
	des=p.des;
}
float Point::Area()
{
	return 0;
}
ostream& operator<<(ostream& o, const Point& p)
{
	o<<"id:"<<p.obj_id<<" "<<"("<<p.x<<","<<p.y<<")"<<" "<<"des:"<<p.des;
	return o;
}
istream& operator>>(istream& i,Point& p)
{
	i>>p.obj_id>>p.x>>p.y>>p.a>>p.des;
	return i;
}
bool operator<(Point &p1,Point &p2)
{
	if(p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y)) 
		return 1;
	else 
		return 0;
		
}
Point operator+(Point &p1,Point &p2)
{
	Point p3;
	p3.x=p1.x+p2.x;
	p3.y=p1.y+p2.y;
	return p3;
}
float Point::Distance(const Point&p2)
{
	float dx=x-p2.x;
	float dy=y-p2.y;
	return sqrt(dx*dx+dy*dy);
}
void Point::Distance_R()
{
	Rect r2;
	vector<Rect> r;
	Rect temp_rect;
	vector<Rect>::iterator k;
	ifstream file3;
	file3.open("rect.txt");
	if(!file3)
		cout<<"fail"; 
	while(!file3.eof())
	{
		file3>>temp_rect;
		r.push_back(temp_rect);
	}

	int choice;
	cout<<"请输入rect序号：";
	cin>>choice;
	cout<<"你选择的rect的数据为"<<endl<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				r2=*k;	
			}
			
	}
	float d[4];
	Point lp1(r2.lp.x,r2.rp.y);
	Point rp1(r2.rp.x,r2.lp.y);
	d[0]=this->Distance(lp1);
	d[1]=this->Distance(rp1);
	d[2]=this->Distance(r2.lp);
	d[3]=this->Distance(r2.rp);
	int mini=0;
	for(int i=0;i<4;i++)
	{
		if(d[mini]>d[i])
			mini=i;
	}
	cout<<"the distance is:"<<d[mini]<<endl;
	file3.close(); 
}
void Point::Distance_L()
{
	Line l1;
	vector<Line> l;
	vector<Line>::iterator j;
	Line temp_line;
	ifstream file2;
	file2.open("Line.txt");
	if(!file2)
		cout<<"fail"; 
	
	while(!file2.eof())
	{
		file2>>temp_line;
		l.push_back(temp_line);
	}
	
	int choice;
	cout<<"请输入line序号；"; 
	cin>>choice;
	cout<<"你选择的line的数据为"<<endl<<endl; 
	for(j=l.begin();j!=l.end();j++)
	{
		if(j->getid()==choice)
			{
				cout<<*j<<endl<<endl;
				l1=*j;	
			}
			
	}
	float d[2];
	d[0]=this->Distance(l1.p1);
	d[1]=this->Distance(l1.p2);
	int mini=0;
	for(int i=0;i<2;i++)
	{
		if(d[mini]>d[i])
			mini=i;
	}
	cout<<"the distance is:"<<d[mini]<<endl;
	file2.close();
}
void Point:: WriteToFile(ofstream& o)
{
	o<<obj_id<<" "<<"("<<x<<","<<y<<")"<<" "<<des<<endl;
} 
