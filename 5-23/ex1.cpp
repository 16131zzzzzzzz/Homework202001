#include<iostream>
#include<vector>
using namespace std;

template<class T>
void check(const vector<T> a)
{
    int b = a.size()/2 + 1;
    bool judge = true;
    for (int i = 0; i < b; i++)
    {
        if (a[i] != a[a.size()-i-1])
        {
            judge = false;
        }
    }
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << "is" << (judge?" ":" not ") << "a palindrome" << endl;
}

int main()
{
	vector<int> a={ 1,2,3,2,1 };
	vector<char> b{ 'a','b','c' };
	check(a);
	check(b);

}
