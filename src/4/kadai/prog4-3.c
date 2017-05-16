#include <stdio.h>
#include <malloc.h>
#define SIZE5 5
typedef struct {
  int a;
  float b;
} record;

int main(void){
  int i;
  record *ptr;
  printf("/*** P4-3 **\n");
  printf("ptr = %p\n",ptr);
  printf("** (record) **\n");
  ptr = (record *) malloc(sizeof(record) * SIZE5);
  if(ptr != NULL){
    printf("ptr=%p\n",ptr);
    for(i=0;i<SIZE5;i++){
      ptr[i].a = i*10+1;
      ptr[i].b = (float)i*100 + 1.0f;
    }
    for(i=0;i<SIZE5;i++){
      printf("ptr[%d].a=%03d,ptr[%d].b=%f\n",i,ptr[i].a,i,ptr[i].b);
    }
  }
  free(ptr);
  return 0;
}
