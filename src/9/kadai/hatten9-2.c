#include <stdio.h>
#include <stdlib.h>

#define MAX_GAKUSEI 3
#define MAX_KAMOKU 3

struct SEISEKI {
  struct SEISEKI *glink;
  struct SEISEKI *klink;
  struct GAKUSEI *gakusei;
  struct KAMOKU *kamoku;
  int seiseki;
};

struct GAKUSEI {
  struct SEISEKI *glink;
  char *name;
} gakusei[MAX_GAKUSEI];

struct KAMOKU {
  struct SEISEKI *klink;
  char *name;
} kamoku[MAX_KAMOKU];

void initialize(){
  int i;
  for(i=0;i<MAX_GAKUSEI;i++){
    gakusei[i].glink = NULL;
  }
  for(i=0;i<MAX_KAMOKU;i++){
    kamoku[i].klink = NULL;
  }
}

void add_seiseki(int x,int y,int a){
  struct SEISEKI *p;
  if((p = malloc(sizeof(struct SEISEKI)))==NULL){
    printf("no memory");
    exit(-1);
  }
  p->glink = gakusei[x].glink;
  gakusei[x].glink = p;
  p->klink = kamoku[y].klink;
  kamoku[y].klink = p;
  p->gakusei = &(gakusei[x]);
  p->kamoku = &kamoku[y];
  p->seiseki = a;
}

short get_seiseki(int x,int y){
  struct SEISEKI *p;
  for(p=gakusei[x].glink;p!=NULL;p=p->glink){
    if(p->kamoku == &kamoku[y]){
      return p->seiseki;
    }
  }
  return -1;
}

void print_gakusei(int x){
  struct SEISEKI *p;
  for(p=kamoku[x].klink;p!=NULL;p=p->klink){
    printf("%s %d\n",p->gakusei->name,p->seiseki);
  }
}

int main(void){
  int i;
  printf("/*\n");
  initialize();
  char name[3][20] = {"Tanaka","Saitou","Yamazaki"};
  char kamokuname[3][20] = {"English","Mathematics","Programming"};
  gakusei[0].name = name[0];
  gakusei[1].name = name[1];
  gakusei[2].name = name[2];

  kamoku[0].name = kamokuname[0];
  kamoku[1].name = kamokuname[1];
  kamoku[2].name = kamokuname[2];

  add_seiseki(0,0,67);
  add_seiseki(0,1,80);
  add_seiseki(1,0,59);
  add_seiseki(1,2,98);
  add_seiseki(2,0,77);
  add_seiseki(2,1,88);
  add_seiseki(2,2,90);
  for(i=0;i<MAX_KAMOKU;i++){
    printf("kamoku=%s\n",kamoku[i].name);
    print_gakusei(i);
  }
  printf("*/\n");
}

