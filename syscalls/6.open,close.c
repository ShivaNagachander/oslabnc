#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main() 
{
    int fd, i;
    fd = open("test", O_CREAT | O_RDWR | O_APPEND, 0644); // Corrected the bitwise OR operator and added permissions
    if (fd == -1) 
    {
        perror("Error opening file");
        return 1;
    }
    for (i = 0; i < 10; i++) 
    {
        write(fd, "CVSR", 4); // Corrected the write function to write 4 bytes
    }
    close(fd);
    return 0;
}

//old
