```c
#include <stdio.h>
#include <stdlib.h>

typedef struct Car {
    int num;
    double gas;
    struct Car *next;
} Car;

void show_carlist(Car *start, char *str);
void add_car2(Car *p,int n,double g);

int main(void)
{
    Car head2;
	int i;
	i=2;
    head2.num = 1; head2.gas = 0;
    head2.next = NULL;
    show_carlist(&head2, "head2 (1)");
    add_car2(&head2, i, 40.3);
	i=i+1;
    add_car2(&head2, i, 33.8);
	i=i+1;
    add_car2(&head2, i, 26.1);
	i=i+1;
    show_carlist(&head2, "head2 (2)");

    return 0;
}

void show_carlist(Car *start, char *str)
{
    Car *pcar;
    printf("--- %s ---\n", str);
    for(pcar = start; pcar!=NULL; pcar = pcar->next) {
        printf("num: %d, gas: %lf\n", pcar->num, pcar->gas);
    }
}

void add_car2(Car *p,int n,double g){
    Car *new;
    new=(Car *)malloc(sizeof(Car));
    new->num=n;
    new->gas=g;
	new->next=p->next;
	//1回目の呼び出しではnew1->nextにはNULLが入る
　　　　 //2回目の呼び出しではnew2->nextにはp->next、つまりnew1が入る
	p->next=new;
	//1回目の呼び出しではp->nextにはnew1が入る
　　　　//2回目の呼び出しではp->nextにはnew2が入る
}

```
結果は以下のようになる

![image](https://user-images.githubusercontent.com/82156802/167529999-9d402159-2057-4329-9660-610bfa307ea2.png)

つまり、1、４、３、２，の順で連結されていく
