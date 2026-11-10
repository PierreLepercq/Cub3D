/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plepercq <plepercq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 16:16:00 by plepercq          #+#    #+#             */
/*   Updated: 2026/11/10 15:10:25 by plepercq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

//t_vec2f	get_next_hit(t_vec2f pos, t_vec2f dir)
//{
//	
//}

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

void	draw_map(t_game *g)
{
	int		ch;
	t_vec2	px;

	px = vec2(0, 0);
	while (px.y <= WIN_HEIGHT)
	{
		px.x = 0;
		while (px.x <= WIN_WIDTH)
		{
			ch = (int)(px.y / 100) * (WIN_WIDTH / 100) + (int)(px.x / 100);
			if (MAP[ch] == '1')
				draw_pixel(g->frame, px, argb(100, 255, 255, 255)); 
			px.x++;
		}
		px.y++;
	}
	px = vec2(100, 100);
	while (px.y <= WIN_HEIGHT)
	{
		draw_line(g->frame, vec2(0, px.y), vec2(WIN_WIDTH, px.y), argb(0, 55, 55, 55));
		px.y += 100;
	}
	while (px.x <= WIN_WIDTH)
	{
		draw_line(g->frame, vec2(px.x, 0), vec2(px.x, WIN_HEIGHT), argb(0, 55, 55, 55));
		px.x += 100;
	}
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

//t_vec2	get_next_cell(t_game *g)
//{
//	int16_t	ang;
//	t_vec2	vec;
//
//	ang = g->player.angle % 360;
//	if (ang < 0)
//		ang = 360 + ang;
//	printf("Angle : %i\n", ang);
//	if (ang == 0)
//		return (vec2((int)(g->player.pos.x + 1), (int)g->player.pos.y));
//	if (ang == 180)
//		return (vec2((int)(g->player.pos.x), (int)g->player.pos.y));
//	if (ang == 90)
//		return (vec2((int)g->player.pos.x, (int)(g->player.pos.y + 1)));
//	if (ang == 270)
//		return (vec2((int)g->player.pos.x, (int)(g->player.pos.y)));
//	vec = vec2(1, 1);
//	if (ang > 180)
//		vec.y = 0;
//	if (ang < 270 && ang > 90)
//		vec.x = 0;
//	vec = vec2_add(g->player.pos, vec);
//	return (vec2((int)vec.x, (int)vec.y));
//}

//t_vec2	angle_to_relative_pos(int16_t ang)
//{
//	t_vec2	pos;
//
//	ang = ang % 360;
//	if (ang < 0)
//		ang = 360 + ang;
//	pos = vec2(1, 1);
//	if (ang % 90 == 0)
//	{
//		if (ang == 180)
//			pos.x = -1;
//		if (ang == 270)
//			pos.y = -1;
//	}
//	else
//	{
//		if (ang > 180)
//			pos.y = -1;
//		if (ang > 90 && ang < 270)
//			pos.x = -1;
//	}
//	return (pos);
//}

t_vec2	angle_to_relative_pos(int16_t ang)
{
	t_vec2	pos;

	ang = ang % 360;
	if (ang < 0)
		ang = 360 + ang;
	if (ang == 0)
		return (vec2(1, 0));
	if (ang == 90)
		return (vec2(0, 1));
	if (ang == 180)
		return (vec2(-1, 0));
	if (ang == 270)
		return (vec2(0, -1));
	pos = vec2(1, 1);
	if (ang > 180)
		pos.y = -1;
	if (ang > 90 && ang < 270)
		pos.x = -1;
	return (pos);
}

bool	is_int(float f)
{
	return ((int)f == f);
}

t_vec2	get_next_edges(t_vec2 pos, int16_t angle)
{
	t_vec2	edges;

	edges = angle_to_relative_pos(angle);
	if (edges.x == -1 && !is_int(pos.x))
		edges.x = 0;
	if (edges.y == -1 && !is_int(pos.y))
		edges.y = 0;
	edges = vec2_add(pos, edges);
	return (vec2((int)edges.x, (int)edges.y));
}

float	min(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

float	raycast(t_vec2 pos, int16_t angle)
{
	float	rad;
	t_vec2	delta;

	angle = angle % 360;
	if (angle < 0)
		angle = 360 + angle;
	rad = angle * (M_PI / 180.);
	printf("next = ");
	pvec2(get_next_edges(pos, angle));
	printf("pos = ");
	pvec2(pos);
	delta = vec2_sub(get_next_edges(pos, angle), pos);
	printf("delta = ");
	pvec2(delta);
	if (abs(angle % 180) == 0)
		return (fabsf(delta.x));
	if (abs(angle % 180) == 90)
		return (fabsf(delta.y));
	return (min(fabsf(delta.x / cosf(rad)), fabsf(delta.y / sinf(rad))));
}

/*
	//pos = vec2_add(g->player.pos, vec2_mult(dir, hyp));
	printf("2 - %f\n", hyp);
	//pvec2(pos);

	pos = vec2_add(g->player.pos, vec2_mult(dir, hyp));
	delta = vec2_sub(get_next_edges(g), pos);
	pvec2(delta);
	if (abs(ang % 180) == 0)
		hyp += fabsf(delta.x);
	else if (abs(ang % 180) == 90)
		hyp += fabsf(delta.y);
	else
		hyp += min(delta.x / cos(rad), delta.y / sin(rad));

	printf("3 - %f\n", hyp);
	//pvec2(pos);

	//pvec2(vec2_add(g->player.pos, vec2_mult(dir, hyp)));

	//next_cell = pos;
	//if (ang > 90 && ang < 270)
	//	next_cell.x -= 1;
	//if (ang > 180)
	//	next_cell.y -= 1;
	
	pos = vec2_add(g->player.pos, vec2_mult(dir, hyp));
	ch = (int)(pos.y) * (WIN_WIDTH / 100) + (int)(pos.x);
	printf("INDEX = %i | NEXT_CELL = %c\n", ch, MAP[ch]);
	pos = vec2_add(vec2_mult(g->player.pos, 100), vec2_mult(dir, hyp * 100));
	draw_line(
		g->frame,
		vec2_mult(g->player.pos, 100),
		pos,
		argb(0, 0, 255, 0)
	);

	//hyp = vec2(delta.x / cos(rad), delta.y / sin(rad));
	//pvec2(hyp);
	//if (hyp.x < hyp.y)
	//	printf("X\n");
	//else
	//	printf("Y\n");
	return (0.);
}
*/

int	game_loop(void *game)
{
	t_game	*g;
	float	rad;
	t_vec2	pos;
	t_vec2	dir;
	float	hyp1;
	float	hyp2;

	g = game;

	if (g->inputs.left)
		g->player.angle -= 3;
	if (g->inputs.right)
		g->player.angle += 3;

	printf("Angle : %i\n", g->player.angle % 360);
	rad = g->player.angle * (M_PI / 180.);
	dir = vec2(cosf(rad), sinf(rad));
	//pvec2(dir);

	if (g->inputs.forward)
		g->player.pos = vec2_add(g->player.pos, vec2_mult(dir, 0.1));
	if (g->inputs.backward)
		g->player.pos = vec2_add(g->player.pos, vec2_mult(dir, -0.1));
	draw_fillrect(g->frame, vec2(0, 0), g->frame.size, argb(0, 0, 0, 0));
	draw_map(g);
	pos = vec2_mult(g->player.pos, 100);
	draw_line(
		g->frame,
		vec2_mult(g->player.pos, 100),
		vec2_add(vec2_mult(g->player.pos, 100), vec2_mult(dir, 1000)),
		argb(0, 50, 50, 50)
	);
	
	hyp1 = raycast(g->player.pos, g->player.angle);
	draw_line(
		g->frame,
		vec2_mult(g->player.pos, 100),
		vec2_add(vec2_mult(g->player.pos, 100), vec2_mult(dir, hyp1 * 100)),
		argb(0, 0, 255, 0)
	);

	pos = vec2_add(g->player.pos, vec2_mult(dir, hyp1));
	pvec2(pos);

	draw_fillcircle_aa(
		g->frame,
		vec2_mult(pos, 100),
		5,
		argb(0, 0, 255, 0)
	);

	hyp2 = raycast(pos, g->player.angle);
	draw_line(
		g->frame,
		vec2_mult(pos, 100),
		vec2_add(vec2_mult(pos, 100), vec2_mult(dir, hyp2 * 100)),
		argb(0, 0, 0, 255)
	);


	draw_fillcircle_aa(
		g->frame,
		vec2_mult(g->player.pos, 100),
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
	game->player.pos = vec2(4, 4);
	game->player.angle = -90;
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
