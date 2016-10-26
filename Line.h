#ifndef LINE_H
#define LINE_H
#include"Point.h"
using namespace std;
class Line:public Shape
{
		Point p1;
		Point p2;
		double len;
		static int count;
	public:
		Line();			//无参构造函数 
		Line(Point a,Point b);		//有参构造函数
		Line(const Line &l);			//拷贝构造函数 
		virtual float Area();
		friend ostream& operator<<(ostream& o,const Line& l);
		friend istream& operator>>(istream& i,Line& l);
		friend operator <(Line &l1,Line &l2);
		static int GetCount(){return count;}
		static void inccount(){count++;} 
		void setdata(float ,float ,float ,float);
		float Distance(const Line&l2);
		float const getlen(){return len;}
		virtual void WriteToFile(ofstream& o);
		friend class Point;
};

#endif
