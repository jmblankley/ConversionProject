# Conversion Program

**Authors:** Joshua Blankley, Lance Cole, Renato da Silva Filho, Edward Duque, Aaron Jacobsen, Marcus Jones, Lia Revkova

**Date:** October 2023

## Project Description

Menu-driven program to convert numbers from base 10 to 2, from 2 to 10 and using the short cut methods between 16 and 2.

## Technologies Used

Linux, Github, C++

## Installation

In the terminal:
1. Compile the program using `g++ -o conversion -Wall -ansi -pedantic -std=c++20 main.cpp`.
2. Execute the program using `./conversion`.

## Usage

The following commands are available for interacting with the program:

- `db` - followed by a decimal number, converts the decimal number to binary
- `bd` - followed by a binary number, converts the binary number to decimal 
- `hb` - followed by a hexidecimal number, converts the hexidecimal number to binary 
- `bh` - followed by a binary number, converts the binary number to hexidecimal
- `list` - lists available commands
- `q` - quits the program
- `clear` - clears the user terminal

## Example
```console
Please enter conversion command, followed by the value you wish to convert.
Commands:
   db - decimal(base 10) to binary
   bd - binary to decimal(base 10)
   hb - hexadecimal(base 16) to binary
   bh - binary to hexadecimal(base 16)
   clear - clears the terminal
   q - quit
   list - list Commands
>>> db 5320945
Converted from Decimal to Binary: 10100010011000011110001
>>> bd 10110101101001
11625
>>> hb A307B2
Converted from Hexidecimal to Binary: 101000110000011110110010
>>> 1010010101010111010100111
Sorry that is not a valid command, please try again.
>>> bh 1010010101011010110111
Converted from Binary to Hexidecimal: 4E4B9
>>> q
