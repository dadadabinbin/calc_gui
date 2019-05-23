#include <iostream>
#include <cmath>

using namespace  std;

class Calculator{
public:
//加法
	double sum(double a,double b){
		return a+b;
	}
//减法
	double sub(double a,double b){
		return a-b;
	}
//乘法
	double multi(double a,double b){
		return a*b;
	}
//除法
	double division(double a,double b){
		return a/b;
	}
};
int main(int argc,char** argv){
	double a,b;
	Calculator cal;
	cout<<"请输入第一个数字："<<endl;
	cin>>a;
	cout<<"请输入第二个数字："<<endl;
	cin>>b;
	cout<<"两数之和:"<<cal.sum(a,b)<<endl;
	cout<<"两数之差:"<<cal.sub(a,b)<<endl;
	cout<<"两数之积:"<<cal.multi(a,b)<<endl;
	cout<<"两数之商:"<<cal.division(a,b)<<endl;
	return 0;
}
