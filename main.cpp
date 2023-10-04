/*******************************************************************************
Conversion Project

Joshua Blankley, Aaron Jacobsen, ...

October 2023

Menu-driven program to convert numbers from base 10 to 2, from 2 to 10 and using the short cut methods between 16 and 2.
*******************************************************************************/
#include <iostream>
#include <vector>
using namespace std;

// Globals
int currIndex = 0;
int remainderArr[64];

// Prints out the decimal to binary conversion result.
// Params: none
void printBinary()
{
	cout << "Converted number: ";
	for (int i = currIndex - 1; i >= 0; i--)
	{
		cout << remainderArr[i];
	}
	cout << endl;
}

// Converts a decimal number to binary representation.
// Params: valueToConvert The decimal value to convert to binary.
void decimalToBinary(int valueToConvert)
{
	int remainderVal;

	if (valueToConvert == 0)
	{
		printBinary();
		currIndex = 0;
		return;
	}

	remainderVal = valueToConvert % 2;
	valueToConvert = valueToConvert / 2;

	remainderArr[currIndex] = remainderVal;
	currIndex++;

	decimalToBinary(valueToConvert);
}

// Purpose: Converts a binary number to decimal representation.
// Params: valueToConvert The binary value to convert to decimal.
void binaryToDecimal(long valueToConvert)
{
	cout << valueToConvert << endl;
}

// Converts a hexadecimal number to binary representation.
// Params: valueToConvert The hexadecimal value to convert to binary.
void hexToBinary(long valueToConvert)
{
}

// Purpose: Converts a binary number to hexadecimal representation.
// Params: valueToConvert The binary value to convert to hexadecimal.
void binaryToHex(long valueToConvert)
{
	// used for storing each digit from the binary number passed in by the user
	long arrayofdigits[64];

	// used for storing the remainder in first while loop
	long remainder = 0;

	// used for storing the number calculated by the four or eight binary digit number passed in by the user
	long calculatednumber = 0;

	// a and b used for iterating and functioning, and performing calculations in the while and for loops
	long a = 1;

	long b = 0;

	// next three loops convert binary number to hexadecimal number
	// loop performs the appropriate calculations for each binary digit and adds them together and stores them into the calculatednumber variable
	// if user inputted an eight digit binary number will store both calculated numbers from the first and last four binary digits into the same calculatednumber variable
	while (valueToConvert > 0)
	{
		remainder = valueToConvert % 2;
		calculatednumber += remainder * a;
		a = a * 2;
		valueToConvert = valueToConvert / 10;
	}

	// reset a back to zero
	a = 0;
	// loop stores the calculated number from the first four binary digits or if user inputted eight binary digits the calculated numbers from first and last four digits seperately into array that contains the one or two number values needed for reading in the next loop to finally convert to the right hexadecimal value
	while (calculatednumber != 0)
	{
		arrayofdigits[a] = calculatednumber % 16;
		calculatednumber /= 16;
		a++;
	}
	// for loop that, executes after converting binary number to hexadecimal number above, that will print hexadecimal value as correct corresponding hexadecimal number value if the converted value is less than nine and if the converted value is more than nine will print the correct corresponding hexadecimal letter or character value
	for (b = a - 1; b >= 0; b--)
	{
		if (arrayofdigits[b] > 9)
		{
			cout << (char)(arrayofdigits[b] + 55);
		}
		else
		{
			cout << arrayofdigits[b];
		}
	}
	cout << endl;
}

// Purpose: Prints the list of available commands.
// Params: none
void printCommands()
{
	string commandList[] = {"   db - decimal(base 10) to binary", "   bd - binary to decimal(base 10)", "   hb - hexadecimal(base 16) to binary", "   bh - binary to hexadecimal(base 16)", "   q - quit", "   list - list Commands"};

	cout << "Commands:" << endl;
	for (int i = 0; i < 6; i++)
	{
		cout << commandList[i] << endl;
	}
}

int main(int argc, char *argv[])
{
	string command;
	long valueToConvert;

	cout << "Please enter conversion command, followed by the value you wish to convert." << endl;

	printCommands();

	cout << ">>> ";

	while (cin >> command)
	{
		if (command == "q")
		{
			break;
		}
		else if (command == "list")
		{
			printCommands();
		}
		else if (command == "db")
		{
			cin >> valueToConvert;
			decimalToBinary(valueToConvert);
		}
		else if (command == "bd")
		{
			cin >> valueToConvert;
			binaryToDecimal(valueToConvert);
		}
		else if (command == "hb")
		{
			cin >> valueToConvert;
			hexToBinary(valueToConvert);
		}
		else if (command == "bh")
		{
			cin >> valueToConvert;
			binaryToHex(valueToConvert);
		}
		else
		{
			cout << "Sorry that is not a valid command, please try again." << endl;
		}

		cout << ">>> ";
	}

	return 0;
}