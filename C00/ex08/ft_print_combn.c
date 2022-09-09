/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 11:52:26 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/16 13:18:09 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_combn(int n)
{
	char	buffer[9];
	int		i;

	buffer[0] = '0' - 1;
	i = 0;
	while (buffer[0] < 10 - n + '0')
	{
		while (buffer[i] >= 10 - n + i + '0')
			i--;
		buffer[i]++;
		while (i < n - 1)
		{
			i++;
			buffer[i] = buffer[i - 1] + 1;
		}
		while (buffer[i] <= 10 - n + i + '0')
		{
			write(1, buffer, n);
			buffer[i]++;
			if (buffer[0] < 10 - n + '0' || (n == 1 && buffer[0] == '9'))
				write(1, ", ", 2);
		}
	}
}
