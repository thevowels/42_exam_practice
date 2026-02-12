/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_queens_re.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aphyo-ht <aphyo-ht@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 09:59:22 by aphyo-ht          #+#    #+#             */
/*   Updated: 2026/02/12 10:14:10 by aphyo-ht         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


void print_solution(int *board, int queens)
{
	int i;

	i = 0;
	while(i < queens)
	{
		printf("%d", board[i]);
		if(i != queens -1)
			printf(" ");
		i++;
	}
	printf("\n");
}
int ft_issafe(int *board, int queens, int col)
{
	int old_col;

	if(col == 0)
		return (1);
	old_col = 0;
	while(old_col < col)
	{
		if(board[old_col] == board[col])
			return (0);
		if((col - old_col) == abs(board[old_col] - board[col]))
			return (0);
		old_col++;
	}
	return (1);
}

void backtrack(int *board,int queens, int col)
{
	int row;

	row = 0;
	while(row < queens)
	{
		board[col] = row;
		if(ft_issafe(board, queens, col))
		{
			if(col == queens -1)
				print_solution(board,queens);
			else
				backtrack(board, queens, col +1);
		}
		row++;
	}
}

void n_queens(int queens)
{
	int *board;

	board = (int *) malloc(sizeof(int) * queens);
	if(!board)
		exit(EXIT_FAILURE);
	backtrack(board, queens, 0);
	free(board);
	
}

int main(int argc, char **argv)
{
	int queens;

	if(argc != 2)
		exit(EXIT_FAILURE);
	queens = atoi(argv[1]);
	if(queens < 0)
		exit(EXIT_FAILURE);
	n_queens(queens);

}