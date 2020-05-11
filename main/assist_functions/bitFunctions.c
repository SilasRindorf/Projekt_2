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

void calculateDirectoryInBits(char *bits, int startBit, char directory) {
    directory -='0';
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