#include <stdio.h>

int calc(int n1,int n2){
  if(n1 == n2){
    return n2;
  } else {
    return n1 + calc(n1 + 1,n2);
  }
}

int main(void){
  int n1,n2,i;
  printf("Summation Program\n");
  for(i = 0;i<3;i++){
    printf("N1=");
    scanf("%d",&n1);
    printf("N2=");
    scanf("%d",&n2);
    printf("sum from %d to %d = %d\n",n1,n2,calc(n1,n2));
  }
  return 0;
}

