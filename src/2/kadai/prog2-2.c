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

int main(void){
  int wd,b=0x00ff0f0f,d=0x0ff03c3c;
  int p1,p2,p3,p,q = 0x0ff03c3c;
  printf("/*** P2 2(ビット演算) *** \n");
  printf("b = 0x00ff0f0f --> ");
  print_bitposition(b);
  printf("d = 0x0ff03c3c --> ");
  print_bitposition(d);
  
  wd = b | d;
  printf("b OR d ----------> ");
  print_bitposition(wd);

  wd = b & d;
  printf("b AND d ---------> ");
  print_bitposition(wd);

  wd = b ^ d;
  printf("b (+) d ---------> ");
  print_bitposition(wd);

  wd = ~b;
  printf("~b --------------> ");
  print_bitposition(wd);

  p1 |= q;
  printf("p1 ---> ");
  print_bitposition(p1);

  p2 &= q;
  printf("p2 ---> ");
  print_bitposition(p2);

  p3 ^= q;
  printf("p3 ---> ");
  print_bitposition(p3);

  p = b == d;
  printf("(b==d) = %d\n",p);
  
  p = b < d;
  printf("(b < d) = %d\n",p);

  printf("*/\n");
}
