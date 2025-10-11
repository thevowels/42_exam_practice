/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 06:58:16 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/11 09:30:35 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_isalpha(char c)
{
	return ( ((unsigned)c | 32) - 'a' < 26);
}

void rot_13(char c)
{
	int is_lower;

	is_lower = (unsigned)c - 'a' < 26;
	if(ft_isalpha(c))
	{
		c = c - ('A' * !is_lower + 'a' * is_lower);
		c += 13;
		c = c % 26;
		c += ('A' * !is_lower + 'a' * is_lower);
		write(1,&c,1);
	}
	else
		write(1,&c, 1);
}

void do_print(char *s)
{
	while(*s)
	{
		rot_13(*s);
		s++;
	}
}

int	main(int argc, char **argv)
{
	if(argc == 2)
		do_print(argv[1]);
	write(1, "\n", 1);
	return (0);
}