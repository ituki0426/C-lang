# 配列へのポインタとは？


1次元配列へのポインタの宣言


```data_type （* var_name ）[ size_of_array ] ; ```


例
```c
int （* ptr ）[ 5 ] ; 
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

ポインタへの配列にアドレスを格納する場合は「&array_name」とする。

また、格納されている値にアクセスするには、
```(*array_name)[i]```

とする。


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
