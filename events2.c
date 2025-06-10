/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:18:53 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/27 19:18:54 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	change_palette(t_fract *fractol)
{
	if (fractol->palette == 0xFFFFFF)
		fractol->palette = 0x6600CC;
	else if (fractol->palette == 0x6600CC)
		fractol->palette = 0xFF0000;
	else if (fractol->palette == 0xFF0000)
		fractol->palette = 0x0000FF;
	else if (fractol->palette == 0x0000FF)
		fractol->palette = 0x00FF00;
	else
		fractol->palette = 0xFFFFFF;
}

int	handle_key(int keycode, t_fract *fractol)
{
	if (keycode == 53) // ESC
		free_and_exit(fractol);
	else if (keycode == 123) // flecha izquierda
		fractol->shift_x = fractol->shift_x - 0.1 / fractol->zoom;
	else if (keycode == 124) // flecha derecha
		fractol->shift_x = fractol->shift_x + 0.1 / fractol->zoom;
	else if (keycode == 126) // flecha arriba
		fractol->shift_y = fractol->shift_y - 0.1 / fractol->zoom;
	else if (keycode == 125) // flecha abajo
		fractol->shift_y = fractol->shift_y + 0.1 / fractol->zoom;
	else if (keycode == 8) // tecla 'c'
		change_palette(fractol);
	else if (keycode == 34) // tecla 'i'
	{
		if (fractol->max_iters < 1000)
			fractol->max_iters = fractol->max_iters + 10;
	}
	render_fractol(fractol);
	return (0);
}

int	handle_mouse_zoom(int button, int x, int y, t_fract *fractol)
{
	if (button == 1) // click izquierdo: activa o desactiva motion
		fractol->motion = !fractol->motion;
	else if (button == 4) // scroll up (zoom in)
		zoom_at(fractol, 1.2, x, y);
	else if (button == 5) // scroll down (zoom out)
		zoom_at(fractol, 0.8, x, y);

	render_fractol(fractol);
	return (0);
}


int	handle_mouse_motion(int x, int y, t_fract *fractol)
{
	fractol->mouse_x = x;
	fractol->mouse_y = y;
	if (fractol->motion == 0)
		return (0);
	fractol->cr = (((double)x / 800.0) - 0.5) * 2.0;
	fractol->ci = (((double)y / 800.0) - 0.5) * 2.0;
	render_fractol(fractol);
	return (0);
}

int	handle_exit(t_fract *fractol)
{
	free_and_exit(fractol);
	return (0);
}
