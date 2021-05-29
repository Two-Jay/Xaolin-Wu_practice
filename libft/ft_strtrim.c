/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 01:02:49 by jekim             #+#    #+#             */
/*   Updated: 2021/01/21 09:47:23 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_start_ix(const char *s1, const char *set, size_t s1_l)
{
	size_t ix;

	ix = 0;
	while (ix < s1_l)
	{
		if (ft_strchr(set, s1[ix]) == 0)
			break ;
		ix++;
	}
	return (ix);
}

static size_t	ft_get_end_ix(const char *s1, const char *set,
				size_t s1_l, size_t start)
{
	size_t ix;

	ix = s1_l;
	while (ix > start)
	{
		if (ft_strrchr(set, s1[ix]) == 0)
			break ;
		ix--;
	}
	return (ix);
}

char			*ft_strtrim(const char *s1, const char *set)
{
	char	*ret;
	size_t	s1_l;
	size_t	start;
	size_t	end;
	size_t	ix;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	ix = 0;
	s1_l = ft_strlen(s1);
	start = ft_get_start_ix(s1, set, s1_l);
	end = ft_get_end_ix(s1, set, s1_l, start);
	if (start >= end)
		return (ft_strdup(""));
	if (!(ret = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (NULL);
	while (start < end + 1)
		ret[ix++] = s1[start++];
	ret[ix] = '\0';
	return (ret);
}
