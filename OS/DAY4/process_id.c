#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid, ppid;

    // Get the process ID
    pid = getpid();

    // Get the parent process ID
    ppid = getppid();

    // Print the process ID and parent process ID
    printf("Process ID: %d\n", pid);
    printf("Parent Process ID: %d\n", ppid);

    return 0;
}

