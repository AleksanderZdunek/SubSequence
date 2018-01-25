#include <iostream>
#include <string>

typedef char element_type;

int subsequenceSearch(const element_type* exemplar, const size_t exemplarLength, const element_type* sequence, const size_t sequenceLength);
bool beginEqually(const element_type* seq1, const element_type* seq2, const size_t length);
int detectInitialSubsequenceRepeat(const element_type* seq, const size_t seqLength);
int detectRepeatingSubsequences(const element_type* seq, const size_t seqLength);
std::string toString(const char* seq, size_t length);

//const char string[] = "This is a This character sequence.";
const char string[] = "abcdefghijklmnopqrstuvwxyzABCDabcEFGHIJKLMNOPQRSTUVWXYZ1234567890";
//const char string[] = "abcdefghijklmnopqrstuvwxyz";
size_t stringLength = sizeof(string) - 1;

int main(int argc, char* argv[])
{
	std::cout << "SubSequence Compare" << std::endl;
	
	int found = detectRepeatingSubsequences(string, stringLength);
	
	std::cout << "found: " << found << std::endl;

	return 0;
}

int subsequenceSearch(const element_type* exemplar, const size_t exemplarLength, const element_type* sequence, const size_t sequenceLength)
{
	int count = 0;

	for (size_t i = 0; i <= sequenceLength - exemplarLength; i++)
	{
		if(beginEqually(exemplar, sequence + i, exemplarLength)) count++;
	}

	return count;
}

bool beginEqually(const element_type* seq1, const element_type* seq2, const size_t length)
{
	for (size_t i = 0; i < length; i++)
	{
		if (seq1[i] != seq2[i]) return false;
	}
	
	return true;
}

int detectInitialSubsequenceRepeat(const element_type* seq, const size_t seqLength)
{
    int count = 0;
    
    size_t minExemplarLength = 1;
    size_t maxExemplarLength = seqLength/2;
    
    for (size_t i = minExemplarLength; i <= maxExemplarLength; i++)
    {
        std::cout << "Ex: " << toString(seq, i) << " ";
        int found = subsequenceSearch(seq, i, seq+i, seqLength-i);
        std::cout << ";found: " << found << std::endl;
        count += found;
    }
    
    return count;
}

int detectRepeatingSubsequences(const element_type* seq, const size_t seqLength)
{
	int count = 0;
    for (size_t i = 0; i < seqLength; i++)
    {
    	count += detectInitialSubsequenceRepeat(seq+i, seqLength-i);
    }
    return count;
}

std::string toString(const char* seq, size_t length)
{
    std::string s;
    for(int i = 0; i<length; i++)
    {
        s.push_back(seq[i]);
    }
    return s;
}
