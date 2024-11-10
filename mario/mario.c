#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    char input[101];

    do
    {
        // Ask user to input pyramid's height
        printf("Enter pyramid's height (1-8): ");
        fgets(input, sizeof(input), stdin);

        char *endptr;
        height = strtol(input, &endptr, 10);

        if (*endptr != '\0' && *endptr != '\n') 
        {
            printf("Invalid input. Please enter a valid integer.\n");
        }
        else if (height < 1 || height > 8) 
        {
            printf("Height must be between 1 and 8. Try again.\n");
        }
    } 
    while (height < 1 || height > 8);
    
    // Calculate rows
    for (int row = 0; row < height; row++)
    {
        //  Calculate and print left white spaces
        for (int white_spaces = height - 1; white_spaces > row; white_spaces--)
        {
            printf(" ");
        }

        // Calculate and print left hashes
        for (int left_hashes = 0; left_hashes <= row; left_hashes++)
        {
            printf("#");
        }

        // Print gap
        for (int gap = 0; gap < 2; gap++)
        {
            printf(" ");
        }

        // Calculate and print right hashes
        for (int right_hashes = 0; right_hashes <= row; right_hashes++)
        {
            printf("#");
        }

        printf("\n");
    }
}