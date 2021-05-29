/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 01:54:55 by jekim             #+#    #+#             */
/*   Updated: 2021/01/23 07:24:28 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_count_words(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static unsigned int	ft_wordlen(const char *s, char c)
{
	unsigned int	len;

	len = 0;
	while (*s != '\0' && (*s != c && *s != '\0'))
	{
		len++;
		s++;
	}
	return (len);
}

static void			*ft_free_ret(char **ret, unsigned int ix)
{
	unsigned int	jx;

	jx = 0;
	while (jx < ix)
	{
		free(ret[jx]);
		jx++;
	}
	free(ret);
	return (NULL);
}

static char			**ft_fill_strings_to_ret(const char *s, char c,
				unsigned int words_count, char **ret)
{
	unsigned int	ix;
	unsigned int	len;

	ix = 0;
	len = 0;
	while (ix < words_count)
	{
		while (*s == c)
			s++;
		len = ft_wordlen(s, c);
		if (!(ret[ix] = (char *)malloc(sizeof(char) * (len + 1))))
			return (ft_free_ret(ret, ix - 1));
		ft_strlcpy(ret[ix], s, len + 1);
		s += len;
		ix++;
	}
	ret[ix] = NULL;
	return (ret);
}

char				**ft_split(const char *s, char c)
{
	char			**ret;
	unsigned int	words_count;

	if (!s)
		return (NULL);
	words_count = ft_count_words(s, c);
	if (!(ret = (char **)malloc(sizeof(char *) * (words_count + 1))))
		return (NULL);
	ft_fill_strings_to_ret(s, c, words_count, ret);
	return (ret);
}
