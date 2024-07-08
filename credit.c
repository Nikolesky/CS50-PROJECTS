#include <cs50.h>
#include <stdio.h>

int every_other_number(long credit_card_number);
int break_and_add(long credit_card_number);
int counter(long credit_card_numbber);
int first_two_digits(long credit_card_number);
int first_digit(long credit_card_number);

int main(void)
{
    long credit_card_number = get_long("Number: ");
    int a = every_other_number(credit_card_number) + break_and_add(credit_card_number);
    if (a % 10 == 0)
    {
        if (counter(credit_card_number) == 15)
        {
            if (first_two_digits(credit_card_number) == 34 ||
                first_two_digits(credit_card_number) == 37)
                printf("AMEX\n");

            else
                printf("INVALID\n");
        }

        else if (counter(credit_card_number) == 16)
        {
            if (first_digit(credit_card_number) == 4)
                printf("VISA\n");

            else if (first_two_digits(credit_card_number) == 51 ||
                     first_two_digits(credit_card_number) == 52 ||
                     first_two_digits(credit_card_number) == 53 ||
                     first_two_digits(credit_card_number) == 54 ||
                     first_two_digits(credit_card_number) == 55)
                printf("MASTERCARD\n");

            else
                printf("INVALID\n");
        }

        else if (counter(credit_card_number) == 13)
        {
            if (first_digit(credit_card_number) == 4)
                printf("VISA\n");

            else
                printf("INVALID\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int every_other_number(long credit_card_number)
{
    int sum1 = 0, c;
    for (c = 0; credit_card_number > 0; c++)
    {
        if (c % 2 == 0)
        {
            sum1 = sum1 + credit_card_number % 10;
        }
        credit_card_number = credit_card_number / 10;
    }
    return sum1;
}

int break_and_add(long credit_card_number)
{
    int sum2 = 0, c, a;
    for (c = 0; credit_card_number > 0; c++)
    {

        if (c % 2 != 0)
        {
            a = (credit_card_number % 10) * 2;
            sum2 = sum2 + (a / 10) + (a % 10);
        }
        credit_card_number = credit_card_number / 10;
    }
    return sum2;
}

int counter(long credit_card_number)
{
    int i;
    for (i = 0; credit_card_number > 0; i++)
    {
        credit_card_number = credit_card_number / 10;
    }
    return i;
}

int first_two_digits(long credit_card_number)
{
    int first_two;
    while (credit_card_number >= 100)
    {
        credit_card_number /= 10;
    }
    first_two = credit_card_number;
    return first_two;
}

int first_digit(long credit_card_number)
{
    int first;
    while (credit_card_number >= 10)
    {
        credit_card_number /= 10;
    }
    first = credit_card_number;
    return first;
}
