//******************************************************************************
// File name:   main.cpp
// Author:      Erick Paxtian
// Date:        09/18/24
// Class:       CS200-01
// Assignment:  Base Converter
// Purpose:     Convert a given number in a specifc base to equivalent
//              numbers in the other two bases
// Hours:       4.5
//******************************************************************************

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

const string BINARY_PREFIX = "0b", HEX_PREFIX = "0x";
const char DECIMAL_BASE = 'D', HEX_BASE = 'H', BINARY_BASE = 'B';
const int LAST_NUMBER_INDEX = 2, BASE_TWO = 2;

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

  string myTitle = "HEX-DECIMAL-BINARY CONVERTER";
  printTitle (myTitle);
  cout << endl;

  string strNumber;
  strNumber = getNumber ("Enter a number: ");
  cout << "Base of your number: " << getBase (strNumber) << endl;

  if (getBase (strNumber) == BINARY_BASE){
    cout << "Decimal Representation: " << binaryToDecimal (strNumber) << endl;
  }
  if (getBase (strNumber) == DECIMAL_BASE){
    cout << "Binary Representation: " << decimalToBinary (strNumber) << endl;
  }
  
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
  const char HEX_INDICATOR = 'x', BINARY_INDICATOR = 'b';
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

/**************************************************************************
 Function: 	 	printTitle

 Description: Prints the given title surrounded by asterisks

 Parameters:	myTitle - the title to print out

 Returned:	 	None
 *************************************************************************/
void printTitle (const string& myTitle){
  const int NUMBER_OF_SYMBOLS = 5, DOUBLE_SYMBOLS = NUMBER_OF_SYMBOLS * 2;
  const char SYMBOL = '*';


  cout << setfill (SYMBOL) << setw (myTitle.length () + (DOUBLE_SYMBOLS))
       << SYMBOL << endl;
  cout << setw (myTitle.length () + NUMBER_OF_SYMBOLS) << myTitle
       << setw (NUMBER_OF_SYMBOLS) << SYMBOL << endl;
  cout << setw (myTitle.length () + (DOUBLE_SYMBOLS)) << SYMBOL;
}

/**************************************************************************
 Function: 	 	binaryToDecimal

 Description: Convert binary number to its equivalent decimal representation

 Parameters:	strNumber - a binary number in string form

 Returned:	 	Returns the equivalent decimal representation in string form
 *************************************************************************/
string binaryToDecimal (const string& strNumber){
  const char BINARY_ONE = '1';
  const int FIRST_NUMBER_INDEX = strNumber.length () - 1;

  int equivalentDecimal = 0;

  for (int i = FIRST_NUMBER_INDEX; i >= LAST_NUMBER_INDEX; i--){
    if (strNumber.at (i) == BINARY_ONE){
      equivalentDecimal += pow (BASE_TWO, FIRST_NUMBER_INDEX - i);
    }
  }

  return to_string (equivalentDecimal);
}

/**************************************************************************
 Function: 	 	decimalToBinary

 Description: Convert decimal number to its equivalent binary representation

 Parameters:	strNumber - a decimal number in string form

 Returned:	 	Returns the equivalent binary representation in string form
 *************************************************************************/
string decimalToBinary (const string& strNumber){
  string equivalentBinary = "";
  int decimal = stoi (strNumber), quotient, remainder;

  do{
    quotient = decimal / BASE_TWO;
    remainder = decimal % BASE_TWO;
    equivalentBinary += to_string (remainder);
    decimal = quotient;
  } while (decimal != 0);

  reverse (equivalentBinary.begin (), equivalentBinary.end ());

  return BINARY_PREFIX + equivalentBinary;
}