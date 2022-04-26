#include<stdio.h>
#include<stdlib.h>
struct node{
    int send;
    int receive;
    int id;
};
int main(){
    struct node p[15];
    int n,numzero=0,numone=0,ans;
    int coord;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter the coordinator id except 0 : ");
    scanf("%d",&coord);
    for(int i=1;i<=n;i++){
        if(i!=coord){
            p[i-1].id=i;
            printf("Enter the reply that node %d sent the coordinator %d : ",p[i-1].id,coord);
            scanf("%d",&p[i-1].send);
        }
    }

    //counting the number of zeroes and ones
    for(int i=1;i<=n;i++){
        if(i!=coord && p[i-1].send==0)
            numzero++;
        else if(i!=coord && p[i-1].send==1)
            numone++;
    }

    //deciding commit or abort the transaction
    if(numzero>numone)
        ans=0;
    else
        ans=1;

    //conveying result to the nodes
    for(int i=1;i<=n;i++){
        if(i!=coord){
            p[i-1].receive= ans;
        }
    }
    if(numzero>numone)
        printf("Abort\n");
    else if(numzero == numone)
        printf("Cannot decide\n");
    else
        printf("Commit\n");

    printf("\n");
    printf("Status of all the nodes...\n");
    for(int i=1;i<=n;i++){
        if(i!=coord && p[i-1].receive==0)
            printf("Node %d aborts\n",p[i-1].id);
        else if(i!=coord && p[i-1].receive==1)
            printf("Node %d commits\n",p[i-1].id);
    }
}
