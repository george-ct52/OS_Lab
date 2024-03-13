#include <stdio.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void main()
{
  char str[100];
  int shmid=shmget((key_t)2366,1024,0666|IPC_CREAT);
  printf("Key of Shared Memory is %d \n",shmid);
  
  void *shm = shmat(shmid,NULL,0);
  printf("Process is attached at %p \n",shm);
  printf("Enter DATA : ");
  scanf("%s",str);
  strcpy(shm,str);
  printf("\n Value Written by WRITER Process is : %s",(char*)shm);
}
