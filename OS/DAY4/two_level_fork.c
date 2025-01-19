#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid1, pid2;

    // First fork to create the first child
    pid1 = fork();

    if (pid1 < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid1 == 0) {
        // This is the first child process
        printf("First child process: PID = %d, Parent PID = %d\n", getpid(), getppid());

        // Second fork to create the second-level child (grandchild)
        pid2 = fork();

        if (pid2 < 0) {
            // Fork failed
            fprintf(stderr, "Fork failed in first child\n");
            return 1;
        } else if (pid2 == 0) {
            // This is the second-level child (grandchild)
            printf("Second-level child (grandchild) process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        } else {
            // First child process continues here after creating grandchild
            sleep(1);  // Sleep for a while to allow grandchild to execute first
            printf("First child process after creating grandchild: PID = %d\n", getpid());
        }
    } else {
        // This is the parent process
        printf("Parent process: PID = %d, First child PID = %d\n", getpid(), pid1);
        sleep(2);  // Sleep for a while to allow children to complete
    }

    return 0;
}

