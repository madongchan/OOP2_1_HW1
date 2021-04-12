#include <iostream>

// quiz1
int countMatchedNumberLetterInString(const char* str, int digit)
{

}

// quiz2
void excludeRedundantLetters(char* str)
{
	int len = strlen(str);

	int lenToAlloc = 0;
	for (int i = 0; i < len; i++) {
		
	}
}

// quiz3
int countWords(const char* str)
{

}


// quiz4
bool examinePairedParenthesis(const char* str)
{

}
void convertString(char* str)
{

}


// quiz5

int main()
{
	int count = countMatchedNumberLetterInString("112233443311334913201234", 4);
	printf("quiz1: %d\n", count);

	char data[100]{ "Hello World" };
	excludeRedundantLetters(data);
	printf("quiz2: %s\n", data);

	int nWords = countWords("Hell World. Here	is the train\n");
	printf("quiz3: %d\n", nWords);

	bool result = examinePairedParenthesis("((()))");
	printf("quiz4: %s\n", result == true ? "true" : "false");

	char input[100] = "Hell World. Nice to Meet  you";
	convertString(input);
	printf("quiz5: %s\n", input);

	return 0;
}
