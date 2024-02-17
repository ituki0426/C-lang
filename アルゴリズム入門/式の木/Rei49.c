#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tnode{
    struct tnode *left;
    char ope;
    struct tnode *right;
};
struct tnode *talloc(void);
struct tnode *gentree(struct tnode *, char *);

struct tnode *gentree(struct tnode *p, char *w){
    int n;
    n = strlen(w);
    p = talloc();
    if('0' <= w[n-1] && w[n-1] <= '9')
        p-> ope = w[n-1] - '0';
    else 
        p->ope = w[n-1];
    w[n-1] = '\0';
    if(!(p->ope == '+' || p->ope == '-' || p->ope == '*' || p->ope == '/')){
        p->right = NULL;
        p->left = NULL;
    }else{
        p->right = gentree(p->right, w);
        p->left = gentree(p->left, w);
    }
}
void postfix(struct tnode *p){
    if(p != NULL){
        postfix(p->left);
        postfix(p->right);
        printf("%c", p->ope);
        switch (p->ope)
        {
        case '+':
            p -> ope = p->left->ope + p->right->ope;
            break;
        case '-':
            p -> ope = p->left->ope - p->right->ope;
            break;
        case '*':
            p -> ope = p->left->ope * p->right->ope;
            break;
        case '/':
            p -> ope = p->left->ope / p->right->ope;
            break;
        default:
            break;
        }
    }
}
struct tnode *talloc(void){
    return (struct tnode *)malloc(sizeof(struct tnode));
}