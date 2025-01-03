/*
1. Write a program that finds the "smallest" and "largest” in a series of words. After the user
enters the words, the program will determine which words would come first and last if the
words were listed in dictionary order. The program must stop accepting input when the user
enters a four-letter word. Assume that no word is more than 20 letters long. An interactive
session with the program might look like this:

Enter word: dog
Enter word: zebra
Enter word: rabbit
Enter word: catfish
Enter word: walrus
Enter word: cat
Enter word: fish

Smallest word: cat
Largest word: zebra

Hint: Use two strings named smallest_word and largest_word to keep track of the
“smallest" and “largest" words entered so far. Each time the user enters a new word, use
strcmp to compare it with smallest_word; if the new word is "smaller," use strcpy
to save it in smallest word. Do a similar comparison with largest_word. Use
strlen to determine when the user has entered a four-letter word.
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR_COUNT 20
#define MAX_WORD_LENGTH (MAX_CHAR_COUNT + 1)
#define TERM_LETTER_COUNT 4

int main(void)
{
    char smallest_word[MAX_WORD_LENGTH];
    char largest_word[MAX_WORD_LENGTH];
    char c;
    bool first_word = true;
    bool overflow = false;

    while (1) {
        printf("Enter word: ");

        int i = 0;
        char curr_word[MAX_WORD_LENGTH];
        while ((c = getchar()) != '\n') {
            if (i < MAX_CHAR_COUNT) {
                curr_word[i++] = c;
            } else {
                overflow = true;
            }
        }
        curr_word[i] = '\0';

        if (overflow) {
            // Clear input buffer
            while (c != '\n') {
                c = getchar();
            }
        }

        if (first_word) {
            strcpy(smallest_word, curr_word);
            strcpy(largest_word, curr_word);
            first_word = false;
        } else {
            if (strcmp(curr_word, smallest_word) < 0) {
                strcpy(smallest_word, curr_word);
            }

            if (strcmp(curr_word, largest_word) > 0) {
                strcpy(largest_word, curr_word);
            }
        }

        if (strlen(curr_word) == TERM_LETTER_COUNT) {
            break;
        }
    }

    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}
