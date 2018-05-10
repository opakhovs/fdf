/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/02 15:12:54 by opakhovs          #+#    #+#             */
/*   Updated: 2018/04/02 19:00:30 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include <mlx.h>

int		freeline(char **res)
{
	free((*res));
	(*res) = NULL;
	return (1);
}

void	addit_to_map(char ***res, int length, char *str)
{
	char	**temp;
	int		size;
	int		i;

	size = ft_strcount(res);
	i = -1;
	temp = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size && (temp[i] = ft_strnew(ft_strlen((*res)[i]))))
		ft_strcpy(temp[i], (*res)[i]);
	temp[i] = NULL;
	freestr(res);
	(*res) = (char **)malloc(sizeof(char *) * (size + 2));
	i = -1;
	while (++i < size)
	{
		(*res)[i] = ft_strnew(ft_strlen(temp[i]));
		ft_strcpy((*res)[i], temp[i]);
	}
	(*res)[i] = ft_strnew(length);
	ft_strcpy((*res)[i], str);
	(*res)[i + 1] = NULL;
	freestr(&temp);
}

void	reader(int fd, t_map **map, char ***read)
{
	int		i;
	char	*line;
	int		count;
	int		step;

	line = ft_strnew(1);
	while (freeline(&line) && (get_next_line(fd, &line)) > 0)
		addit_to_map(read, ft_strlen(line), line);
	(*map)->map = (int **)malloc(sizeof(int *) * ft_strcount(read));
	count = -1;
	(*map)->line = ft_strcount(read);
	(*map)->column = count_num((*read)[0]);
	while (++count < (*map)->line && (step = -1))
	{
		(*map)->map[count] = (int *)malloc(sizeof(int) * (*map)->column);
		i = 0;
		while (++step < (*map)->column)
			(*map)->map[count][step] = atoii((*read)[count], &i);
	}
	(*map)->map[count] = NULL;
	freeline(&line);
}

int		main(int ar, char **av)
{
	t_map	*map;
	int		fd;
	char	**read;

	read = (char **)malloc(sizeof(char *) * 1);
	*read = NULL;
	if (ar == 2 && ((fd = open(av[1], O_RDONLY)) != -1))
	{
		map = (t_map *)malloc(sizeof(t_map));
		reader(fd, &map, &read);
		check_draw(map);
		if (!(map->mlx = mlx_init()))
			return (0);
		if (!(map->win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "FDF")))
			return (0);
		map->name = av[1];
		draw(map);
		mlx_key_hook(map->win, deal, map);
		mlx_loop(map->mlx);
	}
	else
		ft_putstr("need be: ./fdf file\n");
	freestr(&read);
	return (0);
}
