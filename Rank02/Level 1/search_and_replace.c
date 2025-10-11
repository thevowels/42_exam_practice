/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:39:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/11 09:56:53 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"

int	ft_ischar(char *s)
{
	return (s[1] == 0);
}

int ft_update(char *s, char c, char v)
{
	int	i;
	
	i = 0;
	while(s[i])
	{
		if(s[i] == c)
			s[i] = v;
		i++;
	}
	return i;
}

int	main(int argc, char **argv)
{
	int	i;


	if (argc == 4 && ft_ischar(argv[2]) && ft_ischar(argv[3]))
	{
		i = ft_update(argv[1], *argv[2], *argv[3]);
		write(1, argv[1], i);
	}
	write(1, "\n", 1);
	return (0);
}