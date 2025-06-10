/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 19:47:01 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/27 19:47:02 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_white_palette(double t, int *r, int *g, int *b)
{
	*r = (int)(255 * t);
	*g = (int)(255 * t);
	*b = (int)(255 * t);
}

void	get_psico_palette(double t, int *r, int *g, int *b)
{
	*r = (int)(255 * fabs(sin(10.0 * t)));
	*g = (int)(255 * fabs(sin(15.0 * t)));
	*b = (int)(255 * fabs(sin(20.0 * t)));
}

void	get_red_palette(double t, int *r, int *g, int *b)
{
	*r = (int)(255 * fabs(sin(7.0 * t)));
	*g = (int)(100 * fabs(sin(5.0 * t)));
	*b = (int)(20 * fabs(sin(4.0 * t)));
}

void	get_blue_palette(double t, int *r, int *g, int *b)
{
	*r = (int)(80 * fabs(sin(4.0 * t)));
	*g = (int)(160 * fabs(sin(5.0 * t)));
	*b = (int)(255 * fabs(sin(6.0 * t)));
}

void	get_green_palette(double t, int *r, int *g, int *b)
{
	*r = (int)(50 * fabs(sin(3.0 * t)));
	*g = (int)(255 * fabs(sin(6.0 * t)));
	*b = (int)(80 * fabs(sin(4.0 * t)));
}
