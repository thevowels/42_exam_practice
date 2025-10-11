/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 15:52:21 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/10 16:00:20 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int ft_print(char c)
{	
	int i;

	if(c >= 'a' && c <= 'z')
	{
		i = 0;
		while(i <= c - 'a')
		{
			write(1,&c,1);
			i++;
		}
	}
	else if(c >= 'A' && c <= 'Z')
	{
		i = 0;
		while(i <= c - 'A')
		{
			write(1,&c,1);
			i++;
		}
	}
	else
		write(1,&c,1);
	return (0);
	
}

int main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 2)
	{
		while(argv[1][i])
		{
			ft_print(argv[1][i]);
			i++;
		}
	}
	write(1,"\n",1);
	return (1);

}