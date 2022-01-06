# 配列全体へのポインタとは？

アドレス演算子を使用した場合```&a```
で生成されるのは配列全体へのポインタである。

では配列全体へのポインタとは何か？

例
```c
int a[5];
```

この時の```a```
と
```&a```
の違い。

結論

アドレスそのものは```a```と書いたとき（先頭配列へのポインタ）と変わらないが、型が異なる。

・```a```=```int *```//(```int```型の配列へのポインタ。要素がいくつあるかはわからない)

・```&a```=```int (*)[5]``` (```int```が5つの配列へのポインタ)//つまり、より細かく指定される。

 # 配列へのポインタ
 
 宣言
 
 ```data_type (*var_name)[size_of_array];```
 
 例
 
 ```int (*ptr)[5];```
 
 この時、ptrは整数の要素を5個持つ配列へのポインタとなる。
 
 この時、以下のようにするとエラーが発生する。
 
 ```c
 int a[5]={1,2,3,4,5}
 int (*ptr)[5];
 ptr=a;//エラー
 ```
 
 理由としては、```int (*ptr)[5];```では、int型の要素を5つもつ配列だと宣言しているのに、ただ```ptr=a```と書くと、```a```はint型のポインタへの配列であるということしか示さない。
 
 よって、型が違うためエラーが発生する。
 
 そこで先ほど説明した、配列全体へのポインタ```&a```を用いて以下のように書く。
 
 ```c
 int a[5]={1,2,3,4,5}
 int (*ptr)[5];
 ptr=&a;//成功
 ```
 
 値にアクセスするには？
 
 以下のようにする。
 
 ```*(q)[i]```
 
 こうすることで先頭からi番目の要素にアクセスることが出来る。
 
 例
 
 ```c
 #include<stdio.h>
int main(void){
 int a[5]={1,2,3,4,5};
 int(*ptr)[5];
 ptr=&a;
 for(int i=0;i<5;i++){
	 printf("(*ptr)[%d]=%d\n",i,(*ptr)[i]);
 }
}
 ```
 結果
 ```
(*ptr)[0]=1
(*ptr)[1]=2
(*ptr)[2]=3
(*ptr)[3]=4
(*ptr)[4]=5
 ```
 # 2次元配列とポインタ
 
 ```c
 #include<stdio.h>
int main(void){
	int s[3][2]={{1,2},{3,4},{5,6}};
	int i,j,*t;
	t=&s[0][0];
	f(s);
	printf("\n");
	for(j=0;j<6;j++){
	 printf("t[%d]=%d\n",j,t[j]);
	}
}
 ```
 結果
 ```
 t[0]=1
t[1]=2
t[2]=3
t[3]=4
t[4]=5
t[5]=6
 ```
 理由
 ポインタ変数tはint型である。よって、配列として扱うと、数字が一つ上がるごとに4バイト先のアドレスのデータにアクセスする。
 
 また、上の結果からもわかるように2次元配列はメモリ上に直列に存在する。
 
 上記は下の結果からも確認できる。
 
 ```c
 #include<stdio.h>
int main(void){
	int s[3][2]={{1,2},{3,4},{5,6}};
	int i,j,*t;
	t=&s[0][0];
	printf("\n");
	for(j=0;j<6;j++){
	 printf("t[%d]=%d\n",j,t[j]);
	}
	for(j=0;j<6;j++){
	 printf("&t[%d]=%u\n",j,&t[j]);
	}
}

 ```
 
 結果
 ```
 t[0]=1
t[1]=2
t[2]=3
t[3]=4
t[4]=5
t[5]=6
&t[0]=6422000
&t[1]=6422004
&t[2]=6422008
&t[3]=6422012
&t[4]=6422016
&t[5]=6422020
 ```
 # 間接演算子と添え字演算子
 
 以下のように宣言する。
 
 ```c
 int a[5];
 int *p;
 p=a;
 ```
 
 以下の式はすべて、先頭からi個後ろの要素を表す。
 ```a[i]```
 ```a[i]```
 ```a[i]```
 ```a[i]```
 
 また、以下の式はすべて、先頭からi個後ろの要素へのポインタ。
 
 また、p+1の意味とは？
 
 結論
 
 pはint型で定義してる。よって、+1すると1*4で+4byte先のアドレスを指す。よって、配列の次の要素にアクセスすることが出来る。
 
 
 # アドレス演算
 ```c
 #include<stdio.h>
int main(void){
	int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	int (*q)[2];//配列へのポインタ
	int (*f)[3];
	int *R;
	f=a;
	R=a;
	q=a;
	printf("a=%d \nq+1=%d\nR+1=%d\n",a,q+1,R+1);
	//qはintの2型なので、+1すると4×2bit、つまり、8bit先に進む。
	//Rはただのint型なので4bitのみ進む。
	printf("*R=%d\n",*R);
	printf("*(R+1)%d\n",*(R+1));
	printf("*(R+2)=%d\n",*(R+2));
	printf("*(R+3)=%d\n",*(R+3));
	printf("*(R+4)=%d\n",*(R+4));
	printf("*(R+5)=%d\n",*(R+5));
	printf("*(R+6)=%d\n",*(R+6));
	printf("*(q)[0]=%d\n",*(q)[0]);//1、q[0]=q+0、
	printf("*(q)[1]=%d\n",*(q)[1]);//3、q[1]=q+1、
	printf("*(q)[2]=%d\n",*(q)[2]);//5、q[2]=q+2、
	printf("*(q)[2]=%d\n",*(q)[3]);//7、q[3]=q+3
	printf("*(f)[0]%d\n",*(f)[0]);//1、f[0]=f+0
	printf("*(f)[1]=%d\n",*(f)[1]);//4、f[1]=f+1→f+(2*1)バイト先の要素つまり、先頭から4個先の要素
	printf("*(f)[2]=%d\n",*(f)[2]);//7、f[2]=f+2→f+(2*3)バイト先の要素つまり、先頭から6個先の要素

}
 ```
 ```
a=6421984 
q+1=6421992
R+1=6421988
*R=1
*(R+1)2
*(R+2)=3
*(R+3)=4
*(R+4)=5
*(R+5)=6
*(R+6)=7
*(q)[0]=1
*(q)[1]=3
*(q)[2]=5
*(q)[3]=7
*(f)[0]1
*(f)[1]=4
*(f)[2]=7
 ```
 
# 配列のポインタ

宣言

```data_type *arrar_name[array_size];```

例
```c
int *arr[5];
```

ここで```arr```は5つの整数ポインタの配列です。

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
結果
```
```

# ポインタへの配列とポインタ配列の違い

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

結果
```
p = 0x0061FF04, ptr = 0x0061FF04
p = 0x0061FF08, ptr = 0x0061FF18
```
pの型がint型のポインタであるのに対し、ptrの型はint型の要素を5つもつ配列へのポインタである。

ポインタ演算は、ポインタ変数の型のサイズに対して実行される。

よって、```ptr++```と書くと5×4で20バイト前方にシフトされる。

また、```p++```
と書くと4×1で4バイト前方にシフトする。
# 文字列と配列

# ポインタと文字列

ポインタを利用すれば、文字列は便利に扱うことが出来る。

```c
#include <stdio.h>

int main()
{
    char str[] = "ABCD";
    //char str[] = { 'A', 'B', 'C', 'D', '\0' };
    
    char *strP = "EFGH";

    printf("%s\n", str); //ABCD
    printf("%s\n", strP); //EFGH

    getchar();
}
```

文字列リテラルは、プログラムの実行開始かメモリ上に存在する　上に存在する。配列の初期値に文字列リテラルを指定すると、その文字列分の長さ（プラスNULL文字）のサイズを持つ配列が自動で生成され、そこに一文字ずつ値がコピーされる。

![image](https://programming.pc-note.net/images/c/pointer4_1.png)

8行目のコード
```char *strP = "EFGH";```
に着目する。

文字列リテラルを評価すると、その文字列リテラルの先頭アドレス（char型のポインタ）が返ってくる。

![image](https://programming.pc-note.net/images/c/pointer4_2.png)

・文字列のポインタのメリット

配列にはない便利な点として、代入だけで文字列を別の文字列に変更できる点。

```c
char str[] = "ABCD";
char *strP = "EFGH";
char *strP2;

//これはNG
str = "IJKL";

//これはOK
strP = "IJKLMNOPQRSTU";

//これもOK
strP2 = strP;
```

・文字列のポインタのデメリット

C言語では文字列リテラルは書き換えてはならないというルールがある。

よって。文字を置き換えることはできない。

```c
char str[] = "ABCD";
char *strP = "EFGH";

//これはOK
str[1] = 'Z';

//これはNG
strP[1] = 'Z';

//こうやってもNG
*(strP + 1) = 'Z';
```

文字配列の時は、5行目のように文字列を書き換えることが出来る。配列は、文字列リテラルとは別の場所に領域を確保し、そこに値を保存しているから書き換えても問題はない。

しかし、ポインタが指し示すのは文字列リテラル自身です。文字列リテラルは書き換えてはならないというルールがあるため、8、11行目のような記述はできない。


# 2次元配列の要素へのアクセスの方法

```a[i][j] == *( a[i] + j ) == *( *(a+i) + j )```

理由

![image](https://www.asahi-net.or.jp/~UC3K-YMD/Lesson/Section02/matrix02.gif)

添え字が1つだけの```a[i]```
は配列名を意味する。よって各行の先頭アドレスを示す。

すると配列を次のように書き表すことが出来る。

```a[i][j]```
は```*(a[i]+j)```
と等しい。

よそa[i][j]は、その行の先頭アドレスa[i]からjだけ後ろの位置にある。そして、アドレス(a[i]+j)の内容は間接演算子を用いて```*(a[i]+j)```
で参照できる。

さらに配列a[i]は、```*(a+i)```
と書けるので、次のような等式が成り立つ。

```a[i][j] == *( a[i] + j ) == *( *(a+i) + j )```

また、2次元配列とアドレスアドレスの関係は以下のようになる。
	
| 配列名 | 配列の先頭要素のアドレス |
| :--- | :---: | 
| 配列名[行] | 行の先頭要素のアドレス |
| 配列名[行][列]　|　配列要素の値　| 

# 1次元配列を渡す

```c
#include <stdio.h>
//Size of the created array
#define ARRAY_SIZE  5
//Function to read array element
void ReadArray(int *paData)
{
    int index = 0;
    for(index= 0; index < ARRAY_SIZE; ++index)
    {
        printf("%d\n",paData[index]);
    }
}
int main(int argc, char *argv[])
{
    //Create an array
    int aiData[ARRAY_SIZE] = {1,2,3,4,5};
    //Pass array as a parameter
    ReadArray(aiData);
    return 0;
}
```

# 2次元配列を渡す

```c
#include <stdio.h>
//Size of the created array
#define ARRAY_ROW      3
#define ARRAY_COL      3
void ReadArray(int(*piData)[ARRAY_COL])
{
    int iRow = 0;
    int iCol = 0;
    for (iRow = 0; iRow < ARRAY_ROW; ++iRow)
    {
        for (iCol = 0; iCol < ARRAY_COL; ++iCol)
        {
            printf("%d\n", piData[iRow][iCol]);
        }
    }
}
int main(int argc, char *argv[])
{
    //Create an 2D array
    int aiData[ARRAY_ROW][ARRAY_COL] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    //Pass array as a parameter
    ReadArray(aiData);
    return 0;
}
```

```c
#include <stdio.h>
//Size of the created array
#define ARRAY_ROW      3
#define ARRAY_COL      3
void ReadArray(int(*piData)[ARRAY_ROW][ARRAY_COL])
{
    int iRow = 0;
    int iCol = 0;
    for (iRow = 0; iRow < ARRAY_ROW; ++iRow)
    {
        for (iCol = 0; iCol < ARRAY_COL; ++iCol)
        {
            printf("%d\n", (*piData)[iRow][iCol]);
        }
    }
}
int main(int argc, char *argv[])
{
    //Create an 2D array
    int aiData[ARRAY_ROW][ARRAY_COL] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    //Pass array as a parameter
    ReadArray(&aiData);
    return 0;
}
```

```c
#include <stdio.h>
int f(int [][]);
int main(void){
int s[3][2]={{1,2},{3,4},{5,6}};
int i,j,*t;
t = &s[0][0];
f(s);
printf("¥n");
for(i=0;i<3;i++){
for(j=0;j<2;j++){
printf("s[%d][%d]=%d,%d¥t",
i,j,s[i][j],*(*(s+i)+j));
}
printf("¥n");
}
for(i=0;i<6;i++){
printf("t[%d]=%d¥t",i,t[i]);
}
printf("¥n");
return 0;
}

int f(int (*p)[2]){
int i,j,*q;
q = (int *)p;
for(i=0;i<2;i++){
for(j=0;j<3;j++){
printf("*(*(p+%d)+%d)=%d¥t",i,j,
*(*(p+i)+j));
}
printf("¥n");
}
for(i=0;i<6;i++){
printf("*(q+%d)=%d¥t",i,(q+i));
}
return 0;
}
```
# 構造体のポインタ渡し

構造体は、そのまま関数の引数にして渡すことが出来る。

この場合、関数に渡されるのは構造体変数をコピーしたものです。

```c
#include <stdio.h>

#define NAME_LENGTH 50

typedef struct
{
    char name[NAME_LENGTH];
    int age;
    char gender;
} Person;

void PrintPerson(Person *p)
{
    printf("name: %s\n", (*p).name);
    printf("age: %d\n", (*p).age);
    printf("gender: %d\n", (*p).gender);
}

int main()
{
    Person person = { "A山B男", 20, 0 };
    PrintPerson(&person);

    getchar();
}
```

関数内で構造体のポインタ変数にアクセスするには、丸括弧でポインタ変数をかこったうえでアドレス演算子を記述する。

```c
//メンバ変数にアクセス
(*p).name

//これはNG
*p.name

//↑はこのような意味になってしまう
*(p.name)
```

・アロー演算子

メンバ変数にアクセスするたびに上記のように書くのは面倒なので、別の記述方法が用意されている；

```c
#include <stdio.h>

#define NAME_LENGTH 50

typedef struct
{
    char name[NAME_LENGTH];
    int age;
    char gender;
} Person;

void PrintPerson(Person *p)
{
    printf("name: %s\n", p->name);
    printf("age: %d\n", p->age);
    printf("gender: %d\n", p->gender);
}

int main()
{
    Person person = { "A山B男", 20, 0 };
    PrintPerson(&person);

    getchar();
}

```

