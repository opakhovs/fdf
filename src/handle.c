/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/15 15:32:44 by opakhovs          #+#    #+#             */
/*   Updated: 2018/04/15 15:32:46 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>
#include <mlx.h>

int		deal_arrow_high(int key, t_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	if (key == 126)
		map->dy += 5;
	else if (key == 125)
		map->dy -= 5;
	else if (key == 123)
		map->dx += 5;
	else if (key == 124)
		map->dx -= 5;
	else if (key == 69)
		map->z -= 1;
	else if (key == 78)
		map->z += 1;
	draw(map);
	return (0);
}

int		deal_color(int key, t_map *map)
{
	if (key == 67)
	{
		mlx_clear_window(map->mlx, map->win);
		if (map->color == SKY)
			map->color = RED;
		else if (map->color == RED)
			map->color = GREEN;
		else if (map->color == GREEN)
			map->color = BLUE;
		else if (map->color == BLUE)
			map->color = YELLOW;
		else if (map->color == YELLOW)
			map->color = BROWN;
		else
			map->color = SKY;
		draw(map);
	}
	return (0);
}

int		deal_zoom(int key, t_map *map)
{
	if (key == 30)
	{
		mlx_clear_window(map->mlx, map->win);
		map->zoomx += 0.05;
		map->zoomy += 0.05;
		map->sx = (WIDTH * map->zoomx) / (map->column - 1);
		map->sy = (HEIGHT * map->zoomy) / (map->line - 1);
		draw(map);
	}
	else if (key == 33 && map->zoomy > 0.05)
	{
		mlx_clear_window(map->mlx, map->win);
		map->zoomx -= 0.05;
		map->zoomy -= 0.05;
		map->sx = (WIDTH * map->zoomx) / (map->column - 1);
		map->sy = (HEIGHT * map->zoomy) / (map->line - 1);
		draw(map);
	}
	return (0);
}

int		deal_esc(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}

int		deal(int key, t_map *map)
{
	if (key == 53)
		deal_esc();
	else
	{
		deal_color(key, map);
		deal_zoom(key, map);
		deal_arrow_high(key, map);
	}
	return (0);
}
