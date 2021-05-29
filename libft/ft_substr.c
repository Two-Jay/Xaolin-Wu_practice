/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 01:02:23 by jekim             #+#    #+#             */
/*   Updated: 2021/01/14 04:38:33 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char	*ret;
	size_t	ix;

	ix = 0;
	if (!src)
		return (NULL);
	if (start >= ft_strlen(src))
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (ix < len)
		ret[ix++] = src[start++];
	ret[ix] = '\0';
	return (ret);
}
