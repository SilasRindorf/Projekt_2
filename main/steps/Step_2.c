//
// Created by Silas on 11-05-2020.
//

#include <stdio.h>
#include <stdlib.h>
char *machineCodeConverter(const char *string,int *programCounter);

void step2(char *filepath){
    int programCounter = 3000;
    FILE *fp;
    char line[20000];
    fp = fopen( filepath, "r");
    if (fp == NULL) {
        printf("%s", "Could not open file ", filepath);
        exit(1);
    }
    FILE *outputFile;
    char writeLine[20000];
    outputFile = fopen("../resource/output.txt", "w");
    if (outputFile == NULL) {
        printf("%s", "Could not open file ", filepath);
        exit(1);
    }
    int counter = 1;
    while (fgets(line, 20000, fp) != NULL) {
        //printf("%s", line);
        //printf(machineCodeConverter(line,programCounter));
        fprintf(outputFile,machineCodeConverter(line,programCounter),counter);
        programCounter++;
        counter++;
    }
    fclose(fp);
    exit(0);
}