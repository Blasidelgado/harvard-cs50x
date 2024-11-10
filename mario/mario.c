#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Ask user to input pyramid's height
    int height;
    do
    {
        height = get_int("Enter pyramid's height: ");
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