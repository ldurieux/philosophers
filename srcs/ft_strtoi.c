/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:16:05 by ldurieux          #+#    #+#             */
/*   Updated: 2022/08/11 16:16:06 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#define BASE_10_LEN 10

static int	ft_is_whitespace(const char chr)
{
	return (chr == ' ' || chr == '\f' || chr == '\n'
		|| chr == '\r' || chr == '\t' || chr == '\v');
}

static int	ft_is_digit(const char chr)
{
	return (chr >= '0' && chr <= '9');
}

int	ft_strtoui(const char *str, char **end_ptr)
{
	int	res;
	int	tmp;

	if (!str)
		return (0);
	res = 0;
	while (ft_is_whitespace(*str))
		str++;
	if (*str == '+')
		str++;
	while (ft_is_digit(*str))
	{
		tmp = res * BASE_10_LEN + (*str++ - '0');
		if (tmp < res)
		{
			res = INT_MAX;
			break ;
		}
		res = tmp;
	}
	if (end_ptr)
		*end_ptr = (char *)str;
	return (res);
}
