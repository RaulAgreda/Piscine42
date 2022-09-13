/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:35:11 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/19 12:35:51 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
