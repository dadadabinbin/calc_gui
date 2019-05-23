#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class SavingAccount{
public:
	SavingAccount(string name,double balance){
		this->m_Name=name;
		this->m_Balance=balance;
		
	}
	void showImassage(){
		cout<<"储户姓名="<<m_Name<<endl;
		cout<<"余额="<<m_Balance<<endl;
		cout<<"年利率="<<SavingAccount::m_AnnualInterestRate<<endl;
		cout<<"月利息="<<CalculateMonthlyInterest()<<endl;
	}
	void putMoney(double money){
		this->m_Balance+=money;
	}
	double getMoney(double money){
		this->m_Balance-=money;
		return money;
	}
	static double m_AnnualInterestRate;
	static int ModifyInterestRate(double newrate);
	double CalculateMonthlyInterest(){
		double temp=m_Balance*SavingAccount::m_AnnualInterestRate;
		return temp/12.0;
	}
	string getName(){
		return this->m_Name;
	}
	double getBalance(){
		return this->m_Balance;
	}
private:
	string m_Name;
	double m_Balance;
};
double SavingAccount::m_AnnualInterestRate=0.0;
int SavingAccount:: ModifyInterestRate(double newrate){
	SavingAccount::m_AnnualInterestRate=newrate;
	return newrate;
}


int main(int argc,char** argv){
	SavingAccount a1("account1",3000.0);
	SavingAccount a2("account2",5000.0);
	SavingAccount::m_AnnualInterestRate=0.03;
	cout<<"account1的月利息为："<<a1.CalculateMonthlyInterest()<<endl;
	cout<<"account2的月利息为："<<a2.CalculateMonthlyInterest()<<endl;
	a1.putMoney(200.0);
	a1.getMoney(100.0);
	cout<<"account1的余额："<<a1.getBalance()<<endl;
	SavingAccount::ModifyInterestRate(0.025);
	cout<<"账户的余额:"<<a1.getBalance()<<endl;
	cout<<"账户的月利息:"<<a1.CalculateMonthlyInterest()<<endl;
 	return 0;
}
