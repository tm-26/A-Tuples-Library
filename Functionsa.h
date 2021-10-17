//Author: Charlton Sammut
#ifndef A_TUPLES_LIBRARY_FUNCTIONS_H
#define A_TUPLES_LIBRARY_FUNCTIONS_H

typedef struct tuple_t{
    char id[32];

    char symbol;
    int num;
    float longnum;
    char string[32];
}tuple_t;

int checkifint(void);

int maina();
tuple_t* createTuple(char id[32], char symbol, int num, float longnum, char string[32], int counter, struct tuple_t* ptr);
tuple_t* getTupleByID(char getid[32], struct tuple_t* ptr, int counter);
tuple_t* getTupleID(int getnum, struct tuple_t* ptr, int counter);
void showTuple(char getid[32], struct tuple_t* ptr, int counter);
void deleteTuple(int num, struct tuple_t* ptr, int counter);
int cmpTuples(char firsttuple[32], char secondtuple[32], int counter, struct tuple_t* ptr);
void joinTuples(char firsttuple[32], char secondtuple[32], int counter, struct tuple_t* ptr, char newname[32]);
int saveAllTuples(struct tuple_t* ptr, int counter);
tuple_t* loadAllTuples(struct tuple_t* ptr, int *count);
int mainb();


#endif