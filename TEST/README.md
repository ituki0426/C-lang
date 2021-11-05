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
