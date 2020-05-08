#include <iostream>
using namespace std;


class IntegerSet{
private:
    int k[101];
public:
    IntegerSet()
    {
        for(int i = 0;i < 101;++i)
        {
            k[i] = 0;
        }
    }

    IntegerSet(int*,int);

    void inputSet();
    void printSet() const;
    bool isEqualTo(IntegerSet) const;
    void insertElement(int);
    IntegerSet unionOfSets(IntegerSet) const;
    IntegerSet intersectionOfSets(IntegerSet) const;
    void deleteElement(int);
};

IntegerSet::IntegerSet(int* num,int n){
    for (int i = 0; i < n; ++i) {
        k[num[i]] = 1;
    }
}

void IntegerSet::inputSet(){
    int inp = 0;
    cout << "Enter an element ('-1' to end) :";
    cin >> inp;
    while (inp != -1){
        k[inp] = 1;
        cout << "Enter an element ('-1' to end) :";
        cin >> inp;
    }
    cout << "Entry complete\n";
    cout << endl;
}

void IntegerSet::printSet() const{
    cout << "{ ";
    for (int i = 0; i < 101; ++i){
        if(k[i] == 1)
        {
            cout << i << " ";
        }
    }
    cout << "}" << endl;
}

bool IntegerSet::isEqualTo(IntegerSet a)const{
        for (int i = 0; i < 101; ++i){
            if(k[i] != a.k[i])
            {
                return 0;
            }
        }
    return 1;
}

void IntegerSet::insertElement(int n){
    k[n] = 1;
}

IntegerSet IntegerSet::unionOfSets(IntegerSet a) const{
    IntegerSet added = a;
    for (int i = 0; i < 101; ++i)
    {
        if(k[i] == 1)
        {
            added.k[i] = 1;
        }
    }
    return added;
}

IntegerSet IntegerSet::intersectionOfSets(IntegerSet a)const{
    IntegerSet iso;
    for (int i = 0; i < 101; ++i){
        if(a.k[i] == 1 && this -> k[i] == 1){
            iso.k[i] = 1;
        }
    }
    return iso;
}

void IntegerSet::deleteElement(int n)
{
    if(k[n] == 1){
        k[n] = 0;
    }
    else{
        cout << "Invalid insert attempted!" << endl;
    }
}

void printEqual(bool a){
    if(a == 1){
        cout << "A is equal to B\n";
    }
    else{
        cout << "A is not equal to B\n";
    }
}

int main() {
    IntegerSet A;
    IntegerSet B;
    IntegerSet C;

    cout << "Enter set A:\n";
    A.inputSet();
    cout << "Enter set B:\n";
    B.inputSet();

    cout << "Union of A and B is:\n";
    C = A.unionOfSets(B);
    C.printSet();

    cout << "intersection of A and B is:\n";
    C = A.intersectionOfSets(B);
    C.printSet();

    printEqual(A.isEqualTo(B));
    cout << endl;

    cout << "insert 77 into set A...\n";
    A.insertElement(77);
    cout << "Set A is now :\n";
    A.printSet();
    cout << endl;

    cout << "delete 77 from A...\n";
    A.deleteElement(77);
    cout << "Set A is now :\n";
    A.printSet();
    A.deleteElement(101);
    A.deleteElement(50);

    const int arraySize = 10;
    int intArray[arraySize] = {25,67,2,9,99,105,45,-5,101,1};
    IntegerSet e(intArray,arraySize);

    cout << "\nSet e is:\n";
    e.printSet();
    cout << endl;

    return 0;
}