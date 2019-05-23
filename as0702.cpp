#include <iostream>
#include <cmath>

using namespace std;

class Complex{
private:
	double real;
	double vir;
public:
	Complex(double real,double vir){
		this->real=real;
		this->vir=vir;
	}
	Complex(){
		this->real=0.0;
		this->vir=0.0;
	}
	void setReal(double real){
		this->real=real;
	}
	void setVir(double vir){
		this->vir=vir;
	}
	double getReal(){
		return this->real;
	}
	double getVir(){
		return this->vir;
	}
	void outputNum(){
		cout<<"复数是："<<this->real<<"+"<<this->vir<<"i"<<endl;
	}
	Complex add(const Complex &a,const Complex &b){
		Complex temp;
		temp.real=a.real+b.real;
		temp.vir=a.vir+b.vir;
		return temp;
	}
	Complex multi(const Complex &a,const Complex &b){
		int virPart=a.vir*b.real+a.real*b.vir;
		int realPart=a.real*b.real-a.vir*b.vir;
		Complex temp(realPart,virPart);
		return temp;
	}
};

int main(int argc,char** argv){
	Complex obj1,obj2;
	cout<<"设置第一个数实部:"<<endl;
	double real;
	cin>>real;
	obj1.setReal(real);
	cout<<"设置第一个数虚部:"<<endl;
	double vir;
	cin>>vir;
	obj1.setVir(vir);
	cout<<"第一个数实部:"<<obj1.getReal()<<endl;
	cout<<"第一个数虚部:"<<obj1.getVir()<<endl;
	cout<<"设置第二个数实部:"<<endl;
	double real2;
	cin>>real2;
	obj2.setReal(real2);
	cout<<"设置第二个数虚部:"<<endl;
	double vir2;
	cin>>vir2;
	obj2.setVir(vir2);
	cout<<"第一个数实部:"<<obj2.getReal()<<endl;
	cout<<"第一个数虚部:"<<obj2.getVir()<<endl;
	//虚数和
	cout<<"虚数和:"<<endl;
	obj1.add(obj1,obj2).outputNum();
	//虚数相乘
	cout<<"虚数相乘:"<<endl;
	obj1.multi(obj1,obj2).outputNum();

	return 0;
}
