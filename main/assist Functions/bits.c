//
// Created by Silas on 8-05-2020.
//


void resetCharArray(char *chars, int size) {
    for (int i = 0; i < size; i++) {
        chars[i] = '0';
    }
}
int doublePower(int powerTimes){
    int number = 2;
    for (int i = 0; i < powerTimes; i++){
        number = number * 2;
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
void calculateValueInBits(char *bits, int startBit, int bitsAvailable, int value) {
    int offset = 0;
    for (int i = bitsAvailable; i > 0; i--) {
        if (value - offset - 4 >= 0) {
            bits[startBit] = '1';
            offset += 4;
        }
    }
}