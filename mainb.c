//Author: Charlton Sammut
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functionsb.h"
#include "sgets.h"



tuple_tb *pointer;
int counter;

int case1b(){
    char id[32];
    printf("Enter name of your new tuple\n");
    fflush(stdin); //clear buffer
    sgets(id, 32);
    printf("How many elements is your tuple going to hold\n");
    int num1 = checkifint(); //num1 = number of elements
    int num2[num1]; //num2 shows which data type the user wants in that particular position

    //declaring all arrays

    int num[num1];
    float floatnum[num1];
    double doublenum[num1];
    char symbol[num1];
    char string[64][num1];
    short shortnum[num1];
    long longnum[num1];

    for (int i = 0; i < num1; i++) {
        int exit = 0;
        do{
            printf("Select the data type of element #%d\n", i);
            printf("1) Int\n");
            printf("2) Float\n");
            printf("3) Double\n");
            printf("4) Char\n");
            printf("5) String, of 64 bits\n");
            printf("6) Short\n");
            printf("7) Long\n");
            num2[i] = checkifint();

            switch (num2[i]) {
                case 1:
                    printf("Enter your Integer\n");
                    num[i] = checkifint();
                    exit++;
                    break;
                case 2:
                    printf("Enter your Float\n");
                    scanf("%f", &floatnum[i]);
                    exit++;
                    break;
                case 3:
                    printf("Enter your Double\n");
                    scanf("%lf", &doublenum[i]);
                    exit++;
                    break;
                case 4:
                    printf("Enter your Symbol\n");
                    scanf("%c", &symbol[i]);
                    exit++;
                    break;
                case 5:
                    printf("Enter your String\n");
                    fflush(stdin); //clear buffer
                    sgets(string[i], 32);
                    exit++;
                    break;
                case 6:
                    printf("Enter your Short\n");
                    scanf("%hd", &shortnum[i]);
                    exit++;
                    break;
                case 7:
                    printf("Enter your Long\n");
                    scanf("%ld", &longnum[i]);
                    exit++;
                    break;
                default:
                    printf("Invalid Input\n");
            }
        } while (exit == 0);
    }
    pointer = createTupleb(num1, num2, counter, pointer, num, floatnum, doublenum, symbol, string, shortnum, longnum,
                           id);
    counter++;
    showTupleb(id, pointer, counter, num1, num2);
}



int case2b(){
    char input[32];
    printf("Select the ID of the tuple you want to be returned\n");
    for (int i = 0; i < counter; i++) {
        printf("Tuple ID #%d) %s\n", i, pointer[i].id);
    }
    fflush(stdin); //clear buffer
    scanf("%s", input);
    tuple_tb *ptrfound = getTupleByIDb(input, pointer, counter);
    if (ptrfound == NULL) {
        printf("Tuple not found\n");
    } else {
        showTupleb(input, pointer, counter, ptrfound->num1, ptrfound->num2);
        printf("has been returned\n");
    }
}

int case3b(){
    int input;
    printf("Enter the position of the tuple you want to be returned\n");
    fflush(stdin); //clear buffer
    input = checkifint();
    tuple_tb *tuplefound = getTupleIDb(input, pointer, counter);
    if(tuplefound == NULL){
        printf("Tuple not found\n");
    }
    else {
        printf("%s has been returned\n", tuplefound->id);
    }

}

int case4b(){
    char getid[32];
    printf("Select the tuple you wish to view\n");
    for(int i = 0; i < counter; i++){
        printf("Tuple #%d) %s \n", i, pointer[i].id);
    }
    fflush(stdin); //clear buffer
    sgets(getid, 32);
    tuple_tb *tuplefound = getTupleByIDb(getid, pointer, counter);
    if(tuplefound == NULL){
        printf("Tuple not found\n");
    }
    else {
        showTupleb(tuplefound->id, pointer, counter, tuplefound->num1, tuplefound->num2);
    }
}

int case5b(){
    char getid[32];
    printf("Select the tuple you want to delete\n");
    for(int i = 0; i < counter; i++){
        printf("Tuple #%d) %s \n", i, pointer[i].id);
    }
    fflush(stdin); //clear buffer
    sgets(getid, 32);
    tuple_tb *tuplefound = getTupleByIDb(getid, pointer, counter);
    if(tuplefound == NULL){
        printf("Tuple not found\n");
    }
    else{
        for(int i = 0; i <= counter; i++) {
            if (strcmp(pointer[i].id, getid) == 0) {
                printf("Are you sure you want to delete this tuple\n");
                showTupleb(getid, pointer, counter, tuplefound->num1, tuplefound->num2);
                printf("Y/N\n");
                char ans;
                scanf("%c", &ans);
                int exit = 0;
                do{
                    switch(ans){
                        case 'Y':
                        case 'y':
                            deleteTupleb(i, pointer, counter);
                            printf("Tuple deleted\n");
                            counter--;
                            return 1;
                        case 'N':
                        case 'n':
                            printf("Tuple not deleted\n");
                            i = counter; //To exit loop
                            exit = 1;
                            break;

                        default:
                            exit++;
                            printf("Please enter a valid input");
                            break;
                    }
                }while(exit == 0);
            }
        }
    }
}

int case6b(){
    printf("Select which tuples you want to compare\n");
    char getfirstid[32];
    char getsecondid[32];
    for(int i = 0; i < counter; i++){
        printf("Tuple #%d) %s \n", i, pointer[i].id);
    }

    printf("First Tuple:");
    fflush(stdin); //clear buffer
    sgets(getfirstid, 32);
    printf("Second Tuple:");
    fflush(stdin); //clear buffer
    sgets(getsecondid, 32);
    tuple_tb *tuplefound1 = getTupleByIDb(getfirstid, pointer, counter);
    tuple_tb *tuplefound2 = getTupleByIDb(getsecondid, pointer, counter);
    if(tuplefound1 == NULL || tuplefound2 == NULL){
        if(tuplefound1 == NULL) {
            printf("First tuple not found\n");
            return 0;
        }else{
            printf("Second tuple not found\n");
            return 0;
        }
    }
    else{
        int ans = cmpTuplesb(getfirstid, getsecondid, counter, pointer);
        if(ans == 2){
            printf("Tuples not found\n");
            return 0;
        }
        if(ans == 3){
            printf("Tuples aren't compatible\n");
            return 0;
        }
        if(ans == 0){
            printf("%s is identical to %s\n", getfirstid, getsecondid);
            return 0;
        }
        if(ans > 0){
            printf("%s is larger then %s\n", getfirstid, getsecondid);
            return 0;
        }
        if(ans < 0){
            printf("%s is smaller then %s\n", getfirstid, getsecondid);
            return 0;
        }
    }
}

int case7b(){
    char getfirstid[32];
    char getsecondid[32];
    printf("Select which tuples you want to join.\n");
    for(int i = 0; i < counter; i++){
        printf("Tuple #%d) %s \n", i, pointer[i].id);
    }
    printf("First Tuple:");
    fflush(stdin); //clear buffer
    sgets(getfirstid, 32);
    printf("Second Tuple:");
    fflush(stdin); //clear buffer
    sgets(getsecondid, 32);
    printf("Now enter the name of the tuple that will store your joint elements");
    char newname[32];
    fflush(stdin); //clear buffer
    sgets(newname, 32);
    joinTuplesb(getfirstid, getsecondid, counter, pointer, newname);
}

int case8b(){
    printf("Are you sure you want to save, this will override your previous save file\n");
    printf("Y/N\n");
    char ans;
    int saveans;
    fflush(stdin);
    scanf("%c", &ans);
    int exit = 0;
    do{
        switch(ans){
            case 'Y':
            case 'y':
                saveans = saveAllTuplesb(pointer, counter);
                if(saveans == 1){
                    printf("An error happened while saving\n");
                }
                else{
                    printf("All tuples successfully saved\n");
                }
                exit++;
                break;
            case 'N':
            case 'n':
                exit++;
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }while(exit == 0);
}

int case9b(){
    printf("Are you sure you want to load your previous save, this will override all unsaved data\n");
    printf("Y/N\n");
    char ans;
    fflush(stdin);
    scanf("%c", &ans);
    int exit = 0;
    do{
        switch(ans){
            case 'Y':
            case 'y':
                pointer = loadAllTuplesb(pointer, &counter);
                exit++;
                break;
            case 'N':
            case 'n':
                exit++;
                break;
            default:
                printf("Invalid input\n");
                break;
        }
    }while(exit == 0);
}



int mainb(){
    int exit = 0;
    do{
        char input;
        printf("------------------------------------------------------------------\n");
        printf("Select a Function.\n");
        printf("1) Create a Tuple\n");
        printf("2) Find a specific Tuple with it's ID\n");
        printf("3) Get Tuple ID\n");
        printf("4) Show a specific Tuple\n");
        printf("5) Delete a specific Tuple\n");
        printf("6) Compare two Tuples\n");
        printf("7) Join two Tuples\n");
        printf("8) Save all Tuples\n");
        printf("9) Load all Tuples from a save file\n");
        printf("q) Exit Program\n");
        printf("------------------------------------------------------------------\n");
        scanf("%c", &input);
        switch (input) {
            case '1': //Create Tuple
                case1b();
                break;
            case '2': //GetTupleWithID
                case2b();
                break;
            case '3'://GetTupleID
                case3b();
                break;
            case '4'://showTuple
                case4b();
                break;
            case '5'://deleteTuple
                case5b();
                break;
            case '6'://cmpTuples
                case6b();
                break;
            case '7'://joinTuples
                case7b();
                break;
            case '8'://saveTuples
                case8b();
                break;
            case '9'://LoadTuples
                case9b();
                break;
            case 'q':
                exit++;
                break;
            default:
                printf("Error: Invalid Input\n");
                break;
        }
        //Clearing the buffer
        fseek(stdin, 0, SEEK_END);
    }while(exit == 0);
}