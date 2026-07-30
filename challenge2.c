#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        char *argv[] = {"date", NULL};
        execvp(argv[0], argv);
    }
    else if (pid == -1) 
    {
        perror("ERROR: ");
        return 1;
    }
    else {
        wait(NULL);
    }
    return 0;
}