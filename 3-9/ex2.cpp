#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class Time
{
public:
    Time();
    Time(int inp_hours,int inp_minutes = 0,int inp_seconds = 0);
    void tick();
    void setTime(int,int,int);
    void display(int);
    void printStandared();
private:
    int hours;
    int minutes;
    int seconds;
};

Time::Time():hours(0),minutes(0),seconds(0){}
Time::Time( int inp_hours, int inp_minutes , int inp_seconds):hours(inp_hours),minutes(inp_minutes),seconds(inp_seconds){}

void Time::tick()
{
    seconds++;
    minutes += (seconds/60);
    seconds %= 60;
    hours += (minutes/60);
    minutes %= 60;
    hours %= 24;
}
void Time::setTime( int a, int b, int c)
{
    hours = a;
    minutes = b;
    seconds = c;
}



void Time::display(int a){
    if (a < 10)
    {
        cout << "0" << a;
    }
    else
    {
        cout << a;
    };
}

void Time::printStandared()
{
    if ( hours >= 1 and hours < 12)
    {
        display(hours);cout << ":"; display(minutes);cout << ":";display(seconds);cout <<" AM \n";
    } else if (hours == 0)
    {
        cout << "12" << ":"; display(minutes);cout << ":";display(seconds);cout <<" AM \n";
    } else if (hours == 12)
    {
        display(hours);cout << ":"; display(minutes);cout << ":";display(seconds);cout <<" PM \n";
    }else
    {
        display(hours%12);cout << ":"; display(minutes);cout << ":";display(seconds);cout << " PM \n";
    }

}


int main() {
    Time time;
    time.setTime(0,0,0);
    for (int i = 0; i < 10; ++i) {
        time.tick();
        time.printStandared();
    }
}