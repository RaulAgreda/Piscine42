/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:12:29 by ragreda-          #+#    #+#             */
/*   Updated: 2022/09/01 12:30:32 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	check_correct_base(char *base);
int	analyze_first_part(char *str, int *end_index);
int	index_of_base(char c, char *base);
int	abs(int x);

int	ft_strlen(char *base)
{
	int	count;

	count = 0;
	while (base[count] != 0)
		count++;
	return (count);
}

int	n_digits(int number, int base)
{
	int	n;

	n = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= base;
		n++;
	}
	return (n);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	b;
	int	idx;

	b = ft_strlen(base);
	n = 0;
	i = 0;
	idx = index_of_base(str[i], base);
	while (idx != -1)
	{
		n = n * b + idx;
		i++;
		idx = index_of_base(str[i], base);
	}
	return (n);
}

char	*ft_nbr_base(int n, char *base, int sign)
{
	char	*nbr;
	int		b;
	int		size;
	int		i;

	b = ft_strlen(base);
	size = n_digits(n, b);
	if (sign == -1 && n != 0)
		size ++;
	nbr = malloc(size + 1);
	nbr[size] = 0;
	if (sign == -1 && n != 0)
		nbr[0] = '-';
	nbr[0] = base[0];
	i = size - 1;
	while (n != 0)
	{
		nbr[i] = base[abs(n % b)];
		n /= b;
		i--;
	}
	return (nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	i;
	int	sign;
	int	n;

	if (check_correct_base(base_from) <= 1 || check_correct_base(base_to) <= 1)
		return (0);
	sign = analyze_first_part(nbr, &i);
	n = ft_atoi_base(nbr + i, base_from);
	return (ft_nbr_base(n, base_to, sign));
}
