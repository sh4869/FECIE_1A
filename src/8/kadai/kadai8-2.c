#include <stdio.h>
#include "PLIB.h"

struct LIST *head;
int N=1;
int main(void){
  struct LIST *p1,*p2;
  int i;
  printf("/*** Program 3.4 **\n");
  head = NULL;
  head = inputdata(head);
  printf("Exapmle: Deletiong og the %dth record \n",N);
  i = 1;
  p1 = head;
  p2 = p1->next;
  while((i+1<N) && (p2 != NULL)) {
    i++;
    p1 = p2;
    p2 = p1->next;
  }
  printlist(head);
  if((i+1 != N) && (i != 1)) printf("Deletion Error\n");
  else {
    p1->data = p2->data;
    p1->next = p2->next;
  }
  if(N == 1) head = p2;
  printlist(head);
  printf("*/\n");
}
