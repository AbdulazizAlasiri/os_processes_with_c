#include <stdio.h>
#include <unistd.h>
int main(){

	int i;
	i = fork();

	if(i==0){
		printf("Running child with process id : %d\n", getpid());
		printf("Child finshed\n");
		return 0;
	}

	
	printf("This is the parent that is running for 10s. With pid: %d\n",i);
	sleep(20);
	printf("Parent finshed\n");
	return 0;

}

