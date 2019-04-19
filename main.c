#include <stdio.h>
#include <string.h>
#include "config.h"

void print_as_float(char *bytes)
{
    // Avoid strict aliasing violation
    float   f;
    memcpy(&f, bytes, sizeof(float));
    printf("%s%.*e%s", TEXT_BEG, DIGITS, f, TEXT_END);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <text>\n", argv[0]);
        return 1;
    }

    char  *string = argv[1];
    size_t length = strlen(string) + 1; // Include null terminator
    size_t  index = 0;

    printf("%s", PROG_BEG);

    while(index + sizeof(float) <= length)
    {
        print_as_float(&string[index]);
        index += sizeof(float);
    }

    if (length % sizeof(float))
    {
        char    copy[sizeof(float)];
        strncpy(copy, &string[index], sizeof(float));
        print_as_float(copy);
    }

    printf("%s", PROG_END);

    return 0;
}
