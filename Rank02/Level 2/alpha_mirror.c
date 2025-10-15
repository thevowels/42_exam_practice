/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_mirror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:37:45 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 12:31:00 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_isalpha(int c)
{
	return (((unsigned)c | 32) - 'a' < 26);
}

void	alpha_mirror(char *s)
{
	int	is_lower;
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
		{
			is_lower = (unsigned)s[i] - 'a' < 26;
			s[i] = s[i] - ('a' * is_lower + 'A' * !is_lower);
			s[i] = 25 - s[i];
			s[i] = s[i] + ('a' * is_lower + 'A' * !is_lower);
		}
		i++;
	}
	write(1, s, i);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		alpha_mirror(argv[1]);
	}
	write(1, "\n", 1);
	return (0);
}
