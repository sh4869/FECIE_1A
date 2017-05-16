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
  char ch1,ch2;
  unsigned int t;
  int n,p,s,wd,b = 0x00ff0ff0,d = 0x0ff05c5c;

  printf("/*** Test-2 ****\n");
  print_bitposition(66561);
  ch1 = 'j';
  ch2 = 'p'-'f';
  printf("\n ch1+3=%c ch2=%d\n\n",ch1+3,ch2);

  wd = b & d;
  printf("b AND d ---> ");
  print_bitposition(wd);
  
  p = b > d;
  printf("\n(b>d) = %d,a < b = %d\n\n",p,'a' < 'b');
  s = 0x00ffffff;
  printf("s = %08x ",s);
  s= s>>8;
  printf("s = %08x\n\n",s);
  s = s << 16;
  printf("s = %08x ",s);
  s= s>>8;
  printf("s = %08x\n\n",s);
  t = 0xffff0000;
  printf("s = %08x ",t);
  t = t >> 8;
  printf("s = %08x\n\n",t);
  
  printf("sizeof(ch1)=%d,&ch1=%p\n\n",sizeof(ch1),&ch1);
  printf("sizeof(b)=%d,&b=%p\n\n",sizeof(b),&b);
  n = 298;
  printf("n=%04d,%d,%04x,%04x,%x\n",n,n,n,n,n);
  printf("\n");
}
