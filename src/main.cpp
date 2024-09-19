//******************************************************************************
// File name:   main.cpp
// Author:      Erick Paxtian
// Date:        09/18/24
// Class:       CS200-01
// Assignment:  Base Converter
// Purpose:     Convert a given number in a specifc base to equivalent
//              numbers in the other two bases
// Hours:       0.25
//******************************************************************************

#include <iostream>
#include <string>

using namespace std;

int hexCharToInt (char hexDigit);
char getBase (const string& strNumber);
string getNumber (const string& prompt);
void printTitle (const string& myTitle);
string binaryToDecimal (const string& strNumber);
string decimalToBinary (const string& strNumber);
string decimalToHex (const string& strNumber);
string hexToDecimal (const string& strNumber);
string hexToBinary (const string& strNumber);
string binaryToHex (const string& strNumber);

int main () {

  char hexDigit;
  cout << "Enter Hex Digit: ";
  cin >> hexDigit;

  cout << "Corresponding Int: " << hexCharToInt (hexDigit) << endl;

  string strNumber;
  strNumber = getNumber ("Enter a number: ");
  cout << "Base of your number: " << getBase (strNumber) << endl;
  
  return EXIT_SUCCESS;
}

/**************************************************************************
 Function: 	 	hexCharToInt

 Description: Turns a char in hexidecimal form to an int in decimal form

 Parameters:	hexDigit - a char in hexidecimal form

 Returned:	 	The equivlent int in decimal form
 *************************************************************************/
int hexCharToInt (char hexDigit){
  const char LOWEST_INTEGER = '0', HIGHEST_INTEGER = '9',
             LOWEST_HEX_CHAR = 'A';
  const int HEX_CHAR_OFFSET = 10;
  int equivalentInt;

  if (hexDigit >= LOWEST_INTEGER && hexDigit <= HIGHEST_INTEGER){
    equivalentInt = static_cast<int> (hexDigit - LOWEST_INTEGER);
  }
  else {
    equivalentInt = static_cast<int> (hexDigit - LOWEST_HEX_CHAR) + 
                    HEX_CHAR_OFFSET;
  }

  return equivalentInt;
}

/**************************************************************************
 Function: 	 	getBase

 Description: Return the base of the given number's representation

 Parameters:	strNumber - a number in the form of hex, binary, or decimal

 Returned:	 	The base of the number representaion in the form of a char
 *************************************************************************/
char getBase (const string& strNumber){
  const char DECIMAL_BASE = 'D', HEX_BASE = 'H', BINARY_BASE = 'B',
             HEX_INDICATOR = 'x', BINARY_INDICATOR = 'b';
  const int INDICATOR_INDEX = 1;
  char numberBase;

  if (strNumber.length () > 2){
    if (strNumber.at (INDICATOR_INDEX) == HEX_INDICATOR){
      numberBase = HEX_BASE;
    }
    else if (strNumber.at (INDICATOR_INDEX) == BINARY_INDICATOR){
      numberBase = BINARY_BASE;
    }
    else {
      numberBase = DECIMAL_BASE;
    }
  }
  else {
    numberBase = DECIMAL_BASE;
  }

  return numberBase;
}

/**************************************************************************
 Function: 	 	getNumber

 Description: Ask the user for a number and return it in string form

 Parameters:	prompt - the prompt to output to the user in string form

 Returned:	 	The number the user inputted in string form
 *************************************************************************/
string getNumber (const string& prompt){
  string strNumber;
  cout << prompt;
  cin >> strNumber;

  return strNumber;
}