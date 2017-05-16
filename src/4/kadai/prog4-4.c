#include <stdio.h>
#include <string.h>
static char a[3][12] = {"Tanaka","Nagashima","Yoshida"};

int main(void){
  int p= 10,q=20,selection;
  char u = 'P';
  char nm1[12],nm2[20],nm3[] = "abcdefghij",nm4[30]="Hellow!";
  char man1[12]="main1",man2[12]="man2",man3[12]="man3";
  printf("/*** P4-4 ***\n");
  printf("sizeof(nm1)=%d,sizeof(nm3)=%d\n",sizeof(nm1),sizeof(nm3));
  strcpy(nm1,"Shibaura");
  printf("(1) nm1=%s\n",nm1);
  printf("strlen(nm1)=%d,strlen(nm3)=%d\n",strlen(nm1),strlen(nm3));
  strcpy(nm1,nm3);

  printf("strlen(nm1)=%d,strlen(nm3)=%dnm1=%s\n",strlen(nm1),strlen(nm3),nm1);
  strcpy(nm1,a[0]);
  strcpy(nm2,a[1]);
  strcpy(nm3,a[2]);

  printf("(3) nm1=%s,nm2=%s,nm3=%s\n",nm1,nm2,nm3);
  printf("strcmp(nm1,nm1)=%d (nm1==nm1)\n",strcmp(nm1,nm1));
  printf("strcmp(nm1,nm2)=%d (nm1>nm2)\n",strcmp(nm1,nm2));
  printf("strcmp(nm2,nm3)=%d (nm2<nm3)\n",strcmp(nm2,nm3));

  printf("(5) 名をローマ字(英数半角)で入力してください\n");
  scanf("%s",nm2);
  strcat(nm4,nm2);
  printf("%s\n",nm4);

  selection = (p>q) ? (p+1) : (q-5);
  printf("(6) (p>q) ? (p+1) : (q-5);selection=%d(p=%d,q=%d)\n",selection,p,q);
  printf("*/\n");
}
