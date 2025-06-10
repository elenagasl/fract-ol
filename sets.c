/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:49:30 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/27 19:49:31 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static	unsigned int	get_color(t_fract *fractol, int i)
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

int	check_mandelbrot_set(t_fract *fractol, t_coord *c)
{
	int		i;
	double	real;
	double	imaginary;
	t_coord	z;

	i = 0;
	z.x = 0;
	z.y = 0;
	while (i < fractol->max_iters)
	{
		real = z.x * z.x - z.y * z.y + c->x;
		imaginary = 2 * z.x * z.y + c->y;
		if (real * real + imaginary * imaginary > 4)
			break ;
		z.x = real;
		z.y = imaginary;
		i++;
	}
	if (i == fractol->max_iters)
		return (0x000000);
	else
		return (get_color(fractol, i));
}

int	check_julia_set(t_fract *fractol, t_coord *complex_num)
{
	int		i;
	double	real;
	double	imaginary;
	t_coord	z;

	i = 0;
	z.x = complex_num->x;
	z.y = complex_num->y;
	while (i < fractol->max_iters)
	{
		real = z.x * z.x - z.y * z.y + fractol->cr;
		imaginary = 2 * z.x * z.y + fractol->ci;
		if (real * real + imaginary * imaginary > 4)
			break ;
		z.x = real;
		z.y = imaginary;
		i++;
	}
	if (i == fractol->max_iters)
		return (0x000000);
	else
		return (get_color(fractol, i));
}

int	check_tricorn_set(t_fract *fractol, t_coord *c)
{
	int		i;
	double	zx;
	double	zy;
	double	xtemp;

	i = 0;
	zx = 0.0;
	zy = 0.0;
	while (i < fractol->max_iters)
	{
		xtemp = zx * zx - zy * zy + c->x;
		zy = -2 * zx * zy + c->y;
		zx = xtemp;
		if ((zx * zx + zy * zy) > 4.0)
			break ;
		i++;
	}
	if (i == fractol->max_iters)
		return (0x000000);
	return (get_color(fractol, i));
}

int	check_in_fractol_set(t_fract *fractol, t_coord *pixel)
{
	t_coord	complex_num;
	int		color;

	color = -1;
	complex_num = map_pixel_to_complex(*pixel, fractol);
	if (!ft_strncmp(fractol->name, "Mandelbrot", 10))
		color = check_mandelbrot_set(fractol, &complex_num);
	else if (!ft_strncmp(fractol->name, "Julia", 5))
		color = check_julia_set(fractol, &complex_num);
	else if (!ft_strncmp(fractol->name, "Tricorn", 7))
		color = check_tricorn_set(fractol, &complex_num);
	return (color);
}
