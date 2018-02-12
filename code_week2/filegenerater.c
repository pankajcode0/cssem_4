/*
name- pankaj kumar
roll no -111601014;
code lab2- merge sort on files

// this is the file generator code
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>




int main() {
    char inFname[] = "randomNum.bin";
   
     int num,max;
   
    FILE *fptr1 = fopen(inFname , "wb"); //randomNum.bin is the binary generated file.
    FILE *P=fopen("read.txt","w");  //generated readable file will be read.txt

    printf("\n input max");//input value for generating no of values;
    scanf("%d",&max);
 
    if(fptr1 ) {
        srand(time(NULL));                  // seed for the random number
        for(int i=0;i<max; i++) {
            num = rand();
            printf("%d",num );
            fwrite (&num, sizeof(num), 1, fptr1);//writing into .bin file
            fprintf(P,"%d \n",num );//writing into read.txt file;
        }
    }
    fclose(fptr1);
    fclose(P);
   // fclose(fptr2);
    return 0;
}
