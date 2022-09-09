/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:56:55 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/24 11:30:29 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*long_to_hex(char *str, long number, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0)
	{	
		str[i] = number % 16 + '0';
		if (str[i] > '9')
			str[i] += 39;
		number /= 16;
		i--;
	}
	return (str);
}

void	print_hex_chars(char *str, int size)
{
	int		i;
	char	buf[2];

	i = 0;
	while (i < 16)
	{
		if (i < size || size == 16)
		{
			write(1, long_to_hex(buf, (long)((unsigned char)(str[i])), 2), 2);
			if (i % 2 == 1)
				write(1, " ", 1);
		}
		else
			write(1, " ", 1);
		i++;
	}
}

void	print_str(char *str, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] < ' ' || str[i] == 127)
			write(1, ".", 1);
		else
			write(1, str + i, 1);
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char	addr_str[16];
	int		i;

	i = 0;
	while ((unsigned int)i < 16 * (size / 16))
	{
		write(1, long_to_hex(addr_str, (long)(addr + i), 16), 16);
		write(1, ": ", 2);
		print_hex_chars(addr + i, 16);
		print_str(addr + i, 16);
		write(1, "\n", 1);
		i += 16;
	}
	if (size % 16 != 0)
	{
		write(1, long_to_hex(addr_str, (long)(addr + i), 16), 16);
		write(1, ": ", 2);
		print_hex_chars(addr + i, size % 16);
		print_str(addr + i, size % 16);
		write(1, "\n", 1);
	}
	return (addr);
}
