#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int isrepeating(string s);
int isvalidkey(string s);
int nonalpha(string s);

int main(int argc, string argv[])
{
    if (argc == 2 && isvalidkey(argv[1]))
    {
        string plaintext = get_string("plaintext: "); 

        int len = strlen(plaintext);s
        if (len > 0 && plaintext[len - 1] == '\n')
        {
            plaintext[len - 1] = '\0';
        }

        string s = argv[1];

        printf("ciphertext: ");
        for (int i = 0; i < len; i++)
        {
            int x;
            if (isalpha(plaintext[i]))
            {
                if (isupper(plaintext[i]))
                {
                    x = plaintext[i] - 'A';
                    printf("%c", toupper(s[x]));
                }
                else
                {
                    x = plaintext[i] - 'a';
                    printf("%c", tolower(s[x]));
                }
            }

            else
                printf("%c", plaintext[i]);
        }
        printf("\n");
        return 0;
    }
    else
    {
        if (argc != 2)
            printf("Usage: ./substitution KEY\n");

        else if (strlen(argv[1]) != 26)
            printf("Key must contain 26 characters\n");

        else if (nonalpha(argv[1]))
            printf("Key must only contain alphabetic characters\n");

        else if (isrepeating(argv[1]))
            printf("Key must not contain repeated characters\n");

        return 1;
    }
}

int isrepeating(string s)
{
    int i, j, l = strlen(s);
    for (i = 0; i < l; i++)
    {
        for (j = i + 1; j < l; j++)
        {
            if (s[i] == s[j])
                return 1;
        }
    }
    return 0;
}

int nonalpha(string s)
{
    for (int i = 0, len = strlen(s); i < len; i++)
    {
        if (isdigit(s[i]))
            return 1;
    }
    return 0;
}

int isvalidkey(string s)
{
    if (strlen(s) != 26 || isrepeating(s) || nonalpha(s))
    {
        return 0;
    }

    else
    {
        for (int i = 0, l = strlen(s); i < l; i++)
        {
            if (!isalpha(s[i]))
                return 0;
        }

        return 1;
    }
}
