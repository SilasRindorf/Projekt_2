
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 200
#include <stdbool.h>


int findOffset(char labels[100][200], int labelvalue[100], int programCounter, char label[]);
void resetCharArray(char *chars, int size);
void calculateDirectoryInBits(char *bits, int startBit, char directory);
void valueToCharArrayInBits(char *bits, int startBit, int bitsAvailable, int value);
int charToInt(char *chars, int pos);
void hexaDecimalToBinary(char *bits, const char *string, int startingPos);
void stringz(char *string, char *bits, int *programCounter, FILE *outputFile);
void step2 (const char *inputPath, const char *outputPath, int *programCounterPointer) {
    int programCounter = (int) programCounterPointer;
    FILE *inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        printf("%s", "Could not open file ", inputPath);
        exit(1);
    }
    FILE *outputFile;
    outputFile = fopen(outputPath, "w");
    if (outputFile == NULL) {
        printf("%s", "Could not open file output");
        exit(2);
    }
    char string[MAX_SIZE];
    int counter = 0;
    int labelValue[100];
    char labels[100][MAX_SIZE];
    for (int k = 0; k < 100; ++k) {
        strcpy(labels[k], "Empty");
        labelValue[k] = -1;
    }

    int labelCounter = 0;
    while (fgets(string, MAX_SIZE, inputFile) != NULL) {
        //Empty command
        char *bits = "0000000000000000\n\0";
        //Set all 'bits' to 0 but not \n and \0 value at [16] and [17]
        resetCharArray(bits, 16);
        if (string[0] == 'A' && string[1] == 'D') {}//ADD
        else if (string[0] == 'N' && string[1] == 'O' && string[2] == 'T') {}//NOT
        else if (string[0] == 'B' && string[1] == 'R') {}//BR
        else if (string[0] == 'L' && string[1] == 'D') {}//LDR/LD
        else if (string[0] == 'S' && string[1] == 'T') {}//ST
        else if (string[0] == '.') {
            //.ORIG x
            if (string[1] == 'O') {
                //hexaDecimalToBinary(bits, string, 6);
            }
                //.FILL
            else if (string[1] == 'F') {
                //hexaDecimalToBinary(bits, string, 6);
            }
                //.BLKW
            else if (string[1] == 'B') {
                for (int i = 0; i < charToInt(string, 6) - 1; i++) {
                    //printf("%s",bits);
                    programCounter++;
                    // printf("%s","\n");
                }
            }
                //.STRINGZ
            else if (string[1] == 'S') {
                //stringz(string, bits, programCounter);
                for (int i = 0; i < 15; ++i) {
                    bits[i] = '0';
                }
            }
                // END
            else if (string[1] == 'E') {

            }

        }//LABEL
        else if (string[0] != ' ' && string[0] != '\n') {
            strcpy(labels[labelCounter], string);
            labelValue[labelCounter] = programCounter;
            labelCounter++;
        }
        programCounter++;
        counter++;
        //printf("%s", bits);
        //fprintf(outputPath, bits, counter);
    }
    counter = 0;
    programCounter = (int) programCounterPointer;

    inputFile = fopen(inputPath, "r");
    if (inputFile == NULL) {
        printf("%s", "Could not open file ", inputPath);
        exit(1);
    }


    while (fgets(string, MAX_SIZE, inputFile) != NULL) {
        printf("%s", string);
        //Empty command
        char *bits = "0000000000000000\n\0";
        //Making sure not to print labels
        bool print = false;

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
            print = true;
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
            print = true;
        }
            //BR
        else if (string[0] == 'B' && string[1] == 'R') {
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
            char offsetString[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            int temp = 0;
            int i = 6;
            while (string[i] != '\n'){
                offsetString[temp] = string[i];
                temp ++;
                i++;
            }

            valueToCharArrayInBits(bits,7,9,findOffset(labels, labelValue, programCounter, offsetString));
            print = true;
        }
            //LDR
        else if (string[0] == 'L') {
            bits[2] = '1';
            //LDR
            if (string[2] == 'R') {
                bits[1] = '1';
                calculateDirectoryInBits(bits, 4, string[5]);
                calculateDirectoryInBits(bits, 7, string[8]);
                valueToCharArrayInBits(bits,10,6,charToInt(string,11));
            }

                //LD
            else {
                calculateDirectoryInBits(bits, 4, string[4]);
                bits[1] = '0';
                char offsetString[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
                int temp = 0;
                int i = 6;
                while (string[i] != '\n'){
                    offsetString[temp] = string[i];
                    temp ++;
                    i++;
                }
                valueToCharArrayInBits(bits,7,9,findOffset(labels, labelValue, programCounter, offsetString));
            }
            print = true;
        }
            //ST
        else if (string[0] == 'S') {
            bits[2] = '1';
            bits[3] = '1';
            calculateDirectoryInBits(bits, 4, string[4]);
            char offsetString[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
            int temp = 0;
            int i = 6;
            while (string[i] != '\n'){
                offsetString[temp] = string[i];
                temp ++;
                i++;
            }
            valueToCharArrayInBits(bits,7,9,findOffset(labels, labelValue, programCounter, offsetString));
            print = true;
        }
            //.ORIG x
        else if (string[0] == '.' && string[1] == 'O') {
            hexaDecimalToBinary(bits, string, 6);
            print = true;
        }

            //.FILL
        else if (string[0] == '.' && string[1] == 'F') {
            hexaDecimalToBinary(bits, string, 6);
            print = true;
        }
            //.BLKW
        else if (string[0] == '.' && string[1] == 'B') {
            for (int i = 0; i < charToInt(string, 6) - 1; i++) {
                printf("%s",bits);
                programCounter++;
                printf("%s","\n");
            }
            print = true;
        }
            //.STRINGZ
        else if (string[0] == '.' && string[1] == 'S') {
            stringz(string, bits, (int *) programCounter,outputFile);
            for (int i = 0; i < 16; ++i) {
                bits[i] = '0';
            }
            print = true;
        }
            // .END
        else if (string[0] == '.' && string[1] == 'E') {
            return;
        }
        if (print){
            printf("%s", bits);
            fprintf(outputFile,"%s",bits);
        }
        programCounter++;
        counter++;
    }
    fclose(inputFile);
    printf("%s", "god help me plz");
    fclose(outputFile);
}