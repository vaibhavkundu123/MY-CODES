#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create a child process
    pid = fork();

    if (pid < 0) {
        // Fork failed
        fprintf(stderr, "Fork failed\n");
        return 1;
    } else if (pid == 0) {
        // Child process
        printf("This is the child process. PID: %d, Parent PID: %d\n", getpid(), getppid());
    } else {
        // Parent process
        printf("This is the parent process. PID: %d, Child PID: %d\n", getpid(), pid);
        sleep(2);
    }

    return 0;
}

