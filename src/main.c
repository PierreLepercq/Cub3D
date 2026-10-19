/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:16:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/19 22:43:03 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wrong_arg_count(void)
{
	(void)argc;
	ft_putstr_fd("Incorrect number of arguments (expected 1)\n", 2);
	ft_putstr_fd("Usage : ./cub3D scene_description_file\n", 2);
	return (1);
}

int	load_params_failed(char *game_file)
{
	ft_putstr_fd("Failed to load game parameters from file : ", 2);
	ft_putstr_fd(game_file, 2);
	ft_putstr_fd("\n", 2);
	return (2);
}

// ------------------------------------

int	game_exit(t_game *game, char *err_msg)
{
	(void)err_msg;

	if (game->mlx_win)
		mlx_destroy_window(game->mlx, game->mlx_win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
		game->mlx = NULL;
	}
	return (SUCCESS);
}

void	move(t_game *g)
{
	(void)g;
}

int	key_hook(int keysym, void *game)
{
	if (keysym == 'w' || keysym == KEY_UP)
		move(game);
	if (keysym == 'a' || keysym == KEY_LEFT)
		move(game);
	if (keysym == 's' || keysym == KEY_DOWN)
		move(game);
	if (keysym == 'd' || keysym == KEY_RIGHT)
		move(game);
	if (keysym == K_ESC)
		game_exit(game, NULL);
	return (0);
}

void	mlx_window_init(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->mlx_win)
		game_exit(game, NULL);
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, (void *)game_exit, game);
}

int	game_init(t_game *game, char *file_path)
{
	(void)file_path;
	game->win = 0;
	game->mlx = NULL;
	game->mlx_win = NULL;

	game->mlx = mlx_init();
	if (!game->mlx)
		game_exit(game, NULL);
	mlx_window_init(game);
	return (0);
}

int	game_launch(t_game *g)
{
	t_frame	frame;
	char	*dst;
	int		h;
	int		w;

	frame.img = mlx_new_image(g->mlx, WIN_WIDTH, WIN_HEIGHT);
	frame.addr = mlx_get_data_addr(frame.img, &frame.bits_per_pixel, &frame.line_length, &frame.endian);
	h = 0;
	while (h < WIN_HEIGHT)
	{
		w = 0;
		while (w < WIN_WIDTH)
		{
			dst = frame.addr + (h * frame.line_length + w * (frame.bits_per_pixel / 8));
			if (h > WIN_HEIGHT / 2)
				*(unsigned int*)dst = 0x00FFFF00;
			else
				*(unsigned int*)dst = 0x0000FFFF;
			w++;
		}
		h++;
	}
	mlx_put_image_to_window(g->mlx, g->mlx_win, frame.img, 0, 0);
	mlx_loop(g->mlx);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	//if (argc != 2)
	//	return (wrong_arg_count(argc));
	//if (!load_game_params(g, argv[1]))
	//	return (load_params_failed(argv[1]));
	game_init(&game, argv[1]);
	game_launch(&game);
	game_exit(&game, NULL);
	return (1);
}
