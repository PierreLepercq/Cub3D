#include "draw.h"

void	draw_aacircle(t_frame f, t_vec2 pos, int radius, t_color color)
{
	t_vec2	px;
    float   dist;
    float   alpha;
	float	weight;

	weight = 1;
	px = vec2(pos.x - radius - weight, pos.y - radius - weight);
	while (px.x <= pos.x + radius + weight)
    {
        while(px.y <= pos.y + radius + weight)
        {
            dist = vec2_len(vec2_sub(px, pos));
			alpha = (255 - (float)color.a) / 255;
			alpha *= weight + 0.5f - fabsf(dist - radius);
			if (alpha > 1)
				alpha = 1;
            if (alpha > 0)
            {
                alpha = (1 - alpha) * 255;
                draw_pixel(f, px, argb(alpha, color.r, color.g, color.b));
            }
            px.y++;
        }
        px.y = 0;
        px.x++;
    }
}