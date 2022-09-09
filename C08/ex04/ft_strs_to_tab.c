/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 20:46:43 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/28 21:21:16 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != 0)
		count++;
	return (count);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*sdup;

	i = 0;
	while (src[i] != 0)
		i++;
	sdup = (char *)malloc(sizeof(char) * (i + 1));
	if (sdup == 0)
		return (0);
	i = 0;
	while (src[i] != 0)
	{
		sdup[i] = src[i];
		i++;
	}
	sdup[i] = 0;
	return (sdup);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*st;

	st = malloc(sizeof(t_stock_str) * (ac + 1));
	if (st == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		st[i].str = av[i];
		st[i].size = ft_strlen(av[i]);
		st[i].copy = ft_strdup(av[i]);
		i++;
	}
	st[i].str = 0;
	st[i].size = 0;
	st[i].copy = 0;
	return (st);
}
