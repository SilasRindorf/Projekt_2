//
// Created by Silas on 11-05-2020.
//
void resetCharArray(char *chars, int size);
void calculateDirectoryInBits(char *bits, int startBit, int directory);
void calculateValueInBits(char *bits, int startBit, int bitsAvailable, int value);

char *machineCodeConverter(const char *string) {
    //Empty command
    char *bits = "0000000000000000\n\0";
    int offset = 0;
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
            if (string[11] == '-')
                bits[11] = '1';
        }
        offset++;

    }
        //NOT
    else if (string[0] == 'N') {
            bits[0] = '1';
            bits[3] = '1';
            calculateDirectoryInBits(bits, 4, (string[5] - '0'));
            calculateDirectoryInBits(bits, 7, (string[8] - '0'));
            bits[10] = '1';
            bits[11] = '1';
            bits[12] = '1';
            bits[13] = '1';
            bits[14] = '1';
            bits[15] = '1';
            offset++;
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
        //Step 2. Need label for it
    }
        //LDR
    else if (string[0] == 'L') {
        bits[2] = '1';
        //LDR
        if (string[2] == 'R') {
            bits[1] = '1';
        }
        //PCoffset9 here
        //BaseR is where we start from. 3000x
        //Step 2. Need label for it


        //LD (is still here to show LD is considered)
        else {
            bits[1] = '0';
        }
    }
        //ST
    else if (string[0] == 'S') {
        bits[2] = '1';
        bits[3] = '1';
        //PCoffset9 here
        //Step 2. Need label for it
    }
    return bits;
}
