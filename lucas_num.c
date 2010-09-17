#include <stdio.h>
#define TRUE 1
#define FASLE 0

int isLucas ( int num );

int main (){

int num;


scanf("%d", &num);

isLucas (num);

printf("%d", isLucas (num));


}


int isLucas ( int num )
{ int cur, prev1, prev2;
  
  int Lucas, i;

  prev1=2, prev2=3;
    printf("L1=%d\nL2=%d\n", prev1, prev2);

    cur = prev1+prev2;

    for (i=3; i < num; i++)
    { cur = prev1+prev2;
      prev2= prev1;
      prev1= cur;
        
      printf ("L%d=%d\n", i , cur); 

      if (num = cur) { 
          Lucas = TRUE;
          printf("%d", i);
          break;
       }else{ 
           printf( "-1\n");
       }
 return Lucas;
 }}
