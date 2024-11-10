#include <cs50.h>
#include <stdio.h>

int years(int start, int expected);

int main(void)
{
    int start_population, expected_population;
    // Prompt for start size
    do
    {
        start_population = get_int("Enter the start population: ");
    }

    while (start_population < 9);


    // Prompt for end size
    do
    {
        expected_population = get_int("Enter the expected population: ");
    }

    while (expected_population < start_population);


    // Print number of years
    printf("Years: %i\n", years(start_population, expected_population));
}

// Calculate number of years until we reach threshold
int years(int start, int expected)
{
    int year = 0;
    while (start < expected)
    {
        start += start / 3 - start / 4;
        year++;
    }

    return year;
}
