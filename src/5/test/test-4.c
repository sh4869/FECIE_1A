#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
  double aa,bb;
  int i,num;
  char u = 'Q';
  char mn1[24],mn2[20],mn3[]="abcdefghij",mn4[30]="Hellow! ";
  static char a[3][12] = {"Handam","Nagashima","Koizumi"};
  enum animal {cat,cow,pig,dog};
  enum animal an;
  char a1 ='V',b1='f',c1='$',d1='7',e1=' ';
  char str1[] = "abCDdeFGhijk xxx!#$#&xxYYzzPp",str2[30];
  
  printf("/** TEST-4 \n");
  strcpy(mn1,"Tokyo-Yokohama");
  printf("(1) mn1=%s : ",mn1);
  printf("strlen(mn1)=%d,strlen(mn3)=%d\n",strlen(mn1),strlen(mn3));
  strcpy(mn1,a[0]);

  printf("(2) mn1=%s,a[1]=%s : ",mn1,a[1]);
  printf("strcmp(mn1,a[1] = %d \n",strcmp(mn1,a[1]));

  printf("(3) 名をローマ字(英数半角)で入力してください\n");
  scanf("%s",mn2);
  strcat(mn4,mn2);
  printf("%s\n",mn4);
  printf("(4) enum: \n 動物の番号を選んでください\n");
  printf("0=dog,1=cat,2=cow,3=pig\n");
  scanf("%d",&num);
  an = (enum animal) num;
  if(an == pig) printf(" **ブー**\n");
  else if(an == cat) printf(" **ニャン**\n");
  else if(an == cow) printf(" **モー**\n");
  else if(an == dog) printf(" **ワン**\n");

  printf("(5)\n");
  printf("isalpha(%c)=%d",c1,isalpha(c1));
  printf("isalpha(%c)=%d",a1,isalpha(a1));
  printf("isspace(%c)=%d",a1,isalpha(a1));
  printf("isspace(%c)=%d",e1,isalpha(e1));
  printf("isdigit(%c)=%d",b1,isalpha(b1));
  printf("isdigit(%c)=%d",d1,isalpha(d1));
  for(i=0;i<sizeof(str1);i++) str2[i] = toupper(str1[i]);
  printf("str2=%s\n",str2);
  for(i=0;i<sizeof(str1);i++) str1[i] = toupper(str2[i]);
  printf("str1=%s\n",str1);

  printf("*/\n");
}

