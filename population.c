#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Prompt user for starting population
    int s;
    do
    {
        s = get_int("Starting Population: ");
    }
    while (s < 9);

    // Prompt user for ending population
    int e;
    do
    {
        e = get_int("Ending Population: ");
    }
    while (e < s);

    // Calculate the number of years until we reach threshold
    int y = 0;

    while (s < e)
    {
        s = s + (s / 3) - (s / 4);
        y++;
    }

    // Print number of years
    printf("Years: %i\n", y);
}
