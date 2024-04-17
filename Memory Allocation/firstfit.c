#include<stdio.h>
void main()
{
 int bsize[10],psize[10],bno,pno,flag[10],allocation[10],i,j;
 for(i=0;i<10;i++)
 {
  flag[i]=0;
  allocation[i]=-1;
 }
 printf("enter no of blocks:");
 scanf("%d",&bno);
 printf("\nEnter size of each block:");
 for(i=0;i<bno;i++)
 scanf("%d",&bsize[i]);
 printf("\n Enter no of processes:");
 scanf("%d",&pno);
 printf("enter size of each process:");
 for(i=0;i<pno;i++)
 scanf("%d",&psize[i]);
 for(int i=0;i<pno;i++)
 {
  for(int j=0;j<bno;j++)
  {
   if(bsize[j]>=psize[i])
   {
    allocation[i]=j;
    bsize[j]=0;
    break;
   }
  }
 }
 printf("\n Process no \t process size \t Blck no \n");
 for(int i=0;i<pno;i++)
 {
  printf("%d \t\t %d \t\t",i+1,psize[i]);
  if(allocation[i]!=-1)
   printf("%d\n",allocation[i]+1);
  else
   printf("not allocated \n");
  }
 }


