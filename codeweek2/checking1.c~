
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

//using namespace std;
void mergesort(int lo, int hi);
int min(int a, int b){
    return (a <= b ? a : b);
}


int main() {
int num,i,max;
scanf("%d",&max);
mergesort(0,max-1);

}











void mergesort(int lo, int hi){
int i,w;
   
    for ( w = 1; w <= hi - lo; w <<= 1){
        printf("\n%d\n", w);
       // fseek(q, 0, SEEK_SET);
        for ( i = lo; i < hi; i += 2*w){
         //   merge(i, min(i + w - 1, hi), min(i + 2*w-1, hi));
printf("\n low--%d   mid--%d   high--%d",i, min(i + w - 1, hi), min(i + 2*w-1, hi));
        }
    }
   }
