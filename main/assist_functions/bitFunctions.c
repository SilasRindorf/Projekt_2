#include <stdbool.h>
#include <stdio.h>

void resetCharArray(char *chars, int size) {
    for (int i = 0; i < size; i++) {
        chars[i] = '0';
    }
}

int doublePower(int powerTimes) {
    int number = 2;
    if (powerTimes == 0)
        return 1;
    for (int i = 1; i < powerTimes; i++) {
        number *= 2;
    }
    return number;
}

void calculateDirectoryInBits(char *bits, int startBit, char directory) {
    directory -= '0';
    int offset = 0;
    if (directory - offset - 4 >= 0) {
        bits[startBit] = '1';
        offset += 4;
    }
    if ((directory - offset - 2) >= 0) {
        bits[startBit + 1] = '1';
        offset += 2;
    }
    if ((directory - offset - 1) == 0) {
        bits[startBit + 2] = '1';
    }
}

int charToInt(char *chars, int pos) {
    int number = 0;
    int counter;
    bool negativeNumber = false;
    if (chars[pos] == '-') {
        negativeNumber = true;
        pos++;
    }
    counter = pos;
    while (1) {
        if (chars[counter] == '\0' || chars[counter] == '\n') {
            if (negativeNumber) {
                number *= -1;
                return number;
            }
            return number;
        }
        number *= 10;
        number += chars[counter] - '0';
        counter++;
    }
}

void valueToCharArrayInBits(char *bits, int startBit, int bitsAvailable, int value) {
    bitsAvailable--;
    int offset = 0;
    int counter = 0;
    int number = doublePower(bitsAvailable);
    bool negativeNumber = false;
    if (value < 0) {
        value *= -1;
        negativeNumber = true;
    }
    for (int i = bitsAvailable + 1; i > 0; i--) {
        if (value - offset - number >= 0) {
            bits[startBit + counter] = '1';
            offset += number;
        }
        counter++;
        number = doublePower(bitsAvailable - counter);
    }
    if (negativeNumber) {
        for (int i = 0; i <= bitsAvailable; i++) {
            if (bits[startBit + i] == '1')
                bits[startBit + i] = '0';
            else if (bits[startBit + i] == '0')
                bits[startBit + i] = '1';
        }
        bits[startBit] = '1';
    }
}

void hexaDecimalToBinary(char *bits, const char *string, int startingPos) {
    int i = startingPos;
    int binaryCounter = 0;
    if (string[i] == 'x') {
        i++;
    }
    while (string[i]) {
        switch (string[i]) {
            {
                case '0':
                    bits[binaryCounter] = '0';
                bits[binaryCounter + 1] = '0';
                bits[binaryCounter + 2] = '0';
                bits[binaryCounter + 3] = '0';
                binaryCounter += 4;
                break;
                case '1':
                    bits[binaryCounter] = '0';
                bits[binaryCounter + 1] = '0';
                bits[binaryCounter + 2] = '0';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                case '2':
                    bits[binaryCounter] = '0';
                bits[binaryCounter + 1] = '0';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '0';
                binaryCounter += 4;
                break;
                case '3':
                    bits[binaryCounter] = '0';
                bits[binaryCounter + 1] = '0';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                case '4':
                    bits[binaryCounter] = '0';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '0';
                bits[binaryCounter + 3] = '0';
                binaryCounter += 4;
                break;
                case '5':
                    bits[binaryCounter] = '0';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '0';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                case '6':
                    bits[binaryCounter] = '0';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '0';
                binaryCounter += 4;
                break;
                case '7':
                    bits[binaryCounter] = '0';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                case '8':
                    bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '0';
                bits[binaryCounter + 2] = '0';
                bits[binaryCounter + 3] = '0';
                binaryCounter += 4;
                break;
                case '9':
                    bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '0';
                bits[binaryCounter + 2] = '0';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                case 'a':
                case 'A':
                    bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '0';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '0';
                binaryCounter += 4;
                break;
                case 'b':
                case 'B':
                    bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '0';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                case 'c':
                case 'C':
                    bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '0';
                bits[binaryCounter + 3] = '0';
                binaryCounter += 4;
                break;
                case 'd':
                case 'D':
                    bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '0';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                case 'e':
                case 'E':
                    bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '0';
                binaryCounter += 4;
                break;
                case 'f':
                case 'F':
                    bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                default:;
            }
        }
        i++;
    }
}

void stringzErNogetLort(char *string, char *bits) {
    //Source https://www.geeksforgeeks.org/convert-string-binary-sequence/
    //Rewrote the Java code into C code
    int stringCounter = 10;
    int bitCounter = 9;
    int val = 0;
    while (string[stringCounter] != '"') {
        val = string[stringCounter];

        if (string[stringCounter] != ' ') {
            while (val > 0) {
                if (val % 2 == 1) {
                    bits[bitCounter] = '1';
                    bitCounter++;
                } else {
                    bits[bitCounter] = '0';
                    bitCounter++;
                }
                val /= 2;
            }
            int l, r;
            r = 15;
            for (l = 9; l < r; l++, r--) {
                char temp = bits[l];
                bits[l] = bits[r];
                bits[r] = temp;
            }
        } else{
            for (int i = 0; i < 16; ++i) {
                if (i == 10){
                    bits[10]='1';
                } else bits[i] = '0';
            }
        }

        bitCounter = 9;
        stringCounter++;
        printf("%s", bits);
    }
}