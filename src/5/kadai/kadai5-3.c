#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
int sp[N],printflag;
void data_set(){
  long int longi,d1,d2;
  sp[0] = 2000;
  for(longi=1;longi<N;longi++){
    d1=rand()%2;
    d2=rand()%10;
    if(sp[longi-1] > 5000) d1 = 1;
    else if(sp[longi-1] < 500) d1 = 0;
    if(d1==0) sp[longi] = sp[longi - 1] + sp[longi - 1] * d2 / 100;
    else sp[longi] = sp[longi - 1] - sp[longi - 1] * d2 / 100;
  }
}

int modify_value(long int longi){
  int dd,d1,d2,xi;
  if(longi<N) return sp[longi];
  dd = longi/N;
  d1 = dd%2;
  d2 = (dd+(longi%10))%10;
  if(d1==0) xi = sp[longi%N] + sp[longi%N] * d2 / 100;
  else xi = sp[longi%N] - sp[longi%N] * d2 / 100;
  return xi;
}

int main(void){
  int i,j,mxp,mxsp,d,dd,d1,d2,xi,xj,msf,NN,pat;
  clock_t start,end;
  long int longi,longj;
  srand(time(NULL));
  data_set();
  while(1){
    printf("0(n):1 0(n*N):2 ? ");
    scanf("%d",&pat);
    printf("NN=");
    scanf("%d",&NN);
    if(pat==1){
      start = clock();
      printf("/*** アルゴリズム O(n) **\n");
      mxp = sp[1] - sp[0];
      msf = sp[0];
      for(longi=1;longi <= NN - 1;longi++){
        xi = modify_value(longi);
        d = xi - msf;
        if(d > mxp) mxp = d;
        if(msf > xi) msf = xi;
      }
      end = clock();
      printf("mxp = %d \n*/\n",mxp);
      printf("order=O(n) NN = %d time = %2f秒\n",NN,(double)(end - start)/CLOCKS_PER_SEC);
    } else if(pat == 2){
      start = clock();
      printf("/*** アルゴリズム O(nn) **\n");
      mxp = sp[1] - sp[0];
      for(longi=1;longi<=NN-2;longi++){
        xi = modify_value(longi);
        for(longj=longi+1;longj<=NN-1;longj++){
          xj = modify_value(longj);
          d = xi - xj;
          if(d > mxp) mxp = d;
        }
      }
      end = clock();
      printf("mxp = %d \n*/\n",mxp);
      printf("order=O(n*n) NN = %d time = %2f秒\n",NN,(double)(end - start)/CLOCKS_PER_SEC);

    } else exit;
  } 
}


