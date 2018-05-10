/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:50:07 by opakhovs          #+#    #+#             */
/*   Updated: 2018/04/19 15:50:08 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		calc_y1(t_map *dr, int x, int y)
{
	return (dr->dy + dr->map[y / dr->sy][(x + dr->sx) / dr->sx]
		* dr->z + (x + y + dr->sx) / 2);
}

int		calc_y2(t_map *dr, int x, int y)
{
	return (dr->dy + dr->map[(y + dr->sy) / dr->sy][x / dr->sx]
		* dr->z + (x + y + dr->sy) / 2);
}
