/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 23:40:43 by jekim             #+#    #+#             */
/*   Updated: 2021/01/14 04:53:32 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char *s;
	unsigned char find;

	s = (unsigned char *)src;
	find = c;
	while (n--)
	{
		if (*s != find)
			s++;
		else
			return (s);
	}
	return (0);
}
