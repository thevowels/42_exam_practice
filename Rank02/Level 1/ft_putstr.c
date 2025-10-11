/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:41:39 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/10 15:44:34 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	if (!str || !str[0])
		return ;
	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
}

int	main(void)
{
	ft_putstr("Hello World");
}