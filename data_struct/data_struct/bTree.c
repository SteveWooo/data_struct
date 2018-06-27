#include "bTree.h"
#include <stdlib.h>

int _index;
typedef struct BitNode{
    int data;
    struct BitNode* left;
    struct BitNode* right;
}BitNode;

void NLR_read(BitNode* t){
    if(t == NULL){
        return ;
    }
    printf("data:%d\n", t->data);
    NLR_read(t->left);
    NLR_read(t->right);
}

BitNode* create(int data[],int length){
    BitNode* p;
    _index ++;
    if(_index >= length){
        p = NULL;
        return p;
    }
    if(data[_index] == 0){
        p = NULL;
        return p;
    }
    
    p = (BitNode*)malloc(sizeof(BitNode));
    p->data = data[_index];
    p->left = create(data, length);
    p->right = create(data, length);
    return p;
}

void LNR_read(BitNode* t){
    if(t == NULL){
        return ;
    }
    LNR_read(t->left);
    printf("data:%d\n", t->data);
    LNR_read(t->right);
}

void LRN_read(BitNode* t){
    if(t == NULL){
        return ;
    }
    LRN_read(t->left);
    LRN_read(t->right);
    printf("data:%d\n", t->data);
}

void test(){
    _index = -1;
    int data[] = {1, 2, 0, 3, 0, 0, 4, 5};
    int length = sizeof(data)/sizeof(int);
    BitNode* t = NULL;
    t = create(data, length);
    printf("NLR:\n");
    NLR_read(t);
    printf("LNR:\n");
    LNR_read(t);
    printf("LRN:\n");
    LRN_read(t);
}
