#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];
    

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    read(fd, buf, MAX_BUF);
    printf("Received as string: %s\n", buf);

int num = atoi(buf);
     printf("The integer is: %d\n", num);
      printf("The sum is: %d\n", num + 5);

    close(fd);

    return 0;
}