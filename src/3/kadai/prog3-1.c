#include <stdio.h>
#include "PLIB.h"

typedef unsigned int P32;
typedef short int I16;
typedef unsigned char P8;

int main(void){
  int i1,i2,i3,a1,*a2;
  float f1,b1,*b2;
  double f2,d1,*d2;
  char c1,c2,ch1[10] = "abcdefgh",ch2[] = "abcdefgh";
  P32 pp;
  I16 aa;
  P8 ch3;

  printf("/*** P3-1 (sizeof,typedef,pointer ) ***\n");
  
  i1 = -4;
  printf("i1=");
  print_bitposition(i1);
  printf("i2=");
  i2 = 255;
  print_bitposition(i2);
  i3 = 0x3f8000f1;
  printf("i3=");
  print_bitposition(i3);

  f1 = 1.75f;
  f2 = 1.5;
  printf("\nf1=%f,f2=%f\n",f1,f2);
  c1 = 'A';
  c2 = -4;
  ch3 = 200;
  printf("c1 = %c(%02d),c2 = %d,ch3 = %d\n",c1,c1,c2,ch3);
  
  pp = 20000 * 50000;
  aa = 30000;
  printf("pp = %d(%08x) aa = %d(%04x)\n",pp,pp,aa,aa);
  printf("sizeof(int)=%d,sizeof(short)=%d,sizeof(I16)=%d,sizeof(P8)=%d\n",sizeof(int),sizeof(short),sizeof(I16),sizeof(P8));
  printf("sizeof(float)=%d,sizeof(double)=%d\n",sizeof(float),sizeof(double));
  printf("sizeof(ch1)=%d sizeof(ch2) = %d\n\n",sizeof(ch1),sizeof(ch2));

  a1 = 20;
  a2 = &a1;

  printf("a1=%d,a2=%p,*a2=%d\n",a1,a2,*a2);

  b1 = 12.3f;
  b2 = &b1;
  printf("b1=%f,b2=%p,*b2=%f\n",b1,b2,*b2);
  d1 = 45.6;
  d2 = &d1;
  printf("d1=%f,d2=%p,d2=%f\n",d1,d2,*d2);

  printf("ch2=%p ch2=%s",ch2,ch2);
  printf("\n*/\n");
}
