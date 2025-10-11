/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:25:58 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/10 15:34:02 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_put_str(char *s)
{
	int	i;

	i = 0;
	while(*s == 32 || *s == 9)
		s++;
	while (s[i] && s[i] != ' ')
		i++;
	write(1, s, i);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{

		ft_put_str(argv[1]);
	}
	ft_put_str("\n");
	return (1);
}
