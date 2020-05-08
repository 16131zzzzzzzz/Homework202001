#include <iostream>
using namespace std;
class HugeInteger
{
public:
HugeInteger(long a);
HugeInteger add( HugeInteger a );
bool isEqualTo( HugeInteger a );
bool isNotEqualTo( HugeInteger a );
bool isGreaterThan(HugeInteger a );
bool isLessThan( HugeInteger a );
bool isGreaterThanOrEqualTo( HugeInteger a );
bool isLessThanOrEqualTo( HugeInteger a );
void output();
private:
int integer[ 40 ];
};

HugeInteger::HugeInteger(long a){
	for(int i = 0; i < 40; i++){
		integer[40-i-1] = a % 10;
		a = (a - a % 10)/10;
	}
};

HugeInteger HugeInteger::add( HugeInteger a ){
	output();
	for(int i = 0; i < 40; i++){
		integer[i] += a.integer[i];
	}
	int up = 0;
	for(int i = 39; i >= 0; i--){
		integer[i] += up;
		if (integer[i] > 9){
			up = integer[i] / 10;
			integer[i] %= 10;
		}
		else{
			up = 0;
		}
	}
	cout << " + ";
	a.output();
	cout << " = ";
	output();
};

bool HugeInteger::isEqualTo( HugeInteger a ){
	for(int i = 0; i < 40; i++){
		if(integer[i] != a.integer[i]){
		return 0;
		}
		return 1;
	}
};
bool HugeInteger::isNotEqualTo( HugeInteger a ){
		for(int i = 0; i < 40; i++){
		if(integer[i] != a.integer[i]){
		return 1;
		}
		return 0;
	}
};
bool HugeInteger::isGreaterThan(HugeInteger a ){
	if (isEqualTo(a) == 1){
		return 0;
	}
	else{
		for(int i = 0; i < 40; i++){
			if(integer[i] < a.integer[i]){
				return 0;
			}
		}
		return 1;
	}
};

bool HugeInteger::isLessThan( HugeInteger a ){
		if (isEqualTo(a) == 1){
		return 0;
	}
	else{
		for(int i = 0; i < 40; i++){
			if(integer[i] > a.integer[i]){
				return 0;
			}
		}
		return 1;
	}
};
bool HugeInteger::isGreaterThanOrEqualTo( HugeInteger a ){
	for(int i = 0; i < 40; i++){
		if(integer[i] < a.integer[i]){
			return 0;
		}
	}
	return 1;
};
bool HugeInteger::isLessThanOrEqualTo( HugeInteger a ){
	for(int i = 0; i < 40; i++){
		if(integer[i] > a.integer[i]){
			return 0;
		}
	}
	return 1;
};
void HugeInteger::output(){
	int a = 0;
	for(int i = 0; i < 40; i++){
		if (integer[i] != 0){
			a = i;
			break;
		}
	}
	for(int j = a; j < 40; j++){
		cout << integer[j];
	}
};

int main(){
	HugeInteger a(1242343744);
	HugeInteger b(377854357);
	a.add(b);
}
