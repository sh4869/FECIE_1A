#include <stdio.h>
#define MAX 30

int main(void){
  int i,j;
  int n = 7;
  int start = 6;
  printf("sun mon tue wed thu fri sat\n");
  for(i = 1;i<=MAX;i++){
    if(i == 1){
      for(j=0;j<start;j++){
        printf("    ");
      }
    }
    printf(" %3d",i);
    if(start == 6){
      start = 0;
      printf("\n");
    } else {
      start++;
    }
  }
  printf("\n");
}
