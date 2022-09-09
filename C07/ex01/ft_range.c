/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:48:52 by ragreda-          #+#    #+#             */
/*   Updated: 2022/09/01 16:15:48 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	if (min >= max)
		return (0);
	range = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (i < max - min)
	{
		range[i] = i + min;
		i++;
	}
	return (range);
}
