#include <stdio.h>
#include "PLIB.h"
#define HEAPSIZE 1000
static int heap[HEAPSIZE] = {0,72,46,47,18,35,32,13,5,9,29};
static int n = 10;

int Deletemax(void);
int main(void){
  printf("/*** プログラム3.14 **\n");
  printheap(heap,n);
  printf("Deletemax()%d\n",Deletemax());
  printheap(heap,n);
  printf("Deletemax()%d\n",Deletemax());
  printheap(heap,n);
  printf("Deletemax()%d\n",Deletemax());
  printheap(heap,n);
  printf("*/\n");
}

int Deletemax(void){
  int x,i,j,t;
  if(n==0){
    printf("Heap Underflow\n");
    return -1;
  } else {
    x = heap[1];
    heap[1] = heap[n--];
    i = 1;
    while(i*2<=n){
      j = i*2;
      if(i*2+1 <= n && heap[i*2] < heap[i*2+1]){
        j = i*2 + 1;
      }
      if(heap[i] >= heap[j]) {
        break;
      } else {
        t = heap[i];
        heap[i] = heap[j];
        heap[j] = t;
      }
      i = j;
    }
  }
  return x;
}

