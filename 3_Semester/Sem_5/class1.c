#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define BUFFER_SIZE 1000000

void read_file_to_string(const char* filename, char* str)
{
    FILE* f = fopen(filename, "r");
    
    int i = 0;
    while (1)
    {
        int c = fgetc(f);
        if (c == EOF)
            break;

        str[i] = (char)c;
        i += 1;
    }
    str[i] = '\0';

    fclose(f);
}

void save_string_to_file(const char* filename, const char* str)
{
    FILE* f = fopen(filename, "w");
    fprintf(f, "%s", str);
    fclose(f);
}


int main(char argc, char** argv)
{
    char str[BUFFER_SIZE];
    read_file_to_string(argv[1], str);
    int letters[26] = {0};
    for (int i = 0; str[i] != '\0'; i++)
    {
        str[i] = tolower(str[i]);
        letters[str[i] - 'a'] += 1;
    }
    for (int i = 0; i < 26; i += 1)
        printf("%c: %i\n", i + 'a', letters[i]);
}