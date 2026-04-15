#pragma once
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "clsString.h"
#include "clsDate.h"
using namespace std;

class clsUtil
{
public:
	enum enCharType {
		SmallLetter = 1, CapitalLetter = 2,
		Digit = 3, MixChars = 4, SpecialCharacter = 5
	};
	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
static int RandomNumber(int From, int To)
	{
		
		int RandNum = rand() % (To - From + 1) + From;
	
		return RandNum;
	}
static char GetRandomCharacter(enCharType CharType)
{
	
	if (CharType == MixChars)
	{
		//Capital/Samll/Digits only
		CharType = (enCharType)RandomNumber(1, 3);

	}
	switch (CharType)
	{
	case enCharType::SmallLetter:
	{
		return char(RandomNumber(97, 122)); 
		break;
	}
	case enCharType::CapitalLetter:
	{
		return char(RandomNumber(65, 90));
		break;
	}
	case enCharType::SpecialCharacter:
	{
		return char(RandomNumber(33, 47));
		break;
	}
	case enCharType::Digit:
	{
		return char(RandomNumber(48, 57));
		break;
	}
	}
}
static string GenerateWord(enCharType CharType, short Length)
{
	string Word;
	for (int i = 1; i <= Length; i++) // 1 <= 4 ? | 2 <= 4 ...
	{
		Word += GetRandomCharacter(CharType);
	}
	return Word;
}
static string GenerateKey(enCharType = CapitalLetter)
{
	string Key = "";
	Key = GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4) + "-";
	Key = Key + GenerateWord(enCharType::CapitalLetter, 4);
	return Key;
}
static void GenerateKeys(short NumberOfKeys)
{
	for (int i = 1; i <= NumberOfKeys; i++)
	{
		cout << "Kay [" << i << "] : " << GenerateKey() << endl;
	}
}
static void FillArrayWithRandomNumbers(int arr[100], int& arrLength)

{
	cout << "Enter number of elements : \n";
	cin >> arrLength;
	for (int i = 0; i < arrLength; i++)  
		arr[i] = RandomNumber(1, 100); 
}
static void ShuffleArray(int arr[100], int arrLength)
{
	for (int i = 0; i < arrLength; i++)
	{
		Swap(arr[RandomNumber(1, arrLength) - 1], arr[RandomNumber(1, arrLength) - 1]);
	}
}
static string EncryptText(string Text, short EncryptionKey)
{
	
	for (int i = 0; i <= Text.length(); i++)
	{ 
		Text[i] = char((int)Text[i] + EncryptionKey);

	}
	return Text; 
}
static string DecryptionText(string Text, short EncryptionKey)
{
	for (int i = 0; i <= Text.length(); i++)
	{
		Text[i] = char((int)Text[i] - EncryptionKey);
		
	}
	return Text; 
}
static void FillArrayWithRandomWords(string arr[100], int arrLength, enCharType CharType, short Wordlength)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = GenerateWord(CharType, Wordlength);

}

static void FillArrayWithRandomKeys(string arr[100], int arrLength, enCharType CharType)
{
	for (int i = 0; i < arrLength; i++)
		arr[i] = GenerateKey(CharType);
}

static  void Swap(int& A, int& B)
{
	int Temp;

	Temp = A;
	A = B;
	B = Temp;
}

static  void Swap(double& A, double& B)
{
	double Temp;

	Temp = A;
	A = B;
	B = Temp;
}

static  void Swap(bool& A, bool& B)
{
	bool Temp;

	Temp = A;
	A = B;
	B = Temp;
}

static  void Swap(char& A, char& B)
{
	char Temp;

	Temp = A;
	A = B;
	B = Temp;
}

static  void Swap(string& A, string& B)
{
	string Temp;

	Temp = A;
	A = B;
	B = Temp;
}

static  void Swap(clsDate& A, clsDate& B)
{
	clsDate::SwapDates(A, B);

}

};

