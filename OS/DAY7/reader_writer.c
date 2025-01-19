#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<string.h>

sem_t mutex,wrt;
int rcount=0;
char msg1[100]="Hello";
char msg2[2]=" ";
char msg3[30];
void *reader(void *arg)
{
 
int f;
  f=((int)arg);
    
//sleep(1);

  //if(f>0)
  //sleep(8);
 
  sem_wait(&mutex);
  rcount++;
  if(rcount==1)
   sem_wait(&wrt);
  sem_post(&mutex);
  printf("Reader%d is reading.... %s\n",f,msg1);
  //sleep(1);
  sem_wait(&mutex);
  rcount--;
  if(rcount==0)
   sem_post(&wrt);
  sem_post(&mutex);
  
}

void *writer(void *arg)
{
  int f;
  f = ((int) arg);
 
  //if(f>0)
   //sleep(2);
   
   sem_wait(&wrt);
  printf("Enter for writing ");
   gets(msg3);
 strcat(msg1,msg2);
 strcat(msg1,msg3);
  printf("Writer%d is writing.... %s\n",f,msg3);
  //sleep(1);
  sem_post(&wrt);
  
}

main()
{
  int i;
  pthread_t rtid[5],wtid[5];
  sem_init(&mutex,0,1);
  sem_init(&wrt,0,1);
  while(1){
  for(i=0;i<5;i++)
  {
    pthread_create(&wtid[i],NULL,writer,(void *)i);
    pthread_create(&rtid[i],NULL,reader,(void *)i);
  }
  
  for(i=0;i<5;i++)
  {
    pthread_join(wtid[i],NULL);
    pthread_join(rtid[i],NULL);
  }
  }
}
