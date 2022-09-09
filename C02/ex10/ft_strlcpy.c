/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 16:45:34 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/22 12:03:35 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	length;
	unsigned int	i;

	length = 0;
	while (src[length] != 0)
		length++;
	i = 0;
	while (i < length + 1 && i < size)
	{
		if (i == size - 1)
			dest[i] = 0;
		else
			dest[i] = src[i];
		i++;
	}
	return (length);
}
/*
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int	main(int argc, char **argv)
{
	char dest[100];
	int n = ft_strlcpy(dest, argv[1], atoi(argv[2]));
	write(1, dest, 100);
	printf("\n%d\n", n);
}*/
