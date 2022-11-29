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
