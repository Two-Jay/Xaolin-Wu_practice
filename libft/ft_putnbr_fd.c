/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 04:22:49 by jekim             #+#    #+#             */
/*   Updated: 2021/01/17 19:28:44 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int nbr;

	if (fd < 0)
		return ;
	if (n < 0)
	{
		write(fd, "-", 1);
		nbr = (unsigned int)(n * -1);
	}
	else
		nbr = (unsigned int)(n);
	if (nbr >= 10)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10 + '0'), fd);
}
