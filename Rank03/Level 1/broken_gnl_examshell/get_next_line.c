/*
 * EXERCISE: BROKEN_GNL (Get Next Line)
 *
 * DESCRIPTION:
 * Implement get_next_line that reads line by line from a file descriptor.
 * This version may contain special cases or intentional "bugs".
 */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}
/*

3
=> 
2
1


*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if(n == 0)
		return (dest);
	while (n-- > 0)
		((char *)dest)[n] = ((char *)src)[n];
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	res;

	res = 0;
	while (s && *s)
	{
		s++;
		res++;
	}
	return (res);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	size1 = ft_strlen(*s1);
	tmp = malloc(size2 + size1 + 1);
	if (!tmp)
		return (0);
	ft_memcpy(tmp, *s1, size1);
	ft_memcpy(tmp + size1, s2, size2);
	tmp[size1 + size2] = '\0';
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
	// size_t	i;

	// if (dest < src)
	// 	return (ft_memcpy(dest, src, n));
	// else if (dest == src)
	// 	return (dest);
	// i = ft_strlen((char *)src) - 1;
	// while (i >= 0)
	// {
	// 	((char *)dest)[i] = ((char *)src)[i];
	// 	i--;
	// }
	// return (dest);

	char	*tmp;

	tmp = (char *)malloc(sizeof(char *) * n);
	if (tmp == NULL)
		return (NULL);
	ft_memcpy(tmp, src, n);
	ft_memcpy(dest, tmp, n);
	free(tmp);
	return (dest);

}

char	*get_next_line(int fd)
{
	char		*b;
	static char	*ret = NULL;
	char		*tmp;
	int			read_ret;

	if (fd < 0)
		return (NULL);
	b = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!b)
		return (NULL);
	tmp = ft_strchr(ret, '\n');
	while (!tmp)
	{
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (free(b),NULL);
		if (read_ret == 0)
			break;
		b[read_ret] = 0;
		if (!str_append_str(&ret, b))
			return (NULL);
		tmp = ft_strchr(b, '\n');
	}
	tmp = ft_strchr(ret, '\n');
	free(b);
	b = NULL;
	if(tmp)
	{
		if (!str_append_mem(&b, ret, (tmp - ret) + 1))
		{
			free(ret);
			return (NULL);
		}
		ft_memmove(ret, tmp +1, ft_strlen(tmp + 1)+1);	
	}
	else
	{
		if(!ret || !*ret)
			return (NULL);
		if(!str_append_mem(&b, ret, ft_strlen(ret)))
			return (free(ret), NULL);
		free(ret);
		ret = NULL;
	}
	return (b);
}

// int	main(void)
// {
// 	int fd;
// 	char *str;

// 	fd = open("broken_gnl.c", O_RDONLY);
// 	while (1)
// 	{
// 		str = get_next_line(fd);
// 		if (!str)
// 			break ;
// 		printf("%s", str);
// 		free(str);
// 	}
// }