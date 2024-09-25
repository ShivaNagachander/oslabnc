#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
int main(int argc, char *argv[]) {
    DIR *dp;
    struct dirent *dirp;

    if (argc != 2) {
        printf("A single argument (the directory name) is required.\n");
        exit(1);
    }
    if ((dp = opendir(argv[1])) == NULL) {
        printf("Cannot open directory: %s\n", argv[1]);
        exit(1);
    }
    while ((dirp = readdir(dp)) != NULL) {
        printf("Name: %s | Inode: %ld\n", dirp->d_name, dirp->d_ino);
    }
    closedir(dp);
    return 0;
}
