#include "MyString.h"

using namespace std;

// CONSTRUCTORS   
MyString::MyString()	// default constructor
{
	_capacity = 16;		// initializes _capacity to 16 chars
	_length = 0;
	_string = new char [_capacity + 1];		// initializes this MyString to an empty MyString

	_string[0] = '\0'; //null character
}

// parameterized constructors
MyString::MyString(const char * aCString)	// takes a c style string argument
{
	_length = strlen(aCString);	//initializes length to the cString

	if (_length = 16)	// initializes capacity to greater of strlen(cString) or 16 chars
	{
		_capacity = 16;
	}
	else if (_length > 16)
	{
		_capacity = _length;
	}

	_string = new char [_capacity + 1];	// initializes this MyString to cString

	_string[0] = '\0'; //null character
}

 
MyString::MyString(int numChars)	// takes an int argument
{
	_capacity = numChars;	// initializes capacity to numChars chars
	_length = 0;
	_string = new char [_capacity + 1];	// initializes this MyString to an empty MyString
	_string[0] = '\0'; //null character
}

// copy constructor
MyString::MyString(const MyString & original)
{
	_capacity = original._capacity;
	_length = original._length;
	_string = strcpy(_string, original._string);	// initializes this MyString to a deep copy of the original
	_string[0] = '\0'; //null character
}

// DESTRUCTOR
MyString::~MyString()
{
	delete[] _string;	// dealocate dynamic storage
}

// METHODS

      // Append
void MyString::Append(const MyString & aMyString)	// Takes a MyString argument
{
	MyString newString = aMyString;	

	int newLength = _length + newString._length;

	if (_capacity < newLength)
	{
		_capacity = newLength;
	}

	newString = new char[_capacity + 1];

	_string = strcat(_string, newString._string);	// Appends chars to the end of this MyString

	_string[0] = '\0'; //null character
}
            
void MyString::Append(const char * aCString)// Takes  a c style string argument
{
	string newString = aCString;

	int newLength = _length + strlen(aCString);

	if (_capacity < newLength)
	{
		_capacity = newLength;
	}

	newString = new char[_capacity + 1];

	_string = strcat(_string, aCString);// Appends chars to the end of this MyString

	_string[0] = '\0'; //null character
}

// Assign   
void MyString::Assign(const MyString & aMyString)	 // Takes a MyString argument
{
	_capacity = aMyString._capacity;
	_length = aMyString._length;
	_string = new char[_capacity + 1];

	_string = strcpy(_string, aMyString._string);	// makes this MyString a copy of aMyString

	_string[0] = '\0'; //null character
}
    
void MyString::Assign(const char * const aCString)	// Takes  a c style string argument
{
	string newString = aCString;

	_length = strlen(aCString);

	if (_capacity < _length)
	{
		_capacity = _length;
	}

	newString = new char[_capacity + 1];

	strcpy(_string, aCString); // makes this MyString contain the chars of aCString

	_string[0] = '\0'; //null character
}

// At       
char MyString::At(int index) const 	// Takes an int argument
{
	if (index < 0 || index >= _length)	// throws an exception if index is < 0 or >= _length
	{
		throw std::runtime_error("***Index given must not be < 0 or >= _length.***");
	}

	char charAtIndex = _string[index];

	return charAtIndex;	// Returns a copy of the char at that index
}

// Clear           
void MyString::Clear()
{
	// does not change capacity;
	_length = 0;
	strcpy(_string, "");	// Makes this MyString empty

	_string[0] = '\0'; //null character
}
      
void MyString::Clear(int newCapacity)
{
	_string = strcpy(_string, "");	// Makes this MyString empty
	_length = strlen(_string);
	_capacity = newCapacity;	// changes capacity to newCapacity

	if (_capacity < 0)	// throws an exception if newCapacity < 0
	{
		throw std::runtime_error("***Capacity must not be < 0.***");
	}

	_string[0] = '\0'; //null character
}

// Compare
int MyString::Compare(const MyString & aMyString)	// Takes a MyString argument
{
	return strcmp(_string, aMyString._string); //Returns 0 of chars =, >0 if alphabetically less, <0 if alphabetically more
}

// CurrentCapacity
int MyString::CurrentCapacity() const
{
	return _capacity;	// Returns number of characters that this instance can hold without reallocating
}

// Equals
bool MyString::Equals(const MyString & aMyString) const	// Takes a MyString argument
{
	if (strcmp(_string, aMyString._string) == 0)
	{
		return true;	// Returns (true) if the argument contains the same string of chars as this MyString
	}
	else
	{
		return false;	//   otherwise it returns (false).
	}

}

bool MyString::Equals(const char * const aCString) const	// Takes a c style string argument
{
	if (strcmp(_string, aCString) == 0)
	{
		return true;	// Returns (true) if the argument contains the same string of chars as this MyString
	}
	else
	{
		return false;	//   otherwise it returns (false).
	}
}

// Find
int MyString::Find(const MyString & aMyString) const	// Takes a myString argument

{
	int index = strcspn(_string, aMyString._string);

	if (index == strlen(_string))
	{
		return -1;	//    If it is not found, then returns -1.
	}
	else
	{
		return index;	 // Returns the index (int) where the argument MyString was found in this MyString.
	}
}

// Insert
void MyString::Insert(const MyString & aMyString, int index)	// Takes two arguments
{
	strncat(_string, aMyString._string, index);	// An int – the index in this MyString at which to insert the new chars
												// A MyString containing the chars to be inserted
}

// Length          
int MyString::Length(void) const
{
	return _length;	// Returns the number (int) of chars in this MyString
}

// Replace         
void MyString::Replace(int startIndex, int numChars, const MyString & aMyString)	// Takes three arguments
{
	numChars = aMyString._length;	// An int – the number of chars to replace

	MyString tempString = aMyString;	// And a MyString containg the replacement string 

	int newLength = _length + tempString._length;
	if (_capacity < newLength)
	{
		_capacity = newLength;
	}
	tempString = new char[_capacity + 1];

	if (startIndex >= _length)
	{
		throw std::runtime_error("***startIndex is >= _length.***");	// throws an exception if startIndex >= Length
	}
	else if ((startIndex + numChars) > _length)
	{
		throw std::runtime_error("***startIndex + numChars is >= _length.***");	// throws an exception if startIndex + numChars > Length()
	}
	else if (aMyString._length < numChars)
	{
		throw std::runtime_error("***aMyString._length is < numChars***");	// throws an exception if aMyString.Length() < numChars
	}
	strncat(_string, aMyString._string, numChars);

	for (int i = 0; i < numChars; i++)
	{
		_string[i + startIndex] = aMyString[i];
	}
	
	char *charsToInsert;

	charsToInsert = strstr(_string, aMyString._string);

	MyString newString = strncpy(_string, aMyString._string, startIndex);
}

// Substr           
MyString MyString::SubStr(int startIndex, int numChars) const	// Takes two int arguments,
{
	if (startIndex + numChars > _length) // throws an exception if startIndex + numChars > Length()
		throw std::runtime_error("Start index + # of characters is greater than the length of the string");

	MyString toReturn(numChars +1);
	
	char *tempString = new char[numChars +1];

	MyString newString(tempString);	//   from the original MyString

	return newString;	// Returns a MyString with the requested sub-string
}

// OPERATORS
MyString MyString::operator= (const MyString & aMyString)
{
	Assign(aMyString._string);	// = (assignment - takes a MyString)

	return *this;
}

MyString MyString::operator= (const char *  const aCString)
{
	Assign(aCString);	// = (assignment - takes a c style string)

	return *this;
}

MyString MyString::operator+ (const MyString & aMyString)
{
	MyString newString = *this;	// + (concatenation - takes a MyString)

	newString.Append(aMyString);	//adds new string to original string
	
	return newString; //returns concatenated strings
}

MyString MyString::operator+= (const MyString & aMyString)
{
	Append(aMyString); //+= (concatenation - takes a MyString)

	return *this; //returns appended string
}
          
char & MyString::operator[] (int index) const	// [] (read/write char access by index)
{
	char calledChar = At(index);

	if(index < 0 || index >= _length)	// throws an exception if index is < 0 or >= _length
		throw std::runtime_error("Index must be greater than 0 and less than length"); 
		
	return calledChar;	// Returns a reference to the char at that index
}

 // >, <, >=, <=, ==, != (boolean relational test operators)
bool MyString::operator> (const MyString & aMyString) 
{
	return Compare(aMyString) > 0;
}

bool MyString::operator< (const MyString & aMyString)
{
	return Compare(aMyString) < 0;
}

bool MyString::operator>= (const MyString & aMyString)
{
	return (Compare(aMyString) > 0 || Compare(aMyString) == 0);
}

bool MyString::operator<= (const MyString & aMyString)
{
	return (Compare(aMyString) < 0 || Compare(aMyString) == 0);
}

bool MyString::operator== (const MyString & aMyString)
{
	return Compare(aMyString) == 0;
}

bool MyString::operator!= (const MyString & aMyString)
{
	return Compare(aMyString) != 0;
}
     
const char* MyString::_cstr() const
{
	return _string;	// returns a pointer to the underlying c-style string
}
   
ostream & operator<< (ostream & os, const MyString & aMyString)
{
	return os << aMyString._string;	// << stream insertion and extraction
}

 
istream & operator>> (istream & is, MyString & aMyString)
{
	return is >> aMyString._string;	//>> stream insertion and extraction
}