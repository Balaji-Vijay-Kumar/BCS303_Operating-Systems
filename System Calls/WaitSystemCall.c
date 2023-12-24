#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>
int main()
{
if (fork()== 0)
printf("Hello from child,The Process_ID is %d\n",getpid());
else
{
printf("Hello from parent,The process_ID is %d\n",getpid());
wait(NULL);
printf("Child has terminated,PID is %d\n",getpid());
}
printf("Bye,The PID is %d\n",getpid());
return 0;
}

/*Sample output look like: ( fully depends upon scheduling of your CPU)

sample output:Hello from parent,The process_ID is 3909
Hello from child,The Process_ID is 3910
Bye,The PID is 3910
Child has terminated,PID is 3909
Bye,The PID is 3909*/
