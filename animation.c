#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>

int main(){
    
    system("clear");
    bool game = true;
    bool player = true; //if player is true = X, else = 0
    int place;
    char board[9] = {'_', '_', '_', '_', '_', '_', '_', '_', '_'};
    int win[8][3] = {{0, 1, 2}, {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, {3, 4, 5}, {6, 7, 8}, {0, 4, 8}, {2, 4, 6}};
    int space = 9;
    
    while (game){
        printf("\n\033[0m0|1|2\n3|4|5\n6|7|8\n");
        printf("Which block? [0-8] ");
        scanf(" %d", &place);
        bool valid = true;
        if (place < 9){
            if (player){
                if (board[place] == '_'){
                    board[place] = 'X';
                    player = false;
                    space--;
                }else{
                    printf("Invalid input, X turn");
                    valid = false;
                }
            }else{
                if (board[place] == '_'){
                    board[place] = 'O';
                    player = true;
                    space--;
                }else{
                    printf("Invalid input, O turn");
                    valid = false;
                }
            }
            if (valid){
                for (int j=1; j<=3; j++){
                    for (int i=0; i<9; i++){
                        if (j == 1){
                            if (i == place){
                                printf("\033[0;31m.");
                            }else{
                                printf("\033[0m%c", board[i]);
                            }
                        }else if (j == 2){
                            if (i == place){
                                board[i] == 'X' ? printf("\033[0;33mx"): printf("\033[0;35mo");
                            }else{
                                printf("\033[0m%c", board[i]);
                            }
                        }else{
                            if (i == place){
                                board[i] == 'X' ? printf("\033[1;33mX"): printf("\033[1;35mO");
                            }else{
                                printf("\033[0m%c", board[i]);
                            } 
                        }
                        if ((i+1)%3==0){
                            printf("\n");
                        }
                    }
                    
                    usleep(400000);
                    if (j < 3){
                        system("clear");
                    }

                }
                
            }
        }else{
            printf("Invalid input, number out of range");
        }
        for (int i = 0; i < 8; i++){
            if (board[win[i][0]] != '_' && board[win[i][0]] == board[win[i][1]] && board[win[i][1]] == board[win[i][2]]){
                for (int j = 0; j < 3; j++){
                    system("clear");
                    for (int k = 0; k < 9; k++){
                        if (k == win[i][0] || k == win[i][1] || k == win[i][2]){
                            printf("\033[1;34m%c", board[win[i][0]]);
                        }else{
                            printf("\033[0m%c", board[k]);
                        }
                        if ((k+1)%3==0){
                            printf("\n");
                        }
                        
                    }
                    if (j==0){
                        printf("\033[0;31m%c wins!\n", board[win[i][0]]);
                    }else if (j == 1){
                        printf("\033[0;33m%c wins!\n", board[win[i][0]]);
                    }else{
                        printf("\033[0;34m%c wins!\n", board[win[i][0]]);
                    }

                    usleep(400000);
                }
                
                game = false;
            }
        }
        if (game != false && space == 0){
            printf("\033[0mIt's a draw!");
            game = false;
        }
        
    }
    printf("\033[0m\nGame ends\n");
}
