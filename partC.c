#include <stdio.h>
#include <unistd.h>  

int main() {     
    pid_t pid = fork();     

    // 1. Check for error
    if (pid < 0) {
        perror("Fork Failed");
        return 1;
    }
    
    // 2. Child process execution
    if (pid == 0) {         
        printf("Child Process\n");        
        printf("PID = %d\n", getpid());     
    }    
    // 3. Parent process execution
    else {         
        printf("Parent Process\n");         
        printf("PID = %d\n", getpid());     
    }      

    return 0; 
}