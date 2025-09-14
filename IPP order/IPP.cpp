#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

struct node{
	int data;
	struct node *left, *right;
};

struct node *newnode(int data){
	struct node *node=(struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right=NULL;
	return node;
}

void inorderR(struct node*root){
	if(root==NULL)
	   return;
	inorderR(root->left);
	printf("%d", root->data);
	inorderR(root->right);
}

void preorderR(struct node *root){
	if(root==NULL)
	   return;
	printf("%d", root->data);
	preorderR(root->left);
	preorderR(root->right);
}

void postorderR(struct node*root){
	if(root==NULL)
	   return;
	postorderR(root->left);
	postorderR(root->right);
	printf("%d", root->data);
}

void postorderN(struct node*root){
	if(root==NULL)
	   return; 
	   
	struct node*x[MAX],*y[MAX];
	int t1 = -1, t2 = -1;
	
	x[++t2]=root;
	
	while(t1 != -1)
	{
		struct node* node=x[t1--];
		y[++t2] = node;
		
		if(node->left)
		   x[++t1]=node->left;
		if(node->right)
		   x[++t1]=node->right;
	}
	
	while(t2!=-1)
	{
		printf("%d", y[t2--]->data);
	}
}

int main() {
    struct node *root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);

    printf("Inorder (Recursive): ");
    inorderR(root);
    printf("\n");

    printf("Preorder (Recursive): ");
    preorderR(root);
    printf("\n");

    printf("Postorder (Recursive): ");
    postorderR(root);
    printf("\n");

    printf("Postorder (Non-Recursive): ");
    postorderN(root);
    printf("\n");

    return 0;
}

