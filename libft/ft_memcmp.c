/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:31:23 by jekim             #+#    #+#             */
/*   Updated: 2021/01/18 08:50:30 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	size_t			ix;

	ix = 0;
	s1 = (unsigned char *)ptr1;
	s2 = (unsigned char *)ptr2;
	if ((!ptr1 && !ptr2) || !n)
		return (0);
	while (ix < n)
	{
		if (s1[ix] != s2[ix])
			return (s1[ix] - s2[ix]);
		ix++;
	}
	return (0);
}
