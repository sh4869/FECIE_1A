#include <stdio.h>

int main(void){
  int i,j,w,data[4] = {4,-4,256,66560};
  char ch1,ch2,ch3;
  printf("/*** P2 1 ***\n");
  for(j=0;j<4;j++){
    w = data[j];
    for(i=0;i<32;i++){
      if(w<0)printf("1");
      else printf("0");
      w = w << 1;
    }
    printf("\n");
  }

  printf("\n\n***10進数(16進数)とASCII文字との対応***\n");
  for(i=32;i<127;i++){
    if(i==(i/8)*8){
      printf("\n");
      printf("%3d(%02x)%c",i,i,i);
    }
  }
  ch1 = 'A';
  ch2 = ch1 + 5;
  ch3 = 'a' - 'z';
  printf("\n\n ch1=%c,ch1=%d,ch2=%c,ch3=%d",ch1,ch1,ch2,ch3);
  printf("\n*/\n");
}
