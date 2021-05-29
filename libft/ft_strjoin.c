/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 05:39:20 by jekim             #+#    #+#             */
/*   Updated: 2021/01/17 19:27:40 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*ret;
	size_t	s1_l;
	size_t	s2_l;
	size_t	ix;
	size_t	jx;

	ix = -1;
	jx = 0;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1 || !s2)
		return (!(s1) ? ft_strdup(s2) : ft_strdup(s1));
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (s1_l + s2_l + 1))))
		return (NULL);
	while (++ix < s1_l)
		ret[ix] = s1[ix];
	while (jx < s2_l)
		ret[ix++] = s2[jx++];
	ret[ix] = '\0';
	return (ret);
}
