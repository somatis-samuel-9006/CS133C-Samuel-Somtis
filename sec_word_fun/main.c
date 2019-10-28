#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


bool again = true, game_end = false, valid = true;
char correct[100], word_display[100], guess, missing_letters[50], letter, replay;
long int length;
int found, position, win_check, guess_counter = 0, guesses_left = 10;

void check_valid(char *correct){   // why cant this just be check_valid(correct){} ???
    for(int i=0; i<length; ++i){
        letter = correct[i];
        if(isalpha(letter) == 0){
            valid = false;
            break;
        }
    }

    return 0;
}
void find_guess(guess){

    for(int i=0; i<length; ++i){
        if(correct[i] == guess){
            found = 1;
            break;
        }else{
            found = 0;
        }
    }

    return 0;
}

void initialize_display(){

    for(int i=0; i<length; ++i){
        word_display[i] = '*';
    }

    return 0;
}

void update_display(guess){

    for(int i=0; i<length; ++i){
        if(correct[i] == guess){
            word_display[i] = guess;
        }
    }

    return 0;
}

void get_missing_letters(){

    for(int i=0; i<length; ++i){
        if(correct[i] != word_display[i]){
            printf("%c", correct[i]);
        }
    }

    return 0;
}
int main()
{
    while(again == true){
        printf("(Note:Upper and lowercase are allowed)\nPlayer 1, enter a word: ");
        scanf("%s", correct);
        system("cls");
        length = strlen(correct);
        check_valid(correct);
        if(valid == false){
            printf("Invalid word");
            break;
        }
        initialize_display();
        printf("\n(Note:Upper and lowercase are allowed)");
        while(game_end == false && guess_counter != 10 && valid == true){
            while (getchar() != '\n');
            printf("\nHidden word: %s\nPlayer 2, guess a letter: ", word_display);
            scanf("%c", &guess);
            find_guess(guess);
            update_display(guess);
            guess_counter += 1;
            guesses_left -= 1;

            if(found == 1){
                printf("Correct, %d guesses left\n", guesses_left);
            } else if(found == 0){
                printf("Wrong, %d guesses left\n", guesses_left);
            }
            win_check = strcmp(correct, word_display);
            if(win_check == 0){
                game_end = true;
            }
        }

        if(guess_counter <= 10 && game_end == true){
            printf("\nYou Won! The word was %s.\n", correct);

        } else{
            printf("\nYou lost! The word was %s. Missing letters: ", correct);
            get_missing_letters();
        }

        printf("\nWould you like to play again? Type y/n " );
        scanf(" %c", &replay);
        if(replay == 'y'){
            again = true;
            game_end = false;
            guess_counter = 0;
            guesses_left = 10;
            found = 0;
            position = 0;
            win_check = 0;
            length = 0;
            memset(correct, 0, 100);
            memset(word_display, 0, 100);
            memset(missing_letters, 0, 50);
        } else{
            again = false;
        }

    }
    return 0;
}
