#include <stdio.h>
#define Ni 3
#define Nj 4
static int A[Nj] = {11,12,13,14};
static int B[Ni][Nj] = {1,2,3,4,11,12,13,14,21,22,23,24};

int main(void){
  int i,j,C[Nj];

  printf("/** P3-3  **\n");

  printf("step1:\n");
  for(j=0;j<Nj;j++) printf("A[%d]=%2d ",j,A[j]);
  
  printf("\n\nstep2: (アドレスのつながりを確認しよう)\n");
  printf("A=%p",A);
  for(j=0;j<Nj;j++) printf("&A[%d]=%p ",j,&A[j]);
  
  printf("\nstep3:\n");
  for(i=0;i<Ni;i++){
    for(j=0;j<Nj;j++) printf("B[%d][%d]=%2d ",i,j,B[i][j]); 
    printf("\n");
  }
  
  printf("\nstep4: (アドレスのつながりを確認しよう)");
  for(i=0;i<Ni;i++){
    for(j=0;j<Nj;j++) printf("&B[%d][%d]=%2d ",i,j,&B[i][j]);
    printf("\n");
  }

  for(j=0;j<Nj;j++) C[j]=B[2][j] + 100;
  for(j=0;j<Nj;j++) printf("C[%d] =%03d",j,C[j]);
  printf("\n*/\n");
}
