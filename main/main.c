#include <stdio.h>


char *machineCodeConverter(const char *string);


//Main function
int main() {
    int MAX_LENGTH = 20;
    printf("Type in Assembly command\n");
    char string[20];
    while (1) {
        fgets(string, MAX_LENGTH, stdin);
        printf(machineCodeConverter(string));
    }
    return 0;
}


void resetCharArray(char *chars, int size) {
    for (int i = 0; i < size; i++) {
        chars[i] = '0';
    }
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

char *machineCodeConverter(const char *string) {
    //Empty command
    char *bits = "0000000000000000\n\0";
    //Set all 'bits' to 0 but not \n and \0 value at [16] and [17]
    resetCharArray(bits, 16);
    //OP code first
    //Then parameters
    //ADD
    if (string[0] == 'A' && string[1] == 'D') {
        bits[3] = '1';
        calculateDirectoryInBits(bits, 4, (string[5] - '0'));
        calculateDirectoryInBits(bits, 7, (string[8] - '0'));
        if (string[10] == 'R'){
            calculateDirectoryInBits(bits, 13, (string[11] - '0'));
        }
        else{
            bits[10] = '1';
        }

    }
        //NOT
    else if (string[0] == 'N') {
        bits[0] = '1';

        bits[3] = '1';
    }
        //BR
    else if (string[0] == 'B') {

        if (string[2] == 'n')
            bits[4] = '1';
        if (string[2] == 'z' || string[3] == 'z')
            bits[5] = '1';
        if (string[2] == 'p' || string[3] == 'p' || string[4] == 'p')
            bits[6] = '1';
        //PCoffset9 here
    }
        //LDR
    else if (string[0] == 'L') {
        bits[2] = '1';
        //LDR
        if (string[2] == 'R') {
            bits[1] = '1';
        }
            //LD (is still here to show LD is considered)
        else {
            bits[1] = '0';
        }
    }
        //ST
    else if (string[0] == 'S') {

        bits[2] = '1';
        bits[3] = '1';
    }
    return bits;
}
