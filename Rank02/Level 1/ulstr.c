/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:58:27 by aphyo-ht          #+#    #+#             */
/*   Updated: 2025/10/11 10:04:56 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
int main(int argc, char **argv)
{
	int i;

	if( argc == 2)
	{	
		i = 0;
		while(argv[1][i])
		{
			if( (unsigned)argv[1][i] - 'A' < 26)
				argv[1][i] += 32;
			else if( (unsigned)argv[1][i] - 'a' < 26)
				argv[1][i] -= 32;
			i++;
		}
		write(1,argv[1],i);
	}
	write(1,"\n",1);
	return (0);
}