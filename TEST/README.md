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

 (pM+i)->avg = (*(pM+i)).avg 
 

## 構造体のリスト
```c
```c
 #include <stdio.h>
#define NUM 3
typedef struct Member {    /*Member は省略できる*/
	double avg;
	int hr;
    struct Member *next;
} MEMBER;
int show_list(MEMBER *start, char *str);

int main(void){
  MEMBER team[NUM],*pT;
  team[0].next=&team[1];
  team[1].next=&team[2];
  team[2].next=NULL;
  team[0].avg = 0.275;	team[0].hr = 14;
  team[1].avg = 0.288;	team[1].hr = 21;
  team[2].avg = 0.305;	team[2].hr = 29;
  show_list(team, "HOME"); 
  return 0;
}

int show_list(MEMBER *start, char *str){
    MEMBER *pT;
    printf("--- %s ---\n", str);
    for(pT=start; pT->next != NULL;pT=pT->next){
        printf("avg %5.3f : HR %d\n",pT->avg, pT->hr);
        }
        printf("avg %5.3f : HR %d \n", pT->avg, pT->hr);
        return 0;
}
 ```

# ファイル入力出力で気を付けること
## 1.ファイルを開く
```fopen()```
を使う

例
```c
FILE *fp1; //オープンしたファイルを参照するポインタ(ファイルポインタ)
fp1=fopen("text.txt","w");//第1引数にはファイル名、第2引数にはオープンモードを入れる。
fclose(fp1);
```

## 2.オープンモード
"r" : 読み出し専用

"w" : 書き込み専用

"a": 追加書き込み専用

## 2.ファイルに書き込む(出力)

fputs():文字列を1行出力する。

```c
```
fprintf():文字列を書式付きで出力する。
```c
```
fputc():ファイルに文字を1文字出力する。
```c
```

## 3.ファイルに書き込む(出力)

fgets():ファイルから1行入力する

fscanf():ファイルから書式付きで入力する

fgetc():ファイルから1文字入力する


## 注意点

・fscanf()はスペースは区切りの文字として読み飛ばすので、空白をデータとして読み込ませたければ、fgets()を使う

・fgetsの第2引数で、文字数を指定することが出来る。

```c
#include<stdio.h>
int main(void){
    FILE *fp;
    char str[10];
    fp=fopen("file.txt","r");
    fgets(str,3,fp);
    printf("%s",str);
    fclose(fp);
}
```
