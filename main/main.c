#include <stdio.h>
char *machineCodeConverter(const char *string);
void *step2(char *filepath);

//Main function
int main() {
    int MAX_LENGTH = 20;
    printf("Type in Assembly command\n");
    char string[20];
    while (1) {
        //fgets(string, MAX_LENGTH, stdin);
        //printf(machineCodeConverter(string));
         step2("../resource/assembly.txt");
    }
    return 0;
}



