#include <stdio.h>
#include <string.h>

int main(void){
  struct kozo1 {
    int a;
    float b;
    char name[16];
  };
  struct kozo1 g1,g,*p;
  typedef struct {
    int a;
    double b;
    char name[16];
  } kozo2;
  kozo2 g2,*p2;

  printf("/*** P3-2 *****\n");
  printf("sizeof(struct kozo1)=%d,&g1=%p,&g1.a=%p\n&1.b=%p,&g1.name=%p\n",sizeof(struct  kozo1),&g1,&g1.a,&g1.b,&g1.name);
  printf("sizeof(kozo2)=%d,&g2=%p,&g2.a=%p\n&g2.b=%p,&g2.name=%p\n\n",sizeof(kozo2),&g2,&g2.a,&g2.b,&g2.name);

  g2.a = 10;
  g2.b = 12.3;
  strcpy(g2.name,"shibaura");
  printf("g2.a=%d,g2.b=%f,g2.name=%s\n\n",g2.a,g2.b,g2.name);
  p2 = &g2;
  printf("p2->a=%d,p2->b=%f,p2->name=%s\n",p2->a,p2->b,p2->name);
  g1.a = 90;
  g1.b = (float)99.9;
  strcpy(g1.name,"Ohmiya");
  printf("g1.a=%d,g1.b=%f,g1.name=%s\n\n",g1.a,g1.b,g1.name);
  
  g = g1;
  p = &g;
  printf("p2->a=%d,p2->b=%f,p2->name=%s\n",p2->a,p2->b,p2->name);
  printf("g2.a=%d,g2.b=%f,g2.name=%s\n\n",g2.a,g2.b,g2.name);
  printf("*/\n");
}
