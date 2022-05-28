# 再帰処理

## 2a(n+2)-3a(n+1)+a(n)=0,a(1)=1,a(2)=2を求める
```c
#include <stdio.h>
int main(void){
	int i;
	double a[11];
	a[1]=1.0;
	a[2]=2.0;
	for(i=1;i<=8;i++){
		a[i+2]=1.5*a[i+1]-0.5*a[i];
	}
	printf("%lf",a[10]);
}
```
## 2a(n+2)-3a(n+1)+a(n)=0,a(1)=1,a(2)=2を求める

```c
#include <stdio.h>
double hoge(double n){
	double fact;
	if(n==1){
		return 1;
	}else if(n==2){
		return 2;
	}
	else{
		fact=(3*hoge(n-1)-hoge(n-2))/2;
		return fact;
	}
}
int main(void){
	double i;
	for(i=1;i<10;i++){
		printf("%lf\n",hoge(i));
	}
}
```
## nの階乗を求める

```c
#include <stdio.h>
int fact(int n);
int main(void){
	printf("%d",fact(3));
}
int fact(int n){
	int fac;
	if(n==0){
		return 1;
	}else{
		fac=n*fact(n-1);
		return fac;
	}
}
```

# アルゴリズム

## 入力した数字を下の桁から表示する

##

# ソート

## 単純挿入法
```c
#include <stdio.h>
int main(void){
	int i,j,t;
	int a[6]={7,3,5,9,1,6};
	for(i=1;i<6;i++){
		for(j=i-1;j>=0;j--){
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}else{
				break;
			}
		}
	}
	for(i=0;i<6;i++){
		printf("%d ",a[i]);
	}
}
```

## ビンソート
```c
#include <stdio.h>
#define NUM 5//与えられたデータの個数
#define MAX 6//与えられたデータの最大値+1
void BinSort(int data[]){
	int i,j,k=0;
	int bin[MAX];
	//bin配列の初期化
	for(i=0;i<MAX;i++)
		bin[i]=0;
	for(i=0;i<NUM;i++)
		bin[data[i]]++;
	
	for(i=0;i<MAX;i++){
		for(j=bin[i];j>0;j--)
			data[k++]=i;		
	}
}
int main(void){
	int i;
	int data[NUM]={3,5,1,3,1};
	BinSort(data);
	for(i=0;i<NUM;i++)
	    printf("%d ",data[i]);
}
```

# 内部表現

## 入力された値をビット単位で表示する
```c
#include <stdio.h>
//2進数表記で、「1」の数を返す
int count_bits(unsigned int x){
	int count=0;
	while (x){//xが0でない限り繰り返す
		if(x & 1U) count++;
		x >>= 1;//xを右に1ビットシフトしている。
	}
	return count;
}
int int_bits(void){
	return(count_bits(~0U));//~0Uは全ビットが1のunsigned int型整数
}
//unsigned int型のビット内容を表示
void print_bits(unsigned int x){
	int i;
	for(i=int_bits()-1;i>=0;i--){
		if((x>>i) & 1U){
			putchar('1');
		}else{
			putchar('0');
		}
	}
}
int main(void){
	unsigned int na;
	scanf("%u",&na);//%uはunsigned型の変換指定子
	printf("A="); print_bits(na); printf("\n");
}
```
## unsigned int型を左右にnビットシフトした値

















