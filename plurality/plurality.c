#include <errno.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 9

typedef struct
{
    char *name;
    int votes;
} candidate;

candidate candidates[MAX];

int candidate_count;

bool vote(char *name);
void print_winner(void);
char *get_input(const char *prompt);
int get_integer(const char *prompt);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_integer("Number of voters: ");

    for (int i = 0; i < voter_count; i++)
    {
        char *name = get_input("Vote: ");

        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }

        free(name);
    }

    print_winner();
}

bool vote(char *name)
{
    if (!name)
    {
        return false;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int max_vote_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_vote_count)
        {
            max_vote_count = candidates[i].votes;
        }
    }

    if (max_vote_count == 0)
    {
        printf("No winner\n");
        return;
    }
        
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_vote_count)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    
    return;
}

char *get_input(const char *prompt) {
    printf("%s", prompt);
    
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
        return NULL;
    }

    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
        buffer[len - 1] = '\0';
    }

    char *str = malloc(len + 1);
    if (str == NULL) {
        return NULL;
    }
    strcpy(str, buffer);

    return str;
}

int get_integer(const char *prompt) {
    char buffer[1024];
    long num;
    char *endptr;

    while (true) {
        printf("%s", prompt);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL) {
            fprintf(stderr, "Error reading input.\n");
            exit(EXIT_FAILURE);
        }

        buffer[strcspn(buffer, "\n")] = '\0';

        errno = 0;
        num = strtol(buffer, &endptr, 10);

        if (endptr == buffer) {
            fprintf(stderr, "Error: Not a valid number.\n");
        } else if (*endptr != '\0') {
            fprintf(stderr, "Error: Extra characters after number.\n");
        } else if (errno == ERANGE || num < INT_MIN || num > INT_MAX) {
            fprintf(stderr, "Error: Number out of range.\n");
        } else {
            return (int)num;
        }
    }
}