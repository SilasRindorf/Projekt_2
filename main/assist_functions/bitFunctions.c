#include <stdio.h>
#include <stdbool.h>


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

void calculateDirectoryInBits(char *bits, int startBit, int directory) {
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

//TEMP FUNCTION
//TODO MAKE PERMANENT FUNCTION
int charTo2DigitInt(const char chars[2]) {
    int number;
    if (chars[1] >= '0' && chars[1] <= '9') {
        number = chars[0] - '0';
        number *= 10;
        number += chars[1] - '0';
    } else {
        number = chars[0] - '0';
    }
    return number;
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
        if (chars[counter] == '\0') {
            if (negativeNumber) {
                return -number;
            }
            return number;
        }
        number *= 10;
        number = chars[counter] - '0';
        counter++;
    }
}

void valueToCharArrayInBits(char *bits, int startBit, int bitsAvailable, int value) {
    int offset = 0;
    bitsAvailable--;
    int number = doublePower(bitsAvailable);
    int counter = 0;
    for (int i = bitsAvailable + 1; i > 0; i--) {
        if (value - offset - number >= 0) {
            bits[startBit + counter] = '1';
            offset += number;
        }
        counter++;
        number = doublePower(bitsAvailable - counter);
    }
}