# include<stdio.h>
# include<string.h>
int Count(void);
 
typedef struct student {
  char name[60];
  int gold;
  int silver;
  int blonde;
} STUDENT;

void Sort_country(STUDENT* argument){	
  int column_nuber=Count();
  int i;
  char main[256][256];
  int gold[256];
  int shilber[256];
  int blonde[256];
  for(int j=0;j<column_nuber;j++){
	  strcpy(main[j],argument[j].name);
	  gold[j]=argument[j].gold;
	  shilber[j]=argument[j].silver;
	  blonde[j]=argument[j].blonde;
  }
/*
 if(strcmp(main[0],main[1])>0){
	  char save[256];
	  strcpy(save,main[0]);
	  strcpy(main[0],main[1]);
	  strcpy(main[1],save);
  }else if(strcmp(main[0],main[1])<0){
	   return;
  }else{
	  return;
  }

*/
if(strcmp(main[1],main[2])<0){
	printf("%s is bigger than %s \n",main[1],main[2]);
}else if(strcmp(main[1],main[2])>0){
	printf("%s is smaller than %s \n",main[1],main[2]);
}

  for(i=0;i<column_nuber;i++){
    printf(" %s ",main[i]);
    printf("金メダル:%d ",gold[i]);
    printf("銀メダル:%d ",shilber[i]);
    printf("銅メダル:%d ",blonde[i]);
    printf("\n");
  }
}
