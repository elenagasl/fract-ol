/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 19:03:40 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/24 19:03:41 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_split(char **components)
{
	int	i;

	i = 0;
	while (components[i])
	{
		free(components[i]);
		i++;
	}
	free(components);
}

void	init_fractol(t_fract *fractol)
{
	fractol->mlx = mlx_init();
	if (!fractol->mlx)
		return (ft_putstr_fd("Error: Connection with X11\n", 2));
	fractol->window = mlx_new_window(fractol->mlx, 800, 800, fractol->name);
	if (!fractol->window)
		return (ft_putstr_fd("Error: Window couldn't be created\n", 2));
	fractol->image = mlx_new_image(fractol->mlx, 800, 800);
	if (!fractol->image)
		return (ft_putstr_fd("Error: Image couldn't be created\n", 2));
	fractol->data_address = mlx_get_data_addr(fractol->image,
			&fractol->bpp, &fractol->line_len, &fractol->endian);
	if (!fractol->data_address)
		return (ft_putstr_fd("Error: Image address couldn't be resolved\n", 2));
	fractol->mouse_x = 400;
	fractol->mouse_y = 400;
	fractol->max_iters = 20;
	fractol->zoom = 1;
	fractol->shift_x = 0.0;
	fractol->shift_y = 0.0;
}

t_coord	map_pixel_to_complex(t_coord pixel, t_fract *fractol)
{
	t_coord	complex_num;
	double	scale_factor;

	scale_factor = 4.0 / 800.0;
	complex_num.x = (pixel.x - 400.0) * scale_factor / fractol->zoom
		+ fractol->shift_x;
	complex_num.y = (pixel.y - 400.0) * scale_factor / fractol->zoom
		+ fractol->shift_y;
	return (complex_num);
}

unsigned int	get_color(t_fract *fractol, int i)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (i == fractol->max_iters)
		return (0x000000);
	t = (double)i / fractol->max_iters;
	if (fractol->palette == 0xFFFFFF)
		get_white_palette(t, &r, &g, &b);
	else if (fractol->palette == 0x6600CC)
		get_psico_palette(t, &r, &g, &b);
	else if (fractol->palette == 0xFF0000)
		get_red_palette(t, &r, &g, &b);
	else if (fractol->palette == 0x0000FF)
		get_blue_palette(t, &r, &g, &b);
	else if (fractol->palette == 0x00FF00)
		get_green_palette(t, &r, &g, &b);
	else
	{
		r = (int)(255 * t);
		g = (int)(255 * t);
		b = (int)(255 * t);
	}
	return ((r << 16) | (g << 8) | b);
}

void	render_fractol(t_fract *fractol)
{
	t_coord	pixel;
	int		color;
	char	*dst;

	pixel.y = 0;
	while (pixel.y < 800)
	{
		pixel.x = 0;
		while (pixel.x < 800)
		{
			color = check_in_fractol_set(fractol, &pixel);
			if (color > -1)
			{
				dst = fractol->data_address
					+ ((int)pixel.y * fractol->line_len)
					+ ((int)pixel.x * (fractol->bpp / 8));
				*(unsigned int *)dst = (unsigned int)color;
			}
			pixel.x++;
		}
		pixel.y++;
	}
	mlx_put_image_to_window(fractol->mlx, fractol->window,
		fractol->image, 0, 0);
}
