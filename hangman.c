// 5/31/2024
// hangman.c

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STR_LEN 15
#define NUM_STRINGS 18

int main() {

    srand(time(NULL));

    int rnd = rand() % NUM_STRINGS;

    // i should read from a list of words in a file, but whatever
    char strings[NUM_STRINGS][MAX_STR_LEN] = {
        "strawberry",
        "compiler",
        "computer",
        "elephant",
        "bravo",
        "tango",
        "suspect",
        "fallen",
        "arrow",
        "dinosaur",
        "element",
        "king",
        "united",
        "sacred",
        "linux",
        "slash",
        "airplane",
        "planet"
    };

    int lifes = 7;

    char *chosenWord = strings[rnd];

    char display[MAX_STR_LEN];
    memset(display, '_', strlen(chosenWord));
    display[strlen(chosenWord)] = '\0';

    printf("Try to guess the word: %s\n", display);

    while(lifes > 0)
    {
        char guess;
        printf("Type a letter: ");
        scanf(" %c", &guess);
        
        bool found = false;
        for (int i = 0; i < strlen(chosenWord); i++) {
            if (chosenWord[i] == guess) {
                display[i] = guess;
                found = true;
            }
        }

        if (found) {
            printf("The letter %c is in the word!\n", guess);
        } else {
            lifes--;
            printf("The letter %c is not in the word. You have %d lives left.\n", guess, lifes);
        }

        printf("Word: %s\n", display);

        if (strcmp(display, chosenWord) == 0) {
            printf("Congratulations! You guessed the correct word: %s\n", chosenWord);
            break;
        }

    }

    if (lifes == 0) {
        printf("Your lives are over! The correct word was: %s\n", chosenWord);
    }

    return 0;
}