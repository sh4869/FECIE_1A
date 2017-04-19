#include <stdio.h>

int main(void){
  int k;
  for(k=0;k<5;k++){
    if(k==3) break;
    printf("k=%d\n",k);
  }
}


