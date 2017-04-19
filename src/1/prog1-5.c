#include <stdio.h>

int arr[4];

void f(){
  arr[2] = 2;
  arr[3] = 3;
}

int main(void){
  arr[0] = 0;
  arr[1] = 1;
  f();
  printf("arr[]={%d,%d,%d,%d}\n",arr[0],arr[1],arr[2],arr[3]);
}
