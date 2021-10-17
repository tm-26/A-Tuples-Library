//Author: Charlton Sammut
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functionsa.h"
#include "sgets.h"

int checkifint(void){
    int exit;
    int next;
    int ans;
    do {
        scanf("%d", &ans);
        exit=1;
        if ( ((next = getchar()) != EOF && next != '\n')) {
            clearerr(stdin);
            do {
                next = getchar();
            } while (next != EOF && next != '\n');
            clearerr(stdin);
            printf("\nPlease enter a valid input!");
            exit=0;
        }
    }while(exit == 0);
    return ans;
}

int main(){
    int exit = 0;
    int input;
    do {
        printf("Access program using:\n");
        printf("1) A Pre-defined Tuple structure\n");
        printf("2) Custom Tuple structure\n");
        input = checkifint();
        switch(input){
            case 1: maina(); exit++; break;
            case 2: mainb(); exit++; break;
            default: printf("Invalid Input\n");
        }
    }while(exit == 0);
}