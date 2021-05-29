/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 04:10:56 by jekim             #+#    #+#             */
/*   Updated: 2021/01/24 14:03:05 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int ix;
	unsigned int jx;
	unsigned int ndl_l;

	ix = 0;
	jx = 0;
	ndl_l = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!(ndl_l = (unsigned int)ft_strlen(needle)))
		return ((char *)haystack);
	while (haystack[ix] && ix + 1 <= n)
	{
		if (haystack[ix] == needle[jx] && jx == ndl_l - 1)
			return ((char *)haystack + ix - jx);
		else if (haystack[ix] == needle[jx] && jx < ndl_l - 1)
			jx++;
		else if (haystack[ix] != needle[jx])
		{
			ix -= jx;
			jx = 0;
		}
		ix++;
	}
	return (NULL);
}
