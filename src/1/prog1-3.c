#include <stdio.h>
int func(){
  int i,m,k=100;
  for(i=0;i<5;i++){
    m = k+i;
    printf("f:m=%d\n",m);
  }
  printf("f:k=%d\n",k);
  return 1;
}

int main(void){
  int m,k = 14;
  printf("main-1: k=%d\n",k);
  func();
  printf("main-2: k=%d\n",k);
  return  1;
}
