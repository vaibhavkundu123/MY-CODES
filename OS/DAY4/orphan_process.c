#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // This is the child process
        printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Wait for a while to ensure the parent process terminates first
        sleep(1);

        // Print the process IDs after the parent has terminated
        printf("Orphan process: PID = %d, New Parent PID = %d\n", getpid(), getppid());
    } else {
        // This is the parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
        
        sleep(0.1);

        // Terminate the parent process
        exit(0);
    }

    return 0;
}

