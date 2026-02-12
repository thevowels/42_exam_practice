/*
	Step 1: Here I will fix the syntax errors first.
		Most of them are syntatx error but some of them are related to the nature of the problem. which means logical errors are also inevitable if we encounter.
		You can see most of the error instantly just by compiling cc broken_gnl.c.
		The compiler shows us all errors it can see at the compile process. If you want to go a little bit deeper, you can make some research about compile languages.

	Note: cc broken_gnl_before_fix.c &> out
		  cc broken_gnl_after_fix.c &> outfix
	// This will help you to compare the results before and after fix.
*/

/*
broken_gnl_step1.c:7:10: error: 'broken_gnl.h' file not found with <angled> include; use "quotes" instead
#include <broken_gnl.h>
         ^~~~~~~~~~~~~~
         "broken_gnl.h"

		 // Here we can see we are using <> notation instead of "". It even shows us the solution right away.
		
		 Fix: use "" notation instead of <>
		 fix and compile again.
*/
#include "broken_gnl.h"

/*
broken_gnl_step1.c:28:10: error: incompatible pointer to integer conversion returning 'char *' from a function with result type 'char'; dereference with * [-Wint-conversion]
                return (s + i);

				// here we've got error as we are returning char * instead of char.
				Here, we need to fix in 2 ways.
					1. change return type of function
					2. change return value of the function.
				What to choose? if you examine about the nature of the usage of the function in gnl , we can see that we want to get the location of the char. so the return type should be char *
				There is no absolute way to tell we are correct or not as we are fixing other person's code. Lets stick with case 1 for now.
				If there is an error, we can always fix the code. Right?
				
				Current Fix:  change return type of function

*/
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

/*

broken_gnl_step1.c:84:25: warning: incompatible pointer types passing 'char **' to parameter of type 'char *'; dereference with * [-Wincompatible-pointer-types]
        size1 = s1 ? ft_strlen(s1) : 0;
                               ^~
                               *
broken_gnl_step1.c:66:24: note: passing argument to parameter 's' here
size_t  ft_strlen(char *s)

	here we can see the errror log.
	If you are using vscode, the errors are on red, warning on some color and there is note with just grey color.
	Here its showing line 66 , function declaration of ft_strlen. But thats just pointing out us to see the function.
	There is nothing wrong about note.
	We've to focus on warning message.

	What we get from error message:
		imcompitable type
	What we have to do?
		we have to  change the types

	Current fix?
		I'll just take a hunch and change the type of s1 into char * instead of char ** on str_append_mem function declaration
	
	After fix, I still got the error so how about changing the parameter passed into strlen instead of function definition.?
		Yeah it worked, atleast there is no more warning inside the str_append_mem.

*/
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
/*

broken_gnl_step1.c:126:43: error: incompatible integer to pointer conversion passing 'char' to parameter of type 'char *'; take the address with & [-Wint-conversion]
        return (str_append_mem(s1, s2, ft_strlen(s2)));
                                                 ^~
	Problem:
		incompatible int to pointer conversion.
	Current Fix:
		change the parameter from char to char * as the function name suggests str_append_str so both parameters should be somehow compatible with str.
*/

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}
/*

broken_gnl_step1.c:144:3: error: void function 'ft_memmove' should not return a value [-Wreturn-type]
                return (ft_memcpy(dest, src, n));
                ^      ~~~~~~~~~~~~~~~~~~~~~~~~~
broken_gnl_step1.c:146:3: error: void function 'ft_memmove' should not return a value [-Wreturn-type]
                return (dest);
                ^      ~~~~~~

	Problem:
		void function returning values
	
	Current fix:
		if you check man memmove, you can see it return void * (pointer to any type)
		change the return type from void to void *


*/
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
		((char *)dest)[i] = ((char)src)[i];
	}
	return (dest);
}

char	get_next_line(int fd)
{
	static char b[BUFFER_SIZE + 1] = ();
	char *ret;
	int read_ret;

	ret = NULL;
	char *tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		b[0] = '\0';
		read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		if (read_ret == 0)
			break ;
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n');
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

#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	int fd= open("broken_gnl.c", O_RDONLY);

	char *str = get_next_line(fd);
	printf("%s\n", str);
}