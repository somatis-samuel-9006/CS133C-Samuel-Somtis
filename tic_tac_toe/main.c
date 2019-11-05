#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int x, o, counter = 0;
bool game_end = false;
char game_board[9];

void initialize_display(){
    for(int i=0; i<9; ++i){
        game_board[i] = '_';
    }
    for(int i = 0; i < 3; ++i){
        printf(" %c", game_board[i]);
    }
    printf("\n");
    for(int j = 3; j < 6; ++j){
        printf(" %c", game_board[j]);
    }
    printf("\n");
    for(int k = 6; k < 9; ++k){
        printf(" %c", game_board[k]);
    }
    printf("\n");

    return;
}

void update_display_x(int x){

    game_board[x] = 'x';

    for(int i = 0; i < 3; ++i){
        printf(" %c", game_board[i]);
    }
    printf("\n");
    for(int j = 3; j < 6; ++j){
        printf(" %c", game_board[j]);
    }
    printf("\n");
    for(int k = 6; k < 9; ++k){
        printf(" %c", game_board[k]);
    }
    printf("\n");

    return;
}

void update_display_o(o){

    game_board[o] = 'o';

    for(int i = 0; i < 3; ++i){
        printf(" %c", game_board[i]);
    }
    printf("\n");
    for(int j = 3; j < 6; ++j){
        printf(" %c", game_board[j]);
    }
    printf("\n");
    for(int k = 6; k < 9; ++k){
        printf(" %c", game_board[k]);
    }
    printf("\n");

    return;
}

int win_check(char game_board[9]){

    for(int i=0; i<3; i++){
    // determine victory
        if (game_board[i*3+0]==game_board[i*3+1]&&game_board[i*3+1]==game_board[i*3+2]&&game_board[i*3]!='_' ||
            game_board[i]==game_board[i+3]&&game_board[i+3]==game_board[i+6]&&game_board[i]!='_'){
            counter = 9;
            return 1;
        }
    }
    if(game_board[0]==game_board[4]&&game_board[4]==game_board[8]&&game_board[0]!='_' ||
       game_board[2]==game_board[4]&&game_board[4]==game_board[6]&&game_board[2]!='_'){
        counter = 9;
        return 1;
    }else{
        if(game_end == true){
            return 2;
        } else{
            return 0;
        }
    }
}

int main(){
    initialize_display();
    while(game_end == false){
        if(counter == 9){
            game_end = true;
            break;
        }

        printf("Enter an x position: ");
        scanf(" %d", &x);
        counter += 1;
        update_display_x(x);
        win_check(game_board);
        if(counter == 9){
            game_end = true;
            break;
        }
        if(win_check(game_board) == 0){
            printf("There are more moves to be played\n");
        }


        printf("Enter an o position: ");
        scanf(" %d", &o);
        counter += 1;
        update_display_o(o);
        win_check(game_board);
        if(counter == 9){
            game_end = true;
            break;
        }
        if(win_check(game_board) == 0){
            printf("There are more moves to be played\n");
        }

    }

    if(game_end == true){
        win_check(game_board);
        if(win_check(game_board) == 1){
            printf("You win\n");
        } else if(win_check(game_board) == 2){
            printf("Tie\n");
        }
    }

    return 0;
}
