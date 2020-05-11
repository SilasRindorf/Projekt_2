//
// Created by Silas on 11-05-2020.
//
void resetCharArray(char *chars, int size);
void calculateDirectoryInBits(char *bits, int startBit, char directory);
void valueToCharArrayInBits(char *bits, int startBit, int bitsAvailable, int value);
int charToInt(char *chars, int pos);
void hexaDecimalToBinary(char *bits, const char *string,int startingPos);

//Verdens bedste debugger
//printf("%s","value: ");
//printf("%c",string[8]);
//printf("%s","\n");

char *machineCodeConverter(const char *string, int programCounter) {
    //Empty command
    char *bits = "0000000000000000\n\0";
    //Set all 'bits' to 0 but not \n and \0 value at [16] and [17]
    resetCharArray(bits, 16);
    //OP code first

    if (string[0] == 'A' && string[1] == 'D') {
        bits[3] = '1';
        calculateDirectoryInBits(bits, 4, string[5]);
        calculateDirectoryInBits(bits, 7, string[8]);
        if (string[10] == 'R') {
            calculateDirectoryInBits(bits, 13, string[11]);
        }
            //imm5
        else {
            bits[10] = '1';

            //Figure out how to make array in function call
            char temp[3] = {string[11], string[12], string[13]};
            //bit 12,13,14,15
            valueToCharArrayInBits(bits, 11, 5, charToInt(temp, 0));
        }
    }
        //NOT
    else if (string[0] == 'N') {
        bits[0] = '1';
        bits[3] = '1';
        calculateDirectoryInBits(bits, 4, string[5]);
        calculateDirectoryInBits(bits, 7, string[8]);
        bits[10] = '1';
        bits[11] = '1';
        bits[12] = '1';
        bits[13] = '1';
        bits[14] = '1';
        bits[15] = '1';
    }
        //BR
    else if (string[0] == 'B') {
        int pos = 3;
        if (string[2] == 'n') {
            bits[4] = '1';
            pos++;
        }

        if (string[2] == 'z' || string[3] == 'z') {
            bits[5] = '1';
            pos++;
        }
        if (string[2] == 'p' || string[3] == 'p' || string[4] == 'p') {
            bits[6] = '1';
            pos++;
        }
    }
        //LDR
    else if (string[0] == 'L') {
        bits[2] = '1';
        //LDR
        if (string[2] == 'R') {
            bits[1] = '1';
            calculateDirectoryInBits(bits, 4, string[5]);
            calculateDirectoryInBits(bits, 7, string[8]);
        }
            //Offset6 here
            //LD
        else {
            calculateDirectoryInBits(bits, 4, string[4]);
            bits[1] = '0';
            //PCoffset9 here
        }
    }
        //ST
    else if (string[0] == 'S') {
        bits[2] = '1';
        bits[3] = '1';
        calculateDirectoryInBits(bits, 4, string[4]);
        //PCoffset9 here
        //Step 2. Need label for it
    }
        //.ORIG x3000
        //.FILL x3000
        //.BLKW x3000
        //.FILL
    else if(string[0] == '.' && string[1] == 'O'){
        hexaDecimalToBinary(bits,string,7);
    }
    return bits;
}
