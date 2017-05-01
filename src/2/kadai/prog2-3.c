#include <stdio.h>

void print_hexa(int);
void print_c(unsigned char);
void print_bitposition(int);

int main(void){
  int a;
  unsigned int b;
  unsigned char c;
  char ch;
  printf("/** P2-3 (シフト演算) **");
  printf("\n int a; (算術シフト:右シフトは sign bitが続く\n");
  
  a = 0x0fffffff;
  print_hexa(a);
  a = a >> 12;
  print_hexa(a);
  a = a << 16;
  print_hexa(a);
  a = a >> 16;
  print_hexa(a);
  a = a << 20;
  print_hexa(a);
  a = a >> 12;
  print_hexa(a);

  printf("unsigned int b;(論理シフト:右シフトは0が続く)\n");

  b = 0x0fffffff;
  print_hexa(b);
  b = b >> 12;
  print_hexa(b);
  b = b << 16;
  print_hexa(b);
  b = b >> 16;
  print_hexa(b);
  b = b << 20;
  print_hexa(b);
  b = b >> 12;
  print_hexa(b);
  
  printf("\n c:符号なし文字\n");
  print_c(c);
  c = c >> 2;
  print_c(c);
  ch = 97;
  printf("\nch = %d (hexa %x) ch = %c ch +7 =%c\n",ch,ch,ch,ch+7);
  printf("\n");
}
void print_hexa(int t){
  printf("(hex %08X) %10d;",t,t);
  print_bitposition(t);
}

void print_c(unsigned char t){
  printf("(hex %02x) %03d;",t,t);
}

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
