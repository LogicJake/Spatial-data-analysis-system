#ifndef POINT_H
#define POINT_H
#include<iostream>
#include<string> 
using namespace std;
class Shape{
	protected:
		int obj_id; //对象标识符
		string des; //描述对象特征
	public:
		virtual float Area() = 0; //纯虚函数
		virtual void WriteToFile(ofstream& o) = 0;
		string getdes()
		{
			return des;
		}
		int getid()
		{
			return obj_id;
		}
		void writedes(string d)
		{
			des=d;
		}

}; 
class Point:public Shape
{
	public:
		float x, y;
		float a;
		static int count;
	public:
		Point();			//无参构造函数 
		Point(float xx,float yy); //有参构造函数 
		Point(const Point &p);			//拷贝构造函数 
		virtual float Area();
		friend ostream& operator<<(ostream& o,const Point& p); 
		friend istream& operator>>(istream& i,Point& p);
		friend bool operator<(Point &p1,Point &p2);
		friend Point operator+(Point &p1,Point &p2);
		static void inccount(){count++;}
		static int GetCount(){return count;}
		float Distance(const Point&p2);
		void Distance_R();
		void Distance_L();
		virtual void WriteToFile(ofstream& o); 
		friend class Rect;
		friend class Line;
};


#endif
