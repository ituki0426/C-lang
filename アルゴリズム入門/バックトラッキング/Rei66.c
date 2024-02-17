/*
------------------------
Nクイーン問題
------------------------
*/
#include <stdio.h>
#define N 8
int column[N+1]; // 同じ欄に王妃がいるかどうか
int rup[2*N+1]; // 右上がりの対角線に王妃がいるかどうか
int lup[2*N+1]; // 左上がりの対角線に王妃がいるかどうか
int queen[N+1]; // 王妃の位置

void backtrack(int);

void main(void){
    for(int i = 1; i <= N; i++){
        column[i] = 1;
    }
    for(int i = 1; i <= 2*N; i++){
        rup[i] = lup[i] = 1;
    }
    backtrack(1);
}

void backtrack(int i){
    int j,x,y;
    static int num = 0;
    if(i > N){
        printf("\n解 %d\n", ++num);
        for(y = 1; y <= N; y++){
            for(x = 1; x <= N; x++){
                if(queen[i] == y){
                    printf("Q");
                }else{
                    printf(".");
                }
            }
            printf("\n");
        }
    }else{
        for(j = 1; j <= N; j++){
            if(column[j] == 1 && rup[i+j] == 1 && lup[i-j+N] == 1){
                queen[i] = j;
                column[j] = rup[i+j] = lup[i-j+N] = 0;
                backtrack(i+1);
                column[j] = rup[i+j] = lup[i-j+N] = 1;
            }
        }
    }
}