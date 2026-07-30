// challenge_exercise1.c

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main() {
    pid_t pid;
    for (int i = 1; i <= 3; i++) {
        pid = fork();
        if (pid < 0) {
            perror("Fork failed");
            exit(1);
        }
        else if (pid == 0) {
            printf("Child Number: %d | PID: %d | Parent PID: %d\n", i, getpid(), getppid());
            exit(0);
        }
    }
    for (int i = 0; i < 3; i++) {
        wait(NULL);
    }
    printf("Parent: All children have finished. Parent (PID: %d exiting.\n", getpid());
    return 0;
}