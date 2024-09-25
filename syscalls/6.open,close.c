#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main() {
    int fd, i;
    fd = open("test.txt", O_CREAT | O_RDWR | O_APPEND, 0644); 
    if (fd < 0) {
        perror("Failed to open file");
        return 1;
    }
    for (i = 0; i < 5; i++)
        write(fd, "CVSR\n", 5); 
    close(fd); 
    return 0;
}
O/P:
Failed to open file: Permission denied
