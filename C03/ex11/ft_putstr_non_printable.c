/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:00:42 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/22 12:17:53 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	buf[3];
	char	*hex;

	hex = "0123456789abcdef";
	buf[0] = '\\';
	i = 0;
	while (str[i] != 0)
	{
		if (!(str[i] >= 32 && str[i] <= 126))
		{
			buf[1] = hex[(unsigned char)str[i] / 16];
			buf[2] = hex[(unsigned char)str[i] % 16];
			write(1, buf, 3);
		}
		else
			write(1, str + i, 1);
		i++;
	}
}
/*
int	main(int argc, char **argv)
{
	ft_putstr_non_printable("Coucou\ntu vas bien ?");
	char c[] = "Hola a que tal";
	c[5] = 127;
	ft_putstr_non_printable(c);
}*/
