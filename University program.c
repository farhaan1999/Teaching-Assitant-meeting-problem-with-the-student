#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h> 
#include <unistd.h> 
int resource =0;
sem_t mutex; 
  
void* thread(void* arg) 
{ 

    sem_wait(&mutex); 
    resource=resource+10;
     printf("Teacher Assitant is busy with Student \n");
    //printf("\nEntered process is going on \n"); 

 printf("Resource= %d ",resource);
     
    sleep(4); 
      
    
    //printf("\nJust Exiting...\n"); 
      printf("\nTeacher Assitant is Now Free \n");
      sleep(5);
    sem_post(&mutex); 
    
} 
  
  
int main() 
{ 
    sem_init(&mutex, 3, 1); 
    pthread_t t1,t2,t3; 
    pthread_create(&t1,NULL,thread,NULL); 
    sleep(2); 
    pthread_create(&t2,NULL,thread,NULL);
	sleep(2); 
	pthread_create(&t3,NULL,thread,NULL); 
    sleep(2);
    pthread_join(t1,NULL); 
    pthread_join(t2,NULL); 
    pthread_join(t3,NULL);
    sem_destroy(&mutex); 
    return 0; 
}
