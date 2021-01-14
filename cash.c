#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Ask user how much change is owed
    float change;
    do
    {
        change = get_float("Change Owed: ");
    }
    while (change < 0);

    // Calculate
    int cents = round(change * 100);
    int coins = 0;

    // Quarters
    while (cents >= 25)
    {
        cents -= 25;
        coins++;
    }

    // Dimes
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }

    // Nickels
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }

    // Pennies
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }
    printf("%i\n", coins);
}
