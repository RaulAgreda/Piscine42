/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:40:06 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/26 12:38:37 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	return ((c == ' ' || c == '\n' || c == '\t'
			|| c == '\f' || c == '\v' || c == '\r'));
}

int	check_correct_base(char *base)
{
	int	i;
	int	j;
	int	length;

	length = 0;
	while (base[length] != 0)
	{
		if (base[length] == '+' || base[length] == '-' || base[length] == ' ')
			return (0);
		length++;
	}
	i = 0;
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

int	analyze_first_part(char *str, int *end_index)
{
	int	sign;
	int	i;

	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	*end_index = i;
	return (sign);
}

int	index_of_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != 0)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	n;
	int	b;
	int	idx;

	n = 0;
	b = check_correct_base(base);
	if (b <= 1)
		return (0);
	sign = analyze_first_part(str, &i);
	while (index_of_base(str[i], base) != -1)
	{
		idx = index_of_base(str[i], base);
		n = n * b + idx;
		i++;
	}
	return (n * sign);
}
