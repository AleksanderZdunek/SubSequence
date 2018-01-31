//compile: g++ -std=c++11 -o rewrite main.cpp 
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>

const char buffer[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//const char buffer[] = "ABCDEF";
const size_t buffSize = sizeof(buffer)-1; //-1 to account for the string terminator char

//Function declarations
void EnumerateSubstrings(const char string[], const size_t length);
void EnumerateSubstrings2(const char string[], const size_t length);
void EnumerateSubstrings3(const char string[], const size_t length);
void EnumerateSubstrings4(const char string[], const size_t length);
//

int main(int argc, char* argv[])
{
	std::cout << std::endl;
	
	EnumerateSubstrings4(buffer, buffSize);
	
	std::cout << std::endl;
	return 0;
}

/**
	Enumerate all substrings of a string
*/
void EnumerateSubstrings(const char string[], const size_t length)
{
	int n = 0;
	for(int i=0; i<length; i++)
	{
		for(int j=i; j<length; j++)
		{
			std::cout << std::right << std::setw(2) << ++n << ": " << std::string(string+i, j-i+1) << std::endl;
		}
	}
}

/**
	Continuation on EnumerateSubstring():	
	
	We actually only need to enumerate substrings that are shorter
	than or equal half the length of the buffer, since substrings longer than that
	can impossibly appear twice in in the buffer.
	
*/
void EnumerateSubstrings2(const char string[], const size_t length)
{	
	int n = 0;
	for(int i=0; i<length-1; i++)
	{
		for(int j=i; j<(length+i)/2; j++)
		{
			std::cout << std::right << std::setw(2) << ++n << ": " << std::string(string+i, j-i+1) << std::endl;
		}
	} 
}

/**
	Continuation on EnumerateSubstring2():
	
	We also wish to define a minimum substring length.
*/
void EnumerateSubstrings3(const char string[], const size_t length)
{
	const size_t min = 1;
	
	int n = 0;
	for(int i=0; i<length-min; i++)
	{
		for(int j=i+min-1; j<(length+i)/2; j++)
		{
			std::cout << std::right << std::setw(2) << ++n << ": " << std::string(string+i, j-i+1) << std::endl;
		}
	} 
}

/**
	Continuation on EnumerateSubstring3():
	
	While we're at it, might as well also define a maximum substring length.
	Make sure that 1 <= min <= max.
*/
void EnumerateSubstrings4(const char string[], const size_t length)
{
	const size_t min = 5;
	const size_t max = 7;
	
	int n = 0;
	for(int i=0; i<length-min; i++)
	{
		for(int j=i+min-1; j<std::min((length+i)/2, i+max); j++)
		{
			std::cout << std::right << std::setw(2) << ++n << ": " << std::string(string+i, j-i+1) << std::endl;
		}
	} 
}

//Next: Now that we are satisfied with the substring enumeration the next step is to search the buffer for repeats of the enumerated substring
//Also: Might want to write substring enumeration based in start index and length instead of start index and stop index. Possibly. 
