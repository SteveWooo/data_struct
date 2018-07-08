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

BsNode* leftRotate(BsNode* p){
    BsNode* temp = p->left;
    p->left = temp->right;
    temp->right = p;
    
    p->heigh = getHeight(p->left) > getHeight(p->right) ?
        getHeight(p->left) + 1 : getHeight(p->right) + 1;
    
    temp->heigh = getHeight(temp->left) > getHeight(temp->right) ?
        getHeight(temp->left) + 1 : getHeight(temp->right) + 1;
    return temp;
}

BsNode* rightRotate(BsNode* p){
    BsNode* temp = p->right;
    p->right = temp->left;
    temp->left = p;
    
    p->heigh = getHeight(p->left) > getHeight(p->right) ?
        getHeight(p->left) + 1 : getHeight(p->right) + 1;
    temp->heigh = getHeight(p->left) > getHeight(p->right) ?
        getHeight(p->left) + 1 : getHeight(p->right) + 1;
    
    return temp;
}

//10 3 4
BsNode* doubleLeftRotate(BsNode* p){
    p->left = rightRotate(p->left);
    p = leftRotate(p);
    return p;
}

//3 10 4
BsNode* doubleRightRotate(BsNode* p){
    p->right = leftRotate(p->right);
    p = leftRotate(p);
    return p;
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
    if(data <= p->data){
        p->left = insert(p->left, data);
        //左边太高
        if(getHeight(p->left) - getHeight(p->right) >= 2){
            if(data > p->left->data){
                p = doubleLeftRotate(p);
            } else {
                p = leftRotate(p);
            }
        }
    } else {
        p->right = insert(p->right, data);
        if(getHeight(p->right) - getHeight(p->left) >= 2){
            if(data < p->right->data){
                p = doubleRightRotate(p);
            } else {
                p = rightRotate(p);
            }
        }
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
    
    else {
        
        if(p->left == NULL && p->right == NULL){
            p = NULL;
            return p;
        }
        
        else if (p->left == NULL && p->right != NULL){
            p = p->right;
            return p;
        }
        
        else if (p->left != NULL && p->right == NULL){
            p = p->left;
            return p;
        }
        
        else {
            BsNode* temp = p->right;
            while(temp->left != NULL){
                temp = temp->left;
            }
            
            p->data = temp->data;
            p->right = delete(p->right, p->data);
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
    BsNode* p = create_bsnode(10);
//    p = insert(p, 9);
//    p = insert(p, 16);
//    p = insert(p, 13);
//    p = insert(p, 20);
//    p = insert(p, 12);
//    p = insert(p, 14);
//    p = insert(p, 18);
//    p = insert(p, 22);
//    p = delete(p, 16);
    p = insert(p, 3);
    p = insert(p, 1);
    p = insert(p, 4);
    p = insert(p, 5);

    read_bstree(p);
    
//    printf("lnr:\n");
//    read_lnr(p);
}

/*
 left rotate
 BsNode* temp;
 temp = p->left;
 p->left = temp->right;
 temp->right = p;
 
 p->heigh = getHeight(p->left) > getHeight(p->right) ?
 getHeight(p->left) + 1 : getHeight(p->right) + 1;
 
 temp->heigh = getHeight(temp->left) > p->heigh ?
 getHeight(temp->left) + 1 : p->heigh + 1;
 return temp;
 */

/*
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
 */
