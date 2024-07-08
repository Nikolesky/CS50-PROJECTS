#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int integer(string key);

int main(int argc, string argv[])
{
    if (argc == 2 && integer(argv[1]) == 1)
    {
        int k = atoi(argv[1]);

        string s = get_string("plaintext: ");

        int length = strlen(s);
        printf("ciphertext: ");
        for (int i = 0; i < length; i++)
        {
            if (isupper(s[i]))
            {
                int ci = (s[i] + k - 'A') % 26;
                int c = 'A' + ci;
                printf("%c", c);
            }
            else if (islower(s[i]))
            {
                int ci = (s[i] + k - 'a') % 26;
                int c = 'a' + ci;
                printf("%c", c);
            }
            else
                printf("%c", s[i]);
        }
        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int integer(string key)
{
    int length = strlen(key);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit(key[i]))
            return 0;
    }
    return 1;
}
