#include <iostream>

// quiz1 
//실행 여부: 성공
int countMatchedNumberLetterInString(const char* str, int digit)
{
	//char ch0 = '0' int로 48
	//char ch4 = '4' int로 52
	//char = int + 48
	char changeInt = digit + 48;
	int len = strlen(str);//24
	int matchNumberInString = 0;
	//printf("changeInt: %c\n", changeInt); 4
	for (int i = 0; i < len; i++)
	{
		if (str[i] == changeInt)
		{
			matchNumberInString++;
		}
	}
	return matchNumberInString;
}

// quiz2
//실행 여부: 성공
void excludeRedundantLetters(char* str)
{
	int len = strlen(str);//11
	// 문자열을 복사해 넣을 공간을 만든다
	char* result = (char*)malloc(sizeof(char) * (len + 1));

	// 첫번째 문자는 중복 확인 해도 의미가 없어서 미리 삽입
	result[0] = str[0];
	int resultNumber = 1;

	for (int i = 1; i < len; i++) {
		int overlapSighted = 0;
		// 왼쪽으로 이동해가면서 현재 인덱스 문자랑 같은 문자가 있는지 확인하고
		for (int j = i - 1; j >= 0; j--) {
			// 있으면 중복확인 숫자(overlapSighted)를 활성화시킨다
			if (str[i] == str[j] && str[i] != ' ') {
				overlapSighted++;
			}
		}

		// 중복확인이 감지되면 해당 문자는 복사하지 않는다
		if (overlapSighted > 0) {
			continue;
		}
		else {
			//감지되지 않으면 result에 문자를 삽입 후 인덱스를 증가시킨다
			result[resultNumber] = str[i];
			resultNumber++;
		}
	}

	result[resultNumber] = '\0';

	for (int i = 0; i < len; i++)
	{
		str[i] = result[i];
	}
	free(result);
}

// quiz3
//실행 여부: 성공
int countWords(const char* str)
{
	int len = strlen(str);//31

	int numberOfWordsFromString = 0;

	//문자인지 체크하는 bool 변수 선언
	bool checkChar = false;

	for (int i = 0; i < len; i++)
	{
		//' '와'\t'이 이니면 문자로 인식 '\n'줄바꿈 개행문자는 문자로 인식안함
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		{
			//문자체크를 참으로 변경
			checkChar = true;
		}
		//문자체크가 참이고 str[i]이 ' '또는'\t'또는'\n' 또는 str[i+1]이 널문자이면
		//단어 수(numberOfWordsFromString)를 하나 늘린다
		//그리고 문자체크는 다음 문자를 체크하기 위해 false로 바꾼다
		if (checkChar == true && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i + 1] == 0))
		{
			numberOfWordsFromString = numberOfWordsFromString + 1;
			checkChar = false;
		}
	}
	return numberOfWordsFromString;
}


// quiz4
//실행 여부: 성공
bool examinePairedParenthesis(const char* str)
{
	int len = strlen(str);//6
	bool result = true;
	int leftParenthesis = 0, rightParenthesis = 0;
	bool sameParenthesisNumber = true;
	bool checkEven = true;
	bool whatFrontAndBehindBracket = true;

	// '(' 와 ')' 의 개수를 세고 
	for (int i = 0; i < len; i++)
	{
		if (str[i] == '(')
		{
			leftParenthesis++;
		}
		else if (str[i] == ')')
		{
			rightParenthesis++;
		}
	}
	// '(' 와 ')' 의 개수 값이 서로 같으면 쌍 개수의 값이 참 아니면 거짓
	if (leftParenthesis == rightParenthesis)
	{
		sameParenthesisNumber = true;
	}
	else
	{
		sameParenthesisNumber = false;
	}
	// '(' 와 ')' 의 개수 값을 합친 개수가 짝수면 참 아니면 거짓
	if ((leftParenthesis + rightParenthesis) % 2 == 0)
	{
		checkEven = true;
	}
	else
	{
		checkEven = false;
	}
	//무조건  '(' 이 ')' 보다 먼저 나와야 하고 끝은 ')'으로 끝나야 된다
	//str[0]이 '(' 과 str[len-1]이 ')'이면 참 아니면 거짓
	if (str[0] == '(' && str[len - 1] == ')')
	{
		whatFrontAndBehindBracket = true;
	}
	else
	{
		whatFrontAndBehindBracket = false;
	}
	//위 세가지 조건을 모두 충족하면 result는 참 아니면 거짓
	if (sameParenthesisNumber && checkEven && whatFrontAndBehindBracket)
	{
		result = true;
	}
	else
	{
		result = false;
	}

	return result;
}


// quiz5
//실행 여부: 성공
void convertString(char* str)
{
	int len = strlen(str);//30
	//공백문자를 %20으로 바꾸기 위해서 변환문자(convertChar) 배열을 생성
	char convertChar[3] = { '%','2','0' };

	int lenToAlloc = len;
	//공백문자가 %20으로 바뀐 후의 배열 동적할당크기를 구하기 위해서
	//동적길이(lenToAlloc)를 구한다
	for (int i = 0; i < len; i++)
	{
		if (str[i] == ' ')
		{
			lenToAlloc = lenToAlloc + 2; //lenToAlloc : 42
		}
	}
	
	//동적할당
	char* result = (char*)malloc(sizeof(char) * (lenToAlloc + 1));

	int resultNumber = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] != ' ')
		{
			//공백문자를 제거하는 과정 후 인덱스 값 하나씩 올린다
			result[resultNumber] = str[i];//HelloWorld.NicetoMeetyou
			resultNumber++;
		}
		else
		{
			//str의 공백문자를 만나면 result값에 변환문자를 삽입
			for (int j = 0; j < 3; j++)
			{
				result[resultNumber] = convertChar[j];
				resultNumber++;
			}

		}
	}
	result[resultNumber] = '\0';

	for (int i = 0; i < lenToAlloc; i++)
	{
		str[i] = result[i];
	}
	free(result);
}

int main()
{
	int count = countMatchedNumberLetterInString("112233443311334913201234", 4);
	printf("quiz1: %d\n", count);

	char data[100]{ "Hello World" };
	excludeRedundantLetters(data);
	printf("quiz2: %s\n", data);

	int nWords = countWords("Hello World. Here	is the train\n");
	printf("quiz3: %d\n", nWords);

	bool result = examinePairedParenthesis("((()))");
	printf("quiz4: %s\n", result == true ? "true" : "false");

	char input[100] = "Hello World. Nice to Meet  you";
	convertString(input);
	printf("quiz5: %s\n", input);

	return 0;
}
