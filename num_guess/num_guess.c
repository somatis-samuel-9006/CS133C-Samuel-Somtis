#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int correct = 39, guess, you_lose = 0, trys = 0, limit = 7, try_count = 7, again = 1;
int high = 50, low = 0, closest_high = 51, closest_low = 1, closest_overall, low_diff, high_diff;
char choice;


int main()
{
    while(again == 1){
        printf("I'm thinking of a number between 1-50.\n");
        while(guess != correct && you_lose == 0){
            if(trys < limit){
                printf("Guess my number. ");
                scanf("%d", &guess);
                while ((getchar()) != '\n');
                trys++;

                if(guess > correct){
                    if(guess < closest_high){
                        closest_high = guess;
                    }
                    high = guess-1;
                    try_count--;
                    printf("Nope, go lower. It's between %d and %d. You have %d trys left\n", low, high, try_count);
                } else if(guess < correct){
                     if(guess > closest_low){
                        closest_low = guess;
                    }
                    low = guess+1;
                    try_count--;
                    printf("Nope, go higher. It's between %d and %d. You have %d trys left\n", low, high, try_count);
                }
            } else{
                you_lose = 1;
            }
        }
        if(you_lose == 1){
            if(closest_high >= 51){
                high_diff = 9999;
            }else{
                high_diff = closest_high-39;
            }
            if(closest_low <=0){
                low_diff = -9999;
            }else{
                low_diff = 39 - closest_low;
            }
            if(high_diff > low_diff){
                closest_overall = closest_low;
            } else if(high_diff < low_diff){
                closest_overall = closest_high;
            } else{
                closest_overall = closest_high;
            }
            printf("You lost. My number was %d. Closest guess: %d\n", correct, closest_overall);
        } else{
            printf("That's correct, good job!\n");
        }


        printf("Would you like to play again? y/n ");
        scanf("%c", &choice);
        if(choice == 'y'){
            you_lose = 0;
            trys = 0;
            try_count = 7;
            guess = 0;
            low = 1;
            high = 50;
            closest_high = 51;
            closest_low = 1;
            closest_overall = 0;
            high_diff = 0;
            low_diff = 0;

        } else{
            again = 0;
        }



    }
    return 0;
}
