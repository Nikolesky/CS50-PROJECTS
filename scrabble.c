#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score_counter(string s);

int main(void)
{
    string player1 = get_string("Player 1: ");
    string player2 = get_string("Player 2: ");

    int score1 = score_counter(player1);
    int score2 = score_counter(player2);

    if (score1 > score2)
        printf("Player 1 wins!\n");

    else if (score2 > score1)
        printf("Player 2 wins!\n");

    else
        printf("Tie!\n");
}

int score_counter(string s)
{
    int points[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
    int sum = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (isalpha(s[i]))
        {
            if (isupper(s[i]))
                sum += points[s[i] - 'A'];

            else
                sum += points[s[i] - 'a'];
        }
    }
    return sum;
}
