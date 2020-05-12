//
// Created by Silas on 11-05-2020.
//

#include <stdio.h>
#include <stdlib.h>

void machineCodeConverter(const char * inputPath,const char * outputPath, int *programCounter);
void reserveMemory ( char *string,  int *programCounter, char *labels[],int *ints[]);

void step2(char *filepath) {
    int *programCounter = (int *) 3000;
    machineCodeConverter(filepath,"../resource/output.txt",programCounter);




    /*FILE *fp;
    char line[20000];
    char *labels[20];
    int *ints[20];
    for (int j = 0; j < 20; ++j) {
        ints[j] = (int *) -1;
        labels[j] = "Empty";
    }
    int counter = 1;
    while (fgets(line, 20000, fp) != NULL) {
        //printf("%s", line);
        //printf(machineCodeConverter(line,programCounter));
        //fprintf(outputFile,line,counter);
        reserveMemory(line,programCounter,labels,ints);
        counter++;
        programCounter++;
    }
    for (int i = 0; i < 20; ++i) {
        printf("%s","Label: ");
        printf("%p",labels[i]);
        printf("%s","\n");
        printf("%s","int: ");
        printf("%p",ints[i]);
        printf("%s","\n");

    }*/


}