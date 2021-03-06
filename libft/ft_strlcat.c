/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 20:03:42 by jekim             #+#    #+#             */
/*   Updated: 2021/01/21 00:21:16 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t dst_l;
	size_t src_l;
	size_t ix;

	dst_l = (unsigned int)ft_strlen(dst);
	src_l = (unsigned int)ft_strlen(src);
	ix = 0;
	if (n < dst_l)
		return (n + src_l);
	if (n > dst_l)
	{
		while (src[ix] && ix < (n - dst_l - 1))
		{
			dst[dst_l + ix] = src[ix];
			ix++;
		}
		dst[dst_l + ix] = '\0';
	}
	return (src_l + dst_l);
}
