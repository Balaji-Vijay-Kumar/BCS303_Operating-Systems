#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid;

    // Fork a child process
    pid = fork();

    if (pid < 0) { // Error occurred
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) { // Child process
        printf("This is the child process (PID: %d)\n", getpid());
    } else { // Parent process
        printf("This is the parent process (PID: %d) of child with PID: %d\n", getpid(), pid);
    }

    return 0;
}
