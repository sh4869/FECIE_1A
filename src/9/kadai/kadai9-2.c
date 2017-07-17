#include <stdio.h>
#define Qsize 10
int Qhead = 0,Qtail = 0;
int queue[Qsize];
void Enqueue(int x){
  queue[++Qtail] = x;
  printf("(Enqueue) %d ",x);
}

int Dequeue(){
  printf("(Dequeue) %d ",queue[Qhead+1]);
  return queue[++Qhead];
}

int main(void){
  printf("/*** Program 3.9-3.10 **\n");
  Enqueue(10);
  printf("Qhead=%d,Qtail=%d\n",Qhead,Qtail);
  Enqueue(20);
  printf("Qhead=%d,Qtail=%d\n",Qhead,Qtail);
  Enqueue(30);
  printf("Qhead=%d,Qtail=%d\n",Qhead,Qtail);

  Dequeue();
  printf("Qhead=%d,Qtail=%d\n",Qhead,Qtail);
  Dequeue();
  printf("Qhead=%d,Qtail=%d\n",Qhead,Qtail);

  Enqueue(40);
  printf("Qhead=%d,Qtail=%d\n",Qhead,Qtail);

  Dequeue();
  printf("Qhead=%d,Qtail=%d\n",Qhead,Qtail);

  printf("*/\n");
}


