#include <iostream>
#include "functions.h"
#include <cctype>

using namespace std;

//Helper Recursive function
bool isPalindromeR(char strArray[]) {
	char updatedArray[500];
	int startingIndex = 1;
	int length = strlen(strArray);
	int numOfCharactersToGet = strlen(strArray) - 2;
	bool pali = false;

	if (length <= 0) {
		return true;
	}

	if (strArray[0] == strArray[strlen(strArray) - 1]) {
		pali = true;
		if (numOfCharactersToGet >= 1) {
			strncpy(updatedArray, &strArray[startingIndex], numOfCharactersToGet);
			updatedArray[numOfCharactersToGet] = '\0';
			isPalindromeR(updatedArray);
		}
		else {
			return pali;
		}
	}

	else {
		return false;
	}

}

//Find if phrase/word is a palindrome
bool isPalindrome(char strArray[], bool caseSensitive = false, bool ignoreSpaces = true) {
	preprocessCString(strArray, caseSensitive, ignoreSpaces);
	return isPalindromeR(strArray);
}

//Prepare string for comparison
void preprocessCString(char strArray[], bool caseSensitive = false, bool ignoreSpaces = true) {
	int i = 0;
	int offset = 0;

	//Take off punctuation
	if (!ignoreSpaces) {  //Don't remove spaces
		while (strArray[i + offset] != '\0') {
			char character = strArray[i + offset];
			if (!isalnum(character) && (!isspace(character))) {
				offset++;
			}
			else {
				strArray[i] = strArray[i + offset];
				++i;
			}
		}
	}
	if (ignoreSpaces) {  //Remove spaces
		while (strArray[i + offset] != '\0') {
			char character = strArray[i + offset];
			if (!isalnum(character)) {
				offset++;
			}
			else {
				strArray[i] = strArray[i + offset];
				++i;
			}
		}
	}

	//end with null
	strArray[i] = '\0';

	//Lowercase all letters if case-sensitity does not matter
	if (!caseSensitive) {
		for (int i = 0; strArray[i] != '\0'; ++i) {
			strArray[i] = tolower(strArray[i]);
		}
	}
}

//Print this if user is not using program properly
void printUsageInfo(char nameOfExecutable[]) {
	cout << "Usage: " << nameOfExecutable << " [-c] [-s] <term> ... ";
	cout << "  -c: turn on case sensitivity" << endl;
	cout << "  -s: turn off ignoring spaces" << endl;
}
