#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int cents, quarters, dimes, nickels, pennies, coins;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    for (quarters = 0; cents >= 25; cents -= 25)
    {
        quarters++;
    }

    for (dimes = 0; cents >= 10; cents -= 10)
    {
        dimes++;
    }

    for (nickels = 0; cents >= 5; cents -= 5)
    {
        nickels++;
    }

    for (pennies = 0; cents >= 1; cents -= 1)
    {
        pennies++;
    }
    coins = quarters + dimes + nickels + pennies;
    printf("%d\n", coins);
}
