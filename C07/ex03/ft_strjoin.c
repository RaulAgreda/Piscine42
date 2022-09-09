/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 12:48:28 by ragreda-          #+#    #+#             */
/*   Updated: 2022/09/01 17:50:05 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (dest[i] != 0 || *src != 0)
	{
		if (dest[i] == 0)
			start = 1;
		if (start)
		{
			dest[i] = *src;
			src++;
		}
		i++;
	}
	dest[i] = *src;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		ret_length;
	char	*ret;

	i = 0;
	ret_length = (size - 1) * ft_strlen(sep);
	while (i < size)
	{
		ret_length += ft_strlen(strs[i]);
		i++;
	}
	ret = malloc(sizeof(char) * (ret_length + 1));
	if (ret == 0)
		return (0);
	ret[0] = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(ret, strs[i]);
		if (i < size - 1)
			ft_strcat(ret, sep);
		i++;
	}
	return (ret);
}
