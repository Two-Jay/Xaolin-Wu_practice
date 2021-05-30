/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jekim <jekim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 07:50:19 by jekim             #+#    #+#             */
/*   Updated: 2021/05/30 09:29:49 by jekim            ###   ########.fr       */
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

void _dla_changebrightness(rgb_color_p from, rgb_color_p to, float br)
{
  if ( br > 1.0 ) br = 1.0;
  /* linear... Maybe something more complex could give better look */
  to->red = br * (float)from->red;
  to->green = br * (float)from->green;
  to->blue = br * (float)from->blue;
}

plot_(X,Y,D)
{
	rgb_color f_;
	f_.red = r; f_.green = g; f_.blue = b;
	_dla_plot(img, (X), (Y), &f_, (D));
	while (0)
	{
		rgb_color f_;
		f_.red = r; f_.green = g; f_.blue = b;
		_dla_plot(img, (X), (Y), &f_, (D));
	}
}

inline void _dla_plot(image img, int x, int y, rgb_color_p col, float br)
{
  rgb_color oc;
  _dla_changebrightness(col, &oc, br);
  put_pixel_clip(img, x, y, oc.red, oc.green, oc.blue);
}


#define ipart_(X) ((int)(X))
#define round_(X) ((int)(((double)(X))+0.5))
#define fpart_(X) (((double)(X))-(double)ipart_(X))
#define rfpart_(X) (1.0-fpart_(X))
 
#define swap_(a, b) do{ __typeof__(a) tmp;  tmp = a; a = b; b = tmp; }while(0)

void draw_line_antialias(image img, unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, color_component r, color_component g, color_component b )
{
	double dx;
	double dy;

	// x2 - x1 , y2 - y1 을 하여 서로의 차를 구한다.
	dx = (double)x2 - (double)x1;
	dy = (double)y2 - (double)y1;
	if ( fabs(dx) > fabs(dy) )
	{
		// 방향에 따른 스왑
		// 즉, 샤오린 우 알고리즘은 x축 기준으로 양의 방향으로 진행할 때 적용됨
		if ( x2 < x1 )
		{
			swap_(x1, x2);
			swap_(y1, y2);
		}
		double gradient = dy / dx;
		double xend = round_(x1);
		double yend = y1 + gradient * (xend - x1);
		double xgap = rfpart_(x1 + 0.5);
		int xpxl1 = xend;
		int ypxl1 = ipart_(yend);
		plot_(xpxl1, ypxl1, rfpart_(yend)*xgap);
		plot_(xpxl1, ypxl1+1, fpart_(yend)*xgap);
		double intery = yend + gradient;
	
		xend = round_(x2);
		yend = y2 + gradient*(xend - x2);
		xgap = fpart_(x2+0.5);
		int xpxl2 = xend;
		int ypxl2 = ipart_(yend);
		plot_(xpxl2, ypxl2, rfpart_(yend) * xgap);
		plot_(xpxl2, ypxl2 + 1, fpart_(yend) * xgap);
	
		int x;
		for(x=xpxl1+1; x < xpxl2; x++)
		{
			plot_(x, ipart_(intery), rfpart_(intery));
			plot_(x, ipart_(intery) + 1, fpart_(intery));
			intery += gradient;
		}
	}
	else
	{
		if ( y2 < y1 )
		{
			swap_(x1, x2);
			swap_(y1, y2);
		}
		double gradient = dx / dy;
		double yend = round_(y1);
		double xend = x1 + gradient*(yend - y1);
		double ygap = rfpart_(y1 + 0.5);
		int ypxl1 = yend;
		int xpxl1 = ipart_(xend);
		plot_(xpxl1, ypxl1, rfpart_(xend)*ygap);
		plot_(xpxl1 + 1, ypxl1, fpart_(xend)*ygap);
		double interx = xend + gradient;
	
		yend = round_(y2);
		xend = x2 + gradient*(yend - y2);
		ygap = fpart_(y2+0.5);
		int ypxl2 = yend;
		int xpxl2 = ipart_(xend);
		plot_(xpxl2, ypxl2, rfpart_(xend) * ygap);
		plot_(xpxl2 + 1, ypxl2, fpart_(xend) * ygap);
	
		int y;
		for(y=ypxl1+1; y < ypxl2; y++)
		{
			plot_(ipart_(interx), y, rfpart_(interx));
			plot_(ipart_(interx) + 1, y, fpart_(interx));
			interx += gradient;
		}
	}
}