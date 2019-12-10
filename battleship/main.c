#include <stdio.h>
#include <stdlib.h>
#include<ctype.h>
#include<string.h>
#define ROWS 8
#define COLUMNS 8
int x, o, row_x, row_o, row_guess, col_guess, right_row, right_col, count1 = 0, count2 = 0, winner_guesses;
int p1_ship[3][2];
int p2_ship[3][2];
char game_board_1[ROWS][COLUMNS], game_board_2[ROWS][COLUMNS], row_x_input, x_input, row_o_input, o_input, creator[2][10], *winner;
const char *names[2];

struct Info{
    int guesses;
    int hits;
};

struct Players{
    struct Info pdata;
    char *realname;
    char *playername;
} player1, player2;

void initialize_display(){

    printf("\n");
    printf("Player1");
    printf("\n");

    for(int i=0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
            game_board_1[i][j] = '_';
        }
    }
    for(int i = 0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
            printf(" %c", game_board_1[i][j]);
        }
    printf("\n");
    }

    printf("\n\n");
    printf("Player2");
    printf("\n");

    for(int i=0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
            game_board_2[i][j] = '_';
        }
    }
    for(int i = 0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
            printf(" %c", game_board_2[i][j]);
        }
    printf("\n");
    }
    return;
}

void build_ship_p1(){

    printf("%s, enter 3 spots for your ship placement: \n", player1.playername);
    while(count1<3){
        printf("Enter row number: ");
        scanf("%c", &row_x_input);
        while(getchar() != '\n');
        if(isdigit(row_x_input)!=0){
            row_x = row_x_input - '0';
        }else{
            printf("Invalid input \n");
            continue;
        }
        if(row_x<0 || row_x>7){
            printf("Invalid input\n");
            continue;
        }
        printf("Enter column number: ");
        scanf("%c", &x_input);
        while(getchar() != '\n');
        if(isdigit(x_input)!=0){
            x = x_input - '0';
        }else{
            printf("Invalid input \n");
            continue;
        }
        if(x<0 || x>7){
            printf("Invalid input\n");
            continue;
        }
        p1_ship[count1][0] = row_x;
        p1_ship[count1][1] = x;
        count1++;
    }
    return;
}

void build_ship_p2(){

    printf("%s, enter 3 spots for your ship placement: \n", player2.playername);
    while(count2<3){
        printf("Enter row number: ");
        scanf("%c", &row_o_input);
        while(getchar() != '\n');
        if(isdigit(row_o_input)!=0){
            row_o = row_o_input - '0';
        }else{
            printf("Invalid input \n");
            continue;
        }
        if(row_o<0 || row_o>7){
            printf("Invalid input\n");
            continue;
        }
        printf("Enter column number: ");
        scanf("%c", &o_input);
        while(getchar() != '\n');
        if(isdigit(o_input)!=0){
            o = o_input - '0';
        }else{
            printf("Invalid input \n");
            continue;
        }
        if(o<0 || o>7){
            printf("Invalid input\n");
            continue;
        }
        p2_ship[count2][0] = row_o;
        p2_ship[count2][1] = o;
        count2++;
    }
    return;
}

void update_display_1(){

    printf("Player 1\n");
    for(int i = 0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
            printf(" %c", game_board_1[i][j]);
        }
    printf("\n");
    }
    return;
}

void update_display_2(){

    printf("\n\n");
    printf("Player 2\n");
    for(int i = 0; i<ROWS; ++i){
        for(int j=0; j<COLUMNS; ++j){
            printf(" %c", game_board_2[i][j]);
        }
    printf("\n");
    }
    return;
}

void make_str_array(){

    strcpy(creator[0], "Samuel");
    strcpy(creator[1], "Somatis");

    return;
}

void make_ptr_array(){
    names[0] = player1.playername;
    names[1] = player2.playername;

    return;
}

long int guess_factorial(int n){

    if(n>=1){
        return n*guess_factorial(n-1);
    }else{
        return 1;
    }
}

int main()
{
    player1.pdata.guesses = 0;
    player1.pdata.hits = 0;
    player2.pdata.guesses = 0;
    player2.pdata.hits = 0;

    printf("Player 1, Enter your real name: ");
    player1.realname = malloc(50 * sizeof(char));
    scanf("%s", player1.realname); // no longer need '&' in scanf
    printf("Player 1, choose a player name: ");
    player1.playername = malloc(50 * sizeof(char));
    scanf("%s", player1.playername);

    printf("Player 2, Enter your real name: ");
    player2.realname = malloc(50 * sizeof(char));
    scanf("%s", player2.realname);
    printf("Player 2, choose a player name: ");
    player2.playername = malloc(50 * sizeof(char));
    scanf("%s", player2.playername);
    while(getchar()!= '\n');
    system("cls");
    initialize_display();
    printf("\n");
    build_ship_p1();
    printf("\n");
    build_ship_p2();
    system("cls");
    update_display_1();
    update_display_2();

    while(player1.pdata.hits <= 3 || player2.pdata.hits <= 3){
        printf("%s, take a guess. 'O' is a hit. '*' is a miss. Enter row number: ", player1.playername);
        scanf("%d", &row_guess);
        while(getchar()!='\n');
        printf("Enter column number: ");
        scanf("%d", &col_guess);
        while(getchar()!='\n');
        player1.pdata.guesses++;
        system("cls");

        if(p2_ship[0][0]==row_guess&&p2_ship[0][1]==col_guess||
           p2_ship[1][0]==row_guess&&p2_ship[1][1]==col_guess||
           p2_ship[2][0]==row_guess&&p2_ship[2][1]==col_guess){
            player1.pdata.hits++;
            game_board_2[row_guess][col_guess] = 'O';
            update_display_1();
            update_display_2();
        }else{
            game_board_2[row_guess][col_guess] = '*';
            update_display_1();
            update_display_2();
        }

        if(player1.pdata.hits == 3){
            winner = player1.playername;
            winner_guesses = player1.pdata.guesses;
            break;
        }
        printf("%s, take a guess. 'X' is a hit. '*' is a miss. Enter row number: ", player2.playername);
        scanf("%d", &row_guess);
        printf("Enter column number: ");
        scanf("%d", &col_guess);
        player2.pdata.guesses++;
        system("cls");

        if(p1_ship[0][0]==row_guess&&p1_ship[0][1]==col_guess||
           p1_ship[1][0]==row_guess&&p1_ship[1][1]==col_guess||
           p1_ship[2][0]==row_guess&&p1_ship[2][1]==col_guess){
            player2.pdata.hits++;
            game_board_1[row_guess][col_guess] = 'X';
            update_display_1();
            update_display_2();
        }else{
            game_board_1[row_guess][col_guess] = '*';
            update_display_1();
            update_display_2();
        }

        if(player2.pdata.hits == 3){
            winner = player2.playername;
            winner_guesses = player2.pdata.guesses;
            break;
        }


    }
    system("cls");
    make_str_array();
    make_ptr_array();
    printf("Gameover. Check scoreboard.txt for game summary.");

    FILE * fpointer = fopen("scoreboard.txt", "w");

    if(fpointer == NULL){
        printf("Oh no");
    }

    fprintf(fpointer, "Created by %s %s\n", creator[0], creator[1]);
    fprintf(fpointer, "Players: %s & %s\n", names[0], names[1]);
    fprintf(fpointer, "Winner: %s\n", winner);
    fprintf(fpointer, "Factorial of %s's guesses: %ld", winner, guess_factorial(winner_guesses));

    fclose(fpointer);

    return 0;
}
