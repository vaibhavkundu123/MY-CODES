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
        printf("Child process: PID = %d, Parent PPID = %d\n", getpid(), getppid());
        exit(0);  // Child process terminates
    } else {
        // This is the parent process
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);

        // Sleep to allow child to become a zombie
        sleep(2);

        // Use system call to run 'ps' and grep for the child PID to check if it's a zombie
        printf("\nChecking for zombie process:\n");
        char command[50];
        snprintf(command, sizeof(command), "ps aux | grep ' %d '", pid);
        // snprintf(command, sizeof(command), "(ps aux | head -n 1; ps aux | grep ' %d ' | grep Z)", pid);
        system(command);

        // Sleep to keep the parent alive for observation
        sleep(10);

        
    }

    return 0;
}

