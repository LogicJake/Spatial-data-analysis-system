#include <iostream>
#include <fstream> 
#include<stdlib.h>
#include <conio.h>
#include"Point.h"
#include"Rect.h"
#include"Line.h"
#include<iterator> 
#include<string> 
#include <vector>
#include<cctype>
#include<algorithm>
void display();
void task_2_1();
void task_2_2();
void task_3();
void task_4();
void task_5();
void task_6();
int Line::count=0;
int Point::count=0;
int Rect::count=0; 
using namespace std;
int main() 
{
	system("mode con cols=90 lines=5000");
	display();
	cout<<"������������ţ�";
	int choice;
	cin>>choice;
	while(choice>0)
	{
		if(choice==1)
		{
			task_2_1();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"������������ţ�";
			cin>>choice;
			
		}
		if(choice==2)
		{
			task_2_2();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"������������ţ�";	
			cin>>choice;
			
		}
		if(choice==3)
		{
			task_3();
			cout<<"Press any key to continue" ;
			getch();
			system("cls"); 
			display();
			cout<<"������������ţ�";	
			cin>>choice; 
		 
		}
		if(choice==4)
		{
			task_4();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"������������ţ�";
			cin>>choice; 
		}	
		if(choice==5)
		{
			task_5();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"������������ţ�";
			cin>>choice; 
		}	
		if(choice==6)
		{
			task_6();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"������������ţ�";
			cin>>choice; 
		}		
	 } 
}
void WriteData(Shape* s, ofstream& out_file)
{
	s->WriteToFile(out_file);
}
ifstream file("point.txt");
ifstream file2("line.txt");
ifstream file3("rect.txt");
vector<Point> p;
vector<Point>::iterator i;
Point temp_point;
vector<Line> l;
vector<Line>::iterator j;
Line temp_line;
vector<Rect> r;
vector<Rect>::iterator k;
Rect temp_rect;
void display()
{
	cout<<"\t\t\t"<<"1>����2.1:����������" <<endl;
	cout<<"\t\t\t"<<"2>����2.2:����des��ͬ"<<endl;
	cout<<"\t\t\t"<<"3>����3:Ѱ�������ֵ������"<<endl;
	cout<<"\t\t\t"<<"4>����4:��ʾoperator+��<"<<endl; 
	cout<<"\t\t\t"<<"5>����5:��ʾdistance()����"<<endl;
	cout<<"\t\t\t"<<"6>����6:����д���ļ�"<<endl;
}
void task_2_1()
{
	
	if(!file)
		cout<<"open Point.txt fail"<<endl; 
	if(!file2)
		cout<<"open Line.txt fail"<<endl;
	if(!file3)
		cout<<"open Rect.txt fail"<<endl; 
	while(!file.eof())
	{
		file>>temp_point;
		p.push_back(temp_point);
		Point::inccount();
	}
	cout<<"point.txt�ж�������ǣ�"<<Point::GetCount()<<endl;	
	
	 
	
	while(!file2.eof())
	{
		file2>>temp_line;
		l.push_back(temp_line);
		Line::inccount();
	}
	cout<<"line.txt�ж�������ǣ�"<<Line::GetCount()<<endl;
	
	
	
	while(!file3.eof())
	{
		file3>>temp_rect;
		r.push_back(temp_rect);
		Rect::inccount();
	}
	cout<<"rect.txt�ж�������ǣ�"<<Rect::GetCount()<<endl;	

	file.close();
	file2.close();
	file3.close();
}
void task_2_2()
{
	
	int choice;
	string obj_des;
	cout<<"����������һ��point�����:";
	cin>>choice;
	cout<<"��ѡ���point������Ϊ"<<endl<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				obj_des=i->getdes();
			}
			
	}
	cout<<"�뱻ѡ���point��des��ͬ�ĵ�rect������ʾ����"<<endl<<endl ;
	for(k=r.begin();k!=r.end()-1;k++)
	{
		if(k->getdes()==obj_des)
			cout<<*k<<endl;
	}
	cout<<"��ʾ��ϣ�������һ��������"<<endl; 
	cout<<endl<<"����������һ��rect�����:";
	cin>>choice;
	system("cls"); 
	cout<<"��ѡ���rect������Ϊ"<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				obj_des=k->getdes();
			}
			
	}
	cout<<"�뱻ѡ���rect��des��ͬ��point������ʾ����"<<endl<<endl ;
	for(i=p.begin();i!=p.end()-1;i++)
	{
		if(i->getdes()==obj_des)
			cout<<*i<<endl;
	}
	cout<<"��ʾ��ϣ�������һ��������"<<endl; 
}
void task_3()
{
	vector<Rect>::iterator small,big;
	small=r.begin(); 
	big=r.begin();
	for(k=r.begin()+1;k!=r.end()-1;k++)
	{

		if(small->Area()>k->Area())
		{
			small=k;

		}
			
	}
	ofstream outfile("Rect_data.txt");
	outfile<<"�����С"<<endl;
	for(k=r.begin()+1;k!=r.end()-1;k++)
	{
		if(k->Area()==small->Area())
			outfile<<*k<<" "<<"Area:"<<small->Area()<<endl;
	}
	
	
	outfile<<"������"<<endl;
	for(k=r.begin()+1;k!=r.end()-1;k++)
	{
		if(big->Area()<k->Area())
		{
			big=k;
		}
			
	}
	for(k=r.begin()+1;k!=r.end()-1;k++)
	{
		if(k->Area()==big->Area())
			outfile<<*k<<" "<<"Area:"<<k->Area()<<endl;
	}
	outfile.close();
	
	
	vector<Line>::iterator small_line,big_line;
	small_line=l.begin(); 
	big_line=l.begin();

	for(j=l.begin()+1;j!=l.end()-1;j++)
	{

		if(small_line->Area()>j->Area())
		{
			small_line=j;

		}
			
	}
	ofstream outfile2("Line_data.txt");
	outfile2<<"�������"<<endl;
	for(j=l.begin()+1;j!=l.end()-1;j++)
	{
		if(j->Area()==small_line->Area())
			outfile2<<*j<<" "<<"length:"<<j->Area()<<endl;
	}
	
	
	outfile2<<"�����"<<endl;
	for(j=l.begin()+1;j!=l.end()-1;j++)
	{
		if(big_line->Area()<j->Area())
		{
			big_line=j;
		}
			
	}
	for(j=l.begin()+1;j!=l.end()-1;j++)
	{
		if(j->Area()==big_line->Area())
			outfile2<<*j<<" "<<"length:"<<j->Area()<<endl;
	}
	outfile2.close();
	cout<<"������ִ����ϣ�"<<endl; 
}
void task_4()
{
	Point p1,p2,p3;
	int choice;	
	cout<<"�������һ��point�����:";
	cin>>choice;
	cout<<"��ѡ��ĵ�һ��point������Ϊ"<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				p1=*i;	
			}
			
	}
	cout<<"������ڶ���point�����:";
	cin>>choice;
	cout<<"��ѡ��ĵڶ���point������Ϊ"<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				p2=*i;	
			}
			
	}
	p3=p1+p2;
	cout<<"p1+p2="<<"("<<p3.x<<","<<p3.y<<")"<<endl;
	if(p1<p2)
		cout<<"p1<p2"<<endl;
	else
		cout<<"p1>p2"<<endl;
	Rect r1,r2,r3;
	cout<<"�������һ��rect�����:";
	cin>>choice;
	cout<<"��ѡ��ĵ�һ��rect������Ϊ"<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				r1=*k;	
			}
			
	}
	cout<<"������ڶ���rect�����:";
	cin>>choice;
	cout<<"��ѡ��ĵڶ���rect������Ϊ"<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				r2=*k;	
			}
			
	}
	r3=r1+r2;
	cout<<"r1+r2:"<<r3<<endl;
}
void task_5()
{
	char ch;
	int choice;
	cout<<"*******��point���в���*******"<<endl;
	Point p1,p2;
	cout<<"�������һ��point�����:";
	cin>>choice;
	cout<<"��ѡ��ĵ�һ��point������Ϊ"<<endl<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				p1=*i;
			}
			
	}
	cout<<"������ڶ���point�����:";
	cin>>choice;
	cout<<"��ѡ��ĵڶ���point������Ϊ"<<endl<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				p2=*i;	
			}
			
	}
	cout<<"point:diatance:"<<p1.Distance(p2)<<endl; 
	cout<<"Press any key to continue"<<endl ;
	getch();
	cout<<"**********��rect���в���**********"<<endl;
	Rect r1,r2;
	cout<<"�������һ��rect�����:";
	cin>>choice;
	cout<<"��ѡ��ĵ�һ��rect������Ϊ"<<endl<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				r1=*k;	
			}
			
	}
	cout<<"������ڶ���rect�����:";
	cin>>choice;
	cout<<"��ѡ��ĵڶ���rect������Ϊ"<<endl<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				r2=*k;	
			}
			
	}
	cout<<"rect:distance:"<<r1.Distance(r2)<<endl;
	cout<<"Press any key to continue" <<endl;
	getch();
	cout<<"**********��line���в���**********"<<endl;
	Line l1,l2;
	cout<<"�������һ��line�����:";
	cin>>choice;
	cout<<"��ѡ��ĵ�һ��line������Ϊ"<<endl<<endl; 
	for(j=l.begin();j!=l.end();j++)
	{
		if(j->getid()==choice)
			{
				cout<<*j<<endl<<endl;
				l1=*j;	
			}
			
	}
	cout<<"������ڶ���line�����:";
	cin>>choice;
	cout<<"��ѡ��ĵڶ���line������Ϊ"<<endl<<endl; 
	for(j=l.begin();j!=l.end();j++)
	{
		if(j->getid()==choice)
			{
				cout<<*j<<endl<<endl;
				l2=*j;	
			}
			
	}
	cout<<"line:distance:"<<l1.Distance(l2)<<endl;
	cout<<"Press any key to continue"<<endl ;
	getch();
	cout<<"**********��Distance_R()���в���**********"<<endl;
	cout<<"������point�����:";
	cin>>choice;
	cout<<"��ѡ���point������Ϊ"<<endl<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				p1=*i;
			}
			
	}
	p1.Distance_R();
	cout<<"Press any key to continue"<<endl ;
	getch();
	cout<<"**********��Distance_L()���в���**********"<<endl;
	cout<<"������point�����:";
	cin>>choice;
	cout<<"��ѡ���point������Ϊ"<<endl<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				p1=*i;
			}
			
	}
	p1.Distance_L();
}
bool compare( Point &p1, Point &p2)
{
	return p1<p2;
}
bool compare2( Rect &r1,Rect &r2)
{
	return r1.getdes()<r2.getdes();
}
bool compare3( Line &l1,Line &l2)
{
	return l1.getlen()<l2.getlen();
}
void task_6()
{
	Shape *ss;
	cout<<"**********��Point�����������**********"<<endl;
	ofstream file;
	for(i=p.begin();i!=p.end();i++)
	{
		string s=i->getdes();
		transform(s.begin(), s.end(), s.begin(), towlower);			//����д�ַ���ת��ΪСд 
		i->writedes(s);	
	}
    sort(p.begin(), p.end(),compare);								//���� 
    for(i=p.begin();i!=p.end()-1;i++)
    {
    	file.open("Point2.txt",ios::app);
    	ss=&(*i);
    	WriteData(ss, file);
    	file.close();
	}
	cout<<"�������!"<<endl; 
	cout<<"**********��Rect�����������**********"<<endl;
	ofstream file2;
	sort(r.begin(), r.end(), compare2);
	for(k=r.begin();k!=r.end()-2;k++)
	{
		file2.open("Rect2.txt",ios::app);
    	ss=&(*k);
    	WriteData(ss, file2);
    	file2.close();
	}
	cout<<"�������!"<<endl;
	cout<<"**********��Line�����������**********"<<endl;
	ofstream file3;
	sort(l.begin(), l.end(),compare3);
	for(j=l.begin();j!=l.end();j++)
	{
		
		file3.open("Line2.txt",ios::app);
    	ss=&(*j);
    	WriteData(ss, file3);
    	file3.close();
	}
	cout<<"�������!"<<endl; 
	cout<<"��ȫ�������ļ�!"<<endl; 
}
