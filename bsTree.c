#include "bsTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct BsNode{
    int data;
    struct BsNode* left;
    struct BsNode* right;
}BsNode;

BsNode* create_bsnode(int data){
    BsNode* p = (BsNode*)malloc(sizeof(BsNode));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

BsNode* insert(BsNode* p, int data){
    if(p == NULL){
        p = create_bsnode(data);
        return p;
    }
    if(data < p->data){
        p->left = insert(p->left, data);
        return p;
    } else {
        p->right = insert(p->right, data);
        return p;
    }
}

BsNode* delete(BsNode* p, int data){
    if(data < p->data){
        p->left = delete(p->left, data);
        return p;
    } else if(data > p->data){
        p->right = delete(p->right, data);
        return p;
    } else {
        
        if(p->right != NULL && p->left == NULL){
            p = p->right;
            return p;
        } else if (p->right == NULL && p->left != NULL){
            p = p->left;
            return p;
        } else if (p->right == NULL && p->left == NULL){
            p = NULL;
            return p;
        } else {
            BsNode* temp = p->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            p->data = temp->data;
            //删除右子树data;
            printf("temp data:%d\n", temp->data);
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
    printf("data:%d\n", p->data);
    read_bstree(p->right);
}

void bsTree(){
    BsNode* p = create_bsnode(10);
    p = insert(p, 9);
    p = insert(p, 16);
    p = insert(p, 13);
    p = insert(p, 20);
    p = insert(p, 12);
    p = insert(p, 14);
    p = insert(p, 18);
    p = insert(p, 22);
    p = delete(p, 16);
    read_bstree(p);
}
