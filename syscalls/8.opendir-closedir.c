#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
int main() 
{
    DIR *d;
    struct dirent *de;
    d = opendir(".");
    if (d == NULL) 
    {
        perror("Unable to open directory");
        return 1;
    }
    while ((de = readdir(d)) != NULL) 
    {
        printf("%s\n", de->d_name);
    }
    closedir(d);
    return 0;
}
