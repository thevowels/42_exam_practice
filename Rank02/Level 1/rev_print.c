/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 16:01:43 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/10 16:05:56 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_rev_print(char *str)
{
	int	i;
	i = 0;
	while(str[i])
		i++;
	while( i > 0)
	{
		i--;
		write(1,&str[i],1);	
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
	{
		ft_rev_print(argv[1]);
	}
	write(1,"\n",1);
	return(1);
}