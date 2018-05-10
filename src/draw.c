/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 10:05:33 by opakhovs          #+#    #+#             */
/*   Updated: 2018/04/13 12:18:36 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>
#include <mlx.h>

unsigned long	next(int i, int j, unsigned long color)
{
	if ((i > 0 || j > 0) && color == SKY)
		return (RED);
	else if ((i > 0 || j > 0) && color == RED)
		return (GREEN);
	else if ((i > 0 || j > 0) && color == GREEN)
		return (BLUE);
	else if ((i > 0 || j > 0) && color == BLUE)
		return (YELLOW);
	else if ((i > 0 || j > 0) && color == YELLOW)
		return (BROWN);
	else if ((i > 0 || j > 0))
		return (SKY);
	else if ((i < 0 || j < 0) && color == SKY)
		return (BROWN);
	else if ((i < 0 || j < 0) && color == BROWN)
		return (YELLOW);
	else if ((i < 0 || j < 0) && color == YELLOW)
		return (BLUE);
	else if ((i < 0 || j < 0) && color == BLUE)
		return (GREEN);
	else if ((i < 0 || j < 0) && color == GREEN)
		return (RED);
	else if ((i < 0 || j < 0))
		return (SKY);
	return (color);
}

void			draw_line(t_map *draw, int *tab, int x1, int y1)
{
	int		dx;
	int		dy;
	int		sxy[2];
	int		err[2];
	int		tabxy[2];

	tabxy[0] = tab[0];
	tabxy[1] = tab[1];
	dx = pos(x1, tabxy[0]);
	sxy[0] = tabxy[0] < x1 ? 1 : -1;
	dy = pos(y1, tabxy[1]);
	sxy[1] = tabxy[1] < y1 ? 1 : -1;
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (tabxy[0] != x1 || tabxy[1] != y1)
	{
		mlx_pixel_put(draw->mlx, draw->win, tabxy[0], tabxy[1], draw->color);
		err[1] = err[0];
		if (err[1] > -dx && ((tabxy[0] += sxy[0]) || !tabxy[0]))
			err[0] -= dy;
		if (err[1] < dy && ((tabxy[1] += sxy[1]) || !tabxy[1]))
			err[0] += dx;
	}
}

void			check_draw(t_map *draw)
{
	draw->z = -5;
	draw->dx = WIDTH * 0.35;
	draw->dy = 50;
	draw->zoomx = 0.70;
	draw->zoomy = 0.5;
	draw->sx = (WIDTH * draw->zoomx) / (draw->column - 1);
	draw->sy = (HEIGHT * draw->zoomy) / (draw->line - 1);
	draw->color = SKY;
}

void			draw_lines(t_map *dr, int x, int y)
{
	unsigned long	color;
	int				tabxy[2];

	tabxy[0] = dr->dx + ((x - y) * cos(30.0 * PI / 180.0));
	tabxy[1] = dr->dy + dr->map[y / dr->sy][x / dr->sx] * dr->z + (x + y) / 2;
	color = dr->color;
	if (x / dr->sx < dr->column - 1 && y / dr->sy < dr->line)
	{
		if ((x + dr->sx) / dr->sx < dr->column)
			dr->color = next(dr->map[y / dr->sy][x / dr->sx],
			dr->map[y / dr->sy][(x + dr->sx) / dr->sx], color);
		draw_line(dr, tabxy, dr->dx + ((x + dr->sx) - y) * cos(30.0 * PI
			/ 180.0), calc_y1(dr, x, y));
	}
	dr->color = color;
	if (y / dr->sy < dr->line - 1 && x / dr->sx < dr->column)
	{
		if ((y + dr->sy) / dr->sy < dr->line)
			dr->color = next(dr->map[y / dr->sy][x / dr->sx],
			dr->map[(y + dr->sy) / dr->sy][x / dr->sx], color);
		draw_line(dr, tabxy, dr->dx + (x - (y + dr->sy)) * cos(30.0 * PI
			/ 180.0), calc_y2(dr, x, y));
	}
	dr->color = color;
}

void			draw(t_map *draw)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx_string_put(draw->mlx, draw->win, 0, 0, SKY, draw->name);
	while (x / draw->sx < draw->column || y / draw->sy < draw->line - 1)
	{
		if (x / draw->sx == draw->column && !(x = 0))
			y += draw->sy;
		draw_lines(draw, x, y);
		x += draw->sx;
	}
}
