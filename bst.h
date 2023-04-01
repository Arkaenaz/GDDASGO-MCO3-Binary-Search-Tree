/*******************************************************************
YOU ARE NOT ALLOWED TO MODIFY THE STRUCT AND THE FUNCTION PROTOTYPES
*******************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *pLeft;
    struct Node *pRight;
};

typedef struct Node sNode;

typedef struct {
	sNode *pRoot;
} bst;

sNode* createNode(int x) {
    sNode* newNode = (sNode*)malloc(sizeof(sNode));
	
    newNode->data = x;
    newNode->pLeft = NULL;
    newNode->pRight = NULL;

    return newNode;
}

bst* create() {
	bst* pTree = (bst*)malloc(sizeof(bst));
    pTree->pRoot = NULL;
    return pTree;
}

void insert(bst* t, int x) {
	if (t->pRoot == NULL) {
        t->pRoot = createNode(x);
        return;
    }
    sNode* pCurrent = t->pRoot;
    while (pCurrent != NULL) {
        if (x < pCurrent->data) {
            if (pCurrent->pLeft == NULL) {
                pCurrent->pLeft = createNode(x);
                return;
            }
            pCurrent = pCurrent->pLeft;
        } 
		else if (x > pCurrent->data) {
            if (pCurrent->pRight == NULL) {
                pCurrent->pRight = createNode(x);
                return;
            }
            pCurrent = pCurrent->pRight;
        } 
		else {
            return;
        }
    }
}

sNode* search(bst *t, int x) {
	sNode *pCurrent = t->pRoot;

    while (pCurrent != NULL) {
        if (x == pCurrent->data){
			return pCurrent;
		}
        else if (x < pCurrent->data){
			pCurrent = pCurrent->pLeft;
		}
        else{
			pCurrent = pCurrent->pRight;
		}
    }

    return NULL;
}

void inorder(sNode *pPointer) {
	if (pPointer != NULL) {
        inorder(pPointer->pLeft);
        printf("%d ", pPointer->data);
        inorder(pPointer->pRight);
    }
}

void preorder(sNode *pPointer) {
	if (pPointer != NULL) {
        printf("%d ", pPointer->data);
        preorder(pPointer->pLeft);
        preorder(pPointer->pRight);
    }
}

void postorder(sNode *pPointer) {
	if (pPointer != NULL) {
        postorder(pPointer->pLeft);
        postorder(pPointer->pRight);
        printf("%d ", pPointer->data);
    }
}

sNode* maximum(sNode *pPointer) {
	// Your code here
}

sNode* minimum(sNode *pPointer) {
	// Your code here
}

sNode* parent(bst *t, int x) {
	// Your code here
}

sNode* successor(bst *t, int x) {
	// Your code here
}

sNode* predecessor(bst *t, int x) {
	// Your code here
}
