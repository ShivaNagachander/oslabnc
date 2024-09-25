#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    struct stat fileStat;
    if (argc != 2 || stat(argv[1], &fileStat) < 0) return 1;

    printf("File: %s\nSize: %ld bytes\nPermissions: %o\n", argv[1], fileStat.st_size, fileStat.st_mode & 0777);
    return 0;
}
O/P:
=== Code Execution Successful ===


//origiml
$ stat filename
