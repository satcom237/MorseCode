/***********************************************************************************
 *Program: 	x5F.cpp
 *Author: 	Sathya Ramanathan
 *Date: 	2/28/2016
 *Description: 	Asks user to enter text or morse, which will then be converted to
		morse or text respectively
***********************************************************************************/

#include <iostream>
#include <sstream>

using namespace std;

string convertToEnglish(string morse, string const morseCode[], string const alpha[]);
string convertToMorse(string english, string const morseCode[], string const alpha[]);

int main()
{
	string option = "";
	cout << "Do you want to translate (1)Text to Morse Code or translate (2)Morse code to Text?: ";
	getline(cin, option);
    
	string const morseCode[] = {".-", "-...", "-.-.", "-..", ".", "..-.",
    	"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
    	".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", " ", "       "};
	
	string const englishLetter[] = {"A", "B", "C", "D", "E", "F", 
	"G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", 
	"T", "U", "V", "W", "X", "Y", "Z", "", " "};
	
	if (option == "1"){	
		string input = "";
		cout << "Enter Text Message: ";
		getline(cin, input);
		string uppercaseInput = "";
		for (int i = 0; i < input.size(); i++){
			uppercaseInput += toupper(input[i]);
		}
		cout << convertToMorse(uppercaseInput, morseCode, englishLetter) << endl;
		cout << endl;
	} 
	
	else if (option == "2"){
		string input = "";
		cout << "Enter Morse Code: ";
		getline(cin, input);
		cout << endl;
		cout << convertToEnglish(input, morseCode, englishLetter) << endl;
		cout << endl;
	}
	
	else{
		cout << "Invalid input, please try again" << endl;
	}
	return 0;
}

string convertToMorse(string english, string const morseCode[], string const alpha[])
{
	string output = "";
	string currentLetter = "";
	int position = 0;
	int const letterCount = english.length();
	int const numberOfAlpha = 28;
	cout << "\n";
	while (position <= letterCount){
		currentLetter = string(1, english[position]);
		int marker = 0;
		string addition = "";
		while (marker < 28){			
			if (currentLetter == alpha[marker]){
				addition = morseCode[marker];
			}
			++marker;
		}
		output += addition + "   ";
		++position;
	}
	return output;
}

string convertToEnglish(string morse, string const morseCode[], string const alpha[]){
	string output = "";
	string currentLetter = "";
	istringstream ss(morse);
	int const characters = 28;
	while(ss >> currentLetter){
		int index = 0;
        	while(currentLetter != morseCode[index] && index < characters){
			++index;
        	}
		output += 'A' + index;
    	}
	return output;
}

