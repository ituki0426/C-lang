```c
#include <stdio.h>
typedef struct{
	int year;
	int mouth;
	int day;
	int hour;
	char *title;
} schedule;
int main(void){
	schedule schedules[2];
	schedules[0].year=2008;
	schedules[0].mouth=4;
	schedules[0].day=11;
	schedules[0].hour=10;
	schedules[0].title="講義ガイダンス";
	schedules[1].year=2008;
	schedules[1].mouth=7;
	schedules[1].day=14;
	schedules[1].hour=15;
  schedules[1].title="ゼミ";
  for (int i = 0; i < 2; i++){
     printf("%04d/%02d/%02d %02d:00 %s\n",
               schedules[i].year, schedules[i].mouth, schedules[i].day, schedules[i].hour,
               schedules[i].title);
  }
  
	return 0;
}
```
