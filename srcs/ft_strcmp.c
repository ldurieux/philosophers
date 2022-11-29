/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 22:52:30 by ldurieux          #+#    #+#             */
/*   Updated: 2022/11/29 22:52:31 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*r1;
	const unsigned char	*r2;

	r1 = (const unsigned char *)s1;
	r2 = (const unsigned char *)s2;
	if (!r1 || !r2)
		return ((int)(r1 - r2));
	while (*r1 == *r2 && *r1)
	{
		r1++;
		r2++;
	}
	return (*r1 - *r2);
}
