#include <iostream>
using namespace std;

class RationalNumber
{
public:
   RationalNumber( int input_up = 0, int input_down = 1 ):up(input_up),down(input_down){}; // default constructor

   int lcm(int a, int b)
   {
      return b > 0 ? lcm(b, a%b) : a;
   }


   RationalNumber operator+( const RationalNumber& a )
   {
      int x,y;
      x = this->up*a.down + this->down*a.up;
      y = this->down*a.down;
      int k = lcm(x,y);
      RationalNumber b(x/k,y/k);
      return b;
   }; // addition

   RationalNumber operator-( const RationalNumber& a )
   {
      int x,y;
      x = this->up*a.down - this->down*a.up;
      y = this->down*a.down;
      int k = lcm(x,y);
      RationalNumber b(x/k,y/k);
      return b;
   }; // subtraction

   RationalNumber operator*( const RationalNumber& a )
   {
      int x,y;
      x = this->up*a.up;
      y = this->down*a.down;
      int k = lcm(x,y);
      RationalNumber b(x/k,y/k);
      return b;
   }; // multiplication

   RationalNumber operator/( RationalNumber& a )
   {
      int x,y;
      x = this->up*a.down;
      y = this->down*a.up;
      int k = lcm(x,y);
      RationalNumber b(x/k,y/k);
      return b;
   }; // division
   // relational operators

   bool operator>( const RationalNumber& a ) const
   {
      return this->up*a.down > this->down*a.up;
   };

   bool operator<( const RationalNumber& a ) const
   {
      return this->up*a.down < this->down*a.up;
   };

   bool operator>=( const RationalNumber& a ) const
   {
      return !(*this < a);
   };

   bool operator<=( const RationalNumber& a ) const
   {
      return !(*this > a);
   };

   bool operator==( const RationalNumber& a ) const
   {
      return this->up*a.down == this->down*a.up;
   };

   bool operator!=( const RationalNumber& a ) const
   {
      return !(*this == a);
   };

   void printRational()
   {
      int k = lcm(this->up,this->down);
      this->up /= k;
      this->down /= k;
      cout << up;
      down == 1 ? cout << "" : cout << "/" << down;
   }; // display rational number

   private:
   int up; // private variable numerator
   int down; // private variable denominator
   void reduction(); // function for fraction reduction
}; // end class RationalNumber

int main()
{
    RationalNumber c( 7, 3 ), d( 3, 9 ), x;
    c.printRational();
    cout << " + " ;
    d.printRational();
    cout << " = ";
    x = c + d; // test overloaded operators + and =
    x.printRational(); cout << '\n';
    c.printRational();
    cout << " - " ;
    d.printRational();
    cout << " = ";
    x = c - d; // test overloaded operators - and =
    x.printRational();
    cout << '\n';
    c.printRational();
    cout << " * " ;
    d.printRational();
    cout << " = ";
    x = c * d; // test overloaded operators * and =
    x.printRational();
    cout << '\n';
    c.printRational();
    cout << " / " ;
    d.printRational();
    cout << " = ";
    x = c / d; // test overloaded operators / and =
    x.printRational();
    cout << '\n';
    c.printRational();
    cout << " is:\n";
    // test overloaded greater than operator
    cout << ( ( c > d ) ? "  > " : "  <= " );
    d.printRational();
    cout << " according to the overloaded > operator\n"; // test overloaded less than operator
    cout << ( ( c < d ) ? "  < " : "  >= " );
    d.printRational();
    cout << " according to the overloaded < operator\n";
    // test overloaded greater than or equal to operator
    cout << ( ( c >= d ) ? "  >= " : "  < " );
    d.printRational();
    cout << " according to the overloaded >= operator\n";
    // test overloaded less than or equal to operator
    cout << ( ( c <= d ) ? "  <= " : "  > " );
    d.printRational();
    cout << " according to the overloaded <= operator\n";
    // test overloaded equality operator
    cout << ( ( c == d ) ? "  == " : "  != " );
    d.printRational();
    cout << " according to the overloaded == operator\n";
    // test overloaded inequality operator
    cout << ( ( c != d ) ? "  != " : "  == " );
    d.printRational();
    cout << " according to the overloaded != operator" << endl; return 0;
    }