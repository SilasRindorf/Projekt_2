#include <stdio.h>
void *step2(char *filepath);
char *machineCodeConverter(const char *string,int programCounter);

//Main function
int main() {
    int MAX_LENGTH = 20;
    int programCounter = 3000;
    printf("Type in Assembly command\n");
    char string[20];
    while (1) {
        //fgets(string, MAX_LENGTH, stdin);
        //printf(machineCodeConverter(string));
         step2("../resource/assembly.txt");
         programCounter++;
    }
    return 0;
}



