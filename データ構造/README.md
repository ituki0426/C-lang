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

# アルゴリズム
##
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
``
