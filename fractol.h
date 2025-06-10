/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 19:54:30 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/25 19:54:31 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>

typedef struct s_coord
{
	double	x;
	double	y;
}	t_coord;

typedef struct s_fract
{
	void			*mlx;
	void			*window;
	void			*image;
	char			*data_address;
	int				bpp;
	int				line_len;
	int				endian;
	double			zoom;
	double			shift_x;
	double			shift_y;
	int				max_iters;
	unsigned int	palette;
	double			cr;
	double			ci;
	int				motion;
	char			*name;
	int				mouse_x;
	int				mouse_y;
}	t_fract;

/* Gestión de eventos */
void	free_and_exit(t_fract *fractol);
void	setup_hooks(t_fract *fractol);
int		handle_key(int keycode, t_fract *fractol);
int		handle_mouse_zoom(int button, int x, int y, t_fract *fractol);
int		handle_mouse_motion(int x, int y, t_fract *fractol);
int		handle_exit(t_fract *fractol);

/* Parseo de argumentos */
int		check_fract_name(char *name, t_fract *fractol);
int		is_valid_palette(char *arg, t_fract *fractol);
int		parse_complex_num(char *num, t_fract *fractol);
double	ft_atof(const char *str);
void	free_split(char **components);
void	ft_error_args(void);

/* Sets de fractales */
int		check_mandelbrot_set(t_fract *fractol, t_coord *c);
int		check_julia_set(t_fract *fractol, t_coord *z);
int		check_tricorn_set(t_fract *fractol, t_coord *z);
int		check_in_fractol_set(t_fract *fractol, t_coord *pixel);

/* Renderizado */
void	init_fractol(t_fract *fractol);
void	render_fractol(t_fract *fractol);
void	zoom_at(t_fract *fractol, double zoom_factor, int x, int y);
t_coord	map_pixel_to_complex(t_coord pixel, t_fract *fractol);

/* Paletas de color */
void	get_white_palette(double t, int *r, int *g, int *b);
void	get_psico_palette(double t, int *r, int *g, int *b);
void	get_red_palette(double t, int *r, int *g, int *b);
void	get_blue_palette(double t, int *r, int *g, int *b);
void	get_green_palette(double t, int *r, int *g, int *b);

#endif
