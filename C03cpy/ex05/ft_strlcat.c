/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:10:47 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/25 12:18:29 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (str[length] != 0)
		length++;
	return (length);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	d_length;
	unsigned int	s_length;

	d_length = ft_strlen(dest);
	s_length = ft_strlen(src);
	i = 0;
	j = 0;
	if (size == 0 || size <= d_length)
		return (s_length + size);
	while (dest[i] != 0)
		i++;
	while (src[j] != 0 && j < size - d_length - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (d_length + s_length);
}
