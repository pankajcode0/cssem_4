#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

//using namespace std;

int main() {
   
     int num,i,max;
printf("input the max number");
scanf("%d",&max);
   
    FILE *fptr1 = fopen("randomnum.bin" , "wb");
    FILE *fptr2 = fopen("read1.txt" , "w");
   
    if(fptr1 && fptr2) {
        srand(time(NULL));                  // seed for the random number
        for( i=0; i<max; i++) {
            num = rand();
          
            fwrite (&num, sizeof( int), 1, fptr1);
            fprintf ( fptr2,"%d \n",num);
        }   
    }
   
    fclose(fptr1);
    fclose(fptr2);
    return 0;
}
