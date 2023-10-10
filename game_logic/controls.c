/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by binanc            #+#    #+#             */
/*   Updated: 2023/07/15 20:09:14 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	vertical_move(t_complete *game, int i, int j)
{
	if (game->map[j][i] == 'E')
	{
		if (game->collectables != 0)
			return (0);
		ft_printf("\nKazandınız, Tebrikler!\n");
		exit_point(game, 0);
	}
	if (game->map[j][i] == '0')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->counter++;
	}
	if (game->map[j][i] == 'C')
	{
		game->map[j][i] = 'P';
		game->x_axis = i;
		game->y_axis = j;
		game->collectables--;
		game->counter++;
	}
	return (1);
}

static int	keyboard_up(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis - 1;
	if (game->map[j][i] == '1')
		return (0);
	k = vertical_move(game, i, j);
	if (!k)
		return (0);
	game->map[j + 1][i] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

static int	keyboard_down(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis;
	j = game->y_axis + 1;
	if (game->map[j][i] == '1')
		return (0);
	k = vertical_move(game, i, j);
	if (!k)
		return (0);
	game->map[j - 1][i] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Left: %i\n", game->collectables);
	return (1);
}

int	controls_working(int command, t_complete *game)
{
	int	works;

	if (command == 53)
		exit_point(game, 4);
	if (command == 13 || command == 126)
		works = keyboard_up(game);
	if (command == 1 || command == 125)
		works = keyboard_down(game);
	if (command == 0 || command == 123
		|| command == 2 || command == 124)
	{
		works = controls2_working(command, game);
	}
	if (works)
		adding_in_graphics(game);
	mlx_string_put(game->mlxpointer, game->winpointer,
		15, 15, 16777215, ft_itoa(game->counter));
	return (1);
}
