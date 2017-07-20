#include <stdio.h>
#include "PLIB.h"
#define HEAPSIZE 1000
#define INITSIZE 9

static int heap[HEAPSIZE];
static int n;

int Deletemax(void){
  int x,i,j,t;
  if(n==0){
    printf("Heap Underflow\n");
    return -1;
  } else {

    x = heap[1];
    heap[1] = heap[n--];
    i = 1;
    printf("Delete %d - ",x);
    while(i*2<=n){
      j = i*2;
      if(i*2+1 <= n && heap[i*2] < heap[i*2+1]){
        j = i*2 + 1;
      }
      if(heap[i] >= heap[j]) {
        break;
      } else {
        printf("heap[%d]=%d <-> heap[%d]=%d ",i,heap[i],j,heap[j]);
        t = heap[i];
        heap[i] = heap[j];
        heap[j] = t;
      }
      i = j;
    }
  }
  return x;
}

void PushHeap(int x){
  int i,j;
  if(++n >= HEAPSIZE){
    printf("Heap Overflow\n");
    return;
  } else {
    heap[n] = x;
    i = n;
    j = n / 2;
    printf("(add %2d) - ",x);
    while((j > 0) && (x > heap[j])){
      printf("heap[%d]=%d  <-> heap[%d]=%d ",i,heap[i],j,heap[j]);
      heap[i] = heap[j];
      i = j;
      j = i/2;
    }
    printf("\n");
    heap[i] = x;
    printheap(heap,n);
  }
}

int main(void){
  int data;
  int i;
  printf("\n");
  n = 0;
  printf("--start --\n");
  heap[0] = 0;
  while(1){
    printf("input additional data (0 => end, Negative => DeleteMax) :");
    scanf("%d",&data);
    if(data<0) {
      Deletemax();
    } else if (data > 0){
      PushHeap(data);
    } else {
      break;
    }
  }
}

