//compile: g++ -std=c++11 -o rewrite main.cpp 
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <cstddef>

const char buffer[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//const char buffer[] = "ABCDEF";
const size_t buffSize = sizeof(buffer)-1; //-1 to account for the string terminator char

//Function declarations
void EnumerateSubstrings(const char string[], const size_t length);
void EnumerateSubstrings2(const char string[], const size_t length);
void EnumerateSubstrings3(const char string[], const size_t length);
void EnumerateSubstrings4(const char string[], const size_t length);
void Test_FindString();
void EnumerateSubstrings5(const char string[], const size_t length);
//

int main(int argc, char* argv[])
{
	std::cout << std::endl;
	
	std::cout << "Find repeats" << std::endl;
	EnumerateSubstrings5(buffer, buffSize);
	
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

/**
	Compare the first *length* elements of strings pointed to by *s1* and *s2*
	
	\param s1 pointer to a string
	\param s2 pointer to a string
	\return true if the elements of strings are equal
*/
bool StringCompare(const char* s1, const char* s2, size_t length)
{
	for(int i=0; i<length; i++) if(s1[i] != s2[i]) return false;
	return true;
}

/**
	Detects if a pettern appears as a substring of a string
	
	\param pattern pointer to a pattern string
	\param patternLength length of pattern string. patternLength shall not exceed stringLength
	\param string pointer to string to search for substrings in
	\param stringLength length of string
	
	Note: Searches for substring by iterating over every substring with pattern length.
	This funstion is a candidate for improvement with a better substring search algorithm. 
*/
bool FindString(const char* pattern, const size_t patternLength, const char* string, const size_t stringLength)
{
	for(size_t i=0; i <= stringLength-patternLength; i++)
	{
		if(StringCompare(pattern, string+i, patternLength)) return true;
	}
	return false;
}

void Test_FindString()
{
	char testString[] = "0123456789";
	char pattern[] = "6789";
	char pattern2[] ="7890";
	char pattern3[] = "0123456789";
	
	std::cout <<  FindString(pattern, sizeof(pattern)-1, testString, sizeof(testString)-1) << " Expect: 1" << std::endl;
	std::cout <<  FindString(pattern2, sizeof(pattern2)-1, testString, sizeof(testString)-1) << " Expect: 0" << std::endl;
	std::cout <<  FindString(pattern3, sizeof(pattern3)-1, testString, sizeof(testString)-1) << " Expect: 1" << std::endl;
}

/**
	Continuation on EnumerateSubstring4():
	
	Call FindString() on enumerated string, instead of printing it.
*/
//TODO: Next: Fix call to FindString to not include the the pattern string in the search string
void EnumerateSubstrings5(const char string[], const size_t length)
{
	const size_t min = 1;
	const size_t max = length;
	
	int n = 0;
	for(int i=0; i<length-min; i++)
	{
		for(int j=i+min-1; j<std::min((length+i)/2, i+max); j++)
		{
			if(FindString(string+i, j-i+1, string/*FIXME*/, length)) std::cout << std::string(string+i, j-i+1) << " @ i: " << i << std::endl;
		}
	}
}

//Also: Might want to write substring enumeration based in start index and length instead of start index and stop index. Possibly. 
