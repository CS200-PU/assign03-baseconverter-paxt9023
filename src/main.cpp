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

  cout << "Hello World" << endl;
  
  return EXIT_SUCCESS;
}