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
void binaryToDecimal(long bNum)
{

    int decimalNumber = 0, i = 0;
    while (bNum != 0)
    {
        int remainder = bNum % 10;
        bNum /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }

    cout << "The Decimal Number is: " << decimalNumber << endl;
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

    for (long j = i; j < hexatodecimal.length(); j++)
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

// Purpose: Converts a binary number to hexadecimal representation.
// Params: valueToConvert The binary value to convert to hexadecimal.
void binaryToHex(long valueToConvert)
{
    cout << "Converted from Binary to Hexidecimal: ";
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
    string commandList[] = {"   db - decimal(base 10) to binary", "   bd - binary to decimal(base 10)", "   hb - hexadecimal(base 16) to binary", "   bh - binary to hexadecimal(base 16)", "   clear - clears the terminal", "   q - quit", "   list - list Commands"};

    cout << "Commands:" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << commandList[i] << endl;
    }
}

int main(int argc, char *argv[])
{
    string command;
    string input;
    long valueToConvert;
    long bNum;

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
            cin >> input;
            hexadecimalToBinary(input);
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
