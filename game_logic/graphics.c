/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: binanc <binanc@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:36:55 by binanc            #+#    #+#             */
/*   Updated: 2023/07/15 20:09:52 by binanc           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	place_player(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->player, width * 40, height * 40);
	game->y_axis = height;
	game->x_axis = width;
}

void	place_collectable(t_complete *game, int height, int width)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, game->collectable, width * 40, height * 40);
	game->collectables++;
}

void	place_others(t_complete *game, void	*img_ptr, int width, int height)
{
	mlx_put_image_to_window(game->mlxpointer,
		game->winpointer, img_ptr, width * 40, height * 40);
}

void	place_images_in_game(t_complete *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/fd.xpm", &i, &j);
	game->barrier = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/dm.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/cat.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/kapi1.xpm", &i, &j);
	game->collectable = mlx_xpm_file_to_image(game->mlxpointer,
			"textures/dom.xpm", &i, &j);
}

void	adding_in_graphics(t_complete *game)
{
	int	height;
	int	width;

	game->collectables = 0;
	height = 0;
	while (height < game->heightmap)
	{
		width = 0;
		while (game->map[height][width])
		{
			if (game->map[height][width] == '1')
				place_others(game, game->barrier, width, height);
			if (game->map[height][width] == 'C')
				place_collectable(game, height, width);
			if (game->map[height][width] == 'P')
				place_player(game, height, width);
			if (game->map[height][width] == 'E')
				place_others(game, game->exit, width, height);
			if (game->map[height][width] == '0')
				place_others(game, game->floor, width, height);
			width++;
		}
		height++;
	}
}
