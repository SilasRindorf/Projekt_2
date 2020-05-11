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
    while (string[i]) {
        switch (string[i]) {
            {
                case '0':
                    printf("%s", "value: ");
                printf("%c", "0000");
                printf("%s", "\n");
                bits[binaryCounter] = '1';
                bits[binaryCounter + 1] = '1';
                bits[binaryCounter + 2] = '1';
                bits[binaryCounter + 3] = '1';
                binaryCounter += 4;
                break;
                case '1':
                    printf("%s", "value: ");
                printf("%c", "0001");
                printf("%s", "\n");
                break;
                case '2':
                    printf("%s", "value: ");
                printf("%c", "0010");
                printf("%s", "\n");
                break;
                case '3':
                    printf("%s", "value: ");
                printf("%c", "0011");
                printf("%s", "\n");
                break;
                case '4':
                    printf("%s", "value: ");
                printf("%c", "0100");
                printf("%s", "\n");
                break;
                case '5':
                    printf("%s", "value: ");
                printf("%c", "0101");
                printf("%s", "\n");
                break;
                case '6':
                    printf("%s", "value: ");
                printf("%c", "0110");
                printf("%s", "\n");
                break;
                case '7':
                    printf("%s", "value: ");
                printf("%c", "0111");
                printf("%s", "\n");
                break;
                case '8':
                    printf("%s", "value: ");
                printf("%c", "1000");
                printf("%s", "\n");
                break;
                case '9':
                    printf("%s", "value: ");
                printf("%c", "1001");
                printf("%s", "\n");
                break;
                case 'a':
                case 'A':
                    printf("%s", "value: ");
                printf("%c", "1010");
                printf("%s", "\n");
                break;
                case 'b':
                case 'B':
                    printf("%s", "value: ");
                printf("%c", "1011");
                printf("%s", "\n");
                break;
                case 'c':
                case 'C':
                    printf("%s", "value: ");
                printf("%c", "1100");
                printf("%s", "\n");
                break;
                case 'd':
                case 'D':
                    printf("%s", "value: ");
                printf("%c", "1101");
                printf("%s", "\n");
                break;
                case 'e':
                case 'E':
                    printf("%s", "value: ");
                printf("%c", "1110");
                printf("%s", "\n");
                break;
                case 'f':
                case 'F':
                    printf("%s", "value: ");
                printf("%c", "1111");
                printf("%s", "\n");
                break;
                default:
                    printf("%s", "Invalid hexadecimal input." + string[i]);
            }
        }
        i++;
    }
}