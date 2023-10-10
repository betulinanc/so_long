/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by binanc            #+#    #+#             */
/*   Updated: 2023/07/15 20:09:46 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	horizontal_move(t_complete *game, int i, int j)
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

static int	keyboard_left(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis - 1;
	j = game->y_axis;
	if (game->map[j][i] == '1')
		return (0);
	k = horizontal_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i + 1] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

static int	keyboard_right(t_complete *game)
{
	int	i;
	int	j;
	int	k;

	i = game->x_axis + 1;
	j = game->y_axis;
	if (game->map[j][i] == '1')
		return (0);
	k = horizontal_move(game, i, j);
	if (!k)
		return (0);
	game->map[j][i - 1] = '0';
	ft_printf("Steps Taken: %i\n", game->counter);
	ft_printf("Collectables Remaining: %i\n", game->collectables);
	return (1);
}

int	controls2_working(int command, t_complete *game)
{
	int	works;

	if (command == 0 || command == 123)
		works = keyboard_left(game);
	if (command == 2 || command == 124)
		works = keyboard_right(game);
	if (works)
		adding_in_graphics(game);
	return (1);
}
