#include <stdio.h>

void swap(int* arr, int i, int j) 
{ 
    int temp = arr[i]; 
    arr[i] = arr[j]; 
    arr[j] = temp; 
}

//to sort the processes according to priority 
void sortpriority(int pro[],int bt[],int p[], int n)
{
  for(int i=0;i<n-1;i++)
   {
    for(int j=0;j<n-i-1;j++)
     {
       if (p[j]>p[j+1]) 
         {
                swap(pro, j, j + 1);
                swap(bt, j, j + 1);
                swap(p, j, j + 1); 
          }
     }
    }
}







int main()
{
    int n,bt[10],p[10],pro[10],wt[10],tat[10];
    float awt=0,atat=0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        pro[i]= i+1;
    }

    printf("Enter the burst and priority of each process: \n");

    for(int i=0; i<n; i++)
    {
      printf("P%d: ",i+1);
      scanf("%d %d",&bt[i],&p[i]);
    }

   sortpriority(pro,bt,p,n);
   
    wt[0] = 0;

    printf("Pr\tBT\tPrio\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
       wt[i] =0;
       tat[i] = 0;
       for(int j=0;j<i;j++)
       {
          wt[i] += bt[j];
       }

       tat[i] = wt[i] + bt[i] ;
       awt += wt[i];
       atat += tat[i];

       printf("%d\t%d\t%d\t%d\t%d\n",pro[i],bt[i],p[i],wt[i],tat[i]);
    }

    printf("\nAverage waiting time: %f\n",awt/n);
    printf("Average turnaround time: %f",atat/n);
}
