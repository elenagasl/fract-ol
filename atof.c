/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 20:02:00 by elengarc          #+#    #+#             */
/*   Updated: 2025/05/27 20:02:02 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_atof_integer_part(const char *str, int *i)
{
	int	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

static double	ft_atof_decimal_part(const char *str, int *i)
{
	double	result;
	double	divisor;

	result = 0.0;
	divisor = 10.0;
	if (str[*i] == '.')
	{
		(*i)++;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			result = result + (str[*i] - '0') / divisor;
			divisor = divisor * 10.0;
			(*i)++;
		}
	}
	return (result);
}

double	ft_atof(const char *str)
{
	int		i;
	double	sign;
	double	int_part;
	double	dec_part;

	i = 0;
	sign = 1.0;
	if (str[i] == '-')
	{
		sign = -1.0;
		i++;
	}
	else if (str[i] == '+')
		i++;
	int_part = ft_atof_integer_part(str, &i);
	dec_part = ft_atof_decimal_part(str, &i);
	return (sign * (int_part + dec_part));
}
