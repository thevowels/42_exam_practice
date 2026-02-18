#ifndef GNL
# define GNL

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

char    *get_next_line(int fd);

#endif