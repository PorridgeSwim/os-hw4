#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
        int fd1 = open("/tmp/tabletop.tmp", O_WRONLY | O_CREAT | O_APPEND, 0644);
        write(fd1, "hello", 5);

        int fd2 = open("/tmp/tabletop.tmp", O_RDONLY);
        int fd3 = open("/tmp/tabletop.tmp", O_RDONLY | O_CLOEXEC);
        close(fd2);

        pause(); // table-inspector is run while the program is blocked on pause()

        close(fd1);
        close(fd3);
}