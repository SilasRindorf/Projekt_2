#include <stdio.h>


int main() {
    int MAX_LENGTH = 20;
    printf("Type in Assembly command\n");
    char string[MAX_LENGTH];
    fgets(string,MAX_LENGTH,stdin);
    return 0;
}
