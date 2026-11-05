/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepesqu <llepesqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:16:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/11/05 17:10:49 by llepesqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//t_vec2f	get_next_hit(t_vec2f pos, t_vec2f dir)
//{
//	
//}

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

void	move(t_game *g, int dir)
{
	(void)g;
	(void)dir;
}

void	rotate(t_game *g, int angle)
{
	(void)g;
	(void)angle;
	printf("rotate : %i\n", angle);
	g->player.angle += angle;
	printf("player angle : %i\n", g->player.angle);
	//draw_line(
	//	g->frame,
	//	vec2(500, 400),
	//	vec2(
	//		300 + (cos(get_current_time_ms() / 1000.) + 1) * 200,
	//		200 + (sin(get_current_time_ms() / 1000.) + 1) * 200),
	//	argb(0, 255, 255, 255)
	//);
}

int	game_loop(void *game)
{
	t_game	*g;
	t_vec2	dir;

	g = game;

	if (g->inputs.left)
		g->player.angle += 10;
	if (g->inputs.right)
		g->player.angle -= 10;

	dir = vec2(cosf(g->player.angle), sinf(g->player.angle));

	if (g->inputs.forward)
		g->player.pos = vec2_add(g->player.pos, vec2_mult(dir, 1));
	if (g->inputs.backward)
		g->player.pos = vec2_add(g->player.pos, vec2_mult(dir, -1));
	draw_fillrect(g->frame, vec2(0, 0), g->frame.size, argb(0, 0, 0, 0));
	draw_line(
		g->frame,
		g->player.pos,
		vec2_add(g->player.pos, vec2(cos(g->player.angle / 360.) * 100, sin(g->player.angle / 360.) * 100)),
		argb(0, 255, 255, 255)
	);
	draw_fillcircle_aa(
		g->frame,
		g->player.pos,
		5,
		argb(0, 255, 0, 0)
	);
	//draw_fillcircle_aa(
	//	g->frame,
	//	vec2(
	//		300 + (cos(get_current_time_ms() / 1000.) + 1) * 200,
	//		200 + (sin(get_current_time_ms() / 1000.) + 1) * 200),
	//	20,
	//	argb(0, 255, 255, 255)
	//);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->frame.img, 0, 0);
	return (0);
}

int	keydown_hook(int keysym, void *game)
{
	t_game	*g;

	g = game;
	if (keysym == 'w' || keysym == KEY_UP)
		g->inputs.forward = true;
	if (keysym == 'a' || keysym == KEY_LEFT)
		g->inputs.left = true;
	if (keysym == 's' || keysym == KEY_DOWN)
		g->inputs.backward = true;
	if (keysym == 'd' || keysym == KEY_RIGHT)
		g->inputs.right = true;
	if (keysym == K_ESC)
		mlx_loop_end(((t_game *)game)->mlx);
	return (0);
}

int	keyup_hook(int keysym, void *game)
{
	t_game	*g;

	g = game;
	if (keysym == 'w' || keysym == KEY_UP)
		g->inputs.forward = false;
	if (keysym == 'a' || keysym == KEY_LEFT)
		g->inputs.left = false;
	if (keysym == 's' || keysym == KEY_DOWN)
		g->inputs.backward = false;
	if (keysym == 'd' || keysym == KEY_RIGHT)
		g->inputs.right = false;
	return (0);
}

int	mlx_window_init(t_game *game)
{
	game->mlx_win = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!game->mlx_win)
		return (ft_error("window initialization failed.\n"));
	//mlx_key_hook(game->mlx_win, key_hook, game);
	mlx_hook(game->mlx_win, ON_KEYDOWN, (1L << 0), keydown_hook, game);
	mlx_hook(game->mlx_win, ON_KEYUP, (1L << 1), keyup_hook, game);
	mlx_hook(game->mlx_win, 17, 0L, (void *)mlx_loop_end, game->mlx);
	mlx_loop_hook(game->mlx, game_loop, game);
	return (SUCCESS);
}

int	game_init(t_game *game, char *file_path)
{
	(void)file_path;
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (ft_error("mlx initialization failed\n"));
	game->player.pos = vec2(500, 400);
	game->player.angle = 0;
	//game->map = ft_split(MAP);
	return (mlx_window_init(game));
}

int	game_launch(t_game *game)
{
	//char	*dst;
	//int		h;
	//int		w;

	game->frame.img = mlx_new_image(game->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!game->frame.img)
		return (ft_error("image initialization failed\n"));
	game->frame.size = vec2(WIN_WIDTH, WIN_HEIGHT);
	game->frame.addr = mlx_get_data_addr(game->frame.img, &game->frame.bits_per_pixel, &game->frame.line_length, &game->frame.endian);

	//draw_fillcircle_aa(((t_game *)game)->frame, vec2(200, 200), 100, argb(100, 255, 0, 0));

	mlx_put_image_to_window(game->mlx, game->mlx_win, game->frame.img, 0, 0);
	mlx_loop(game->mlx);
	return (SUCCESS);
}

//t_vec2f	get_next_hit(t_vec2f pos, t_vec2f ray_dir)
//{
//	t_vec2f	next;
//	t_vec2f	sign;
//	t_vec2f	delta;
//	t_vec2f	length;
//
//	sign = vec2f(0., 0.);
//	if (ray_dir.x != 0)
//		sign.x = ray_dir.x / fabsf(ray_dir.x);
//	if (ray_dir.y != 0)
//		sign.y = ray_dir.y / fabsf(ray_dir.y);
//	next = vec2f((int)pos.x + sign.x, (int)pos.y + sign.y);
//	delta = vec2f(next.x - pos.x, next.y - pos.y);
//	length.x = fabsf((ray_dir.x / ray_dir.y) * delta.x);
//	length.y = fabsf((ray_dir.y / ray_dir.x) * delta.y);
//	printf("SIGN : %f, %f\n", sign.x, sign.y);
//	printf("NEXT : %f, %f\n", next.x, next.y);
//	printf("LENGTH : %f, %f\n", length.x, length.y);
//	if (length.x < length.y)
//		return (vec2f(delta.x, length.x));
//	return (vec2f(delta.y, length.y));
//}

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
		//get_next_hit(vec2f(0, 0), vec2f(1, 2));
		game_launch(&game);
	}	
	game_exit(&game);
	return (0);
}
