#include <stdio.h>
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



