#include <stdio.h>

void print_bitposition(int w){
  int i = 0;
  for(i=0;i<32;i++){
    if(w<0){
      printf("1");
    } else {
      printf("0");
    }
    w = w << 1;
  }
  printf("\n");
}

int cellingP(double num){
  if(num > (int)num) return (int)num + 1;
  else return (int)num;
}

int floorP(double num){
  return (int)num;
}
