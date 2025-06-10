/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:00:47 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/25 19:00:48 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_and_exit(t_fract *fractol)
{
	if (fractol->image != NULL)
		mlx_destroy_image(fractol->mlx, fractol->image);
	if (fractol->window != NULL)
		mlx_destroy_window(fractol->mlx, fractol->window);
	if (fractol->mlx != NULL)
		free(fractol->mlx);
	exit(0);
}

void	setup_hooks(t_fract *fractol)
{
	mlx_hook(fractol->window, 2, 1L << 0, handle_key, fractol);
	mlx_hook(fractol->window, 17, 0L, handle_exit, fractol);
	mlx_hook(fractol->window, 6, 1L << 6, handle_mouse_motion, fractol);
	mlx_mouse_hook(fractol->window, handle_mouse_zoom, fractol);
}

void	zoom_at(t_fract *fractol, double zoom_factor, int x, int y)
{
	double	mouse_re;
	double	mouse_im;
	double	new_zoom;

	if (x < 0 || x >= 800 || y < 0 || y >= 800)
		return ;
	mouse_re = ((double)x / 800.0) * 4.0 - 2.0;
	mouse_im = ((double)y / 800.0) * 4.0 - 2.0;
	mouse_re = mouse_re / fractol->zoom + fractol->shift_x;
	mouse_im = mouse_im / fractol->zoom + fractol->shift_y;
	new_zoom = fractol->zoom * zoom_factor;
	fractol->shift_x = mouse_re
		- ((mouse_re - fractol->shift_x) * (fractol->zoom / new_zoom));
	fractol->shift_y = mouse_im
		- ((mouse_im - fractol->shift_y) * (fractol->zoom / new_zoom));
	fractol->zoom = new_zoom;
}
