#include <stdio.h>
#include <stdlib.h>
int correct = 39, guess, you_lose = 0, trys = 0, limit = 7, try_count = 7;

int main()
{
    while(guess != correct && you_lose == 0){
        if(trys < limit){
            printf("Guess my number. It's between 1-50. ");
            scanf("%d", &guess);
            trys++;

            if(guess > correct){
                try_count--;
                printf("Nope, go lower. You have %d trys left\n", try_count);
            } else if(guess < correct){
                try_count--;
                printf("Nope, go higher. You have %d trys left\n", try_count);
            }
        } else{
            you_lose = 1;
        }
    }
    if(you_lose == 1){
        printf("You lost");
    } else{
        printf("That's correct, good job!");
    }
    return 0;
}
