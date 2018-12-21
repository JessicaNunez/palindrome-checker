#include <iostream>
#include "functions.h"
#include <cctype>
using namespace std;

int main(int argc, char* argv[]) {
	//Find flags
	bool caseSensitive = false;
	bool ignoreSpaces = true;

	bool error = false;
	int lengthOfUserInput = argc - 1;
	int start = 1;
	int k = 0;
	for (int i = 1; i < argc; ++i) {
		if (argv[i][0] == '-') {
			lengthOfUserInput -= 1;
			start += 1;
			while (argv[i][k] != '\0') {
				if ((argv[i][k]) == tolower('c')) {
					caseSensitive = true;
				}
				else if ((argv[i][k]) == tolower('s')) {
					ignoreSpaces = false;
				}
				else if ((argv[i][k]) != '-') {  //Show usage error when user inputs invalid flags
					printUsageInfo(argv[0]);
					return 0;
				}
				k += 1;
			}
			if (lengthOfUserInput > 0) {   
				if ((argv[i + 1][0]) != '-') {  //Stop processing flags
					break;
				}
			}
		}
	}

	//Show usage error when user doesn't input valid data
	if (lengthOfUserInput < 1) {
		printUsageInfo(argv[0]);
		return 0;
	}

	//Test each word/phrase
	for (int i = start; i < argc; ++i) {

		//Put word/phrase into arrays
		char strArray[500]; //this array will be processed
		char origArray[500];
		strcpy(strArray, argv[i]);
		strcpy(origArray, argv[i]);

		//Call palindrome function
		bool palindrome = isPalindrome(strArray, caseSensitive, ignoreSpaces);

		if (palindrome) {
			cout << "\"" << origArray << "\" is a palindrome." << endl;
		}
		else {
			cout << "\"" << origArray << "\" is not a palindrome." << endl;
		}
	}

	return 0;
}
