#include "bsTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct BsNode{
    int data;
    struct BsNode* left;
    struct BsNode* right;
    int heigh;
}BsNode;
int getHeight(BsNode*);
BsNode* create_bsnode(int data){
    BsNode* p = (BsNode*)malloc(sizeof(BsNode));
    p->data = data;
    p->heigh = 0;
    p->left = NULL;
    p->right = NULL;
    return p;
}

BsNode* rotateLeft(BsNode *p){
    BsNode* temp;
    temp = p->left;
    p->left = temp->right;
    temp->right = p;
    
    p->heigh = getHeight(p->left) > getHeight(p->right) ?
        getHeight(p->left) + 1 : getHeight(p->right) + 1;
    
    temp->heigh = getHeight(temp->left) > p->heigh ?
        getHeight(temp->left) + 1 : p->heigh + 1;
    return temp;
}

int getHeight(BsNode* p){
    if(p == NULL){
        return -1;
    }
    
    return p->heigh;
}

BsNode* insert(BsNode* p, int data){
    if(p == NULL){
        p = create_bsnode(data);
        return p;
    }
    if(data < p->data){
        p->left = insert(p->left, data);
        //avl
        if(getHeight(p->left)-getHeight(p->right) == 2){
            if(data < p->left->data){
                //左旋
                p = rotateLeft(p);
            } else {
                
            }
        }
        
    } else {
        p->right = insert(p->right, data);
    }
    p->heigh = getHeight(p->left) > getHeight(p->right) ?
    getHeight(p->left) + 1 : getHeight(p->right) + 1;
    return p;
}

BsNode* delete(BsNode* p, int data){
    if(data < p->data){
        p->left = delete(p->left, data);
        return p;
    }
    
    else if(data > p->data){
        p->right = delete(p->right, data);
        return p;
    }
    
    else{
        
        if(p->left == NULL && p->right == NULL){
            p = NULL;
            return p;
        }
        
        else if(p->left != NULL && p->right == NULL){
            p = p->left;
            return p;
        }
        
        else if(p->left == NULL && p->right != NULL){
            p = p->right;
            return p;
        }
        
        else{
            BsNode* temp = p->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            
            p->data = temp->data;
            p->right = delete(p->right, temp->data);
            return p;
        }
    }
}

void read_bstree(BsNode* p){
    if(p == NULL){
        return ;
    }
    read_bstree(p->left);
    printf("height:%d,data:%d\n", p->heigh, p->data);
    read_bstree(p->right);
}

void read_lnr(BsNode* p){
    if(p == NULL){
        return ;
    }
    
    printf("data:%d\n", p->data);
    read_lnr(p->left);
    read_lnr(p->right);
}

void bsTree(){
    BsNode* p = create_bsnode(5);
//    p = insert(p, 9, 0);
//    p = insert(p, 16, 0);
//    p = insert(p, 13, 0);
//    p = insert(p, 20, 0);
//    p = insert(p, 12, 0);
//    p = insert(p, 14, 0);
//    p = insert(p, 18, 0);
//    p = insert(p, 22, 0);
//    p = delete(p, 16);
    p = insert(p, 3);
    p = insert(p, 2);
//    p = insert(p, 4);

    read_bstree(p);
    
    printf("lnr:\n");
    read_lnr(p);
}
