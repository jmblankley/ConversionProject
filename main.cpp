/*******************************************************************************
Conversion Project

Joshua Blankley, ...add names here

October 2023
Menu-driven program to convert numbers from base 10 to 2, from 2 to 10 and using the
short cut methods between 16 and 2.
*******************************************************************************/
#include <iostream>
using namespace std;

// Converts a decimal number to binary representation.
// Params: valueToConvert The decimal value to convert to binary.
void decimalToBinary(int valueToConvert)
{
}

// Purpose: Converts a binary number to decimal representation.
// Params: valueToConvert The binary value to convert to decimal.
void binaryToDecimal(int valueToConvert)
{
}

// Converts a hexadecimal number to binary representation.
// Params: valueToConvert The hexadecimal value to convert to binary.
void hexToBinary(int valueToConvert)
{
}

// Purpose: Converts a binary number to hexadecimal representation.
// Params: valueToConvert The binary value to convert to hexadecimal.
void binaryToHex(int valueToConvert)
{
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
	int valueToConvert;

	cout << "Please enter conversion command, followed by the value you wish to convert." << endl;
	printCommands();

	cout << ">>> ";
	cin >> command;

	while (command != "q")
	{
		if (command == "list")
		{
			printCommands();
		}
		else if (command == "db")
		{
			cout << "Enter value you wish to convert: ";
			cin >> valueToConvert;
			decimalToBinary(valueToConvert);
		}
		else if (command == "bd")
		{
			cout << "Enter value you wish to convert: ";
			cin >> valueToConvert;
			binaryToDecimal(valueToConvert);
		}
		else if (command == "hb")
		{
			cout << "Enter value you wish to convert: ";
			cin >> valueToConvert;
			hexToBinary(valueToConvert);
		}
		else if (command == "bh")
		{
			cout << "Enter value you wish to convert: ";
			cin >> valueToConvert;
			binaryToHex(valueToConvert);
		}
		else
		{
			cout << "Sorry that is not a valid command, please try again." << endl;
		}

		cout << ">>> ";
		cin >> command;
	}

	return 0;
}