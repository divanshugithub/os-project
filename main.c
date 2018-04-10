//# os-project
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>

#define MIN_PID 100
#define MAX_PID 1000

struct MAP { int st; } p_map[MAX_PID], total;


void *thread_proc(void *n){
	printf("\nprocess id allocated to thread is %d", n);
	release_pid(n);
	pthread_exit("true");
}


int allocate_map(void){
	int i;
	
	while(true){
		printf("Enter Number of proccess :> ");
		scanf("%d", &total.st);
		if(total.st >= MIN_PID && total.st <= MAX_PID) break;
		else printf("Enter proccess in range %d to %d\n",MIN_PID,MAX_PID);
	}
	
	for(i = 0; i < total.st; i++){ p_map[i].st =0; }
	
	if(i == total.st) return 1;
	return -1;	
}


int allocate_pid(void){
	int i;
	for(i = 0; i< total.st; i++){
		if(p_map[i].st==0 ) { p_map[i].st=1; return i; }
	}
	return -1;
}

void release_pid(int pid) { p_map[pid].st=0; }

int main(){
	int res,i,j;
	int x = allocate_map();
	
	if(x > 0){
		for(i=0;i<total.st;i++){	
			int tid = allocate_pid();
			pthread_create(&tid, NULL , thread_proc , tid);
		}
		for(i=0;i<total.st;i++){ pthread_join(p_map[i].st, NULL); }
	}
	exit(1);
	return 0;
}
