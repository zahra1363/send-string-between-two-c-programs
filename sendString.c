/* #include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;
    char * myfifo = "/tmp/myfifo";
    char * message = "11";

    //create the FIFO with mkfifo(const char *pathname, mode_t mode);//
    mkfifo(myfifo, 0666);

     // Open FIFO for write only
    fd = open(myfifo, O_WRONLY);
    write(fd, message, sizeof("11"));
    close(fd);

    //remove the FIFO //
    unlink(myfifo);

    return 0;
}
*/





// get data from user and write in FIFO

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd;

    // FIFO file path
    char * myfifo = "/tmp/myfifo";

    // Creating the named file(FIFO)
    // mkfifo(<pathname>, <permission>)
    mkfifo(myfifo, 0666);

    char arr1[80], arr2[80];
    while (1)
    {
        // Open FIFO for write only
        fd = open(myfifo, O_WRONLY);

        // Take an input arr2ing from user.
        // 80 is maximum length
        fgets(arr2, 80, stdin);

        // Write the input arr2ing on FIFO
        // and close it
        write(fd, arr2, strlen(arr2)+1);
        close(fd);

        // Open FIFO for Read only
        //fd = open(myfifo, O_RDONLY);

        // Read from FIFO
       // read(fd, arr1, sizeof(arr1));

        // Print the read message
       // printf("User2: %s\n", arr1);
        close(fd);
    }
    return 0;
}

