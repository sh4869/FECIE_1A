#include <stdio.h>
#define QSIZE 4
int queue[QSIZE];
int Qhead;
int Qtail;
void Enqueue(int x){
  Qtail = (Qtail+1) % QSIZE;
  printf("Enqueue %d (head=%d,tail=%d)\n",x,Qhead,Qtail);
  queue[Qtail] = x;
  if(Qhead==Qtail){
    printf("Error: Overflow\n");
    return;
  }
}

int Dequeue(){
  if(Qhead==Qtail){
    printf("Error: Underflow\n");
    return -1;
  }
  Qhead = (Qhead + 1) % QSIZE;
  printf(" (head=%d,tail=%d) ",Qhead,Qtail);
  return queue[Qhead];
}

int main(void){
  int data;
  printf("/*** プログラム3.11-12 **\n");
  Qhead = Qtail = 0;
  Enqueue(10);
  Enqueue(20);
  Enqueue(30);
  data = Dequeue();
  printf("Dequeue1: %d\n",data);
  Enqueue(40);
  data = Dequeue();
  printf("Dequeue2: %d\n",data);
  Enqueue(50);
  Enqueue(60);
  printf("*/\n");
}
