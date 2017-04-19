#include <stdio.h>

int kago[3];

int main(void){
  printf("kagoに5つのballを入れるプログラム\n");
  int k1,k2,k3;
  for(k1=5;k1>=0;k1--){
    kago[0] = k1;
    for(k2=5;k2>=0;k2--){
      kago[1] = k2;
      if(k1+k2>5) continue;
      if(k1<k2) continue;
      for(k3=5;k3>=0;k3--){
        kago[2] = k3;
        if(k2<k3) continue;
        if(k1+k2+k3 == 5){
          printf("kago[]={%d %d %d}\n",kago[0],kago[1],kago[2]);
        }
      }
    }
  }
}
