#include<stdio.h>
#include<conio.h>
struct process
{
struct message
{
  int timestamp;
  int pid;
}m[20];
int nreply;
};
void main()
{
  int total,n,i,j,k,tempid,tempstamp;
  int a,b;
  struct process p[50];

  printf("Enter the number of processes:");
  scanf("%d",&total);
  printf("\nNo of processes trying to enter the CS:");
  scanf("%d",&n);
  j=0;
  for(i=0;i<n;i++)
  {
    printf("\nEnter the process id (less than %d): ",total);
    scanf("%d",&tempid);
    printf("\nTimestamp of that process: ");
    scanf("%d",&tempstamp);
    for(k=0;k<total;k++)
    {
      p[k].m[j].pid=tempid;
      p[k].m[j].timestamp=tempstamp;
      p[k].nreply=total;
    }
    j++;
  }
  for(k=0;k<total;k++)
  {
  for(i=0;i<n-1;i++)
  {
    for(j=i+1;j<n;j++)
    {
      if(p[k].m[i].timestamp>p[k].m[j].timestamp)
      {
	tempid=p[k].m[i].pid;
	tempstamp=p[k].m[i].timestamp;
	p[k].m[i].pid=p[k].m[j].pid;
	p[k].m[i].timestamp=p[k].m[j].timestamp;
	p[k].m[j].pid=tempid;
	p[k].m[j].timestamp=tempstamp;
      }
    }
  }
  }
  for(i=0;i<total;i++)
  {
    printf("\n");
    printf("Process %d with %d REPLY messages",i,p[i].nreply);
    for(j=0;j<n;j++)
    {
      printf("(%d,%d)<--",p[i].m[j].pid,p[i].m[j].timestamp);
    }

  }
  while(n>0)
  {
  for(i=0;i<total;i++)
  {
    if(p[i].m[0].pid==i)
    {
      printf("\n");
      printf("Since process %d is at top of the request queue, it enters CS",i);
      printf("\nOn exiting the critical section ");
      printf("\nProcess %d sends a RELEASE message to all the other processes\n",i);
      printf("------------------------------------------------------------------\n");
      for(a=0;a<total;a++)
      {
      for(j=0;j<n-1;j++)
      {
	p[a].m[j].pid=p[a].m[j+1].pid;
	p[a].m[j].timestamp=p[a].m[j+1].timestamp;

      }
      }
      n--;
      if(n>0)
      {
      printf("Now the request queue status in each process is\n");
      for(a=0;a<total;a++)
      {
	printf("Process %d with %d REPLY messages",a,p[a].nreply);
	for(b=0;b<n;b++)
	{
	  printf("(%d,%d)<--",p[a].m[b].pid,p[a].m[b].timestamp);
	}
	printf("\n");
      }
      }
      else
       printf("Now the request queue is empty\n");

    }
  }
  }
  getch();
}
