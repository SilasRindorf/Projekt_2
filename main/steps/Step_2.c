//
// Created by Silas on 11-05-2020.
//

#include <stdio.h>
#include <stdlib.h>

char *machineCodeConverter(const char *string, int *programCounter);
void reserveMemory (const char *string, int *programCounter, char *labels,int *ints);

void step2(char *filepath) {
    int *programCounter = 3000;
    FILE *fp;
    char line[20000];
    char *labels[20];
    int *ints[20];
    filepath = "../resource/assembly.txt";
    fp = fopen(filepath, "r");
    if (fp == NULL) {
        printf("%s", "Could not open file ", filepath);
        exit(1);
    }
    FILE *outputFile;
    outputFile = fopen("../resource/output.txt", "w");
    if (outputFile == NULL) {
        printf("%s", "Could not open file output");
        exit(1);
    }
    int counter = 1;
    while (fgets(line, 20000, fp) != NULL) {
        //printf("%s", line);
        //printf(machineCodeConverter(line,programCounter));
        fprintf(outputFile,line,counter);
        reserveMemory(line,programCounter,labels,ints);
        counter++;
        programCounter++;
    }
    for (int i = 0; i < 20; ++i) {
        printf("%s","value: ");
        printf("%s",labels[i]);
        printf("%s","\n");
        printf("%i",ints[i]);
        printf("%s","\n");

    }
    while (fgets(line, 20000, fp) != NULL) {
        //printf("%s", line);
        //printf(machineCodeConverter(line,programCounter));
        fprintf(outputFile,line,counter);
        counter++;
        fprintf(outputFile, machineCodeConverter(line,programCounter), counter);
        programCounter++;
        counter++;
    }
    fclose(fp);
    fclose(outputFile);
    exit(0);
}