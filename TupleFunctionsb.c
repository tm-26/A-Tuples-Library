//Author: Charlton Sammut
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functionsb.h"
#include "sgets.h"

extern int counter ;


tuple_tb* createTupleb(int num1, int num2[num1], int counter,  tuple_tb *pointer, int num[num1], float floatnum[num1], double doublenum[num1], char symbol[num1], char string[64][num1], short shortnum[num1], long longnum[num1], char id[32]) {

    int savespace;
    if (counter == 0) {
        savespace = 0;
        pointer = malloc(4 * sizeof( tuple_tb));
    }
    if (pointer == NULL) {
        exit(1);
    }
    if (counter == savespace + 3) {
        pointer = realloc(pointer, 4 * sizeof( tuple_tb));
        savespace = savespace + 4;
    }

    if (counter == 0) {
        pointer[counter].num2 = (int *) malloc(num1 * sizeof(int));
    } else {
        pointer[counter].num2 = (int *) realloc(pointer->num2, num1 * sizeof(int));
    }

    //Check if id allready exisits
    int test = 1;
    for (int i = 0; i <= counter; i++) {
        if (strcmp(pointer[i].id, id) == 0){ //check if tuple ids are equal
            test++;
            for (int i = 0; i < num1; i++) { //num1 is all the tuples that the user entered
                pointer[i].num2[i] = num2[i];
                switch (num2[i]) { //num2 shows which tuple type the user wants that particular position
                    case 1:
                        pointer[i].num = num[i];
                        break;
                    case 2:
                        pointer[i].floatnum = floatnum[i];
                        break;
                    case 3:
                        pointer[i].doublenum = doublenum[i];
                        break;
                    case 4:
                        //strcpy(&pointer[i].symbol, &symbol[i]);
                        memcpy(&pointer[i].symbol, &symbol[i], sizeof(char));
                        break;
                    case 5:
                        memcpy(&pointer[i].string, &string[i], (64 * sizeof(char)));
                        //strcpy(pointer[i].string, string[i]);
                        break;
                    case 6:
                        pointer[i].shortnum = shortnum[i];
                        break;
                    case 7:
                        pointer[i].longnum = longnum[i];
                        break;
                    default:
                        return NULL;
                }
            }
        }
    }
    if (test == 1) { //If tuple ids are not equal then create a new one.
        strcpy(pointer[counter].id, id);
        pointer[counter].num1 = num1;
        for (int i = 0; i < num1; i++) { //num1 is all the tuples that the user entered
            pointer[counter].num2[i] = num2[i];
            switch (num2[i]) { //num2 shows which tuple type the user wants that particular position
                case 1:
                    pointer[counter].num = num[i];

                    break;
                case 2:
                    pointer[counter].floatnum = floatnum[i];

                    break;
                case 3:
                    pointer[counter].doublenum = doublenum[i];

                    break;
                case 4:
                    //strcpy(&pointer[i].symbol, &symbol[i]);
                    memcpy(&pointer[counter].symbol, &symbol[i], sizeof(char));

                    break;
                case 5:
                    //memcpy(&pointer[counter].string, &string[i], (64 * sizeof(char)));
                    strcpy(pointer[counter].string, string[i]);

                    break;
                case 6:
                    pointer[counter].shortnum = shortnum[i];
                    break;
                case 7:
                    pointer[counter].longnum = longnum[i];
                    break;
                default:
                    return NULL;
            }
        }
    }
    counter++;
    return pointer;
}



tuple_tb *getTupleByIDb(char getid[32],  tuple_tb* pointer, int counter){

    for(int i = 0; i <= counter; i++){
        if(strcmp(pointer[i].id, getid) == 0){
            return &pointer[i];
        }
    }
    return NULL;

}

tuple_tb* getTupleIDb(int getnum,  tuple_tb* pointer, int counter){

    if(counter <= getnum || 0 > getnum){
        return NULL;
    }
    else{
        return &pointer[getnum];
    }
}

void showTupleb(char getid[32],  tuple_tb* pointer, int counter, int num1, int num2[num1]){

    tuple_tb* viewtuple;
    viewtuple = getTupleByIDb(getid, pointer, counter);
    printf("Tuple %s = (", viewtuple->id);
    int start = 0;
    for (int i = 0; i < num1; i++) {//num1 is number of elements

        switch(num2[i]){//num2 shows which data type the user wants that particular position
            case 1:
                if(start == 0){
                    printf("%d", viewtuple->num);
                }
                else{
                    printf(", %d", viewtuple->num);
                }
                start++;

                break;
            case 2:
                if(start == 0) {
                    printf("%f", viewtuple->floatnum);
                }
                else{
                    printf(", %f", viewtuple->floatnum);
                }
                start++;
                ;
                break;
            case 3:
                if(start == 0) {
                    printf("%f", viewtuple->doublenum);
                }
                else{
                    printf(", %f", viewtuple->doublenum);
                }
                start++;
                ;
                break;
            case 4:
                if(start == 0){
                    printf("%c", viewtuple->symbol);
                }
                else{
                    printf(", %c", viewtuple->symbol);
                }
                start++;
                ;
                break;
            case 5:
                if(start == 0) {
                    printf("%s", viewtuple->string);
                }
                else{
                    printf(", %s", viewtuple->string);
                }
                start++;
                ;
                break;
            case 6:
                if(start == 0){
                    printf("%d", viewtuple->shortnum);
                }
                else {
                    printf(", %d", viewtuple->shortnum);
                }
                start++;
                ;
                break;
            case 7:
                if(start == 0){
                    printf("%ld", viewtuple->longnum);
                }

                else{
                    printf(", %ld", viewtuple->longnum);
                }
                start++;
                ;
                break;
            default:
                break;
        }

    }
    printf(")\n");
}

void deleteTupleb(int num,  tuple_tb* pointer, int counter){
    for(int i = num; i <=counter; i++){
        strcpy(pointer[i].id, pointer[i+1].id);

        pointer[i].num1 = pointer[i+1].num1;
        memcpy(pointer[i].num2, pointer[i].num2, pointer[i].num * sizeof(pointer[i].num1));
        pointer[i].symbol = pointer[i+1].symbol;
        pointer[i].num = pointer[i+1].num;
        pointer[i].longnum = pointer[i+1].longnum;
        strcpy(pointer[i].string, pointer[i+1].string);
    }
}

int cmpTuplesb(char firsttuple[32], char secondtuple[32], int counter,  tuple_tb* pointer){
    tuple_tb *found1 = getTupleByIDb(firsttuple, pointer, counter);
    tuple_tb *found2 = getTupleByIDb(secondtuple, pointer, counter);

    if ((found1 == NULL) || (found2 == NULL)) {
        return 2; //Wanted to return but C does not allow this, instead 2 represents that no tuple was found.
    }
    //Compatibility test
    if(found1->num1 != found2->num1){
        return 3;
    }

    for (int i = 0; i < found1->num1; i++) {
        if (found1->num2[i] != found2->num2[i]) {
            return 3;
        }
    }
    for (int i = 0; i < found1->num1; i++) {//num1 is number of elements
        switch(found1->num2[i]){//num2 shows which data type the user wants in that particular position
            case 1:
                if (found1->num > found2->num){
                    return 1;
                }
                if (found1->num < found2->num){
                    return -1;
                }
                break;
            case 2:
                if (found1->floatnum > found2->floatnum){
                    return 1;
                }
                if (found1->floatnum < found2->floatnum){
                    return -1;
                }
                break;
            case 3:
                if (found1->doublenum > found2->doublenum){
                    return 1;
                }
                if (found1->doublenum < found2->doublenum){
                    return -1;
                }
                break;
            case 4:
                if (found1->symbol > found2->symbol){
                    return 1;
                }
                if (found1->symbol < found2->symbol){
                    return -1;
                }
                break;
            case 5:
                if (strcmp(found1->string, found2->string) > 0){
                    return 1;
                }
                if (strcmp(found1->string, found2->string) < 0){
                    return -1;
                }
                break;
            case 6:
                if (found1->shortnum > found2->shortnum){
                    return 1;
                }
                if (found1->shortnum < found2->shortnum){
                    return -1;
                }
                break;
            case 7:
                if (found1->longnum > found2->longnum){
                    return 1;
                }
                if (found1->longnum < found2->longnum){
                    return -1;
                }
                break;
            default:
                break;
        }
    }
    return 0;
}


int joinTuplesb(char firsttuple[32], char secondtuple[32], int counter,  tuple_tb* pointer, char newname[32]){
    tuple_tb *found1 = getTupleByIDb(firsttuple, pointer, counter);
    tuple_tb *found2 = getTupleByIDb(secondtuple, pointer, counter);

    if(found1 == NULL || found2 == NULL){
        return 0;
    }
    int newnum1 = found1->num1 + found2->num1;
    int newnum2[newnum1];
    int newnum[newnum1];
    float newfloatnum[newnum1];
    double newdoublenum[newnum1];
    char newsymbol[newnum1];
    char newstring[64][newnum1];
    short newshortnum[newnum1];
    long newlongnum[newnum1];
    int extra = 0;
    for(int i = 0; i < found1->num1; i++){
        extra++;
        newnum2[i] = found1->num2[i];
        newnum[i] = found1->num;
        newfloatnum[i] = found1->floatnum;
        newdoublenum[i] = found1->doublenum;
        newsymbol[i] = found1->symbol;
        strcpy(newstring[i], found1->string);
        newshortnum[i] = found1->shortnum;
        newlongnum[i] = found1->longnum;
    }

    for(int i = 0; i < found2->num1; i++){
        newnum2[i + extra] = found1->num2[i];
        newnum[i + extra] = found1->num;
        newfloatnum[i + extra] = found1->floatnum;
        newdoublenum[i + extra] = found1->doublenum;
        newsymbol[i + extra] = found1->symbol;
        strcpy(newstring[i + extra], found1->string);
        newshortnum[i + extra] = found1->shortnum;
        newlongnum[i + extra] = found1->longnum;
    }

    createTupleb(newnum1, newnum2, counter, pointer, newnum, newfloatnum, newdoublenum, newsymbol, newstring, newshortnum, newlongnum, newname);
    showTupleb(newname, pointer, counter, newnum1, newnum2);
}

int saveAllTuplesb(tuple_tb* pointer, int counter){
    FILE *fp;
    FILE *fp2;
    fp = fopen("save01.bin", "wb");
    fp2 = fopen("save01+.bin", "wb");

    for(int i = 0; i < counter; i++){
        int num2[counter][pointer[i].num1];
        for(int j = 0; j < pointer[i].num1; j++) {
            num2[i][j] = pointer[i].num2[j];
        }
        fwrite(num2, counter * pointer[i].num1* sizeof(int), (size_t) counter, fp);
    }
    if(fp == NULL){
        return 0;
    }
    else{
        fwrite(pointer, sizeof(tuple_tb), (size_t) counter, fp2);
        fclose(fp);
    }
}

tuple_tb *loadAllTuplesb( tuple_tb* pointer, int *count) {
    FILE *fp;
    FILE *fp2;
    tuple_tb tempLocation;
    int num2[50][50];
    fp = fopen("save01.bin", "rb");
    fp2 = fopen("save01+.bin", "rb");
    *count = 0;

    while (fp != NULL && fread(&tempLocation, sizeof(tuple_tb), 1, fp) == 1) {
        while (fp2 != NULL && fread(&num2, 50 * 50 * sizeof(int), 1, fp2) == 1) {
            for (int i = 0; i < 50; i++) {
                for (int j = 0; j < pointer[i].num1; j++) {
                    num2[i][j] = pointer[i].num2[j];
                }
            }
            pointer = createTupleb(tempLocation.num1, tempLocation.num2, *count, pointer, &tempLocation.num,
                                   &tempLocation.floatnum, &tempLocation.doublenum, &tempLocation.symbol,
                                   &tempLocation.string, &tempLocation.shortnum, &tempLocation.longnum,
                                   tempLocation.id);
            (*count)++;
        }
        printf("all tuples successfully loaded\n");
        fclose(fp);
        return pointer;
    }
}