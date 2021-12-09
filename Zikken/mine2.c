#include <stdio.h>
#include<string.h>
#define BUF_SIZE 256
 typedef struct student {
  char name[60];
  int gold;
  int silver;
  int blonde;
} STUDENT;

int Count(void)
{
  FILE *fp;
  char buf[BUF_SIZE];
  int line = 0;
 
  if ((fp = fopen("sample.csv", "r")) == NULL) {
    return -1;
  }
 
  while (fgets(buf, BUF_SIZE, fp) != NULL) {
    line++;
  } 
  return line;
}
void Write(STUDENT* argument){
  int column_nuber=Count();
  int i;
  for(i=0;i<column_nuber;i++){
    printf(" %s ",argument[i].name);
    printf("金メダル:%d ",argument[i].gold);
    printf("銀メダル:%d ",argument[i].silver);
    printf("銅メダル:%d ",argument[i].blonde);
    printf("\n");
  }
}

void Add(){
  char name[256];
  int gold;
  int shilver;
  int blonde;
  printf("国名を入力してください:");
  scanf("%s",name);
  printf("金メダルの数を入力してください:");
  scanf("%d",&gold);
  printf("銀メダルの数を入力してください");
  scanf("%d",&shilver);
  printf("銅メダルの数を入力してください");
  scanf("%d",&blonde);
  FILE *fp;
  fp = fopen("sample.csv","a");
  fprintf(fp,"%s,%d,%d,%d\n",name,gold,shilver,blonde);
  fclose(fp);
}

void Print(STUDENT* argument,char *str){
  int column_nuber=Count();
  int i;
  for(i=0;i<column_nuber;i++){
    if(strcmp(argument[i].name, str) == 0){
      printf("金メダル:%d銀メダル：%d銅メダル%d\n",argument[i].gold,argument[i].silver,argument[i].blonde);
      break;
    }else{
      printf("not same\n");
    }
  }
}

