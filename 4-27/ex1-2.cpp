#include <iostream>
using namespace std;

class MyBase1 {
    public:
        MyBase1()
        {
            cout << "...BaseClass1 Object is created!"<< endl;
        }

        ~MyBase1()
        {
            cout << "...BaseClass1 Object is destroyed!"<< endl;
        }
};

class MyBase2 {
    public:
        MyBase1 a1;
        MyBase2()
        {
            cout << "...BaseClass2 Object is created!"<< endl;
        }

        ~MyBase2()
        {
            cout << "...BaseClass2 Object is destroyed!"<< endl;
        }
};

class Myderived1 : public MyBase2 {
    public:
    Myderived1()
    {
        cout << "...First layer derived Object is created!"<< endl;
    }

    ~Myderived1()
    {
        cout << "...First layer derived Object is Destroyed!"<< endl;
    }
};
class Myderived11 : public Myderived1 {
    public:
    Myderived11()
    {
        cout << "...Second layer derived Object is created!"<< endl;
    }

    ~Myderived11()
    {
        cout << "...Second layer derived Object is destroyed!"<< endl;
    }
};

int main()
{
    MyBase2 a;
    Myderived1 b;
    Myderived11 c;
}
