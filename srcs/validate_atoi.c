/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kojwatan <kojwatan@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 23:54:38 by kojwatan          #+#    #+#             */
/*   Updated: 2024/03/16 00:10:38 by kojwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	validate_strtol(const char *str, int sign_fg)
{
	int	result;
	int	tmp;

	result = 0;
	while (*str && *str >= '0' && *str <= '9')
	{
		tmp = result;
		result = result * 10 + *str - '0';
		if (result < tmp)
		{
			if (sign_fg == -1)
				return (-1);
			else
				return (-1);
		}
		str++;
	}
	if (*str != '\0' && *str != ' ')
		return (-1);
	if (result == 0 && sign_fg == 1)
		return (-1);
	return (1);
}

int	validate_atoi(const char *str)
{
	int		sign_fg;

	sign_fg = 0;
	if (*str == '\0')
		return (1);
	while (*str && ft_isdigit(*str) == 0)
	{
		if (validate_char(*str) == -1)
			return (-1);
		if (sign_fg == 1)
			return (-1);
		sign_fg = 1;
		str++;
	}
	return ((int)(validate_strtol(str, sign_fg)));
}
