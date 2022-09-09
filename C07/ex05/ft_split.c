/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <ragreda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:26:47 by ragreda-          #+#    #+#             */
/*   Updated: 2022/09/01 18:53:20 by ragreda-         ###   ########.fr       */
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

char	*ft_strdup(char *src, int length)
{
	int		i;
	char	*sdup;

	if (length == 0)
		return (0);
	sdup = (char *)malloc(sizeof(char) * (length + 1));
	if (sdup == 0)
		return (0);
	i = 0;
	while (i < length)
	{
		sdup[i] = src[i];
		i++;
	}
	sdup[i] = 0;
	return (sdup);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	findlen;
	int	i;

	if (*to_find == 0)
		return (str);
	findlen = ft_strlen(to_find);
	while (*str != 0)
	{
		if (*str == to_find[0])
		{
			i = 0;
			while ((str[i] != 0 || to_find[i] != 0) && i < findlen)
			{
				if (str[i] != to_find[i])
					break ;
				else if (i == findlen - 1)
					return (str);
				i++;
			}
		}
		str++;
	}
	return (0);
}

int	n_ocurrences(char *str, char *to_find, int *i)
{
	int		n;
	char	*next;

	*i = 0;
	n = 0;
	next = str;
	while (next != 0 && *next != 0)
	{
		next = ft_strstr(next, to_find);
		if (next != 0)
		{
			n++;
			next++;
		}
	}
	return (n);
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		i;

	ret = malloc(sizeof(char *) * (n_ocurrences(str, charset, &i) + 1 + 1));
	while (ret[i] != 0)
	{
		if (ft_strstr(str, charset))
		{
			if (ft_strstr(str, charset) == str)
			{
				str = ft_strstr(str, charset) + ft_strlen(charset);
				continue ;
			}
			ret[i] = ft_strdup(str, ft_strstr(str, charset) - str);
			str = ft_strstr(str, charset) + ft_strlen(charset);
		}
		else
		{
			ret[i] = ft_strdup(str, ft_strlen(str));
			ret[i + 1] = 0;
		}
		i++;
	}
	return (ret);
}
