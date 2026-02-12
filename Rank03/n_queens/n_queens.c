/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:16:48 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/12 10:07:30 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void ft_print_solutions(int *board, int queens)
{
	int i;
	
	i  = 0;
	while(i < queens)
	{
		printf("%d", board[i]);
		if(i != queens -1)
			printf(" ");
		i++;
	}
	printf("\n");
	
}

int	ft_queen_safe(int *board, int col)
{
	int	old_col;

	if (col == 0)
		return (1);
	old_col = 0;
	while (old_col < col)
	{
		// printf("old_col %d | col: %d | board[old_col]: %d | board[col]: %d\n", old_col, col, board[old_col], board[col]);
		if (board[old_col] == board[col])
			return (0);
		if ((col - old_col) == abs(board[old_col] - board[col]))
			return (0);
		old_col++;
	}
	return (1);
}

void	backtrack(int *board, int col, int queens)
{
	int	row;

	row = 0;
	while (row < queens)
	{
		board[col] = row;
		if(ft_queen_safe(board, col))
		{
			if(col == queens -1)
				ft_print_solutions(board, queens);
			else
				backtrack(board, col+1,queens);
		}
		row++;
	}
}

void	n_queens(int queens)
{
	int	*board;
	int	i;

	board = (int *)malloc(sizeof(int) * queens);
	if (!board)
		exit(EXIT_FAILURE);
	backtrack(board, 0, queens);
	free(board);
}

int	main(int argc, char *argv[])
{
	int x;

	if (argc != 2)
	{
		printf("Usage: ./n_queens <int>[num_queens]\n");
		exit(EXIT_FAILURE);
	}
	x = atoi(argv[1]);
	if(x < 0)
		exit(EXIT_FAILURE);
	n_queens(x);
	return (0);
}