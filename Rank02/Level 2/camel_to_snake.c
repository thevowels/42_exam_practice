/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camel_to_snake.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:48:19 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 12:36:58 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

/**
 * @brief to distinguish uppercase characters as we've to mutate them
 * @param c
 * @return 1 if the char is uppercase alpha, 0 otherwise.
 */
int	is_upper(char c)
{
	return ((unsigned)c - 'A' < 26);
}

/**
 * @brief To get the length of result string
 *
 * @param s
 * @return int
 */
int	cal_length(char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (is_upper(s[i]))
			len += 1;
		i++;
		len++;
	}
	return (len);
}

/**
 * @brief convert from camel to snake case and print out the result
 * @param s the string to convert
 * 
 * @note At first calculate the length of result string.
 * As we've to conver all uppercase chars with 
 * 
 */

void	camel_to_snake(char *s)
{
	char	*result;
	int		res_length;
	int		i;

	i = 0;
	res_length = cal_length(s);
	result = malloc(sizeof(char) * (res_length));
	while (*s)
	{
		if (is_upper(*s))
		{
			result[i] = '_';
			i += 1;
			result[i] = *s | 32;
		}
		else
		{
			result[i] = *s;
		}
		s++;
		i++;
	}
	write(1, result, res_length);
	free(result);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		camel_to_snake(argv[1]);
	}
	write(1, "\n", 1);
}
