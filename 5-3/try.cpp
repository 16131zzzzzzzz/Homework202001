#include <iostream>
#include <windows.h>
using namespace std;
bool bonus(int a)
{
	SYSTEMTIME systm;
	GetLocalTime(&systm);
	return (systm.wMonth == a);
}
class Date
{

public:
	Date(int a = 2001, int b = 2, int c = 11) :year(a), month(b), day(c) {}
	void show() { cout << year << "/" << month << "/" << day; }
	int year;
	int month;
	int day;
};
class employee
{
public:
	employee(string thename="wangmou",string security="11-111-111",Date a=Date()):
		name(thename),security_number(security),birthday(a) {}
	virtual void show()
	{
		cout << "employee'name:	 " << name << endl
			<< "birthday:	";
		birthday.show();
		cout<<endl<< "security number is:	"
			<< security_number<<endl;
	}


protected:
	string name;
	Date birthday;
	string security_number;

};
class weekly :public employee
{
public:
	weekly(string thename = "wangmou", string security = "11-111-111", Date a = Date(),double thesalary=100)
	:salary(thesalary)
	{
		name = thename;
		security_number = security;
		birthday = a;

	}
	virtual void show()
	{
		employee::show();
		if (bonus(birthday.month))
		{
			cout << "happy birthday" << endl;
			salary += 100;
		}
		cout << "weekly salary is:	" << salary <<endl << endl;
	}
private:
	double salary;
};
class hours :public employee
{
public:
	hours(string thename = "wangmou", string security = "11-111-111", Date a = Date(), double per= 100,double thetime=1)
		:perhour(per),hour(thetime),salary(per*thetime)
	{
		name = thename;
		security_number = security;
		birthday = a;

	}
	virtual void show()
	{
		employee::show();
		cout << "perhour:" << perhour << "  work hours:  " << hour<<endl;
		if (bonus(birthday.month))
		{
			cout << "happy birthday" << endl;
			salary += 100;
		}
		cout << "weekly salary is:	" << salary << endl << endl;
	}
private:
	double perhour;
	double hour;
	double salary;
};
class sales :public employee
{
public:
	sales(string thename = "wangmou", string security = "11-111-111", Date a = Date(), double per = 100, double thetime = 1)
		:perhour(per), hour(thetime), salary(per* thetime)
	{
		name = thename;
		security_number = security;
		birthday = a;

	}
	virtual void show()
	{
		employee::show();
		cout << "perhour:" << perhour << "  work hours:  " << hour << endl;
		if (bonus(birthday.month))
		{
			cout << "happy birthday" << endl;
			salary += 100;
		}
		cout << "weekly salary is:	" << salary << endl << endl;
	}
private:
	double perhour;
	double hour;
	double salary;
};

int main()
{
	employee* employees[4];
	Date a(2001, 4, 5),b(2003,5,7),c(2023,4,12);
	employees[0] = new weekly("zhangsan","0001",a,100 );
	employees[1] = new hours("lisi", "0002", b, 30, 2.76);
	employees[2] = new sales("niba", "0003", c, 8000, 0.23);
	employees[0]->show();
	employees[1]->show();
	employees[2]->show();

}
