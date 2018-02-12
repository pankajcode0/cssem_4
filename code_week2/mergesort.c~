/*
name - pankaj kumar
roll no- 111601014
code lab week2- merge sort in files;
this code contains algorithm for mergesort;
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

FILE *p, *q, *temp1, *temp2, *f;
int min(int a, int b){        //function to return minimum;
    if(a>b)
        return b;
    else
        return a;
}

int  mergesort(int low, int high);      //sorting function;
void mergehalve(int low, int mid, int high);//merging function

int main(){
    char name1[100], name2[100];
    printf("Enter max size: ");
    int n; scanf("%d", &n);
   
    p = fopen("randomNum.bin", "rb+"); // input binary file.
    f = fopen("output.txt", "w"); // output text file.
    q = fopen("Sorted.bin", "wb+"); // output shorted binary file.

    int temp;
    for(int i=0; i<n; i++){
        fread(&temp, sizeof temp, 1, p); // reading input binary file.
        fwrite(&temp, sizeof temp, 1, q); // making a copy for sorting.
    }
      temp1 = fopen("temp1.bin", "wb+");  //two temporary file;
    temp2 = fopen("temp2.bin", "wb+");
   
    mergesort(0, n-1);

    fseek(q, 0, SEEK_SET);
    for(int i=0; i<n; i++){
        fread(&temp, sizeof temp, 1, q); // reading the sorted bin file.
        fprintf(f, "%d\n", temp); // writing into a text file.
    }

    return 0;
}

int mergesort(int low, int high){          //sorting function;
    int temp;

    temp1 = fopen("temp1.bin", "wb+");
    temp2 = fopen("temp2.bin", "wb+");
    for (int k = 1; k <= high - low; k <<= 1){
      //  printf("\n");
        fseek(q, 0, SEEK_SET);
        for (int i = low; i < high; i += 2*k){
       
            mergehalve(i, min(i + k- 1, high), min(i + 2*k-1, high));
        }
        /*
         fseek(q, 0, SEEK_SET);
        for(int i=0; i<high; i++){
        fread(&temp, sizeof temp, 1, q); // reading the sorted bin file.
        printf( "%d\n", temp); // remove comment to see how sorting happening.
        }
        */
    

    }
    fclose(temp1); fclose(temp2);
    remove("temp1.bin");
    remove("temp2.bin");
    return 0;
}

void mergehalve(int low, int mid, int high){
 
// printf("\nlow - %d mid - %d, high = %d\n",low,mid,high);
    fseek(temp1, 0, SEEK_SET); // Pointer to start of temp file1.
    fseek(temp2, 0, SEEK_SET); // Pointer to start of temp file2.
   
    int temp;
    // Writing into both the temporary files.
    for(int i=low; i<=mid; i++){
        fread(&temp, sizeof temp, 1, q);
        fwrite(&temp, sizeof temp, 1, temp1);
    }
    for(int i=mid+1; i<=high; i++){
        fread(&temp, sizeof temp, 1, q);
        fwrite(&temp, sizeof temp, 1, temp2);
    }



    int left = mid - low + 1;
    int right = high - mid;
    int i = 0, k = 0;
    int num1, num2;
    fseek(q, -(high - low + 1)*4, SEEK_CUR);
    fseek(temp1, 0, SEEK_SET);
    fseek(temp2, 0, SEEK_SET);
    fread(&num1, sizeof num1, 1, temp1);
    fread(&num2, sizeof num2, 1, temp2);

    while(i < left && k< right){    //writing back to binary file;
        if(num1 <= num2){
            fwrite(&num1, sizeof num1, 1, q);
            i++; fread(&num1, sizeof num1, 1, temp1);
        }else{
            fwrite(&num2, sizeof num2, 1, q);
            k++; fread(&num2, sizeof num2, 1, temp2);
        }
    }
    while(i < left){            
        fwrite(&num1, sizeof num1, 1, q);
        i++; fread(&num1, sizeof num1, 1, temp1);
    }
    while(k < right){
        fwrite(&num2, sizeof num2, 1, q);
        k++; fread(&num2, sizeof num2, 1, temp2);
    }
}

 
