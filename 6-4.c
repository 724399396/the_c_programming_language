#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 1000

struct tnode {
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

int getword(char *, int);
struct tnode *addtree(struct tnode *, char *);
struct tnode *descorder(struct tnode *,struct tnode *);
struct tnode *foreach(struct tnode *);
void treeprint(struct tnode *);
struct tnode *talloc();
char *mystrdup(char *);

int main(int argc, char *argv[]) {
    struct tnode *root, *desc;
    char word[MAXWORD];
    int lim;

    if (argc != 2)
        lim = 6;
    else
        lim = atoi(argv[1]);
    
    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (strlen(word) > lim)
            word[lim] = '\0';
        if (isalpha(word[0]))
            root = addtree(root, word);
    }
    
    desc = foreach(root);
    treeprint(root);
    return 0;
}

struct tnode *addtree(struct tnode *p, char *word) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = mystrdup(word);
        p->count = 1;
        p->left = p->right = NULL;
    } else {
        if ((cond = strcmp(word, p->word)) < 0)
            p->left = addtree(p->left, word);
        else if (cond > 0)
            p->right = addtree(p->right, word);
        else
            p->count++;
    }
    return p;             
}

void treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

struct tnode *talloc() {
    struct tnode *p;

    p = (struct tnode *) malloc(sizeof (struct tnode));
    return p;
}

char *mystrdup(char *s) {
    char *p;
    
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}

struct tnode *foreach(struct tnode *src) {
    struct tnode *des = NULL;
    if (src == NULL)
        return des;
    des = foreach(src->left);
    des = descorder(src, des);
    des = foreach(src->right);
    
    return des;
}

struct tnode *descorder(struct tnode *src,struct tnode *des) {    
    if (src == NULL)
        return des;
    
    if (des == NULL) {
        des = talloc();
        des->word = mystrdup(src->word);
        des->count = src->count;
        des->left = des->right = NULL;
    } else {
        if (src->count < des->count)
            des->left = descorder(src, des->left);
        else if (src->count >= des->count)
            des->right = descorder(src, des->right);
    }        
    return des;
}
