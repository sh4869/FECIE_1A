#include <stdio.h>
#include <malloc.h>
#define Number 20
int main(void){
  int i,*ptr;
  printf("/*** P4-2 ***\n");
  ptr = (int*)malloc(sizeof(int)*Number);
  if(ptr != NULL){
    printf("pptr=%p\n",ptr);
    for(i=0;i<Number;i++){
      ptr[i] = i*10+1;
      printf("%03d ",ptr[i]);
    }
  }
  free(ptr);
  printf("\n*/\n");
}
