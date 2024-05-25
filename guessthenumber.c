#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>
// WHY I HAVE TO INCLUDE EVERYTHING
// WHY THIS CAN'T BE LIKE C#, WHERE YOU CAN JUST USE THINGS RIGHT OUT OF THE GATE '-'

int main()
{
    srand(time(NULL));

    int rnd = rand() % (100 + 1 - 0) + 0; // wtf
    int n;
    int guesses;

    printf("Try to Guess the Number (0 - 100): ");
    scanf("%d", &n);

    while(true)
    {
        if(n > 100 || n < 0)
        {
            printf("Number outside of range! (0 - 100)\n Try again: ");
            scanf("%d", &n);
        }

        else
        {
            if( n > rnd)
            {
                printf("%d is greater than the number!\n", n);
                guesses++;
                scanf("%d", &n);
            }
                
            else if (n < rnd)
            {
                printf("%d is less than the number!\n");
                guesses++;
                scanf("%d", &n);
            }
                
            else
            {
                printf("you're right! %d is %d! it took you %d guesses\n", n, rnd, guesses);
                guesses = 0;
                printf("wanna play again?: (y/n) ");
                char c;

                scanf(" %c", &c); // ignore the space

                if(c != 'y')
                    exit(0);

                printf("Try to Guess the Number (0 - 100): ");
                rnd = rand() % (100 + 1 - 0) + 0; // generate another random numbmer
                scanf("%d", &n);
            }
        }
        
    }

    return 0;

}