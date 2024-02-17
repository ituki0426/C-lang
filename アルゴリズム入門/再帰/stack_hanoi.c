// スタックを用いたハノイの塔の再帰的解法
#include <stdio.h>
void hanoi(int, int, int, int);
void move(int, int, int);

int pie[20][3];  // 20:円盤の最大枚数,3:柱の数
int sp[3], N;

void main(void) {
    int i;
    printf("円盤の枚数を入力してください: ");
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        pie[i][0] = N - i;
        pie[i][1] = pie[i][2] = 0;
    }
    sp[0] = N;
    sp[1] = sp[2] = 0;
    hanoi(N, 0, 1, 2);
}   

void hanoi(int n, int a, int b, int c) {
    if (n > 0) {
        hanoi(n - 1, a, c, b);
        move(n, a, b);
        hanoi(n - 1, c, b, a);
    }
}
void move(int n, int s, int d) {
    pie[sp[d]][d] = pie[sp[s] - 1][s];
    sp[d]++;
    sp[s]--;
    printf("円盤 %d を %c から %c に移動\n", pie[sp[d] - 1][d], 'a' + s,
           'a' + d);
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            if (i < sp[j])
                printf("%d ", pie[i][j]);
            else
                printf("  ");
        }
        printf("\n");
    }
    printf("\n a b c\n");
}