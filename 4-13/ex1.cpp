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

    Complex Adding(Complex b){
        Complex c;
        c.real = this->real + b.real;
        c.imag = this->imag + b.imag;
        return c;
        // a.dis();
        // cout << " + ";
        // b.dis();
        // cout << " = ";
        // c.dis();
        // cout << endl;
    }

    Complex Substracting(Complex b){
        Complex c;
        c.real = this->real - b.real;
        c.imag = this->imag - b.imag;
        return c;
        // a.dis();
        // cout << " - ";
        // b.dis();
        // cout << " = ";
        // c.dis();
        // cout << endl;
    }




    friend ostream &operator<<(ostream &output, Complex complex){
        output << "(" << complex.real << "," << complex.imag << ")";
        return output;
    }

    friend istream &operator>>(istream &input, Complex &complex){
        input >> complex.real >> complex.imag;
        return input;
    }


    Complex operator+(Complex complex){
        return Adding(complex);
    }

    Complex operator-(Complex complex){
        return Substracting(complex);
    }

    bool operator!=(Complex complex){
        return (this->real == complex.real && this->imag == complex.imag);
    }

    private:
    double real, imag;
};
int main(){
    Complex x, y( 4.3, 8.2 ), z( 3.3, 1.1 ), k;

    cout << "Enter a complex number in the form: (a, b)\n";
    cin >> k; // demonstrating overloaded

    cout << "x: " << x << "\ny: " << y << "\nz: " << z << "\nk: " << k << '\n'; // demonstrating overloaded <<

    x = y + z; // demonstrating overloaded + and =
    cout << "\nx = y + z:\n" << x << " = " << y << " + " << z << '\n';

    x = y - z; // demonstrating overloaded - and =
    cout << "\nx = y - z:\n" << x << " = " << y << " - " << z << '\n';

    // x = y * z; // demonstrating overloaded * and =
    // cout << "\nx = y * z:\n" << x << " = " << y << " * " << z << "\n\n";

    if ( x != k ) // demonstrating overloaded !=
    cout << x << " != " << k << '\n';
    cout << '\n';
    // x = k;

    // if ( x == k ) // demonstrating overloaded ==
    // cout << x << " == " << k << '\n';    return 0;
} // end main