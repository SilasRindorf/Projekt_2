#include <stdio.h>
#include "Step_1.c"
#include "assist Functions/bits.c"
char *machineCodeConverter(const char *string);


//Main function
int main() {
    int MAX_LENGTH = 20;
    printf("Type in Assembly command\n");
    char string[20];
    while (1) {
        fgets(string, MAX_LENGTH, stdin);
        printf(machineCodeConverter(string));
    }
    return 0;
}



