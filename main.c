/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 07:50:19 by jekim             #+#    #+#             */
/*   Updated: 2021/05/30 08:10:41 by jekim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "xaolinwu.h"

int main(int argc, char **argv)
{
	if (argc != 5)
		return (1);
	int x = ft_atoi(argv[1]);
	int y = ft_atoi(argv[2]);
	int x1 = ft_atoi(argv[3]);
	int y1 = ft_atoi(argv[4]);
	void *mlx_ptr;
	void *win_ptr;

	printf("%d %d %d %d", x, y, x1, y1);

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "xaolinwu_practice");
	mlx_loop(mlx_ptr);
	return (0);
}