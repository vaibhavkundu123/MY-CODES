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
        for (int i = 0; i < 5; i++) {
            printf("Child process: PID = %d, iteration = %d\n", getpid(), i + 1);
            sleep(1);  // Sleep for 1 second
        }
    } else {
        // Parent process
        for (int i = 0; i < 5; i++) {
            printf("Parent process: PID = %d, iteration = %d\n", getpid(), i + 1);
            sleep(1);  // Sleep for 1 second
        }
    }

    return 0;
}

