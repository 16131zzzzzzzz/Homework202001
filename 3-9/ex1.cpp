#include <iostream>
#include <string>
using namespace std;

class Complex{
    public:
    Complex(double inReal = 0, double inImag = 0){
        real = inReal;
        imag = inImag;
    }

    void dis(){
        cout << "(" << real << ", " << imag << ")";
    }

    void Adding(Complex a, Complex b){
        Complex c;
        c.real = a.real + b.real;
        c.imag = a.imag + b.imag;
        a.dis();
        cout << " + ";
        b.dis();
        cout << " = ";
        c.dis();
        cout << endl;
    }

        void Substracting(Complex a, Complex b){
        Complex c;
        c.real = a.real - b.real;
        c.imag = a.imag - b.imag;
        a.dis();
        cout << " - ";
        b.dis();
        cout << " = ";
        c.dis();
        cout << endl;
    }

    private:
    double real, imag;
};

int main(){
    Complex complex1(1, 7);
    Complex complex2(9, 2);
    Complex complex3(10, 1);
    Complex complex4(11, 5);
    complex1.Adding(complex1, complex2);
    complex3.Substracting(complex3, complex4);
}