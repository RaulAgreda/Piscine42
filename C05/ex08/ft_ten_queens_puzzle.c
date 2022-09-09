/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 11:45:39 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/27 11:47:04 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_solution(int *board)
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

int	correct_solution(int *board, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (board[i] == board[j]
				|| board[j] == board[i] + (j - i)
				|| board[j] == board[i] + (i - j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	generate(int row, int *board, int *nsol)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		board[row] = j;
		if (row == 9)
		{
			if (correct_solution(board, 10))
			{
				print_solution(board);
				(*nsol)++;
			}
		}
		else
		{
			if (row == 0 || correct_solution(board, row + 1))
				generate(row + 1, board, nsol);
		}
		j++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	n_solutions;

	n_solutions = 0;
	generate(0, board, &n_solutions);
	return (n_solutions);
}
