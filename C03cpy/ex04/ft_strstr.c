/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:35:14 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/23 20:11:28 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

int	my_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while ((s1[i] != 0 || s2[i] != 0) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		findlen;

	if (*to_find == 0)
		return (str);
	findlen = my_strlen(to_find);
	while (*str != 0)
	{
		if (*str == to_find[0])
			if (my_strncmp(str, to_find, findlen) == 0)
				return (str);
		str++;
	}
	return (0);
}
