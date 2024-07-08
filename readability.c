#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int word_counter(string text);
int letter_counter(string text);
int sentance_counter(string text);

int main(void)
{
    string text = get_string("Text: ");

    int a = word_counter(text);
    int b = letter_counter(text);
    int c = sentance_counter(text);

    float L = ((float) b / a) * 100;
    float S = ((float) c / a) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int i = round(index);

    if (index < 1)
        printf("Before Grade 1\n");

    else if (index >= 16)
        printf("Grade 16+\n");

    else
        printf("Grade %d\n", i);
}

int word_counter(string text)
{
    int words = 1;
    for (int c = 0, length = strlen(text); c < length; c++)
    {
        if (isspace(text[c]))
            words++;
    }
    return words;
}

int letter_counter(string text)
{
    int letters = 0;
    for (int c = 0, length = strlen(text); c < length; c++)
    {
        if (isalpha(text[c]))
            letters++;
    }
    return letters;
}

int sentance_counter(string text)
{
    int sentances = 0;
    for (int c = 0, length = strlen(text); c < length; c++)
    {
        if (text[c] == '.' || text[c] == '?' || text[c] == '!')
            sentances++;
    }
    return sentances;
}
