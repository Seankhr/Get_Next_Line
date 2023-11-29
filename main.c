#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd;
    char *line;
    const char *filename = "sample.txt";

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return (0);
}
