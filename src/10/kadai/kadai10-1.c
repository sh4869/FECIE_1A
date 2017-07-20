#include <stdio.h>
#define HEAPSIZE 1000
#define INITSIZE 9
void printheap(int *heap,int n){
  int i;
  printf("heap(n = %02d) ",n);
  for(i=1;i<=n;i++){
    printf("%2d ",heap[i]);
  }
  printf("\n");
}

static int heapdata[INITSIZE] = {9,5,13,32,29,18,72,35,47};
static int heap[HEAPSIZE];
static int n;
void PushHeap(int);
int main(void){
  int data;
  int i;
  printf("/*** Program 3.13 **\n");
  n = 0;
  printf("--start --\n");
  heap[0] = 0;
  for(i=0;i<INITSIZE;i++){
    PushHeap(heapdata[i]);
  }
  while(1){
    printf("input additional data (0 => end) :");
    scanf("%d",&data);
    if(data<=0) break;
    PushHeap(data);
  }
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
    j = n / 2;
    while((j > 0) && (x > heap[j])){
      heap[i] = heap[j];
      i = j;
      j = i/2;
    }
    heap[i] = x;
    printf("(add %2d) - ",x);
    printheap(heap,n);
  }
}
