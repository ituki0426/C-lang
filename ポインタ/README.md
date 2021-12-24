# (1)間接演算子「*」の意味と使い方

宣言するときに「*」を付けることでその変数がポインタ変数であることを示す。

また、別の使い方としては、*()の()内にアドレスを渡すことで、そのアドレスに格納されている値にアクセスすることが出来る。

つまり、「*」は単なる通し番号であるアドレスから変数という実態を読みが得させることが出来る。

![image](https://user-images.githubusercontent.com/82156802/136716815-8ac5a2b2-888f-445f-9f30-e69a3e3d80c5.png)
```c
*(アドレス)=値;
```

基本操作

```c
#include<stdio.h>
int main()
{
	int x;
	int *p;
	printf("please in put word");
	scanf("%d",&x);
	p=&x;
	printf("\n");
	printf("x=%d\n",x);
	printf("p=%d\n",*p);
	printf("&x=%x\n",&x);
	printf("p=%x",p);
}	


```


とすることで、アドレスを用いて変数を代入することが出来る。
# (2)ポインタを使う意味


______________________________________________________________________________________


➀関数を用いた時、直接main関数内で定義されている変数の値を変更することが出来る。
　なぜなら、ポインタはメモリを直接操作する手法だからだ。


```c
#include<stdio.h>
void hiroko(int *height){
	if(*height < 180){
		*height = 180;
	}
}
int main(void){
	int sato = 178;
	int sanaka = 175;
	int masaki = 179;
	hiroko(&masaki);
  /*masakiの値を関数で直接変更している*/
	printf("佐藤君の伸長:%d\n",sato);
	printf("佐中君の伸長:%d\n",sanaka);
	printf("真崎君の伸長:%d\n",masaki);
}
```

## ポインタへの配列と配列のポインタの違い

____________________________________________________________________________________________________________________________

私たちは、配列のアドレスを格納できるポインタを作ることが出来る。この作られたポインタは、配列へのポインタと呼ばれる。

配列へのポインタは、他次元配列を関数に渡す必要がある場合に役に立つ。
一次元配列へのポインタの宣言

```c
data_type (*var_name)[size_of_array];
```
例

```c
int (*ptr)[5];
```

```c
#include<stdio.h>
#define ARRAY_SIZE 5
int main()
{
    int arr[ARRAY_SIZE] = {1,2,3,4,5};
    int i = 0;
    // Pointer to an array of integers
    int (*ptr)[ARRAY_SIZE];
    // Points to the whole array arr.
    ptr = &arr;
    for(i=0; i< ARRAY_SIZE ; ++i)
    {
        printf(" arr[%d] = %d\n",i,(*ptr)[i]);
    }
    return 0;
}
```
出力
```
arr[0]=1
arr[1]=2
arr[2]=3
arr[3]=4
arr[4]=5
```


配列は基本的に同じデータ型の要素をまとめます。滑都の要素の型は同じで、隣接売るメモリ位置に格納されている必要がある。よって、ポインタの配列を作成できます。これは主にポインタ変数の配列です。

ポインタ配列の宣言
```
data_type *arrar_name[array_size];
```
例
```c
int *arr[5];
```


```c
#include <stdio.h>
int  main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int i = 0;
    // Creating an array of integer pointers
    // and initializing it with integer variables address
    int *arr[3] = {&a,&b,&c};
    // printing values using pointer
    for (i = 0; i < 3; ++i)
    {
        printf("Value of arr[%d] = %d\n", i, *arr[i]);
    }
    return 0;
}
```



```c
#include<stdio.h>
#define ARRAY_SIZE 5
int main()
{
    int arr[ARRAY_SIZE] = {1,2,3,4,5};
    int *p;
    //Pointer to an array of integers
    int (*ptr)[ARRAY_SIZE];
    //Points to the whole array arr.
    ptr = &arr;
    //Assign Array to pointer..
    p = arr;
    printf("p = 0x%p, ptr = 0x%p\n", p, ptr);
    //increment pointer to an array and integer pointer
    p++;
    ptr++;
    printf("p = 0x%p, ptr = 0x%p\n", p, ptr);
    return 0;
}
```

## ポインタと配列の違い

葉入れtの名前はその配列の先頭のアドレスを指します。しかし、ポインタと違って演算はできない。

## 和と差を求める関数


```c
#include<stdio.h>
void sum_diff(int n1, int n2,int *sum , int *diff){
	*sum = n1 + n2;
	*diff =  (n1>n2) ? n1-n2:n2-n1;
}
int main(void){
	int na,nb;
	int wa = 0,wb=0;
	puts("二つの整数を入力してください");
	puts("整数A"); scanf("%d",&na); 
	puts("整数B"); scanf("%d",&nb);
	sum_diff(na,nb,&wa,&wb);
	printf("和は%dで差は%dです",wa,wb);
	
}

```
※重要


オブジェクトへのポインタを仮変数に受け取れば、そのポインタに間接演算子*を適用することによって、そのオブジェクトそのものにアクセスできる。


これを利用すると、呼び出し元が用意したオブジェクトの値を呼び出された側で変更できる。



## ポインタと配列の関係

```int ai[3]```
と確保したとき、先頭のアドレスはaiや、&ai[0]と書ける。

つまり、配列名はそれだけで先頭のポインタを示す。

また、```*pi```
としたとき```pi=ai;```
と代入すれば```*pi```
はai[0]を示す。

また、前提としてポインタ変数に「*
」をつけることで、値にアクセスすることが出来る。

## ポインタと配列の違い

・配列aは
  ・
  ・
  ・
  ・

・ポインタpは

  ・
  ・
  ・
  ・

## 関数の引数の引数に配列を用いる

```c
#include<stdio.h>
#define SIZE 5
void intArr(int *arr){
	int i;
	for(i=0;i<SIZE;i++){
		arr[i]=456;
	}

}
```

```c
#include<stdio.h>
#define SIZE 5
void intArr(int *arr);
int main(){
	int arr[SIZE];
	int i;
	intArr(arr);
	for(i=0;i<SIZE;i++){
		printf("%d ",arr[i]);
	}
	return 0;
}
```

## 配列とポインタの関係性

```c
#include<stdio.h>
int main()
{
	int  a[5] = { 0, 1, 4, 9, 16 };	// 配列
	int  *p;			// ポインタ
	int  i;
	for (i = 0; i < 5; i++) {	// 配列への直接アクセス
		printf("a[%1d] : %d\n", i, a[i]);
	}
	printf("\n");
	p = a;//ポインタpに配列を代入している。
	for (i = 0; i < 5; i++) {	// 間接アクセス方法 #1
		printf("p[%1d] : %d\n", i, p[i]);
	}
	printf("\n");
	p = a;
	for (i = 0; i < 5; i++) {	// 間接アクセス方法 #2
		printf("*(p+%1d) : %d\n", i, *(p+i));
	}
	printf("\n");
	p = a;
	for (i = 0; i < 5; i++) {	// 間接アクセス方法 #3
		printf("*p : %d\n", *p);
		p++;
	}
	printf("\n");
}	


```

## ポインタ変数と配列

・配列の先頭アドレスのポインタ変数への代入

・配列要素のアドレス取得

・ポインタ変数による配列要素の実態の表現

## ポインタ配列

・ポインタ配列の宣言

## ポインタと関数引数
  
## ポインタを格納する配列（ポインタ配列）


ポインタ配列は、ポインタを要素とする配列である。これは、C言語において最も理解に手間取る内容の1つである。ポインタ配列の宣言は配列名の前にアスタリスク「＊
」を付けて宣言する


```データ型　*変数名[要素数]```

例
```c
```











