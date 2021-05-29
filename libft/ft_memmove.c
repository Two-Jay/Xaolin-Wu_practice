/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 03:39:13 by jekim             #+#    #+#             */
/*   Updated: 2021/01/17 19:05:51 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			ix;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	ix = 0;
	if (d == s || n <= 0)
		return (dst);
	if (d > s)
	{
		while (n--)
			d[n] = s[n];
	}
	else
	{
		while (ix < n)
		{
			d[ix] = s[ix];
			ix++;
		}
	}
	return (dst);
}
