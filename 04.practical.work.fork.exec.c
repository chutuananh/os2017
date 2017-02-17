#include <stdio.h>
#include <unistd.h>
 int main() 
 {
     printf("Main before fork()\n");
     //The first child process 
     int child_pid_1 = fork();
     if (child_pid_1 == 0) {
	printf("I am child after fork(), launching ps -ef\n");
	char *args[]= { "/bin/ps", "-ef" , NULL};
	execvp("/bin/ps", args);
	printf("Finished launching ps -ef\n");
     }
     else printf("I am parent after fork(), child is %d\n", child_pid_1);
	
     // The second child process	 
     int child_pid_2 = fork();
     if (child_pid_2 == 0) {
	printf("I am child after fork(), launching free -h\n");
	char *args[]= { "free", "-h" , NULL};
	execvp("free", args);
	printf("Finished launching free -h\n");
     }
     else printf("I am parent after fork(), child is %d\n", child_pid_2);
     return 0;
 } 
