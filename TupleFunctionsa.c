//Author: Charlton Sammut
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Functionsa.h"
#include "sgets.h"



tuple_t* createTuple(char id[32], char symbol, int num, float longnum, char string[32], int counter,  tuple_t* ptr){
    //Start saving process
    int savespace;

    if (counter == 0) {
        savespace = 0;
        ptr = malloc(4 * sizeof( tuple_t));
    }

    if(counter == savespace + 3){
        ptr = realloc(ptr, 4 * sizeof( tuple_t));
        savespace = savespace +4;
    }

    //Check if id allready exisits
    int test = 1;
    for(int i = 0; i <= counter; i++){
        if(strcmp(ptr[i].id, id) == 0){
            strcpy(ptr[i].id, id);
            ptr[i].symbol = symbol;
            ptr[i].num = num;
            ptr[i].longnum = longnum;
            strcpy(ptr[i].string, string);
            test = 0;
            i = counter;
            counter--;
        }
    }
    if(test == 1) {
        //start copying process

        //Tuple deceleration
        strcpy(ptr[counter].id, id);
        ptr[counter].symbol = symbol;
        ptr[counter].num = num;
        ptr[counter].longnum = longnum;
        strcpy(ptr[counter].string, string);
    }

    return ptr;
}

tuple_t*getTupleByID(char getid[32],  tuple_t* ptr, int counter){

    for(int i = 0; i <= counter; i++){
        if(strcmp(ptr[i].id, getid) == 0){
            return &ptr[i];
        }
    }
    return NULL;
}

tuple_t* getTupleID(int getnum,  tuple_t* ptr, int counter){

    if(counter <= getnum || 0 > getnum){
        return NULL;
    }
    else{
        return &ptr[getnum];
    }
}

void showTuple(char getid[32],  tuple_t* ptr, int counter){

    int check = 0;
    for(int i = 0; i <= counter; i++){
        if(strcmp(ptr[i].id, getid) == 0){
            printf("Tuple (#%d) %s = (%c, %d, %f, %s)\n", i, ptr[i].id, ptr[i].symbol, ptr[i].num, ptr[i].longnum,ptr[i].string);
            check++;
            i = counter; //To exit loop
        }
    }
    if(check == 0){
        printf("No match was found\n");
    }
}

void deleteTuple(int num,  tuple_t* ptr, int counter){
    for(int i = num; i <=counter; i++){
        strcpy(ptr[i].id, ptr[i+1].id);
        ptr[i].symbol = ptr[i+1].symbol;
        ptr[i].num = ptr[i+1].num;
        ptr[i].longnum = ptr[i+1].longnum;
        strcpy(ptr[i].string, ptr[i+1].string);
    }
}

int cmpTuples(char firsttuple[32], char secondtuple[32], int counter,  tuple_t* ptr) {
    tuple_t *found1 = getTupleByID(firsttuple, ptr, counter);
    tuple_t *found2 = getTupleByID(secondtuple, ptr, counter);

    if ((found1 == NULL) || (found2 == NULL)) {
        return 2; //Wanted to return but C does not allow this, instead 2 represents that no tuple was found.
    }

    if (found1->symbol > found2->symbol){
        return 1;
    }
    if (found1->symbol < found2->symbol){
        return -1;
    }
    if (found1->num > found2->num){
        return 1;
    }
    if (found1->num < found2->num){
        return -1;
    }
    if (found1->longnum > found2->longnum){
        return 1;
    }
    if (found1->longnum < found2->longnum){
        return -1;
    }
    if (strcmp(found1->string, found2->string) > 0){
        return 1;
    }
    if (strcmp(found1->string, found2->string) < 0){
        return -1;
    }
    return 0;
}

void joinTuples(char firsttuple[32], char secondtuple[32], int counter,  tuple_t* ptr, char newname[32]){
    tuple_t *found1 = getTupleByID(firsttuple, ptr, counter);
    tuple_t *found2 = getTupleByID(secondtuple, ptr, counter);
    createTuple(newname, found1->symbol, found1->num, found1->longnum, found1->string, counter, ptr);
    printf("Tuple (#%d) %s = (%c, %d, %f, %s) created\n", counter, newname, ptr[counter].symbol, ptr[counter].num, ptr[counter].longnum,ptr[counter].string);
}

int saveAllTuples( tuple_t* ptr, int counter){
    FILE *fp;
    fp = fopen("save00.bin", "wb");
    if(fp == NULL){
        return 0;
    }
    else{
        printf("%ld",fwrite(ptr, sizeof( tuple_t), counter, fp));
        fclose(fp);
    }
}

tuple_t* loadAllTuples( tuple_t* ptr, int *count){
    FILE *fp;
    tuple_t tempLocation;
    fp = fopen("save00.bin", "rb");
    *count = 0;

    while (fp != NULL && fread(&tempLocation, sizeof(tuple_t), 1, fp) == 1) {
        ptr = createTuple(tempLocation.id, tempLocation.symbol, tempLocation.num, tempLocation.longnum,
                          tempLocation.string, *count, ptr);
        (*count)++;
    }
    printf("all tuples successfully loaded\n");
    fclose(fp);
    return ptr;
}