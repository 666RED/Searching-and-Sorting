#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* leftChild;
    struct node* rightChild;
};

typedef struct node node;

node* root = NULL;

void insert(int);
node* search(int);
void preOrderTraversal(node*);
void inOrderTraversal(node*);
void postOrderTraversal(node*);

int main(){
    int j;
    int array[7] = {27, 14, 35, 10 ,19, 31, 42};

    for(int i = 0; i < 7; i++){
        insert(array[i]);
    }

    j = 31;
    node* temp = search(j);
    if(temp != NULL){
        printf("[%d] Element found.", temp->data);
        printf("\n");
    }else{
        printf("[ x ] Element not found (%d).\n", j);
    }

    j = 15;
    temp = search(j);
    if(temp != NULL){
        printf("[%d] Element found.", temp->data);
        printf("\n");
    }else{
        printf("[ x ] Element not found (%d).\n", j);
    }

    printf("\nPre order traversal: ");
    preOrderTraversal(root);

    printf("\nIn order traversal: ");
    inOrderTraversal(root);

    printf("\nPost order traversal: ");
    postOrderTraversal(root);

    return 0;
}

void insert(int data){
    node* temp = (node*)malloc(sizeof(node));
    node* curr;
    node* parent;

    temp->data = data;
    temp->leftChild = NULL;
    temp->rightChild = NULL;

    if(root == NULL){
        root = temp;
    }else{
        curr = root;
        parent = NULL;

        while(1){
            parent = curr;
            if(data < parent->data){
                curr = curr->leftChild;
                if(curr == NULL){
                    parent->leftChild = temp;
                    return;
                }
            }else{
                curr = curr->rightChild;
                if(curr == NULL){
                    parent->rightChild = temp;
                    return;
                }
            }
        }
    }
}

node* search(int data){
    node* curr = root;
    printf("Visiting elements: ");

    while(curr->data != data){
        if(curr != NULL){
            printf("%d ", curr->data);
        }

        if(curr->data > data){
            curr = curr->leftChild;
        }else{
            curr = curr->rightChild;
        }

        if(curr == NULL){
            return NULL;
        }
    }

    return curr;
}

void preOrderTraversal(node* root){
    if(root != NULL){
        printf("%d ", root->data);
        preOrderTraversal(root->leftChild);
        preOrderTraversal(root->rightChild);
    }
}

void inOrderTraversal(node* root){
    if(root != NULL){
        inOrderTraversal(root->leftChild);
        printf("%d ", root->data);
        inOrderTraversal(root->rightChild);
    }
}

void postOrderTraversal(node* root){
    if(root != NULL){
        postOrderTraversal(root->leftChild);
        postOrderTraversal(root->rightChild);
        printf("%d ", root->data);
    }
}





















