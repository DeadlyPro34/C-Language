#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 10

struct node
{
	int data;
	struct node *left, *right;
};

struct node *newnode(int data)
{
	struct node *node=(struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = node->right = NULL;
	return node;
}

struct node * insert(struct node *root,int value)
{
	if(root == NULL)
	{
		return newnode(value);
	}
	if(value<root->data)
		root->left = insert(root->left,value);
	
	else if(value>root->data)
		root->right = insert(root->right,value);
	
	return root;
}

void inorderR(struct node *root)
{
	if(root==NULL)
	   return;
	inorderR(root->left);
	printf("%d", root->data);
	inorderR(root->right);
}

void preorderR(struct node *root)
{
	if(root==NULL)
	   return;
	printf("%d", root->data);
	preorderR(root->left);
	preorderR(root->right);
}

void postorderR(struct node*root)
{
	if(root==NULL)
	   return;
	postorderR(root->left);
	postorderR(root->right);
	printf("%d", root->data);
}

void postorderN(struct node* root) 
{
    if (root == NULL)
        return;

    struct node* x[MAX], * y[MAX];
    int topX = -1, topY = -1;

    x[++topX] = root;

    while (topX != -1) {
        struct node* node = x[topX--];
        y[++topY] = node;

        if (node->left)
            x[++topX] = node->left;
        if (node->right)
            x[++topX] = node->right;
    }

    while (topY != -1) {
        printf("%d ", y[topY--]->data);
    }
}

int main() 
{
    struct node *root = NULL;
    int n,v,i;
    
    printf("Enter no of node:  ");
    scanf("%d",&n);
    
    printf("Enter the tree value:  ");
    for(i=0;i<n;i++)
    {
    	scanf("%d", &v);
    	root = insert(root, v);
	}
	
	printf("\nInorder is: ");
    inorderR(root);
    
    printf("\nPreorder is: ");
    preorderR(root);
    
    printf("\nPostorder is: ");
    postorderR(root);
    
    printf("\nPostorder Non-R is: ");
    postorderN(root);
    
    getch();
    return 0;
}
