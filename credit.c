#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Getting the card number
    long number = get_long("Card Number: ");
    
    // Count the number of digits
    int digits = 0;
    long card = number;
    while (card > 0)
    {
        card = card / 10;
        digits++;
    }
    
    // Check if the length is valid
    if (digits != 13 && digits != 15 && digits != 16)
    {
        printf("INVALID\n");
        return 0;
    }
    
    int remainder1;
    int remainder2;
    int sum1 = 0;
    int sum2 = 0;
    int last_digit = 0;
    int digit1;
    int digit2;
    long x = number;
    
    do
    {
        // Removing the last digit to add to sum1
        remainder1 = x % 10;
        x = x / 10;
        sum1 = sum1 + remainder1;
        
        // Removing the second last digit
        remainder2 = x % 10;
        x = x / 10;
        
        // Multiplying the second last digit by 2 and adding the digits to sum2
        remainder2 = remainder2 * 2;
        digit1 = remainder2 % 10;
        digit2 = remainder2 / 10;
        sum2 = sum2 + digit1 + digit2;
    }
    while (x > 0);
    
    last_digit = sum1 + sum2;
    last_digit = last_digit % 10;
    
    // Luhn Algorithm
    if (last_digit != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    
    // Getting the starting digits
    long startdigit = number;
    do
    {
        startdigit = startdigit / 10;
    }
    while (startdigit > 100);
    
    // Checking the starting digits for each card type
    if ((startdigit / 10 == 5) && (0 < startdigit % 10 && startdigit % 10 < 6))
    {
        printf("MASTERCARD\n");
    }
    else if ((startdigit / 10 == 3) && (startdigit % 10 == 4 || startdigit % 10 == 7))
    {
        printf("AMEX\n");
    }
    else if (startdigit / 10 == 4)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
