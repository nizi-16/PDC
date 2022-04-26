#include<stdio.h>
#include<stdlib.h>
struct node{
int id;
int hval;
struct node *l, *r;
int req[20];
};
typedef struct node node;



void insert( node * newnode , node *root)
{

if( newnode->id > root->id)
{
if( root->r == NULL)
{
root->r = newnode;
newnode->hval=root->id;
}
else
insert( newnode,root->r);
}

if( newnode->id < root->id)
{
if( root->l == NULL)
{
root->l = newnode;
newnode->hval=root->id;
}
else
insert( newnode,root->l);
}
}
void inorder(node *root){

     if (root==NULL) return ;
     inorder(root->l);
     printf("%d  %d\n",root->id,root->hval);
     inorder(root->r);
}
void token(node *root,int csnode){

     if (csnode==root->id)
     {
         printf("%d\n",root->id);
         root->hval=root->id;
          return;
          }
     else if(csnode<root->id)
      {
        root->hval=(root->l)->id;
        printf("%d->" ,root->id);
        root=root->l;

       token(root,csnode);
       }
       else if(csnode>root->id)
       {
            root->hval=(root->r)->id;
            printf("%d->" ,root->id);
            root=root->r;
            token(root,csnode);
       }
}
main()
{
    node *root=NULL, *newnode=NULL,*node1;
    int i,n,tnode,idval,csnode,choice;
    root=malloc(sizeof(node));
    node1=malloc(sizeof(node));
    printf("Enter no of nodes in the distributed environment: ");
    scanf("%d",&n);
    printf("Enter the node which has the token : ");
    scanf("%d",&tnode);
    root->id=tnode;
    root->r=root->l=NULL;
    root->hval=root->id;
    printf("Enter the id of the nodes : ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&idval);
        newnode = malloc(sizeof(node));
        newnode->l = newnode->r = NULL;
        if(i==tnode)i++;
        newnode->id = idval;

        insert(newnode,root);
    }
    inorder(root);
    printf("-----------------------------------------------\n");
    printf("Enter the node id which wants to execute the CS\n");
    scanf("%d",&csnode);
    token(root,csnode);
    system("Pause");
}




