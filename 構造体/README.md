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

