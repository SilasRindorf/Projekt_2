#include <stdio.h>
void *step2(char *filepath);

//Main function
int main() {
    int MAX_LENGTH = 20;
    //printf("Type in Assembly command\n");
    char string[] = "../resource/assembly.txt";
    char empty[20];
    while (1) {
        printf("%s","Enter to load again\n");
        fgets(empty, MAX_LENGTH, stdin);
        //printf(machineCodeConverter(string));
         step2(string);
    }
    return 0;
}



