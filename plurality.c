#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 9

bool vote(string candidate_name);
void print_winner(void);
void string_toupper(char *s);

typedef struct
{
    string name;
    int votes;
} candidate;

candidate candidates[MAX_CANDIDATES];
int candidate_count;

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: Plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;

    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates exceeded.\n");
        return 1;
    }

    int voters = get_int("Number of voters: ");

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        string_toupper(candidates[i].name);
        candidates[i].votes = 0;
    }

    for (int i = 0; i < voters; i++)
    {
        string candidate_name = get_string("Vote: ");
        string_toupper(candidate_name);

        if (!vote(candidate_name))
        {
            printf("Invalid vote.\n");
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
    }

    print_winner();

    return 0;
}

bool vote(string candidate_name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].name, candidate_name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int max_votes = 0;

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

void string_toupper(char *s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = toupper(s[i]);
    }
}
