#ifndef RECT_H
#define RECT_H
#include"Point.h" 
#include<string>
#include<fstream>
using namespace std;
class Rect: public Shape{ //������
	private:
		Point lp; //���½�
		Point rp; //���Ͻ�
		static int count;
	public:
		Rect();			//�޲ι��캯�� 
		Rect(Point a,Point b); 
		Rect(const Rect &r);			//�������캯��  
		friend ostream& operator<<(ostream& o,const Rect& r); 
		friend istream& operator>>(istream& i,Rect& r);
		friend Rect &operator+(Rect &r1,Rect &r2);
		friend bool operator<(Rect &r1,Rect &r2);
		static int GetCount(){return count;}
		static void inccount(){count++;} 
		void setdata(float ,float ,float ,float);
		virtual float Area(); 
		float Distance(const Rect&r2);
		virtual void WriteToFile(ofstream& o);
		friend class Point;
};

#endif