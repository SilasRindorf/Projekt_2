//
// Created by Silas on 11-05-2020.
//

#include <stdio.h>
#include <stdlib.h>
char *machineCodeConverter(const char *string);

void step2(char *filepath){
    FILE *fp;
    char line[20000];
    fp = fopen( filepath, "r");
    if (fp == NULL) {
        printf("%s", "Could not open file ", filepath);
        exit(1);
    }
    while (fgets(line, 20000, fp) != NULL) {
        printf("%s", line);
        printf(machineCodeConverter(line));
    }
    exit(0);
    fclose(fp);
}