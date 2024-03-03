#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static int i=0;
static int array[]={1,2,3,4,5,6,7,8};
static pthread_mutex_t inc_mutex;
static void* inc(void *arg){
  for (int j=0;j<1800000;j++){
    pthread_mutex_lock(&inc_mutex);
    i++;
    pthread_mutex_unlock(&inc_mutex);
  }
}
void* sum_array(void * idxs){
  int *indexes=(int *)idxs;
  int sum=0;
  int k=indexes[0];
  printf("[%d,%d] k=%d\n",indexes[0],indexes[1],k);
  for (;k<indexes[1];k++){
    sum+=array[k];
    printf("Thread %d - k=%d sum=%d\n",pthread_self(),k,sum);
  }
  printf("Thread %d sum final %d\n",pthread_self(),sum);
  return (void *)(long long int)sum;
}
int main(int argc, char *argv[]){
  // Somme de tableaux, on partage le tableau en 2 zones indépendantes
  int indexes1[2]={0,4};int indexes2[2]={4,8};
  long long int sum1,sum2;
  pthread_t thread1_tid,thread2_tid;
  pthread_create(&thread1_tid,NULL,(void * (*)(void *))&sum_array,(void*)indexes1);
  //indexes[0]=4;indexes[1]=8;
  pthread_create(&thread2_tid,NULL,(void * (*)(void *))&sum_array,(void*)indexes2);
  int ret1,ret2;
  ret1=pthread_join(thread1_tid,(void*)&sum1);
  ret2=pthread_join(thread2_tid,(void*)&sum2);
  printf("%d %d \n",ret1,ret2);
  printf("%d+%d=%d\n",sum1,sum2,sum1+sum2);
  // Somme avec concurrence sur la variable globale i
  // Sans les mutex on peut constater le problème.
/*  pthread_mutex_init(&inc_mutex,NULL);
  pthread_create(&thread1_tid,NULL,&inc,NULL);
  pthread_create(&thread2_tid,NULL,&inc,NULL);
  pthread_join(thread1_tid,NULL);
  pthread_join(thread2_tid,NULL);
  pthread_mutex_destroy(&inc_mutex);
  printf("%d\n",i);
*/

}