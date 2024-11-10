#include <limits.h>
#include <stdio.h>

int years(int start, int expected);

int main(void)
{
    int start_population, expected_population;

    // Prompt for start size
    do
    {
        printf("Enter the start population: ");
        scanf("%i", &start_population);
    }
    while (start_population < 9 || start_population > INT_MAX);

    // Prompt for end size
    do
    {
        printf("Enter the expected population: ");
        scanf("%i", &expected_population);
    }
    while (expected_population < start_population || expected_population > INT_MAX);

    // Print result
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
