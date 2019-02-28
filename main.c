#include <stdio.h>
#include <string.h>
#include "config.h" /* digits */

/* This prints bytes as a float
 * Relies on digits from `config.h`.
 */
void print_as_float(char *bytes)
{
    printf("%.*e", digits, *(float*)bytes);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <string>\n", argv[0]);
        return 1;
    }

    /* Input string */
    char *string = argv[1];
    int   length = strlen(string);

    /* Print the start of the program */
    printf("#include <stdio.h>\n\nstatic float text[] =\n{\n");

    /* Loop to print the floats */
    for (int i = 0; i + sizeof(float) - 1 < length; i += sizeof(float))
    {
        printf("\t");
        print_as_float(&string[i]);
        printf(",\n");
    }

    /* Print the leftovers we missed, includes null-terminator.
     * TODO: Make this less bad somehow
     */
    if (length % sizeof(float))
    {
        char copy[sizeof(float)] = { 0 };
        int index = length - (length % sizeof(float));
        strncpy(copy, &string[index], sizeof(float));
        printf("\t");
        print_as_float(copy);
        printf("\n");
    }
    else
    {
        /* TODO: Relies on 0.0f containing a null byte, might not be true in some universe. */
        printf("\t0\n");
    }

    /* Print the rest  of the program */
    printf("};\n\nint main()\n{\n\tputs((char*)text);\n}\n");

    return 0;
}
