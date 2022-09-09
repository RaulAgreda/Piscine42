/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ragreda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 15:51:33 by ragreda-          #+#    #+#             */
/*   Updated: 2022/08/23 16:53:23 by ragreda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_charcapitalize(char *c)
{
	if (*c >= 'a' && *c <= 'z')
	{
		*c -= 32;
		return (1);
	}
	return (0);
}

void	strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int	is_alpha_numeric(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		return (1);
	if (*c >= 'A' && *c <= 'Z')
		return (1);
	if (*c >= '0' && *c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	strlowcase(str);
	ft_charcapitalize(str);
	while (str[i] != 0)
	{
		if (!is_alpha_numeric(str + i))
			if (ft_charcapitalize(str + i + 1))
				i++;
		i++;
	}
	return (str);
}
