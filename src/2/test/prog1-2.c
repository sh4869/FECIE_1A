#include <stdio.h>
#define N 100

int main(void){
  int array[N],size,i,k,m;
  for(m=0;;m++){
    printf("enter size=");
    scanf("%d",&size);
    if(size ==0)  return 1;
    printf("Output:\n");
    for(k=0;;k++){
      if(k==size) break;
      if(k % 2 == 0 || k == 0){
        array[k] = -1;
      } else {
        array[k] = k;
      }
    }
    printf("array[]={");
    for(i=0;i<size;i++){
      printf("%4d",array[i]);
    }
    printf("}\n");
  }
}
