#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int child;

    mkfifo("Kovacs Denes", S_IRUSR | S_IWUSR);
    child = fork();

    if (child > 0)
    {
        char s[1024];
        int fd;

        fd = open("Kovacs Denes", O_RDONLY);
        read(fd, s, sizeof(s));
        printf("%s", s);
        close(fd);
        unlink("Kovacs Denes");
    }
    else if (child == 0)
    {
        int fd = open("Kovacs Denes", O_RDONLY);
        write(fd, "Barath DQPDLY\n", 17);
        close(fd);
    }

    return 0;
}