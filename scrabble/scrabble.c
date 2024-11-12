#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Store score for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Evaluate winner and print
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // Initialize score
    int score = 0;

    // Iterate through word to check individual characters
    for (int letter = 0; letter < strlen(word); letter++)
    {
        // Evaluate character for points
        switch (toupper(word[letter])) // Ignore lowercase letters
        {
            case 65:
            case 69:
            case 73:
            case 76:
            case 78:
            case 79:
            case 82:
            case 83:
            case 84:
            case 85:
                score++;
                break;
            case 68:
            case 71:
                score += 2;
                break;
            case 66:
            case 67:
            case 77:
            case 80:
                score += 3;
                break;
            case 70:
            case 86:
            case 87:
            case 89:
                score += 4;
                break;
            case 75:
                score += 5;
                break;
            case 81:
            case 90:
                score += 10;
                break;
            default:
                break;
        }
    }

    // Return total word score
    return score;
}
