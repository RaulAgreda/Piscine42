/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:48:57 by ragreda-          #+#    #+#             */
/*   Updated: 2022/09/01 17:18:22 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (range == 0)
		return (-1);
	size = max - min;
	if (size < 0)
		size = -size;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = malloc(sizeof(int) * size);
	if (*range == 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		(*range)[i] = i + min;
		i++;
	}
	return (size);
}
