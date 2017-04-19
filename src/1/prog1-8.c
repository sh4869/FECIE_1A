#include <stdio.h>

int main(void){
  int k;
  for(k=0;k<5;k++){
    if(k==2) continue;
    if(k==4) continue;
    printf("k=%d\n",k);
  }
}
