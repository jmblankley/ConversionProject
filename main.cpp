/*******************************************************************************
Conversion Program

Authors: Joshua Blankley, Lance Cole, Renato da Silva Filho, Edward Duque, Aaron Jacobsen, Marcus Jones, Lia Revkova

October 2023

Menu-driven program to convert numbers from base 10 to 2, from 2 to 10 and using the short cut methods between 16 and 2.
*******************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Globals
int currIndex = 0;
int remainderArr[64];

// Prints out the decimal to binary conversion result.
// Params: none
void printBinary()
{
    cout << "Converted from Decimal to Binary: ";
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
void binaryToDecimal(unsigned long long bNum)
{

    int decimalNumber = 0, i = 0;
    while (bNum != 0)
    {
        int remainder = bNum % 10;
        bNum /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }

    cout << "Converted from Binary to Decimal: " << decimalNumber << endl;
}

// Converts a hexadecimal number to binary representation.
// Params: valueToConvert The hexadecimal value to convert to binary.
void hexadecimalToBinary(string hexatodecimal)
{
    cout << "Converted from Hexidecimal to Binary: ";
    long i;

    if (hexatodecimal[1] == 'x' || hexatodecimal[1] == 'X')
    {
        i = 2;
    }
    else
    {
        i = 0;
    }

    for (long j = i; j < (long)hexatodecimal.length(); j++)
    {
        // Example 0XAC1
        switch (hexatodecimal[j])
        {
        case '0':
            cout << "0000";
            break;
        case '1':
            cout << "0001";
            break;
        case '2':
            cout << "0010";
            break;
        case '3':
            cout << "0011";
            break;
        case '4':
            cout << "0100";
            break;
        case '5':
            cout << "0101";
            break;
        case '6':
            cout << "0110";
            break;
        case '7':
            cout << "0111";
            break;
        case '8':
            cout << "1000";
            break;
        case '9':
            cout << "1001";
            break;
        case 'A':
        case 'a':
            cout << "1010";
            break;
        case 'B':
        case 'b':
            cout << "1011";
            break;
        case 'C':
        case 'c':
            cout << "1100";
            break;
        case 'D':
        case 'd':
            cout << "1101";
            break;
        case 'E':
        case 'e':
            cout << "1110";
            break;
        case 'F':
        case 'f':
            cout << "1111";
            break;
        default:
            cout << " Not an hexadecimal digit! ";
        }
    }
    cout << endl;
}

void nibbleChecker(string nibble)
{
    if (nibble == "0000")
    {
        cout << '0';
    }
    else if (nibble == "0001")
    {
        cout << '1';
    }
    else if (nibble == "0010")
    {
        cout << '2';
    }
    else if (nibble == "0011")
    {
        cout << '3';
    }
    else if (nibble == "0100")
    {
        cout << '4';
    }
    else if (nibble == "0101")
    {
        cout << '5';
    }
    else if (nibble == "0110")
    {
        cout << '6';
    }
    else if (nibble == "0111")
    {
        cout << '7';
    }
    else if (nibble == "1000")
    {
        cout << '8';
    }
    else if (nibble == "1001")
    {
        cout << '9';
    }
    else if (nibble == "1010")
    {
        cout << 'A';
    }
    else if (nibble == "1011")
    {
        cout << 'B';
    }
    else if (nibble == "1100")
    {
        cout << 'C';
    }
    else if (nibble == "1101")
    {
        cout << 'D';
    }
    else if (nibble == "1110")
    {
        cout << 'E';
    }
    else if (nibble == "1111")
    {
        cout << 'F';
    }
    else
    {
        cout << " Not a valid binary digit! ";
    }
}

void binaryToHex(string valueToConvert)
{
    cout << "Converted from Binary to Hexadecimal: ";

    string extendedValue = valueToConvert;
    int extension = 4 - (valueToConvert.length() % 4);

    if (extension < 4)
    {
        extendedValue = string(extension, '0') + extendedValue;
    }

    for (int i = 0; i < extendedValue.length(); i += 4)
    {
        string nibble = extendedValue.substr(i, 4);
        nibbleChecker(nibble);
    }

    cout << endl;
}

// Purpose: Prints the list of available commands.
// Params: none
void printCommands()
{
    string commandList[] = {"   db - decimal(base 10) to binary", "   bd - binary to decimal(base 10)", "   hb - hexadecimal(base 16) to binary", "   bh - binary to hexadecimal(base 16)", "   clear - clears the terminal", "   q - quit", "   list - list Commands"};

    cout << "Commands:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << commandList[i] << endl;
    }

    cout << "(Keep binary input at 20 Digits or less.)" << endl;
}

int main(int argc, char *argv[])
{
    string command;
    string input;
    unsigned long long valueToConvert;
    string val;

    cout << "Please enter conversion command, followed by the value you wish to convert." << endl;

    printCommands();

    cout << ">>> ";

    while (cin >> command)
    {
        if (command == "q")
        {
            break;
        }
        else if (command == "clear")
        {
            system("clear");
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
            cin >> input;
            hexadecimalToBinary(input);
        }
        else if (command == "bh")
        {
            cin >> val;
            binaryToHex(val);
        }
        else
        {
            cout << "Sorry that is not a valid command, please try again." << endl;
        }

        cout << ">>> ";
    }

    return 0;
}
