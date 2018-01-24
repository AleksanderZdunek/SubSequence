#include <iostream>

typedef char element_type;

int subsequenceSearch(const element_type* exemplar, const size_t exemplarLength, const element_type* sequence, const size_t sequenceLength);
bool beginEqually(const element_type* seq1, const element_type* seq2, const size_t length);

const char string[] = "This is a character sequence.";
size_t stringLength = 29;

int main(int argc, char* argv[])
{
	std::cout << "SubSequence Compare" << std::endl;

	const char ex[] = "is";
	size_t exLength = 2;

	int found = subsequenceSearch(ex, exLength, string, stringLength);
	
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