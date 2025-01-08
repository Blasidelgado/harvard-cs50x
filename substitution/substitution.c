#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001

int invalid_length(int length);
int invalid_characters(char *key, int length);
int repeated_characters(char *key, int length);
void encipher(char input[], char output[], char *key);

int main(int argc, char *argv[])
{
    char cipher_key[26];
    int cipher_len;

    if (argc != 2)
    {
        printf("ERROR!: Expected 1 extra argument but got %i instead.\n", argc - 1);
        printf("Usage: ./substitution key\n");
        return 1;
    }

    cipher_len = strlen(cipher_key);

    if (invalid_length(cipher_len))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (invalid_characters(cipher_key, cipher_len))
    {
        printf("Key must only contain alphabetic characters.\n");
        return 1;
    }

    if (repeated_characters(cipher_key, cipher_len))
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    strcpy(cipher_key, argv[1]);

    char plaintext[MAX_LENGTH];

    do
    {
        printf("plaintext: ");
        fgets(plaintext, sizeof(plaintext), stdin);
    }
    while (strlen(plaintext) < 1);

    int text_length = strlen(plaintext);

    char ciphertext[text_length];

    encipher(plaintext, ciphertext, cipher_key);

    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

int invalid_length(int length)
{
    return length != 26;
}

int invalid_characters(char *key, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return 1;
        }
    }

    return 0;
}

int repeated_characters(char *key, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                return 1;
            }
        }
    }

    return 0;
}

void encipher(char input[], char output[], char *key)
{
    int len = strlen(input);
    for (int i = 0; i < len; i++)
    {
        char c = input[i];
        if (isalpha(c))
        {
            if (isupper(c))
            {
                output[i] = toupper(key[c - 'A']);
            }
            else
            {
                output[i] = tolower(key[c - 'a']);
            }
        }
        else
        {
            output[i] = c;
        }
    }

    output[len] = '\0';
}