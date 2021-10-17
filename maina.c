//Author: Charlton Sammut
/*TODO
check and validate for blank input
Compare tuple bug
Load tuple bug
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functionsa.h"
#include "sgets.h"
#include<process.h>

int counter = 0;
tuple_t *ptr;


struct tuple_t* case1(struct tuple_t *ptr){
    char id[32];
    char symbol;
    int num;
    float longnum;
    char string[32];

    printf("This will create a tuple of the type: (character, integer, number, string)\n");
    printf("Enter the name of your new tuple\n");
    fflush(stdin); //clear buffer
    sgets(id, 32);
    printf("Enter the first element (Has to be a single character)\n");
    scanf("%c", &symbol);
    printf("Enter the second element (Has to be an integer)\n");
    num = checkifint();
    printf("Enter the third element (Has to be a number)\n");
    longnum = checkifint();
    printf("Enter the forth element (Has to be a string)\n");
    fflush(stdin); //clear buffer
    sgets(string, 32);
    ptr = createTuple(id, symbol, num, longnum, string, counter, ptr);
    printf("Tuple (#%d) %s = (%c, %d, %f, %s)\n", counter, ptr[counter].id, ptr[counter].symbol, ptr[counter].num, ptr[counter].longnum,ptr[counter].string);
    counter++;
    return ptr;
}

int case2(){
    char input[32];
    printf("Select the ID of the tuple you want to be returned\n");
    for(int i = 0; i < counter; i++){
        printf("Tuple ID #%d) %s\n", i, ptr[i].id);
    }
    fflush(stdin); //clear buffer
    scanf("%s", input);
    struct tuple_t *ptrfound = getTupleByID(input, ptr, counter);
    if(ptrfound == NULL){
        printf("Tuple not found\n");
    }
    else {
        printf("Tuple %s = (%c, %d, %f, %s) returned\n", ptrfound->id, ptrfound->symbol, ptrfound->num, ptrfound->longnum, ptrfound->string);
    }
}

int case3(){
    int input;
    printf("Enter the position of the tuple you want to be returned\n");
    fflush(stdin); //clear buffer
    input = checkifint();
    struct tuple_t *tuplefound = getTupleID(input, ptr, counter);
    if(tuplefound == NULL){
        printf("Tuple not found\n");
    }
    else {
        printf("Tuple %s = (%c, %d, %f, %s) returned\n", tuplefound->id, tuplefound->symbol, tuplefound->num, tuplefound->longnum, tuplefound->string);
    }

}

int case4(){
    char getid[32];
    printf("Select the tuple you wish to view\n");
    for(int i = 0; i < counter; i++){
        printf("Tuple #%d) %s \n", i, ptr[i].id);
    }
    fflush(stdin); //clear buffer
    sgets(getid, 32);
    showTuple(getid, ptr, counter);
}

int case5(){
    char getid[32];
    printf("Select the tuple you want to delete\n");
    for(int i = 0; i < counter; i++){
        printf("Tuple #%d) %s \n", i, ptr[i].id);
    }
    fflush(stdin); //clear buffer
    sgets(getid, 32);
    int check = 0;
    for(int i = 0; i <= counter; i++) {
        if (strcmp(ptr[i].id, getid) == 0) {
            printf("Are you sure you want to delete this tuple\n");
            printf("Tuple (#%d) %s = (%c, %d, %f, %s)\n", i, ptr[i].id, ptr[i].symbol, ptr[i].num, ptr[i].longnum,ptr[i].string);
            printf("Y/N\n");
            char ans;
            scanf("%c", &ans);
            int exit = 0;
            do{
                switch(ans){
                    case 'Y':
                    case 'y':
                        deleteTuple(i, ptr, counter);
                        printf("Tuple deleted\n");
                        counter--;
                        return 1;
                    case 'N':
                    case 'n':
                        printf("Tuple not deleted\n");
                        check++;
                        i = counter; //To exit loop
                        exit = 1;
                        break;

                    default:
                        printf("Please enter a valid input");
                        break;
                }
            }while(exit == 0);
        }
    }
    if(check == 0){
        printf("No match was found\n");
    }
}

int case6(){
    printf("Select which tuples you want to compare\n");
    char getfirstid[32];
    char getsecondid[32];
    for(int i = 0; i < counter; i++){
        printf("Tuple #%d) %s \n", i, ptr[i].id);
    }
    printf("First Tuple:");
    fflush(stdin); //clear buffer
    sgets(getfirstid, 32);
    printf("Second Tuple:");
    fflush(stdin); //clear buffer
    sgets(getsecondid, 32);
    int ans = cmpTuples(getfirstid, getsecondid, counter, ptr);
    if(ans == 2){
        printf("Tuples not found\n");
    }
    if(ans == 0){
        printf("%s is identical to %s\n", getfirstid, getsecondid);
    }
    if(ans > 0){
        printf("%s is larger then %s\n", getfirstid, getsecondid);
    }
    if(ans < 0){
        printf("%s is smaller then %s\n", getfirstid, getsecondid);
    }
}

int case7(){
    char getfirstid[32];
    char getsecondid[32];
    printf("Select which tuples you want to join.\n");
    for(int i = 0; i < counter; i++){
        printf("Tuple #%d) %s \n", i, ptr[i].id);
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
    joinTuples(getfirstid, getsecondid, counter, ptr, newname);

}

int case8(){
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
                saveans = saveAllTuples(ptr, counter);
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

int case9(){
    printf("Are you sure you want to load your previous save, this will override all unsaved data\n");
    printf("Y/N\n");
    char ans;
   // int loadans;
    fflush(stdin);
    scanf("%c", &ans);
    int exit = 0;
    do{
        switch(ans){
            case 'Y':
            case 'y':
                ptr = loadAllTuples(ptr, &counter);
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

int maina(){
    char save = 0;
    char input;
    int exit = 0;
    do{
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
        switch (input){
            case '1': //Create Tuple
                ptr = case1(ptr);
                break;
            case '2': //GetTupleWithID
                if(counter == 0){
                    printf("Enter a tuple to access this feature\n");
                }
                else{ case2(); }
                break;
            case '3'://GetTupleID
                if(counter == 0){
                    printf("Enter a tuple to access this feature\n");
                }
                else{ case3(); }
                break;
            case '4'://viewTuple
            case4();
                break;
            case '5'://deleteTuple
                if(counter == 0){
                    printf("Enter a tuple to access this feature\n");
                }
                else{
                     case5();
                }
                break;
            case '6'://cmpTuples
                if(counter == 0){
                    printf("Enter a tuple to access this feature\n");
                }
                else{ case6(); }
                break;
            case '7'://JoinTuple
                if(counter == 0 || counter == 1){
                    printf("Enter at least two tuples to access this feature\n");
                }
                else{ case7();}
                break;
            case '8'://Save
                case8();
                save++;
                break;
            case '9'://Load
                printf("Loading all tuples from a save file...\n");
                case9();
                break;
            case 'q':
                printf("Would you like to save before exiting\n");
                printf("Y/N\n");
                char ans;
                int saveans;
                fflush(stdin);
                scanf("%c", &ans);
                int exit1 = 0;
                do{
                    switch(ans){
                        case 'Y':
                        case 'y':
                            saveans = saveAllTuples(ptr, counter);
                            if(saveans == 1){
                                printf("An error happened while saving\n");
                                free(ptr);
                                return 1;
                            }
                            else{
                                printf("All tuples successfully saved\n");
                                free(ptr);
                                return 1;
                            }
                        case 'N':
                        case 'n':

                            free(ptr);
                            return 1;
                        default:
                            printf("Invalid input\n");
                            break;
                    }
                }while(exit1 == 0);
            default:
                printf("Error: Invalid Input\n");
                break;
        }
        //Clearing the buffer
        fseek(stdin,0,SEEK_END);
    }while (exit == 0);
    return 1;
}