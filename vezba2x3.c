#include<pthread.h>
#include<stdio.h>

void* thread_function(void * arg)
{
	int *incoming = (int *) arg;
	int nekibroj;
	
	*incoming = 2*(*incoming);
	
	return(NULL);
};

int main()
{
	pthread_t thread_ID;
	
	int value;
	int bufprom;
	
	value=42;
	bufprom=value;
	
	pthread_create(&thread_ID,NULL,&thread_function, (void *) &bufprom);
	
	pthread_join(thread_ID,NULL);
	
	printf("Value: %d, rezultat %d\n", value, bufprom);
	
	return(0);
}
