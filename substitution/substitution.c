#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool invalid_length(int length);
bool invalid_characters(string key, int length);
bool repeated_characters(string key, int length);
void encipher(string input, char output[], string key);

int main(int argc, string argv[])
{
    string cipher_key;
    int cipher_len;

    // Check if user has provided 2 arguments
    if (argc != 2)
    {
        printf("ERROR!: Expected 1 extra argument but got %i instead.\n", argc - 1);
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        cipher_key = argv[1];
        cipher_len = strlen(cipher_key);
    }

    // Check for illegal key length
    if (invalid_length(cipher_len))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // Check for illegal characters
    else if (invalid_characters(cipher_key, cipher_len))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }
    // Check for repetition in key
    else if (repeated_characters(cipher_key, cipher_len))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }
    else
    {
        // Prompt user to provide a string to be ciphered
        string plaintext = get_string("plaintext: ");

        int text_length = strlen(plaintext);

        // New string to push ciphered values
        char ciphertext[text_length];

        encipher(plaintext, ciphertext, cipher_key);

        printf("ciphertext: %s\n", ciphertext);
    }

    return 0;
}

bool invalid_length(int length)
{
    return length != 26;
}

bool invalid_characters(string key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return true;
        }
    }

    return false;
}

bool repeated_characters(string key, int length)
{
    // Take every letter and compare to remaining letters
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            // Converts letters to uppercase then compare
            if (toupper(key[i]) == toupper(key[j]))
            {
                return true;
            }
        }
    }

    return false;
}

void encipher(string input, char output[], string key)
{
    int len = strlen(input);
    // Loop through the provided string
    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (isalpha(c)) // Look for alphabetic characters
        {
            if (isupper(c)) // If uppercase, match with corresponding key character in uppercase
            {
                output[i] = toupper(key[c - 'A']); // Push ciphered character into new string
            }
            else // If lowercase, match with corresponding key character in lowercase
            {
                output[i] = tolower(key[c - 'a']); // Push ciphered character into new string
            }
        }
        else
        {
            output[i] = c; // Non alphabetical characters remain unchanged
        }
    }

    output[len] = '\0'; // Close the new ciphered string with null character
}