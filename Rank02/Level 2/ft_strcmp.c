/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 13:25:29 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/15 13:33:37 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(*s1 && *s2)
	{
		if(*s1 != *s2)
			return (*s1 - *s2);
	}
	if(*s1)
		return (*s1);
	return (*s2);
}

int main(void)
{
	char *s1 = "asdf";
	char *s2 = "b";

	printf("Result %d \n", ft_strcmp(s1,s2));
}