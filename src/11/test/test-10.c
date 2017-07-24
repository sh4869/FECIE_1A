#include <stdio.h>
#define HEAPSIZE 1000
static int heap[HEAPSIZE] = {0,70,30,60,10,20,50,40};
void PushHeap(int);
int Deletemax();
static int n;

void printheap(int *heap,int n){
  int i;
  printf("heap(n=%02d): ",n);
  for(i=1;i<n;i++){
    printf("%2d ",heap[i]);
  }
  printf("\n");
}

int main(void){
  printf("/*** Test - 10 **\n--start--\n");
  n = 7;
  printheap(heap,n);

  PushHeap(80);
  printheap(heap,n);
  Deletemax();
  printf("Delete Max - ");
  printheap(heap,n);

  PushHeap(55);
  printheap(heap,n);
  Deletemax();
  printf("Delete Max - ");
  printheap(heap,n);

  printf("*/\n");
}

void PushHeap(int x){
  int i,j;
  if(++n >= HEAPSIZE){
    printf("Heap Overflow\n");
    return;
  } else {
    heap[n] = x;
    i = n;
    j = i / 2;
    printf("(PushHeap) heapsize=%d,heap[%d]=%d\n",n-1,n,x);
    while((j>0) && (x > heap[j])){
      heap[i] = heap[j];
      printf("replace heap[%d]=%d <-> heap[%d]=%d\n",j,heap[j],i,x);
      i = j;
      j = i / 2;
    }
    heap[i] = x;
    printf("(add %2d) - ",x);
  }
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
    printf("(Deletemax) set heap[1]=%d\n",heap[1]);
    while(i*2<=n){
      j = i * 2;
      if((i*2+1<=n) && (heap[i*2]<heap[i*2+1])) {
        j = i * 2 + 1;
      }
      if(heap[i] >= heap[j]){
        break;
      } else {
        t = heap[i];
        heap[i] = heap[j];
        heap[j] = t;
        printf("replace heap[%d]=%d <-> heap[%d]=%d\n",i,heap[j],j,heap[i]);
      }
      i = j;
    }
  }
  return x;
}
