#include <stdio.h>
#include <pthread.h>

struct char_print_parms
{
	char character;
	int count;
};

pthread_mutex_t turn;

void* char_print(void* parameters)
{
	struct char_print_parms* p=(struct char_print_parms*) parameters;
	int i;
	
	pthread_mutex_lock(&turn);
	for(i=0;i<p->count; ++i)
	fputc(p->character,stderr);
	pthread_mutex_unlock(&turn);
	return(NULL);
}



int main()
{
	pthread_mutex_init(&turn,NULL);
	pthread_t thread1_id;
	pthread_t thread2_id;
	struct char_print_parms thread1_args;
	struct char_print_parms thread2_args;
	
	thread1_args.character ='x';
	thread1_args.count = 50;
	pthread_create(&thread1_id,NULL,&char_print,&thread1_args);
	
	thread2_args.character = 'o';
	thread2_args.count = 40;
	pthread_create(&thread2_id,NULL,&char_print,&thread2_args);
	
	pthread_join(thread1_id,NULL);
	pthread_join(thread2_id,NULL);
	fputc('\n',stderr);
	
	pthread_mutex_destroy(&turn);
	return(0);
}
	
