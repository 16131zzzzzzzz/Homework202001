#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class String
{
    public:
        friend ostream &operator<<(ostream &output, const String &s)
        {
            output << s.sPtr;
            return output;
        };

        String(char * a=(char*)"")
        {
            length = strlen(a);
        	sPtr = new char[length+1];
            strcpy(sPtr, a);
        }; // conversion constructor String(const String &); // copy constructor

        String &operator=(String& a)
        {
            if(this->sPtr == a.sPtr)
        		return *this;
            length = a.length;
            delete []sPtr;
            sPtr = new char[length];
            strcpy(sPtr, a.sPtr);
            return *this;
        };

        ~String()
        {
        	delete [] sPtr;
		}
		friend String& operator+(const String &a, const String &b)
        {
        	static String r;
            r.length = a.length + b.length;
            r.sPtr = new char[r.length+1];
            for (int j = 0; j < a.length; j++)
            {
                r.sPtr[j] = a.sPtr[j];
            }
            for (int i = 0; i < b.length; i++)
            {
                r.sPtr[i+a.length] = b.sPtr[i];
            }
            r.sPtr[r.length] = '\0';
            return r;
        };
    private:
        char *sPtr; // pointer to start of string
        int length; // string length
}; // end class String

int main()
{
    String string1, string2((char*)"The date is");
    String string3((char*)" August 1, 1993");// test overloaded operators
    cout << "string1 = string2 + string3\n";
    string1 = string2 + string3; // tests overloaded = and + operator
    cout << "\"" << string1 << "\" = \"" << string2 << "\" + \""
    << string3 << "\"" << endl;
    return 0;
}