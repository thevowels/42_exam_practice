/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:42:13 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/12 09:08:34 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_solution(int *board)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = board[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_safe(int *board, int col)
{
	int	check;

	if (col == 0)
		return (1);
	check = 0;
	while (check < col)
	{
		if (board[check] == board[col])
			return (0);
		if ((check - col) == (board[check] - board[col]) || (check - col)
			== -(board[check] - board[col]))
			return (0);
		check++;
	}
	return (1);
}

void	solve_ten_queen(int *count, int *board, int col)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		board[col] = i;
		if (is_safe(board, col))
		{
			if (col == 9)
			{
				(*count) += 1;
				ft_print_solution(board);
			}
			else
			{
				solve_ten_queen(count, board, col + 1);
			}
		}
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	count;
	int	board[10];

	count = 0;
	solve_ten_queen(&count, board, 0);
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	int	count;

	count = ft_ten_queens_puzzle();
	printf("Total number of solution found is %i", count);
}
*/