#include <cs50.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int checksum1(long int card);
int checksum2(long int card);
string validation(int num1, int num2, long int card);

int main(void)
{
    long int card_number = INT_MIN;
    string user_input;
    char *endptr;

    // Prompt user to input credit card number
    do
    {
        user_input = get_string("Enter your credit card number: ");

        // Print the valid card number
        printf("Number: %s\n", user_input);

        // Convert the input to a long integer
        card_number = strtol(user_input, &endptr, 10);

        // Check if the conversion failed (endptr points to the same location)
        if (*endptr != '\0')
        {
            card_number = INT_MIN; // Reset to ensure loop continues
        }
    }
    while (card_number == INT_MIN);

    // Do all validations and store result
    string card_type = validation(checksum1(card_number), checksum2(card_number), card_number);

    // Print validation result
    printf("%s\n", card_type);
}

int checksum1(long int card)
{

    int digit, checksum = 0;

    // Extract every other digit starting from second-to-last digit
    for (int i = 2; (long int) pow(10, i - 1) <= card; i += 2)
    {

        // Store each digit
        digit = card % ((long int) pow(10, i)) / (long int) pow(10, i - 1);

        // Multiply each digit by two
        digit *= 2;

        // Split every two digited and sum eachother
        digit = digit > 9 ? digit / 10 + digit % 10 : digit;

        // Sum extracted and multiplied digits
        checksum += digit;
    }

    return checksum;
}

int checksum2(long int card)
{

    int digit, checksum = 0;

    // Extract the digits that weren't extracted in checksum1
    for (int i = 1; (long int) pow(10, i - 1) <= card; i += 2)
    {

        // Store each digit
        digit = card % ((long int) pow(10, i)) / (long int) pow(10, i - 1);

        // Sum extracted digits
        checksum += digit;
    }

    return checksum;
}

string validation(int sum1, int sum2, long int card)
{
    // Checksum validation
    bool final_checksum = (sum1 + sum2) % 10 == 0;
    if (final_checksum)
    // Prefix and length validation
    {
        int card_length = 0;
        while (card > 99)
        {
            card /= 10;
            card_length++;
        }
        card_length += 2;

        if ((card == 34 || card == 37) && card_length == 15)
        {
            return "AMEX";
        }
        else if ((card >= 51 && card <= 55) && card_length == 16)
        {
            return "MASTERCARD";
        }
        else if ((card >= 40 && card <= 50) && (card_length == 13 || card_length == 16))
        {
            return "VISA";
        }
    }

    return "INVALID";
}