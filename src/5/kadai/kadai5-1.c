#include <stdio.h>
#define N 24
int sp[N] = {
  1670,1750,1280,1080,1700,1850,2030,1870,1920,1750,1400,1560,1070,770,1150,1070,1400,1120,1050,1500,1400,1740,2050,1780};

int main(void){
  int i,j,mxp,d;
  mxp = sp[1] - sp[0];
  printf("/*** アルゴリズム 1.1 **\n");
  for(i=0;i<=N-2;i++){
    for(j=i+1;j<=N-1;j++){
      d = sp[j] - sp[i];
      if(d > mxp) mxp = d;
    }
  }
  printf("mxp = %d\n*/\n",mxp);
}

