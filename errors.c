/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 11:44:26 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/26 11:44:27 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_error_args(void)
{
	ft_putendl_fd("\nUsage:", 2);
	ft_putendl_fd("  ./fractol Mandelbrot <Palette>", 2);
	ft_putendl_fd("  ./fractol Julia <Palette> \"<Re> <Im>\"", 2);
	ft_putendl_fd("  ./fractol Tricorn <Palette>", 2);
	ft_putendl_fd("\nAvailable fractals:", 2);
	ft_putendl_fd("  Mandelbrot", 2);
	ft_putendl_fd("  Julia", 2);
	ft_putendl_fd("  Tricorn", 2);
	ft_putendl_fd("\nAvailable palettes:", 2);
	ft_putendl_fd("  White     (neutral grayscale)", 2);
	ft_putendl_fd("  Psico     (psychedelic mix)", 2);
	ft_putendl_fd("  Red       (warm tones)", 2);
	ft_putendl_fd("  Blue      (cool tones)", 2);
	ft_putendl_fd("  Green     (natural greens)", 2);
	ft_putendl_fd("\nTips:", 2);
	ft_putendl_fd("  In Julia: dynamic shape mode (changes with mouse)", 2);
	ft_putendl_fd("\nControls:", 2);
	ft_putendl_fd("  Arrow keys   Move across the fractal space", 2);
	ft_putendl_fd("  I            Increase iteration depth (Resolution)", 2);
	ft_putendl_fd("  C            Change color palette", 2);
	ft_putendl_fd("  Mouse wheel  Zoom in/out at mouse position", 2);
	ft_putendl_fd("  ESC          Exit the program", 2);
	ft_putendl_fd("\nHave fun exploring fractals!", 2);
}
