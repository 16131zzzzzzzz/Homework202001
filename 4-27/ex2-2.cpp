#include <iostream>
using namespace std;

class MyBase31 {
    public:
        MyBase31(int x, int y, int z) :a(x), b(y), c(z)
        {
            cout << "...BaseClass31 Object is created!"<< endl;
            cout << a << " " << b << " " << c << endl;
        }

        ~ MyBase31()
        {
            cout << "...BaseClass31 Object is destroyed!"<< endl;
        }
        int a, b, c;
};



class MyDerived1 : public MyBase31 {
        MyBase31 a{5,6,7};
        int c;
    public:
        MyDerived1(int x) : c(x), MyBase31(x,8,9)
        {
        cout << "...Base Object has been created!" << endl;
        cout << "...member Object has been created! " << a.a << " " << a.b << " " << a.c << endl;
        cout << "...Derived Object is created! "<< c << endl;
        }
};



int main()
{
    MyDerived1 b(88);
}