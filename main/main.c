#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 40
void step1(int *programCounterPointer, char * string);
void step2 (const char *inputPath, const char *outputPath, int *programCounterPointer);

//Main function
int main() {
    //printf("Type in Assembly command\n");
    char input[] = "../resource/assembly.txt";
    char output[] = "../resource/output.txt";
    char choice[MAX_LENGTH];
    int * programCounter = (int *) 3000;
    while (1) {
        printf("%s","'1' to run step 1\n'2' to run step 2\n'Q' to quit\n");
        scanf("%s",choice);
        if (strcmp(choice,"1") == 0){
            printf("%s","Write an assembly line\n");
            fgets(choice,MAX_LENGTH,stdin);
            fgets(choice,MAX_LENGTH,stdin);
            step1(programCounter,choice);
        }
        else if (strcmp(choice,"2") == 0){
            step2(input,output,programCounter);
        }
        else if (strcmp(choice,"Q") == 0) {
            printf("%s","Closing program\n");
            return 0;
        }
        else
            printf("%s","Not a valid command\n");
    }
}



