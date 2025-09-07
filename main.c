#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rungame(){
    srand(time(NULL));
    int user_score = 0;
    int cpu_score = 0;
    system("clear");
    for(int i = 0; (user_score + cpu_score) != 3; i++){
        int user_choice = -1;
        char user_input[10];

        
        printf("Rock, Paper, Scissors\n>> ");
        scanf("%9s", user_input);

        //convert to lowercase
        for (int j = 0; user_input[j]; j++) {
            if (user_input[j] >= 'A' && user_input[j] <= 'Z') {
                user_input[j] = user_input[j] + ('a' - 'A');
            }
        }

        if(strcmp(user_input, "scissors") == 0){
            user_choice = 2;
        }
        else if(strcmp(user_input, "rock") == 0){
            user_choice = 0;
        }
        else if(strcmp(user_input, "paper") == 0){
            user_choice = 1;
        }
        else{
            printf("ERROR\n");
            continue;
        }

        int r = rand() % 3;
        if(r == 0){
            printf("computer chose rock\n");
            if(user_choice == 0){
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("tie\n");
            }
            else if(user_choice == 1){
                user_score++;
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("user win\n");
            }
            else if(user_choice == 2){
                cpu_score ++;
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("computer win\n");
            }
        }
        if(r == 1){
            printf("computer chose paper\n");
            if(user_choice == 0){
                cpu_score++;
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("computer win\n");
            }
            else if(user_choice == 1){
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("tie\n");
            }
            else if(user_choice == 2){
                user_score++;
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("user win\n");
            }
        }
        if(r == 2){
            printf("ccomputer chose scissors\n");
            if(user_choice == 0){
                user_score ++;
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("user win\n");
            }
            else if(user_choice == 1){
                cpu_score ++;
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("computer win\n");
            }
            else if(user_choice == 2){
                system("clear");
                printf("User score: %d, computer score: %d\n", user_score, cpu_score);
                printf("tie\n");
            }
        }
    }
    system("clear");
    char result[6];
    if(user_score > cpu_score){
        strcpy(result, "WIN");
    }
    else{
        strcpy(result, "LOSE");
    }
    printf("GAME OVER, YOU %s\n", result);
    printf("User score: %d, computer score: %d\n", user_score, cpu_score);
    return 1;
}

int main(){
    int success = rungame();
    if(!success){
        printf("Something went wrong. Sorry!");
        return -0;
    }
}