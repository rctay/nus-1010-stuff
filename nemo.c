#include<stdio.h>
#include<string.h>
#define MAX 101
#define TRUE 1
#define FALSE 0

struct pos {
    unsigned int x;
    unsigned int y;
};

int set_first_pos(char input[MAX][MAX], int size, char first_char, struct pos* start_pos);
int FindLtoR(char input[][MAX], char word[], int size, int length, struct pos* start_pos, struct pos* end_pos);
//void FindRtoL ( char input[][MAX], char word[], int size, int length);
//void FindTtoB ( char input[][MAX], char word[], int size, int length);
//void FindBtoT ( char input[][MAX], char word[], int size, int length);


int main()
{
    char input[MAX][MAX]={{0}}, read;
    struct pos start_pos, end_pos;
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

    if (set_first_pos(input, size, search[0], &start_pos)) {
        fprintf(stderr, "not found!\n");
        return -1;
    }

    if (!FindLtoR(input, search, size, length, &start_pos, &end_pos)) {
        printf("(%d,%d) (%d,%d)\n", start_pos.x, start_pos.y, end_pos.x, end_pos.y);
        return 0;
    }
    /* try another search direction... */

/*
    switch ( direction ){
            case 'r':

            case 'l':

            case 'u':

            case 'd':

    }*/
    return 0;

}

int set_first_pos(char input[MAX][MAX], int size, char first_char, struct pos* start_pos) {
    int i, j;

    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++)
            if (input[i][j] == first_char) {
                start_pos->x = i;
                start_pos->y = j;
                return 0;
            }

    return -1;
}

int FindLtoR(char input[][MAX], char word[], int size, int length, struct pos* start_pos, struct pos *end_pos) {
    int k = 1;

    while (k < length && input[start_pos->x][start_pos->y+k] == word[k])
        k++;

    /* matched */
    if (k == length) {
        end_pos->x = start_pos->x;
        end_pos->y = start_pos->y+k-1;
        return 0;
    }

    return -1;
}

//char FindRtoL ( char input[][MAX], char target[], int size, length);
//void FindTtoB ( char input[][MAX], char target[], int size, length);
//void FindBtoT ( char input[][MAX], char target[], int size, length);
