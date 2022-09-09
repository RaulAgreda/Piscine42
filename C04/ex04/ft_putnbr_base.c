/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 10:40:49 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/25 20:55:48 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_correct_base(char *base)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = 0;
	while (base[length] != 0)
	{
		if (base[length] == '+' || base[length] == '-' || base[length] == ' ')
			return (0);
		length++;
	}
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (length);
}

void	print_str(char *buffer, int i)
{
	while (i-- > 0)
		write(1, buffer + i, 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		b;
	char	buffer[sizeof(int) * 8 + 1];
	int		i;

	i = 0;
	b = check_correct_base(base);
	if (b <= 1)
		return ;
	if (nbr == 0)
		write(1, &base[0], 1);
	if (nbr < 0)
		write(1, "-", 1);
	while (nbr != 0)
	{
		if (nbr % b < 0)
			buffer[i] = base[-(nbr % b)];
		else
			buffer[i] = base[nbr % b];
		nbr /= b;
		i++;
	}
	print_str(buffer, i);
}
