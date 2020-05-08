#include <iostream>
using namespace std;
class HugeInteger
{
public:
HugeInteger();
HugeInteger(long long a);
HugeInteger add( HugeInteger a );
friend ostream &operator<<(ostream& ,HugeInteger a);
bool isEqualTo( HugeInteger a );
bool isNotEqualTo( HugeInteger a );
bool isGreaterThan(HugeInteger a );
bool isLessThan( HugeInteger a );
bool isGreaterThanOrEqualTo( HugeInteger a );
bool isLessThanOrEqualTo( HugeInteger a );
// addition operator; HugeInt + HugeInt
HugeInteger operator+( HugeInteger ) ;
// addition operator; HugeInteger + int
HugeInteger operator+( int ) ;
// addition operator;
// HugeInteger + string that represents large integer value
bool operator==( HugeInteger ) ; // equality operator
bool operator!=( HugeInteger ) ; // inequality operator
bool operator<( HugeInteger ) ; // less than operator
// less than or equal to operator
bool operator<=( HugeInteger ) ;
bool operator>( HugeInteger ) ; // greater than operator
// greater than or equal to operator
bool operator>=( HugeInteger ) ;

private:
int integer[ 40 ];
};

HugeInteger::HugeInteger(){
	for(int i = 0; i < 40; i++){
        integer[i] = 0;
	}
};

HugeInteger::HugeInteger(long long a){
	for(int i = 0; i < 40; i++){
		integer[40-i-1] = a % 10;
		a = (a - a % 10)/10;
	}
};

HugeInteger HugeInteger::add( HugeInteger a ){
    HugeInteger c;
	for(int i = 0; i < 40; i++){
		c.integer[i] = integer[i] + a.integer[i];
	}
	int up = 0;
	for(int i = 39; i >= 0; i--){
		c.integer[i] += up;
		if (c.integer[i] > 9){
			up = c.integer[i] / 10;
			c.integer[i] %= 10;
		}
		else{
			up = 0;
		}
	}
    return c;
};

bool HugeInteger::isEqualTo( HugeInteger a ){
	for(int i = 0; i < 40; i++){
		if(integer[i] != a.integer[i]){
		    return 0;
		}
	}
    return 1;
};

bool HugeInteger::isNotEqualTo( HugeInteger a ){
	for(int i = 0; i < 40; i++){
        if(integer[i] != a.integer[i]){
            return 1;
        }
    }
    return 0;
};

bool HugeInteger::isGreaterThan(HugeInteger a ){
	if (isEqualTo(a) == 1){
		return 0;
	}
	else{
		for(int i = 0; i < 40; i++){
			if(integer[i] > a.integer[i]){
				return 1;
			}
		}
		return 0;
	}
};

bool HugeInteger::isLessThan( HugeInteger a ){
	if (isEqualTo(a) == 1){
		return 0;
	}
	else{
		for(int i = 0; i < 40; i++){
			if(integer[i] < a.integer[i]){
				return 1;
			}
		}
		return 0;
	}
};

bool HugeInteger::isGreaterThanOrEqualTo( HugeInteger a ){
	for(int i = 0; i < 40; i++){
		if(integer[i] > a.integer[i]){
			return 1;
		}
	}
	return 0;
};

bool HugeInteger::isLessThanOrEqualTo( HugeInteger a ){
	for(int i = 0; i < 40; i++){
		if(integer[i] < a.integer[i]){
			return 1;
		}
	}
	return 0;
};

ostream &operator<<(ostream& output,HugeInteger a){
	int k = 0;
	for(int i = 0; i < 40; i++){
		if (a.integer[i] != 0){
			k = i;
			break;
		}
	}
	for(int j = k; j < 40; j++){
		output << a.integer[j];
	}
    return output;
};

HugeInteger HugeInteger::operator+(HugeInteger a){
    return add(a);
};

HugeInteger HugeInteger::operator+(int a){
    long long b = (long long) a;
    HugeInteger k(b);
    return add(k);
};



bool HugeInteger::operator==(HugeInteger a){
    return isEqualTo(a);
};

bool HugeInteger::operator!=(HugeInteger a){
    return isNotEqualTo(a);
};

bool HugeInteger::operator<(HugeInteger a){
    return isLessThan(a);
};

bool HugeInteger::operator<=(HugeInteger a){
    return isLessThanOrEqualTo(a);
};

bool HugeInteger::operator>(HugeInteger a ){
    return isGreaterThan(a);
};

bool HugeInteger::operator>=(HugeInteger a){
    return isGreaterThanOrEqualTo(a);
};


int main(){
	HugeInteger n1(7654321);
	HugeInteger n2(7891234);
	HugeInteger n3(99999999999999999);
    HugeInteger n4(1);
    HugeInteger n5(12341234);
    HugeInteger n6(7888);
    cout << "n1 is " << n1 <<endl;
    cout << "n2 is " << n2 <<endl;
    cout << "n3 is " << n3 <<endl;
    cout << "n4 is " << n4 <<endl;
    cout << "n5 is " << n5 <<endl;
    cout << "n6 is " << n6 <<endl;
    cout << "n1 is";
    n1==n2?cout<<" ":cout <<" not ";
    cout << "equal to n2" << endl;
    cout << "n1 is";
    n1<n2?cout<<" ":cout <<" not ";
    cout << "less than n2" << endl;
    cout << "n1 is";
    n1<=n2?cout<<" ":cout <<" not ";
    cout << "less than or equal to n2" << endl;
    cout << n3 << " + " << n4 << " = " << n3 + n4 <<endl;
    cout << n1 << " + " << "9" << " = " << n1 + 9 <<endl;
    cout << n2 << " + " << "10000" << " = " << n2 + 10000 <<endl;
}
