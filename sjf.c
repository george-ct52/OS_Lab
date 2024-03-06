#include <stdio.h>
#define max 10

void swap(int* arr, int i, int j) 
{ 
    int temp = arr[i]; 
    arr[i] = arr[j]; 
    arr[j] = temp; 
}

void sort_bursttime(int bt[],int p[],int n)
{
    for(int i=0;i<n-1;i++)
   {
    for(int j=0;j<n-i-1;j++)
     {
       if (bt[j] > bt[j + 1]) 
         {
                
                swap(bt, j, j + 1);
                swap(p, j, j + 1); 
          }
     }
    }

}
  
int main()
{
   int n,bt[max],wt[max],p[max],tat[max],ct[max];
   float awt=0,atat=0;
   printf("Enter the number of processes: ");
   scanf("%d",&n);
   printf("Enter the process number and its burst time: ");
   for(int i=0;i<n;i++)
      {
      printf("\nprocess: ");
      scanf("%d %d",&p[i],&bt[i]);
      }
   printf("\nBefore sorting\n ");
   for(int i=0;i<n;i++)
   {
      printf("p%d - burst time: %d\n",p[i],bt[i]);
   }
   
   
   sort_bursttime(bt,p,n);

    printf("\nAfter sorting\n ");
   for(int i=0;i<n;i++)
   {
      printf("p%d - burst time: %d\n",p[i],bt[i]);
   }


printf("PR\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;

         for(int j=0;j<i;j++)
         {
            wt[i]=wt[i]+bt[j];
         }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];

        printf("%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    awt = awt/n;
    atat = atat/n;
    printf("\nAverage waiting time: %f",awt);
    printf("\nAverage turnaround time: %f",atat);
}
