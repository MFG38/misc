#include <stdio.h>
#include <stdlib.h>


int main()
{
    int num = rand() % 100;
    int guess = 0;
    int attempts = 10;
    int guessed = 0;

    puts("I'm thinking of a number between 0 and 100...");

    while(attempts > 0 && guessed == 0)
    {
        scanf("%i", &guess);

        if(guess == num)
        {
            puts("Oh, you guessed it. Cool.");
            guessed = 1;
        }
        else
        {
            attempts--;

            if(attempts == 0) puts("Oh no, you ran out of guesses. :c");
            else puts("Nope! Keep going!");
        }
    }

    return 0;
}
