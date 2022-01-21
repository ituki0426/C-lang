# ポインタで気を付けること

## 2次元配列を1次元的に扱う

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
## 2次元配列のポインタ渡し(1次元的に扱う)

```c
#include<stdio.h>
int Print_array(int (*p)[3]){
   int *q=(int *)p;//1次元配列に落としている
   for(int i=0;i<9;i++){
   	printf("%d\n",q[i]);
   }
}
int main(void){
   int array[3][3]={{0,1,2},{3,4,5},{6,7,8}};
   Print_array(array);
}
```
以下のようにして値を書き換えることもできる。
```c
#include<stdio.h>
int Change_array(int (*p)[3]){
   int *q=(int *)p;
   for(int i=0;i<9;i++){
   	q[i]=0;//キャストしたポインタ変数を用いて値を書き換えている。
   }
}
int main(void){
   int array[3][3]={{0,1,2},{3,4,5},{6,7,8}};
   int *q=(int *)array;
   Change_array(array);
   for(int i=0;i<8;i++){
   	printf("%d\n",q[i]);
   }
}
```
## 2次元配列のポインタ渡し(2次元的に扱う)

気を付けることは、2次元配列のポインタのメンバへのアクセスである。

*(*(s+i)+j)=s[i][j]

iは大きい塊の要素数={}の数

jは小さい塊の中の要素数={}の中の「,」の数

 int s[3][2]={{1,2},{3,4},{5,6}};
 
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
int f(int (*p)[2]);
int main(void){
    int s[3][2]={{1,2},{3,4},{5,6}};
    int i,j,*t;
    t = &s[0][0];
    f(s);
    printf("\n");
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("s[%d][%d]=%d,%d\n",i,j,s[i][j],*(*(s+i)+j));//
            }
            printf("\n");
            }
            return 0;
                }

int f(int (*p)[2]){
    int i,j,*q;
    q = (int *)p;
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            printf("*(*(p+%d)+%d)=%d\n",i,j,*(*(p+i)+j));}
            }
            return 0;
}
```
結果
```
*(*(p+0)+0)=1
*(*(p+0)+1)=2
*(*(p+1)+0)=3
*(*(p+1)+1)=4
*(*(p+2)+0)=5
*(*(p+2)+1)=6
```
## *で値を変えるとき。

値を参照している側の値も変わる。

```c
#include <stdio.h>
int main(void){
    int a, b;
    int *pa, *pb;
    a = 100; b = 25;
    pa = &a; pb = &b;
    printf("%d \n", *pa);
    printf("%d \n", *pb);
    *pa = a + b; //aの値も125になる
    *pb = a + b; //bの値も150になる
    printf("%d \n", *pa);//125
    printf("%d \n", *pb);//150
    return 0;
}
```

# 構造体で気を付けること

## 構造体配列のメンバへのアクセス

```c
int show_member(MEMBER *pM);
 (pM+i)->avg //
 (*(pM+i)).avg //
```

# ファイル入力出力で気を付けること
