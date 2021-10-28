# typdef

typedfを用いると、既に定義されている型に、別の新しい名前を付けて定義することが出来る。

```typdef　定義されている型 定義する新しい型名;```

```c
typedef int * intPtr_t;

/* intPtr_t 型を引数にとり intPtr_t 型を戻り値とする関数 */
/* p のポインタ値を 3 だけ進めたポインタ値を返す */
intPtr_t foo(intPtr_t p)     
{
    return p + 3;
}

main()
{
    int a[10];
    intPtr_t p;           /* intPtr_t 型の変数宣言 */
    
    p = foo(a);           /* p の値は a[3] を指すポインタ値 */
    printf("%d",p);
}

```

結果

intPtr_tには整数型の値が入っているメモリのアドレスを格納することが出来る。

