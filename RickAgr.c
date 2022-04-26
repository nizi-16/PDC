#include<stdio.h>
#include<conio.h>
struct process
{
  int timestamp;
  int pid;
  int nreply;
};
void main()
{
  int i,j,n,total,tempid,tempstamp,k,count=0;
  struct process p[50];
  printf("Enter the total no of processes:");
  scanf("%d",&total);
  for(i=0;i<total;i++)
  {
    p[i].timestamp=0;
    p[i].nreply=0;
  }
  printf("Number of processes competing to enter CS:");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("Enter the process id (less than %d):",total);
    scanf("%d",&tempid);
    printf("Enter the timestamp of that process:");
    scanf("%d",&tempstamp);
    p[tempid].pid=tempid;
    p[tempid].timestamp=tempstamp;
  }
  for(i=0;i<total;i++)
  {
      if(p[i].timestamp!=0)
      {
	printf("Process %d  ",i);
	printf("(%d,%d,%d)",p[i].pid,p[i].timestamp,p[i].nreply);
      }
      printf("\n");
  }
  for(i=0;i<total;i++)
  {
      if(p[i].timestamp==0)
      {
	printf("Process %d does not compete for the CS and sends a reply message to all\n",i);
	for(j=0;j<total;j++)
	{
	  if(p[j].timestamp!=0)
	    p[j].nreply++;
	 }
       }
       else
       {
	 for(j=0;j<total;j++)
	 {
	   if((p[j].timestamp!=0)&&(p[i].timestamp>p[j].timestamp))
	   {
	     printf("Process %d sends a REPLY message to process %d\n",i,j);
	     p[j].nreply++;
	    }
	  }
	}
    }
    printf("\n");
  for(i=0;i<total;i++)
  {
      if(p[i].timestamp!=0)
      {
	printf("Process %d  ",i);
	printf("(%d,%d,%d)",p[i].pid,p[i].timestamp,p[i].nreply);
      }
      printf("\n");
  }
  do
  {
  for(i=0;i<total;i++)
  {
    if(p[i].nreply==total-1)
    {
      printf("Process %d enters the critical section\n",i);
      printf("On exiting the CS process %d sends a REPLY message to others\n\n",i);
      printf("----------------------------------------------------------------\n");
      p[i].timestamp=0;
      p[i].nreply=0;
      count++;
      for(k=0;k<total;k++)
      {
	if(p[k].timestamp!=0)
	  p[k].nreply++;
       }
      for(i=0;i<total;i++)
      {
	if(p[i].timestamp!=0)
	{
	  printf("Process %d is   ",i);
	  printf("(%d,%d,%d)",p[i].pid,p[i].timestamp,p[i].nreply);
	}
	printf("\n");
      }
     }
   }
   }while(count<n);
  getch();
}
