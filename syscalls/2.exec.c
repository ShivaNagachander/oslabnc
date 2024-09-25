#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
    // Use execv() to replace the current process with the "/bin/ls" command
    char *args[] = {"/bin/ls", NULL};  // Arguments for execv, NULL-terminated array
    execv("/bin/ls", args);            // Replace current process with "ls"

    // If execv() fails, this line will be executed
    perror("execv failed");
    
    return 0;
}



// 2.original
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
main()
{
    exec("/bin/ls", "/bin/ls");
}
