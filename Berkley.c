#include<stdio.h>
int main(){
   int nodes,hr[10],min[10],rt[10];
   int hrs=0,mins=0;
   printf("Enter the number of nodes: ");
   scanf("%d",&nodes);
   int coord;
   printf("Enter the co-ordinator node id: ");
   scanf("%d",&coord);
   printf("Enter the time of coodinator node: ");
   scanf("%d : %d",&hr[coord-1],&min[coord-1]);
   for(int i=0;i<nodes;i++){
      if(i+1!=coord){
         printf("Enter the time that is set by node %d to coordinator node: ",i+1);
         scanf("%d : %d",&hr[i],&min[i]);
      }
   }
   for(int i=0;i<nodes;i++){
    if(i+1!=coord){
    printf("Enter the round trip time of node %d: ",i+1);
    scanf("%d",&rt[i]);
    }
   }
   for(int i=0;i<nodes;i++){
      hrs=hrs+hr[i];
      mins=mins+min[i];
   }

   hrs=hrs/nodes;
   mins=mins/nodes;
   while(mins>=60){
      mins=mins-60;
      hrs++;
   }
   int finhr[10];
   int finmin[10];
   finhr[coord-1]=hr[coord-1];
   finmin[coord-1]=min[coord-1];
   for(int i=0;i<nodes;i++){
   if((i+1)!=coord){
      finmin[i]=mins+(rt[i]/2);
      finhr[i]=hrs;
      while(finmin[i]>60){
        finmin[i]=finmin[i]-60;
        finhr[i]++;
      }
      }
   }
   for(int i=0;i<nodes;i++){
      printf("%d: %d\n",finhr[i],finmin[i]);
   }
}
















