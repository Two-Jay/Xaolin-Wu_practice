/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:09:51 by jekim             #+#    #+#             */
/*   Updated: 2021/01/17 19:29:28 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	ix;

	ix = 0;
	if (!dst || !src)
		return (0);
	if (!dstsize)
		return (ft_strlen(src));
	if (dstsize != 0)
	{
		while (src[ix] && ix < (dstsize - 1))
		{
			dst[ix] = src[ix];
			ix++;
		}
		dst[ix] = '\0';
	}
	return (ft_strlen(src));
}
