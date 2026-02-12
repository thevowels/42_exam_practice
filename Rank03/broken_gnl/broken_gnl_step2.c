#include "broken_gnl.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret;

	ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	size1 = s1 ? ft_strlen(*s1) : 0;
	tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	if (*s1)
		ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest < src)
		return (ft_memcpy(dest, src, n));
	else if (dest == src)
		return (dest);
	i = n;
	while (i > 0)
	{
		i--;
		((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}
/*
	We've fixed the compile errors and now time to fix the logical errors.
	We can do in two ways.
		1: with manual print
		2: with gdb

*/
#include <stdio.h>
/*
	If you compile and run the program, you can see that There is an error before the end of the loop.
	We've to fix that.
*/
char	*get_next_line(int fd)
{
	static char	b[BUFFER_SIZE + 1] = {0};
	char		*ret;
	int			read_ret;
	char		*tmp;

	printf("GNL Called\n");
	ret = NULL;
	tmp = ft_strchr(b, '\n');
	printf("Before Loop\n");
	while (!tmp)
	{
		printf("Loop Start\n");
		if (!str_append_str(&ret, b))
			return (NULL);
		printf("Hello\n");

		b[0] = '\0';
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		if (read_ret == 0)
			break ;
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n');
		printf("Loop end\n");
	}
	if (tmp)
	{
		if (!str_append_mem(&ret, b, tmp - b + 1))
		{
			free(ret);
			return (NULL);
		}
		ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	}
	else
	{
		b[0] = '\0';
		if (!ret || !*ret)
		{
			free(ret);
			return (NULL);
		}
	}
	return (ret);
}

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd = open("broken_gnl.c", O_RDONLY);

	char *str = get_next_line(fd);
	printf("%s\n", str);
}