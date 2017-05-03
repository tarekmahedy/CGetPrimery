#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *array;
  size_t used;
  size_t size;
} Array;

void initArray(Array *a, size_t initialSize) {
  a->array = (int *)malloc(initialSize * sizeof(int));
  a->used = 0;
  a->size = initialSize;
}

void insertArray(Array *a, int element) {
  if (a->used == a->size) {
    a->size *= 2;
    a->array = (int *)realloc(a->array, a->size * sizeof(int));
  }
  a->array[a->used++] = element;
}


int check_prime(Array *a,int av)
{
   int c;
   int len=a->used;
  if(len>0){
   for ( c = 0 ; c < len ; c++ )
   { 
     int item=a->array[c];

      if ( av%item == 0 )
	   return 0;
   }

  }else return 1;

    return 1;

}



//get the first argument as the wanted number of prime 
//the second argument the start number 
int main(int argc, char *argv[]) {

if(argc>0){

int il = 0;
int startwith = 2;
sscanf (argv[1],"%d",&il);
if(argc>1){ 
 sscanf (argv[2],"%d",&startwith);
}

Array numbers;
int i;
initArray(&numbers, 50);
int printed=1;

for( i = 2; printed < il; i++) {
   if((i%2)==1){if(check_prime(&numbers, i)){ if(i>startwith){ printed++; printf("%d :", i);} insertArray(&numbers, i);}}
} 
 printf(" \n");
 printf("items searched:  %d\n",i);

}
  printf("end \n");

    return 0;
}


