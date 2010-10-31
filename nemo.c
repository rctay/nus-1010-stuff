#include<stdio.h>
#include<string.h>
#define MAX 101
#define TRUE 1
#define FALSE 0

int set_first_pos(char input[MAX][MAX], int size, char first_char, int* x, int* y);
void FindLtoR(char input[][MAX], char word[], int size, int length, int x0, int y0);
//void FindRtoL ( char input[][MAX], char word[], int size, int length);
//void FindTtoB ( char input[][MAX], char word[], int size, int length);
//void FindBtoT ( char input[][MAX], char word[], int size, int length);


int main()
{
    char input[MAX][MAX]={{0}}, read;
    int x, y;
    int i, j, size, length=0;
    char search [20];
    char direction;

//scanf("%s", word);

//printf("%s", word);

    scanf("%d", &size);


    for (i=0; i<size; i++) {
        j = 0;
        while (j<size && scanf("%c", &read) == 1) {
            switch (read) {
            case '\r':
            case '\n':
                continue;
            default:
                input[i][j] = read;
                j++;
            }
        }
    }

//    for (i=0; i<7; i++)
//    {
     scanf("%s", search);

//    }

    /* determine length of search string */
    while (search[length] != '\0' && length <= 20)
        length++;


/***********/
printf("%d", size);


    for(i=0; i<size; i++)
    {   for (j=0; j<size; j++)
        {
            printf("%c", input[i][j]);

        }
        printf("row%d",i);
    }

printf("last letter scanned: %c", input[8][8]);

    //for(i=0; i<7; i++){

    printf("%s", search);
    //}
/************/




    if (set_first_pos(input, size, search[0], &x, &y)) {
        fprintf(stderr, "not found!\n");
        return -1;
    }

    FindLtoR (input, search, size, length, x, y);

/*
    switch ( direction ){
            case 'r':

            case 'l':

            case 'u':

            case 'd':

    }*/
    return 0;

}

int set_first_pos(char input[MAX][MAX], int size, char first_char, int* x, int* y) {
    int i, j;

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            if (input[i][j] == first_char) {
                *x = i;
                *y = j;
                return 0;
            }

    return -1;
}

void FindLtoR(char input[][MAX], char word[], int size, int length, int x0, int y0) {
    int k = 1;
    while (k < length && input[x0][y0+k] == word[k])
        k++;

    /* matched */
    if (k == length)
        printf("(%d,%d) (%d,%d)\n", x0, y0, x0, y0+k-1);
}

//char FindRtoL ( char input[][MAX], char target[], int size, length);
//void FindTtoB ( char input[][MAX], char target[], int size, length);
//void FindBtoT ( char input[][MAX], char target[], int size, length);
