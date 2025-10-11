/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotone.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:31:09 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/11 09:38:03 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

int ft_isalpha(int c)
{
	return ( ((unsigned)c | 32) - 'a' < 26 );
}

void do_rot(char c)
{
	int is_lower;

	if(ft_isalpha(c))
	{
		is_lower = (unsigned) c - 'a' < 26;
		c = c - ('A' * !is_lower + 'a' * is_lower);
		c += 1;
		c = c % 26;
		c = c + ('A' * !is_lower + 'a' * is_lower);
		write(1,&c,1);
	}
	else
	{
		write(1, &c, 1);
	}
}



int main(int argc, char **argv)
{
	if(argc == 2)
	{
		while(*argv[1])
		{
			do_rot(*argv[1]);
			argv[1]++;
		}
	}
	write(1,"\n", 1);
}