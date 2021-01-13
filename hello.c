#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Asking the user their name
    string name = get_string("What's your name? \n");
    printf("hello, %s\n", name);
}
