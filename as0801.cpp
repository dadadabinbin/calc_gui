#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class XPoint{
public:
//构造函数
	XPoint(){
		this->x=0;
		this->y=0;
	}
	XPoint(int x ,int y){
		this->x=x;
		this->y=y;
	}
//拷贝构造函数
	XPoint(const XPoint &obj){
		this->x=obj.x;
		this->y=obj.y;
	}
	void setX(int x){
		this->x=x;
	}
	void setY(int y){
		this->y=y;
	}
	int getX(){
		return this->x;
	}
	int getY(){
		return this->y;
	}
public:
	int x;
	int y;
};
class Xtriangle{
public:
	vector<XPoint> points;
public:
	Xtriangle():points(3){
		for(int i=0;i<points.size();++i){
			points[i].x=0;
			points[i].y=0;
		}
	}
	//设置顶点
	void setVertex(int index,XPoint &obj){
	 	if(index>=0&&index<3){
			this->points[index].x=obj.x;
			this->points[index].y=obj.y;
		}
	}
	//取出顶点
	XPoint getVertex(int index){
		return points[index];
	}
	//得到周长
	double getPerimeter(){
		double sum=0.0;
		sum+=dictTowPoint(points[0],points[1]);
		sum+=dictTowPoint(points[0],points[2]);
		sum+=dictTowPoint(points[2],points[1]);
		return sum;
	}
	//两点之间的长度
	double dictTowPoint(XPoint &a,XPoint &b){
		double dist1=pow(b.x-a.x,2.0);
		double dist2=pow(b.y-a.y,2.0);
		return sqrt(dist1+dist2);
	}
	//得到面积
	double getArea(){
		double p=getPerimeter()*0.5;
		double a=dictTowPoint(points[0],points[1]);
		double b=dictTowPoint(points[0],points[2]);
		double c=dictTowPoint(points[1],points[2]);
		double multi=p*(p-a);
		multi*=p-b;
		multi*=p-c;
		return sqrt(multi);
	}
	
};
int main(int argc,char** argv){
	XPoint point1(3,6);
	XPoint point2(4,7);
	XPoint point3(6,8);
	Xtriangle obj;
	obj.setVertex(0,point1);
	obj.setVertex(1,point2);
	obj.setVertex(2,point3);
	//取出顶点
	cout<<"x="<<obj.getVertex(0).x<<endl;
	cout<<"y="<<obj.getVertex(0).y<<endl;
	//得到周长
	cout<<"len="<<obj.getPerimeter()<<endl;
	//得到面积
	cout<<"area="<<obj.getArea()<<endl;
	return 0;
}
