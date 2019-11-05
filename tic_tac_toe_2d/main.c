#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROWS 3
#define COLUMNS 3
int x, o, row_x, row_o, counter = 0;
bool game_end = false;
char game_board[ROWS][COLUMNS];

void initialize_display(){
    for(int i=0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
            game_board[i][j] = '_';
        }
    }
    for(int i = 0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
        printf(" %c", game_board[i][j]);
        }
    printf("\n");
    }
    return;
}

void update_display_x(row_x, x){

    game_board[row_x][x] = 'x';

    for(int i = 0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
        printf(" %c", game_board[i][j]);
        }
    printf("\n");
    }

    return;
}

void update_display_o(int row_o, int o){

   game_board[row_o][o] = 'o';

    for(int i = 0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
        printf(" %c", game_board[i][j]);
        }
    printf("\n");
    }

    return 0;
}

int win_check(char game_board[ROWS][COLUMNS]){

    for(int i = 0; i<ROWS; ++i){
        for(int j = 0; j<COLUMNS; ++j){
            if(game_board[i][j]==game_board[i][j+1]&&game_board[i][j+1]==game_board[i][j+2]&&game_board[i][j]!='_' ||
            game_board[i][j]==game_board[i+1][j]&&game_board[i+1][j]==game_board[i+2][j]&&game_board[i][j]!='_')
            {
                counter = 9;
                return 1;
            }
        }
    }

    if(game_board[0][0]==game_board[1][1]&&game_board[1][1]==game_board[2][2]&&game_board[0][0]!='_' ||
       game_board[0][2]==game_board[1][1]&&game_board[1][1]==game_board[2][0]&&game_board[0][2]!='_'){
        counter = 9;
        return 1;
    } else{
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
        printf("Enter a row number for an x position: ");
        scanf(" %d", &row_x);
        printf("Enter a position for x in that row: ");
        scanf(" %d", &x);
        counter += 1;
        update_display_x(row_x, x);
        win_check(game_board);
        if(counter == 9){
            game_end = true;
            break;
        }
        if(win_check(game_board) == 0){
            printf("There are more moves to be played\n");
        }

        printf("Enter a row number for an o position: ");
        scanf(" %d", &row_o);
        printf("Enter a position for o in that row: ");
        scanf(" %d", &o);
        counter += 1;
        update_display_o(row_o, o);
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
