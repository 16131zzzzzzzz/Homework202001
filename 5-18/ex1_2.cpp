#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	ifstream read("1.txt");
	if(!read)
	{
		cerr<<"Files cannot be opened.";
		exit(EXIT_FAILURE);
	}

	string IP, date, time;
	int ip;
	int A=0, B=0, C=0, D=0, E=0;
	while(read>>IP>>date>>time)
	{
		for(int i=0;i<=2;i++)
		{
			if(IP[1]=='.') ip=IP[0]-'0';
			else if(IP[2]=='.') ip=(IP[0]-'0')*10+IP[1]-'0';
			else ip=(IP[0]-'0')*100+(IP[1]-'0')*10+IP[2]-'0';
		}
		if(ip>=0&&ip<=127) A++;
		if(ip>=128&&ip<=191) B++;
		if(ip>=192&&ip<=223) C++;
		if(ip>=224&&ip<=239) D++;
		if(ip>=240&&ip<=247) E++;
	}

	cout << "Number of class A address: "<< A << endl;
	cout << "Number of class B address: "<< B << endl;
	cout << "Number of class C address: "<< C << endl;
	cout << "Number of class D address: "<< D << endl;
	cout << "Number of class E address: "<< E << endl;
}