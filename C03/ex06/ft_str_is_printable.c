/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 12:23:27 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/17 13:33:54 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str)
{
	int	is_printable;

	is_printable = 1;
	while (*str != 0)
	{
		if (!(*str >= 32 && *str <= 126))
			is_printable = 0;
		str++;
	}
	return (is_printable);
}
