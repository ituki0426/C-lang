int Count(void);
 
typedef struct student {
  char name[60];
  int gold;
  int silver;
  int blonde;
} STUDENT;

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
  for(i=O;i<columnumber){
   
  }
 
 
}
