#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc != 3)
        return 1;

    if (strstr(argv[1], argv[2]) != NULL)
        puts("1");
    else
        puts("0");

    return 0;
}