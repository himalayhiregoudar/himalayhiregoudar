#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// BST node structure
struct node

{
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* createNode(int data)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
struct node* insert(struct node* root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to perform preorder traversal of BST
void preorder(struct node* root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function to perform inorder traversal of BST
void inorder(struct node* root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Function to perform postorder traversal of BST
void postorder(struct node* root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

/*void random(int N, int l,int u, FILE *fp)
 {
     int i,array[1000];
     srand(time(0));
     printf("\n the random numbers are:  ");
     for(i=0;i<N;i++)
    {
        array[i]=(rand() % (u-l+1))+l;
        printf("\n%d",array[i]);
        fprintf(fp,"%d\t",array[i]);
        root=insert(root,N);
    }

    fclose(fp);

 }
 */
 int main()
 {
    struct node* root = NULL;
    int l,u,N;
    FILE *fp;
    printf("\n enter range lower and upper:");
    scanf("%d%d",&l,&u);
    printf("\n enter count:");
    scanf("%d",&N);
    fp=fopen("input.txt","w");
    if(fp==NULL)
    {
        printf("\nerror");
        exit(0);
    }
    int i,array[1000];
     srand(time(0));
     printf("\n the random numbers are:  ");
     for(i=0;i<N;i++)
    {
        array[i]=(rand() % (u-l+1))+l;
        printf("\n%d",array[i]);
        fprintf(fp,"%d\t",array[i]);
        root=insert(root,array[i]);
    }

    fclose(fp);


    // Perform different traversals
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder traversal: ");
    postorder(root);
    printf("\n");

    return 0;
    }

