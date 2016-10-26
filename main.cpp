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
	cout<<"请输入任务序号：";
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
			cout<<"请输入任务序号：";
			cin>>choice;
			
		}
		if(choice==2)
		{
			task_2_2();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"请输入任务序号：";	
			cin>>choice;
			
		}
		if(choice==3)
		{
			task_3();
			cout<<"Press any key to continue" ;
			getch();
			system("cls"); 
			display();
			cout<<"请输入任务序号：";	
			cin>>choice; 
		 
		}
		if(choice==4)
		{
			task_4();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"请输入任务序号：";
			cin>>choice; 
		}	
		if(choice==5)
		{
			task_5();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"请输入任务序号：";
			cin>>choice; 
		}	
		if(choice==6)
		{
			task_6();
			cout<<"Press any key to continue" ;
			getch();
			system("cls");
			display();
			cout<<"请输入任务序号：";
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
	cout<<"\t\t\t"<<"1>任务2.1:输出对象个数" <<endl;
	cout<<"\t\t\t"<<"2>任务2.2:查找des相同"<<endl;
	cout<<"\t\t\t"<<"3>任务3:寻找面积最值并保存"<<endl;
	cout<<"\t\t\t"<<"4>任务4:演示operator+和<"<<endl; 
	cout<<"\t\t\t"<<"5>任务5:演示distance()函数"<<endl;
	cout<<"\t\t\t"<<"6>任务6:排序并写入文件"<<endl;
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
	cout<<"point.txt中对象个数是："<<Point::GetCount()<<endl;	
	
	 
	
	while(!file2.eof())
	{
		file2>>temp_line;
		l.push_back(temp_line);
		Line::inccount();
	}
	cout<<"line.txt中对象个数是："<<Line::GetCount()<<endl;
	
	
	
	while(!file3.eof())
	{
		file3>>temp_rect;
		r.push_back(temp_rect);
		Rect::inccount();
	}
	cout<<"rect.txt中对象个数是："<<Rect::GetCount()<<endl;	

	file.close();
	file2.close();
	file3.close();
}
void task_2_2()
{
	
	int choice;
	string obj_des;
	cout<<"请输入任意一个point的序号:";
	cin>>choice;
	cout<<"你选择的point的数据为"<<endl<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				obj_des=i->getdes();
			}
			
	}
	cout<<"与被选择的point的des相同的的rect数据显示如下"<<endl<<endl ;
	for(k=r.begin();k!=r.end()-1;k++)
	{
		if(k->getdes()==obj_des)
			cout<<*k<<endl;
	}
	cout<<"显示完毕，进行下一步操作！"<<endl; 
	cout<<endl<<"请输入任意一个rect的序号:";
	cin>>choice;
	system("cls"); 
	cout<<"你选择的rect的数据为"<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				obj_des=k->getdes();
			}
			
	}
	cout<<"与被选择的rect的des相同的point数据显示如下"<<endl<<endl ;
	for(i=p.begin();i!=p.end()-1;i++)
	{
		if(i->getdes()==obj_des)
			cout<<*i<<endl;
	}
	cout<<"显示完毕，进行下一步操作！"<<endl; 
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
	outfile<<"面积最小"<<endl;
	for(k=r.begin()+1;k!=r.end()-1;k++)
	{
		if(k->Area()==small->Area())
			outfile<<*k<<" "<<"Area:"<<small->Area()<<endl;
	}
	
	
	outfile<<"面积最大"<<endl;
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
	outfile2<<"长度最短"<<endl;
	for(j=l.begin()+1;j!=l.end()-1;j++)
	{
		if(j->Area()==small_line->Area())
			outfile2<<*j<<" "<<"length:"<<j->Area()<<endl;
	}
	
	
	outfile2<<"长度最长"<<endl;
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
	cout<<"任务三执行完毕！"<<endl; 
}
void task_4()
{
	Point p1,p2,p3;
	int choice;	
	cout<<"请输入第一个point的序号:";
	cin>>choice;
	cout<<"你选择的第一个point的数据为"<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				p1=*i;	
			}
			
	}
	cout<<"请输入第二个point的序号:";
	cin>>choice;
	cout<<"你选择的第二个point的数据为"<<endl; 
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
	cout<<"请输入第一个rect的序号:";
	cin>>choice;
	cout<<"你选择的第一个rect的数据为"<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				r1=*k;	
			}
			
	}
	cout<<"请输入第二个rect的序号:";
	cin>>choice;
	cout<<"你选择的第二个rect的数据为"<<endl; 
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
	cout<<"*******对point进行测试*******"<<endl;
	Point p1,p2;
	cout<<"请输入第一个point的序号:";
	cin>>choice;
	cout<<"你选择的第一个point的数据为"<<endl<<endl; 
	for(i=p.begin();i!=p.end();i++)
	{
		if(i->getid()==choice)
			{
				cout<<*i<<endl<<endl;
				p1=*i;
			}
			
	}
	cout<<"请输入第二个point的序号:";
	cin>>choice;
	cout<<"你选择的第二个point的数据为"<<endl<<endl; 
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
	cout<<"**********对rect进行测试**********"<<endl;
	Rect r1,r2;
	cout<<"请输入第一个rect的序号:";
	cin>>choice;
	cout<<"你选择的第一个rect的数据为"<<endl<<endl; 
	for(k=r.begin();k!=r.end();k++)
	{
		if(k->getid()==choice)
			{
				cout<<*k<<endl<<endl;
				r1=*k;	
			}
			
	}
	cout<<"请输入第二个rect的序号:";
	cin>>choice;
	cout<<"你选择的第二个rect的数据为"<<endl<<endl; 
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
	cout<<"**********对line进行测试**********"<<endl;
	Line l1,l2;
	cout<<"请输入第一个line的序号:";
	cin>>choice;
	cout<<"你选择的第一个line的数据为"<<endl<<endl; 
	for(j=l.begin();j!=l.end();j++)
	{
		if(j->getid()==choice)
			{
				cout<<*j<<endl<<endl;
				l1=*j;	
			}
			
	}
	cout<<"请输入第二个line的序号:";
	cin>>choice;
	cout<<"你选择的第二个line的数据为"<<endl<<endl; 
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
	cout<<"**********对Distance_R()进行测试**********"<<endl;
	cout<<"请输入point的序号:";
	cin>>choice;
	cout<<"你选择的point的数据为"<<endl<<endl; 
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
	cout<<"**********对Distance_L()进行测试**********"<<endl;
	cout<<"请输入point的序号:";
	cin>>choice;
	cout<<"你选择的point的数据为"<<endl<<endl; 
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
	cout<<"**********对Point对象进行排序**********"<<endl;
	ofstream file;
	for(i=p.begin();i!=p.end();i++)
	{
		string s=i->getdes();
		transform(s.begin(), s.end(), s.begin(), towlower);			//将大写字符串转化为小写 
		i->writedes(s);	
	}
    sort(p.begin(), p.end(),compare);								//排序 
    for(i=p.begin();i!=p.end()-1;i++)
    {
    	file.open("Point2.txt",ios::app);
    	ss=&(*i);
    	WriteData(ss, file);
    	file.close();
	}
	cout<<"排序完成!"<<endl; 
	cout<<"**********对Rect对象进行排序**********"<<endl;
	ofstream file2;
	sort(r.begin(), r.end(), compare2);
	for(k=r.begin();k!=r.end()-2;k++)
	{
		file2.open("Rect2.txt",ios::app);
    	ss=&(*k);
    	WriteData(ss, file2);
    	file2.close();
	}
	cout<<"排序完成!"<<endl;
	cout<<"**********对Line对象进行排序**********"<<endl;
	ofstream file3;
	sort(l.begin(), l.end(),compare3);
	for(j=l.begin();j!=l.end();j++)
	{
		
		file3.open("Line2.txt",ios::app);
    	ss=&(*j);
    	WriteData(ss, file3);
    	file3.close();
	}
	cout<<"排序完成!"<<endl; 
	cout<<"已全部存入文件!"<<endl; 
}

