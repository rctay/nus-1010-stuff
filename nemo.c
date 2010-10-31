#include<stdio.h>
#include<string.h>
#define MAX 101
#define TRUE 1
#define FALSE 0

void FindLtoR ( char input[][MAX], char search[], int size, int length);
//void FindRtoL ( char input[][MAX], char word[], int size, int length);
//void FindTtoB ( char input[][MAX], char word[], int size, int length);
//void FindBtoT ( char input[][MAX], char word[], int size, int length);


int main()
{
    char input[MAX][MAX]={{0}};
    int i, j, size, length=0;
    char search [20];
    char direction;

//scanf("%s", word);

//printf("%s", word);

    scanf("%d", &size);


    for (i=0; i<size; i++) {
        for (j=0; j<size; j++) {
            scanf( "%c", &input[i][j]);
        }
    }

//    for (i=0; i<7; i++)
//    {
     scanf("%s", search);

//    }


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



    FindLtoR (input, search, size, length);

/*
    switch ( direction ){
            case 'r':

            case 'l':

            case 'u':

            case 'd':

    }*/
    return 0;

}

void FindLtoR ( char input[][MAX], char word[], int size, int length)
{
    int i, j, k;
    int found=FALSE;
    //char direction;
printf("into Find loop\n");

    for(i=0; i<size&&found==FALSE; i++)
    {
        for(j=0; j<size&&found==FALSE; j++)
        {
               if ( input[i][j]==word[0])
               {found= TRUE;
               printf("input found:%c\nlocation:%d,%d\n", input[i][j],i,j);
               break;}
        }
    }

    if (found==TRUE)
    {
        for(k=1; k<length; k++)
        {
            if(input[i][j+k]!=word[k])
                found=FALSE;
              else found=TRUE;
        }
    }
}

//char FindRtoL ( char input[][MAX], char target[], int size, length);
//void FindTtoB ( char input[][MAX], char target[], int size, length);
//void FindBtoT ( char input[][MAX], char target[], int size, length);
