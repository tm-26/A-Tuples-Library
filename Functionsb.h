//Author: Charlton Sammut
#ifndef A_TUPLES_LIBRARY_FUNCTIONSB_H
#define A_TUPLES_LIBRARY_FUNCTIONSB_H
typedef struct tuple_tb{
    char id[32];

    int num1;
    int *num2;

    int num;
    float floatnum;
    double doublenum;
    char symbol;
    char string[64];
    short shortnum;
    long longnum;
}tuple_tb;

int checkifint();
tuple_tb* createTupleb(int num1, int num2[num1], int counter,  tuple_tb *pointer, int num[num1], float floatnum[num1],
        double doublenum[num1], char symbol[num1], char string[64][num1], short shortnum[num1], long longnum[num1], char id[32]);
tuple_tb *getTupleByIDb(char getid[32],  tuple_tb* pointer, int counter);
void showTupleb(char getid[32],  tuple_tb* pointer, int counter, int num1, int num2[num1]);
tuple_tb* getTupleIDb(int getnum,  tuple_tb* pointer, int counter);
void deleteTupleb(int num,  tuple_tb* pointer, int counter);
int cmpTuplesb(char firsttuple[32], char secondtuple[32], int counter,  tuple_tb* pointer);
int joinTuplesb(char firsttuple[32], char secondtuple[32], int counter,  tuple_tb* pointer, char newname[32]);
int saveAllTuplesb( tuple_tb* pointer, int counter);
tuple_tb *loadAllTuplesb( tuple_tb* pointer, int *count);
#endif //A_TUPLES_LIBRARY_FUNCTIONSB_H
