#include "broken_gnl.h"
#include <stdio.h>

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

	// printf("inside strlen\n");
	// printf("S is %p\n", s);
	ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}
/*

	create new memory
	copy content of s1
	append content of s2
	free(s1);
	We've mem A & B
	mem[0,1,2,3,4]
	A => 0
	B => 3

	appendmem(B,A, B - A);
	=> 
*/
int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1;
	char	*tmp;

	size1 = *s1 ? ft_strlen(*s1) : 0;
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
	// printf("str_append_str\n");
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
/*
	If you compile and run the program,
		you can see that There is an error before the end of the loop.
	We've to fix that.
*/

/*

	b => for sure, its going to be the buffer to read from the file.
	read_ret => the count of the read value.
	ret => return ? retain?
	tmp => ?

	initiate buffer.
	set ret = NULL
	tmp =  if \n => pointer to \n else  => NULL

	while(there is no tmp [which means there is no newline inside our stash])
	{

	}
*/
#include <string.h>
char	*get_next_line(int fd)
{
	char		b[BUFFER_SIZE + 1] = {0};
	static char	*ret;
	int			read_ret;
	char		*tmp;

	// printf("GNL Called\n");
	if(ret)
		tmp = ft_strchr(ret, '\n');
	else
		tmp = NULL;
	// printf("Before Loop\n");
	while (!tmp)
	{
		b[0] = '\0';
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		if (read_ret == 0)
			break ;
		b[read_ret] = 0;
		// printf("After read: b = %s\n", b);
		if (!str_append_str(&ret, b))
			return (NULL);
		tmp = ft_strchr(b, '\n');
		// printf("Loop end\n");
	}
	if (tmp)
	{
		// printf("RET X%s\n", ret);
		// printf("xxxxxxxxxxxxxxxx\n");
		// printf("TMP X%s\n", tmp);
		// printf("KKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK\n");
		tmp = NULL;
		if (!str_append_mem(&tmp, ret, (ft_strchr(ret,'\n') - ret) + 1 ))
		{
			free(ret);
			return (NULL);
		}
		// printf("RET X%s\n", ret);
		// printf("xxxxxxxxxxxxxxxx\n");
		// printf("TMP X%s\n", tmp);
		// printf("-------------------------------------------------\n");
		ft_memmove(ret, ft_strchr(ret,'\n')+1 , ft_strlen((ft_strchr(ret,'\n')) + 1) + 1);
		// printf("RET X%s\n", ret);
		// printf("xxxxxxxxxxxxxxxx\n");
		// printf("TMP X%s\n", tmp);
	}
	else
	{
		b[0] = '\0';
		if (!ret || !*ret)
		{
			free(ret);
			return (NULL);
		}
		if(!str_append_mem(&tmp,ret,ft_strlen(ret)))
		{
			free(ret);
			return(NULL);
		}
		free(ret);
	}
	return (tmp);
}

#include <fcntl.h>

int	main(void)
{
	int fd = open("input", O_RDONLY);

	char *str = get_next_line(fd);
	// while(str)
	// {
	// 	printf("%s\n",str);
	// 	free(str);
	// 	str = get_next_line(fd);
	// }
	// printf("After gnl\n");
	// if(str)
	// 	printf("Returned : XXXXX\n%sXXX\n", str);
}