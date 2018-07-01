#include "bTree.h"
#include <stdlib.h>

int _index;
typedef struct BitNode{
    int data;
    struct BitNode* left;
    struct BitNode* right;
    int ltag;
    int rtag;
}BitNode;

BitNode* create(int data[],int length, BitNode* pre){
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
    p->ltag = 0;
    p->rtag = 0;
    p->left = create(data, length, pre);
    p->right = create(data, length, pre);
    return p;
}

void NLR_read(BitNode* t){
    if(t == NULL){
        return ;
    }
    printf("data:%d\n", t->data);
    NLR_read(t->left);
    NLR_read(t->right);
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
    printf("data:%d,ltag:%d,rtag:%d\n", t->data, t->ltag, t->rtag);
}

int get_high(BitNode* t){
    int left_high = 0;
    int right_high = 0;
    if(t->left != NULL){
        left_high = get_high(t->left);
    }
    if(t->right != NULL){
        right_high = get_high(t->right);
    }
    
    int high = left_high > right_high ? left_high : right_high;
    return high + 1;
}

BitNode* pre = NULL;
void set_index(BitNode* t){
    if(t == NULL){
        return ;
    }
    set_index(t->left);
    if(t->left == NULL){
        t->ltag = 1;
        t->left = pre;
    }
    
    if(pre!=NULL&&pre->right == NULL){
        pre->rtag = 1;
        pre->right = t;
    }
    pre = t;
    set_index(t->right);
}

void read_index(BitNode* t){
    if(t == NULL){
        return ;
    }
    
    if(t->ltag == 0){
        read_index(t->left);
    }
    
    printf("data:%d,ltag:%d,rtag:%d,next_data:%d\n", t->data, t->ltag, t->rtag,
           t->right == NULL || t->rtag == 0 ? -1 : t->right->data);
    
    if(t->rtag == 0){
        read_index(t->right);
    }
}

void bTree(){
    _index = -1;
    int data[] = {1, 2, 0, 3, 0, 0, 4, 5};
    int length = sizeof(data)/sizeof(int);
    BitNode* t = NULL;
    t = create(data, length, t);
//    printf("NLR:\n");
//    NLR_read(t);
//    printf("LNR:\n");
//    LNR_read(t);
//    printf("LRN:\n");
//    LRN_read(t);
//    int high = get_high(t);
//    printf("max length:%d\n", high);
//    pre = t;
    set_index(t);
    read_index(t);
}
