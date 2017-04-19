#include <stdio.h>

int kago[3];
int func(int n,int sum){
  int k;
  if(n==4){
    if(sum==5){
      printf("kago[]={%d %d %d}\n",kago[0],kago[1],kago[2]);
    }
    return 0;
  }
  for(k=5;k>=0;k--){
    kago[n-1] = k;
    if(n==1){
      func(n+1,kago[n-1]);
    } else {
      if(sum+k>5) continue;
      if(kago[n-2]<kago[n-1]) {
        continue;
      } else {
        func(n+1,kago[0]+kago[1]+kago[2]);
      }
    }
  }
}

int main(void){
  printf("kagoに5つのballを入れるプログラム\n");
  func(1,0);
  return 0;
}
