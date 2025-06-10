/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 17:21:48 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/25 17:21:50 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_fract_name(char *name, t_fract *fractol)
{
	if (!ft_strncmp(name, "Mandelbrot", 10))
		fractol->name = "Mandelbrot";
	else if (!ft_strncmp(name, "Julia", 5))
		fractol->name = "Julia";
	else if (!ft_strncmp(name, "Tricorn", 7))
		fractol->name = "Tricorn";
	else
		return (0);
	return (1);
}

int	is_valid_palette(char *arg, t_fract *fractol)
{
	if (!ft_strncmp(arg, "White", 5))
		fractol->palette = 0xFFFFFF;
	else if (!ft_strncmp(arg, "Psico", 5))
		fractol->palette = 0x6600CC;
	else if (!ft_strncmp(arg, "Red", 3))
		fractol->palette = 0xFF0000;
	else if (!ft_strncmp(arg, "Blue", 4))
		fractol->palette = 0x0000FF;
	else if (!ft_strncmp(arg, "Green", 5))
		fractol->palette = 0x00FF00;
	else
		return (0);
	return (1);
}

int	check_component(char *component)
{
	int	i;
	int	dot_seen;

	i = 0;
	dot_seen = 0;
	if (component[i] == '+' || component[i] == '-')
		i++;
	while (component[i])
	{
		if (component[i] == '.')
		{
			if (dot_seen)
				return (1);
			dot_seen = 1;
		}
		else if (component[i] < '0' || component[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	parse_complex_num(char *num, t_fract *fractol)
{
	char	**components;
	int		i;

	i = 0;
	components = ft_split(num, ' ');
	if (!components || !components[0] || !components[1])
		return (0);
	while (components[i])
		i++;
	if (i != 2)
		return (free_split(components), 0);
	if (check_component(components[0]) || check_component(components[1]))
		return (0);
	fractol->cr = ft_atof(components[0]);
	fractol->ci = ft_atof(components[1]);
	free_split(components);
	return (1);
}

int	main(int argc, char **argv)
{
	t_fract	fractol;

	if (argc < 3)
		return (ft_error_args(), 1);
	if (!check_fract_name(argv[1], &fractol)
		|| !is_valid_palette(argv[2], &fractol))
		return (ft_error_args(), 1);
	if (!ft_strncmp(fractol.name, "Mandelbrot", 10)
		|| !ft_strncmp(fractol.name, "Tricorn", 7))
	{
		if (argc != 3)
			return (ft_error_args(), 1);
	}
	else
	{
		fractol.motion = 0;
		if (argc != 4)
			return (ft_error_args(), 1);
		if (!parse_complex_num(argv[3], &fractol) || argc != 4)
			return (ft_error_args(), 1);
	}
	init_fractol(&fractol);
	render_fractol(&fractol);
	setup_hooks(&fractol);
	return (mlx_loop(fractol.mlx), 0);
}
