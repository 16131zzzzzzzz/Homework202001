#ifndef STRING_H
#define STRING_H
#include <cstring> 
#include <cassert>

class String
{
   friend ostream &operator<<( ostream &output, const String &s );
public:
   String( const char * const = "" ); 
   String( const String & ); 
   ~String(); 
   const String &operator=( const String & );
   String operator+( const String & );
private:
   char *sPtr; 
   int length; 
}; 
#endif

#include <iostream> 
using std::cout; 
using std::ostream;
#include <cstring> 
#include "String.h" 

String::String( const char * const zPtr )
{
   length = strlen( zPtr ); 
   sPtr = new char[ length + 1 ];
   assert( sPtr != 0 ); 
   strcpy( sPtr, zPtr );
}

String::String( const String &copy )
{
   length = copy.length;
   sPtr = new char[ length + 1 ]; 
   assert( sPtr != 0 ); 
   strcpy( sPtr, copy.sPtr ); 
} 
String::~String()
{
   delete [] sPtr; 
} 
const String &String::operator=( const String &right )
{
   if ( &right != this ) 
   {
      delete [] sPtr;
      length = right.length; 
      sPtr = new char[ length + 1 ];
      assert( sPtr != 0 ); 
      strcpy( sPtr, right.sPtr ); 
   }
   else
      cout << "Attempted assignment of a String to itself\n";
   return *this; 
} 

String String::operator+( const String &right )
{
   String temp;
   temp.length = length + right.length;
   temp.sPtr = new char[ temp.length + 1 ]; 
   assert( sPtr != 0 ); 
   strcpy( temp.sPtr, sPtr ); 
   strcat( temp.sPtr, right.sPtr ); 
   return temp; 
} 
ostream & operator<<( ostream &output, const String &s )
{
   output << s.sPtr;
   return output; 
}