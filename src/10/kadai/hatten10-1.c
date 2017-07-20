#include <stdio.h>
#define N 6
#define NN 36

static int A[N][N] = {
  1,1,1,1,0,1,
  0,1,1,0,1,0,
  1,0,1,1,1,1,
  0,0,1,1,1,0,
  0,0,0,1,0,0,
  1,0,1,1,1,1,
};
static int L[N][N];
static int stack[NN][2];
static int ss = 0;

int push(int i,int j){
  stack[ss][0] = i;
  stack[ss][1] = j;
  ss++;
  return ss;
}

int pop(){
  if(ss == 0) {
    return -1;
  } else {
    ss--;
    return ss;
  }
}

int envsearch(int i,int j){
  if((i-1 >= 0) && (A[i-1][j]==1) && (L[i-1][j] ==0)){
    push(i-1,j);
  }
  if((i+1 < N) && (A[i+1][j]==1) && (L[i+1][j] ==0)){
    push(i+1,j);
  }
  if((j-1 >= 0) && (A[i][j-1]==1) && (L[i][j-1] ==0)){
    push(i,j-1);
  }
  if((j+1 < N) && (A[i][j+1]==1) && (L[i][j+1] ==0)){
    push(i,j+1);
  }
}

int main(void){
  int i,j,s,seqno;
  printf("/*** 第三章 - 演習問題問5 ** \n");
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      L[i][j] = 0;
    }
  }
  seqno = 0;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if((A[i][j]==1) && (L[i][j]==0)){
        seqno = seqno + 1;
        L[i][j] = seqno;
        printf("find new conn A(%d,%d),seqno =%d\n",i,j,seqno);
        envsearch(i,j);
        while(ss>0){
          s = pop();
          if((A[stack[s][0]][stack[s][1]]==1) && (L[stack[s][0]][stack[s][1]]==0)){
            L[stack[s][0]][stack[s][1]] = seqno;
            envsearch(stack[s][0],stack[s][1]);
          }
        }
      }
    }
  }

  for(i=0;i<N;i++){
    printf("\n");
    for(j=0;j<N;j++){
      printf("(%d,%d) = %d ",i,j,L[i][j]);
    }
  }
}
