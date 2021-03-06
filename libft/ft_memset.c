/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 19:59:22 by jekim             #+#    #+#             */
/*   Updated: 2021/01/14 04:32:33 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char *temp;
	unsigned char value;

	temp = dst;
	value = c;
	while (n--)
	{
		*temp++ = value;
	}
	return ((void *)dst);
}
