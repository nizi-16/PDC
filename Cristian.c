#include<stdio.h>
int main(){
   int nodes,serverhour,servermins,rt,clienthour,clientmin;
   printf("Server time in hours: ");
   scanf("%d",&serverhour);
   printf("Server time in mins: ");
   scanf("%d",&servermins);
   printf("The server time is: %d:%d",serverhour,servermins);
   printf("\n");
   printf("Round Trip time in mins: ");
   scanf("%d",&rt);
   clienthour=serverhour;
   clientmin=0;
   if(servermins+(rt/2)>=60){
    clienthour++;
    clientmin=servermins+(rt/2)-60;
   }
   else{
    clientmin=servermins+(rt/2);
   }

   printf("The time is: %d:%d",clienthour,clientmin);
   return 0;
}
