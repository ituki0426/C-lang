# 構造体の使い方

構造体を使うには、構造体の型枠の宣言、その型枠を持つ構造体変数の宣言、この二つのプロセスを踏む必要がある。
```struct 構造体タグ名 {メンバの並び} /*型枠の宣言*/```

```struct 構造体タグ名 構造体変数名 /*構造体変数の宣言*/```

具体的な例

```c
#include<stdio.h>
struct _person /*_psersonが構造体タグ名*/
{
	char name[20];
	char sex;
	int age;
	double height;
	double weight;
};

struct _person p; /*pという名前のstruc _person型変数を宣言*/
```

また、typdefを使ことで以下のように書くことが出来る。

```c
#include<stdio.h>
struct _person /*_psersonが構造体タグ名*/
{
	char name[20];
	char sex;
	int age;
	double height;
	double weight;
};
typedef struct _person person_t;
person_t p; /*pという名前のstruct_person型を宣言*/
```

上のように、typdefを用いて新しい型名を定義するのならば、初めから次のように書いてもよい。また、この場合には、構造体タグ名は必要ではない。

```c
typedef struct {         /* 構造体の型枠を定義して，同時にそれを型名 person_t として定義する */
    char name[20];
    char sex;
    int age;
    double height; 
    double weight; 
} person_t;

person_t p;             /* 変数名 p の person_t 型変数を宣言 */
```

# 初期値設定

構造体の変数を宣言するのと同時に、その各メンバの初期値を設定することが出来る。

```c
person_t p = {"Tom", 'M', 20, 175.2, 66.5};
```

# メンバ参照

構造体変数の中にあるメンバを参照（アクセス）するには、変数名の後に""(ピリオド)に続言えてメンバ名を付ける。

例えば、先程のpという変数内のageを参照するには```p.age```
とする。

```c
typedef struct {
    ....
    int age;              /* 構造体のメンバの一つ */
    ....
} person_t;

int main()
{
    person_t p;           /* person_t 型変数 p の宣言 */

    p.age = 30;         /* p 内のメンバ age に 30 を代入 */
    
    ....
```

サンプルプログラム1

```c
```

# 構造体の代入

一つの構造体変数の内容前部を同じ型の別の構造体変数に、通常の変数を代入するのと同じように、代入することが出来る。

```c
person_t p1 = {"Tom", 'M', 19, 175.2, 69.5};
    person_t p2;
    
    p2 = p1;
```

____________________________________________________________________________________________________________________________

```c
#include <stdio.h>

typedef struct {   
    char name[20];
    char sex; 
    int age;
    double height; 
    double weight; 
} person_t;

main()
{
    person_t p1 = {"Tom", 'M', 19, 175.2, 69.5};
    person_t p2;
    
    p2 = p1;         /* 構造体の代入 */
    
    printf("%s %c %d %f %f\n", p2.name, p2.sex, p2.age, p2.height, p2.weight);

    return 0;
}
```
# メンバ参照（間接参照）

構造体を扱うときに、構造体変数を直接扱うのではなく、構造体変数へのポインタを介して、間接的にに扱うことがある。

この時、演算子```->```
を使う。

構文：```構造体を指すポインタ -> 構造体のメンバ名```

このように書いた場合、それは次のように書くのと同等である。
      
      ```(* 構造体を指すポインタ).構造体のメンバ名```
 
例

```c
person_t p;        /* 構造体 person_t 型変数の宣言 */
person_t * pp;     /* person_t 型を指すポインタ型の変数の宣言 */

pp = &p;           /* pp に p のアドレスを入れる */
pp -> age = 45;    /* pp が指す構造体のメンバ age に 45 を代入 */
```

# 引数に構造体を持つ関数

_______________________________________________________________________________________________________________________

https://programming.pc-note.net/c/struct2.html

関数の引数には、構造体を指定することもできる。

```c
#include <stdio.h>

typedef struct
{
    char name[50];
    int age;
    char gender;
} Person;

void PrintPerson(Person p)
{
    printf("name: %s\n", p.name);
    printf("age: %d\n", p.age);
    printf("gender: %d\n", p.gender);
}

int main()
{
    Person person[] = {
        { "A山B男", 20, 0 },
        { "C下D太", 18, 0 },
        { "E田F子", 21, 1 },
        { "G山H美", 19, 1 },
    };
    PrintPerson(person[2]);

    getchar();
}
```

関数の仮引数へは、実引数（呼び出し元）に指定した値がコピーされます。

これは構造体であっても同じです。

そのため、関数内で構造体のメンバ変数を書き換えても呼び出し元の構造体変数には影響はありません

```c
#include <stdio.h>

typedef struct
{
    char name[50];
    int age;
    char gender;
} Person;

void PrintPerson(Person p)
{
    p.age = 30;
    printf("name: %s\n", p.name);
    printf("age: %d\n", p.age); //30
    printf("gender: %d\n", p.gender);
}

int main()
{
    Person person = { "A山B男", 20, 0 };
    PrintPerson(person);

    printf("\nage: %d", person.age); //20
    getchar();
}
```

# 構造体を返す関数

配列は関数の戻り値にはできませんが、構造体はそれが可能です。

```c
#include <stdio.h>
#include <string.h>

#define NAME_LENGTH 50

typedef struct
{
    char name[NAME_LENGTH];
    int age;
    char gender;
} Person;

Person CreatePerson(char *name, int age, char gender)
{
    Person p = { "", age, gender };
    strcpy_s(p.name, NAME_LENGTH, name);
    return p;
}

int main()
{
    Person person;
    person = CreatePerson("A山B男", 20, 0);

    printf("name: %s\n", person.name);
    printf("age: %d\n", person.age);
    printf("gender: %d\n", person.gender);

    getchar();
}
```
https://programming.pc-note.net/c/struct3.html

# 構造体のポインタ渡し

