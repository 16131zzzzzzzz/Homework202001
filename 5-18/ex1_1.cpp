#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<random>
using namespace std;

int rerand(int inp_start, int inp_end)
{
    return (rand() % (inp_end - inp_start + 1) + inp_start);
}

int main()
{
	srand(time(0));
	ifstream read("1.txt");
	ofstream write("1.txt",ios::out);

	if (!(read && write))
	{
		cout << "wrong";
        exit(EXIT_FAILURE);
	}

    int y;
	for (int i = 0; i < 100; i++)
	{
        int year = rerand(2010,2020);
        int month = rerand(1,12);
        int day = rerand(0,(month=2?(y%4==0?29:28):(month==4||month==6||month==9||month==11?30:31)));
        int hour = rerand(0,24);
        int minute = rerand(0,59);
        int second = rerand(0,59);

		write << rerand(0,240) <<"." << rerand(0,255) << "." << rerand(0,255) << "." << rerand(0,255) << " ";
        write << year << "-" << ((month<10)?"0":"") << month << "-" << (day<10?"0":"") << day << " ";
        write << (hour<10?"0":"") << hour << ":" << (minute<10?"0":"") << minute << ":" << (second<10?"0":"") << second << endl;
	}
	write.close();

    string a;
	while (getline(read, a))
	{
		cout << a << endl;
	}
}
