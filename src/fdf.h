/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:10:12 by opakhovs          #+#    #+#             */
/*   Updated: 2018/04/02 18:27:19 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define PI 3.14159265
# define WIDTH 1920
# define HEIGHT 1080
# define RED 0xcc0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define SKY 0xCCEEFF
# define BROWN 0x663300

typedef struct	s_map
{
	void			*mlx;
	void			*win;
	int				**map;
	int				line;
	float			zoomx;
	float			zoomy;
	int				column;
	int				z;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	unsigned long	color;
	char			*name;
}				t_map;

void			freestr(char ***res);
int				atoii(char *format, int *i);
int				ft_strcount(char ***res);
int				count_num(char *str);
int				pos(int x, int y);
void			check_draw(t_map *draw);
void			draw(t_map *draw);
int				deal_arrow_high(int key, t_map *map);
int				deal_color(int key, t_map *map);
int				deal_zoom(int key, t_map *map);
int				deal_esc(void);
int				deal(int key, t_map *map);
int				calc_y1(t_map *dr, int x, int y);
int				calc_y2(t_map *dr, int x, int y);

#endif
