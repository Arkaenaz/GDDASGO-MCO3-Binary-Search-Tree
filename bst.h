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
    sNode *pNode = (sNode*)malloc(sizeof(sNode));
	
    pNode->data = x;
    pNode->pLeft = NULL;
    pNode->pRight = NULL;

    return pNode;
}

bst* create() {
	bst *pTree = (bst*)malloc(sizeof(bst));

    pTree->pRoot = NULL;

    return pTree;
}

void insert(bst* t, int x) {
	if (t->pRoot == NULL) {
        t->pRoot = createNode(x);
        return;
    }

    sNode *pCurrent = t->pRoot;
	
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
	while (pPointer->pRight != NULL) {
        pPointer = pPointer->pRight;
    }
    return pPointer;
}

sNode* minimum(sNode *pPointer) {
	while (pPointer->pLeft != NULL) {
        pPointer = pPointer->pLeft;
    }
    return pPointer;
}

sNode* parent(bst *t, int x) {

	sNode *pCurrent = t->pRoot;
	sNode *pParent = NULL;

	while (pCurrent != NULL && pCurrent->data != x) {
		pParent = pCurrent;
		if (x < pCurrent->data) {
			pCurrent = pCurrent->pLeft;
		} 
        else {
			pCurrent = pCurrent->pRight;
		}
	}

	if (pCurrent == NULL || pCurrent == t->pRoot) {
		return NULL;
	} else {
		return pParent;
	}
}

sNode* successor(bst *t, int x) {

	sNode *pCurrent = search(t, x);

	if (pCurrent == NULL) {
		return NULL;
	}
	if (pCurrent->pRight != NULL) {
		return minimum(pCurrent->pRight);
	}

	sNode *pSuccessor = parent(t, x);

	while (pSuccessor != NULL && pCurrent == pSuccessor->pRight) {
		pCurrent = pSuccessor;
		pSuccessor = parent(t, pSuccessor->data);
	}

	return pSuccessor;
}

sNode* predecessor(bst *t, int x) {

	sNode *pCurrent = search(t, x);

	if (pCurrent == NULL) {
		return NULL;
	}
	if (pCurrent->pLeft != NULL) {
		return maximum(pCurrent->pLeft);
	}

	sNode *pPredecessor = parent(t, x);

	while (pPredecessor != NULL && pCurrent == pPredecessor->pLeft) {
		pCurrent = pPredecessor;
		pPredecessor = parent(t, pPredecessor->data);
	}
	
	return pPredecessor;
}
