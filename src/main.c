/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pierre_lepercq <pierre_lepercq@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:16:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/10/24 01:49:07 by pierre_lepe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	wrong_arg_count(void)
{
	return(ft_error("Incorrect number of arguments (expected 2)\nUsage : ./cub3D scene_description_file\n"));
}

int	load_params_failed(char *game_file)
{
	ft_error("Failed to load game parameters from file : ");
	ft_putstr_fd(2, game_file);
	ft_putstr_fd(2, "\n");
	return (2);
}

// ------------------------------------

int	game_exit(t_game *game)
{
	if (game->frame.img)
		mlx_destroy_image(game->mlx,game->frame.img);
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
	t_game *g;
	
	g = game;
	if (keysym == 'w' || keysym == KEY_UP)
		move(g);
	if (keysym == 'a' || keysym == KEY_LEFT)
		move(g);
	if (keysym == 's' || keysym == KEY_DOWN)
		move(g);
	if (keysym == 'd' || keysym == KEY_RIGHT)
		move(g);
	if (keysym == K_ESC)
		mlx_loop_end(g->mlx);
	return (0);
}

int	mlx_window_init(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->mlx_win)
		return (ft_error("window initialization failed.\n"));
	mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, (void *)mlx_loop_end, game->mlx);
	return (SUCCESS);
}

int	game_init(t_game *game, char *file_path)
{
	(void)file_path;
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("mlx initialization failed\n"));
	return (mlx_window_init(game));
}


t_vec2f	vec2f(float x, float y)
{
	t_vec2f	vec2;

	vec2.x = x;
	vec2.y = y;
	return (vec2);
}

//void color_pixel(t_vec2i pos)
//{
//	
//}

int	game_launch(t_game *game)
{
	//char	*dst;
	//int		h;
	//int		w;

	game->frame.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->frame.img)
		return (ft_error("image initialization failed\n"));
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_length, &game->frame.endian);
	//draw_pixel(game->frame, vec2(100, 100), argb(0, 0, 255, 0));
	//draw_rect(game->frame, vec2(100, 100), vec2(870, 700), argb(0, 255, 0, 0));
	draw_circle(game->frame, vec2(500, 500), 200, argb(0, 255, 0, 0));
	//draw_line(game->frame, vec2(100, 100), vec2(200, 200), argb(0, 0, 255, 255));
	//h = 0;
	//while (h < WIN_HEIGHT)
	//{
	//	w = 0;
	//	while (w < WIN_WIDTH)
	//	{
	//		dst = game->frame.addr + (h * game->frame.line_length + w * (game->frame.bits_per_pixel / 8));
	//		if (h > WIN_HEIGHT / 2)
	//			*(unsigned int*)dst = 0x00FFFF00;
	//		else
	//			*(unsigned int*)dst = 0x0000FFFF;
	//		w++;
	//	}
	//	h++;
	//}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame.img, 0, 0);
	mlx_loop(game->mlx);
	return (SUCCESS);
}

t_vec2f	get_next_hit(t_vec2f pos, t_vec2f ray_dir)
{
	t_vec2f	next;
	t_vec2f	sign;
	t_vec2f	delta;
	t_vec2f	length;

	sign = vec2f(0., 0.);
	if (ray_dir.x != 0)
		sign.x = ray_dir.x / fabsf(ray_dir.x);
	if (ray_dir.y != 0)
		sign.y = ray_dir.y / fabsf(ray_dir.y);
	next = vec2f((int)pos.x + sign.x, (int)pos.y + sign.y);
	delta = vec2f(next.x - pos.x, next.y - pos.y);
	length.x = fabsf((ray_dir.x / ray_dir.y) * delta.x);
	length.y = fabsf((ray_dir.y / ray_dir.x) * delta.y);
	printf("SIGN : %f, %f\n", sign.x, sign.y);
	printf("NEXT : %f, %f\n", next.x, next.y);
	printf("LENGTH : %f, %f\n", length.x, length.y);
	if (length.x < length.y)
		return (vec2f(delta.x, length.x));
	return (vec2f(delta.y, length.y));
}

int	main(int argc, char **argv)
{
	t_game		game;

	(void)argc;
	//if (argc != 2)
	//	return (wrong_arg_count(argc));
	//if (!load_game_params(g, argv[1]))
	//	return (load_params_failed(argv[1]));

	if (game_init(&game, argv[1]))
	{
		get_next_hit(vec2f(0, 0), vec2f(1, 2));
		game_launch(&game);
	}	
	game_exit(&game);
	return (0);
}
