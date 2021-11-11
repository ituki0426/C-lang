# 静的（スタティック）変数

・プログラムが実行されている間、ずっと確保されている変数
・```static iht i = 0;```
のように定義される

・一度確保されると{}外に出ても残っている。

例
```c
int main(void){
    f(3);
    f(1);
    f(2);
    printf("%d",f(1))
}
int f(int x){
   static int i = 0;//初期化は1回のみ行われる。
   i++;
   return i;
}
```

解説

・終わってもiは残る

　・初期化は1回だけ→この場合、関数が呼ばれるたびにiが1増える。

上の場合ではf()は合計で4回呼ばれているので、最終的に４を返す。

結果

![image](https://user-images.githubusercontent.com/82156802/140502410-a221e25c-59fe-4fdf-8b87-967a3ee482dd.png)

例

File1.c
```c
#include<stdio.h>
int func(int);
int main(void){
	int a,b;
	printf("Input a\n");
	scanf("%d",&a);
	//a=3
	b=func(a);
	//f:a=4,b=4 が出力される。
	//b=4となる。
	printf("m:a=%d,b=%d",a,b);
	//よって、m:a=3,b=4が出力される。
	b = func(a);
	//2回目のfuc()の呼び出しとなる。
	//f:a=4,b=8が出力される。
	//b=８となる。
	printf("m:a=%d,b=%d\n",a,b);
	//この関数の中では、常にa=3であるため、m:a=3,b=8が出力される。
	return 0;
}
```

File2.c

```c
#include<stdio.h>
int func(int a){
	static int b=0;
	//1回目の呼び出しで、b=4となり、次に引きがれる。
	//2回目の呼び出しでは、bの初期化は行われず、b=4のままで開始される。
	a=a+1;
	//2回目でもa=4となる。
	b=a+b;
	//2回目ではb=4+4となる。
	//つまりb=8となる。
	printf("f:a=%d,b=%d\n",a,b);
	return b;
}
```

結果

```f:a=4,b=4```

```m:a=3,b=4```

```m:a=4,b=8```

```f:a=3,b=8```

解説











# 外部変数

・ほかのブロックや関数、ファイルにある変数を使うときの宣言。

・```extern int i```
のように宣言するが、実体はどこかほかのブロックや関数、ファイルにある。

・複数の負関数やファイルで共通の名前で変数を共有したい時につかう。

・同じ名前で変数をブロック内で定義するとそちらが優先される。

# グローバルとローカル

・関数の{}の外側で定義
　・グローバル変数になる。
 
  ・確保したところ以降は関数の外でもなかでもどこからでも使える。
 
・関数の{}内部で定義

　・ローカル変数になる。　
 
  ・その関数やブロック内でのみ有効。

# 変数の有効範囲（スコープ）

・extern：実体がほかの場所にあることを示す　

・static：有効範囲を書いている部分に限定し、ほかのファイル等には見せないようにする。

　→値は保持され続ける。

例
File1.c
```c
#include <stdio.h>
int func(int);

int main(void){
int a,b;
printf("Input a¥n");
scanf("%d", &a);
b = func(a);//1回目の呼び出し
//return bなので、b=4となる。
printf("m:a=%d , b=%d¥n", a, b);//a=3,b=4が出力される。
b = func(a);//2回目の呼び出し//
//1回目と何も変われないため、出力も同じになる。
printf("m:a=%d , b=%d¥n", a, b);
return 0;
}
```

File2.c

```c
#include <stdio.h>
int func(int a){
int b = 0; //呼び出されるたびに、b=0となる。
a = a + 1;
b = a + b;
printf("f:a=%d , b=%d¥n", a, b);
//1回目の呼び出し：a=3→a=4,b=4,よってf:a=4,b=4が出力される。
//2回目の呼び出し
return b;
}
```
コンパイルする際は```gcc -o exe File1.c File2.c```
のようにする。

同時コンパイルすことで、リンクされる。

結果

![image](https://user-images.githubusercontent.com/82156802/141288993-18dcf86a-a1d6-458c-a6ec-1d125d1fa59b.png)

解説

# コンパイルとリンクを分ける。

# マクロ

修正が必要になったら→全部直す必要がある。

マクロの定義

```#define NUM 5```

 ・ファイルの中にNUMが出てきたら「5」と置き換える。
 
 ```#define SUM(s+y)```
 
 　・ファイルの中にSUM(a,b)と型出てきたら、(a+b)に置き換える。
 マクロを使うと以下のようなことが出来る。

main.c

```c
#inculed<stdio.h>
#inculed "head.h"
THIS IS A PEN
```

head.h

```
#define THIS int
#define IS main(void){puts("THIS IS A PEN");
#define A return 
#define PEN 0;}
```
# Makefile

コンパイルの際に
```gcc -c Filename.c```
とすると、```Filename.exe```
という実行ファイルが作成される。

必要なファイルだけがコンパイルされその後、リンクされる。
