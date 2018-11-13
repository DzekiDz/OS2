#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t turn;
pthread_cond_t br_char_nula;

void* tfunc_one(void* parameters)
{
	int* p = (int*) parameters;
	while((*p)>0)
	{
		pthread_mutex_lock(&turn);
		
		--(*p);
		pthread_mutex_unlock(&turn);
	}
	pthread_cond_signal(&br_char_nula);
	
	return(NULL);
}
void* tfunc_two(void* parameters)
{
	int* p = (int*) parameters;
	pthread_mutex_lock(&turn);
	while((*p) != 0)
	pthread_cond_wait(&br_char_nula,&turn);
	pthread_mutex_unlock(&turn);
	
	return(NULL);
}

int main()
{
	
	int br_char = 10;
	
	pthread_mutex_init(&turn,NULL);
	pthread_cond_init(&br_char_nula,NULL);
	
	pthread_t thread1_id;
	pthread_t thread2_id;
	
	pthread_create(&thread1_id,NULL,&tfunc_one,&br_char);
	pthread_create(&thread2_id,NULL,&tfunc_two,&br_char);
	
	pthread_join(thread1_id,NULL);
	pthread_join(thread2_id,NULL);
	
	printf("value of br char is %d\n",br_char);
	
	pthread_mutex_destroy(&turn);
	pthread_cond_destroy(&br_char_nula);
	
	return(0);
}
	
	
		
		


