/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:23:27 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/17 12:48:19 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str)
{
	int	is_lowercase;

	is_lowercase = 1;
	while (*str != 0)
	{
		if (!(*str >= 'a' && *str <= 'z'))
			is_lowercase = 0;
		str++;
	}
	return (is_lowercase);
}
