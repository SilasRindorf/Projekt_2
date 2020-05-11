//
// Created by Silas on 11-05-2020.
//


void resetCharArray(char *chars, int size) {
    for (int i = 0; i < size; i++) {
        chars[i] = '0';
    }
}

int doublePower(int powerTimes) {
    int number = 2;
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
int charTo2DigitInt(const char chars[2]){
    int number;
    if (chars[1] >= '0' && chars[1] <= '9'){
        number = chars[0] - '0';
        number *= 10;
        number += chars[1] - '0';
    } else{
        number = chars[0] - '0';
    }
    return number;
}
void valueToCharArrayInBits(char *bits, int startBit, int bitsAvailable, int value) {
    int offset = 0;
    int number = doublePower(bitsAvailable);
    int counter = 0;
    for (int i = bitsAvailable; i > 0; i--) {

        if (value - offset - number >= 0) {
            bits[startBit + counter] = '1';
            offset += number;
        }
        counter++;
        number = doublePower(bitsAvailable - counter);
    }
}