#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
int main()
{
    int n, f, f1;
    char buff[20];
    f = open("renu.txt", O_RDWR);
    f1 = lseek(f, 5, SEEK_SET);
    printf("Pointer is at %d position\n", f1);
    read(f, buff, 10);
    write(1, buff, 10);
}