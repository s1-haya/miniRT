/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsawamur <hsawamur@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:27:08 by hsawamur          #+#    #+#             */
/*   Updated: 2024/02/23 16:01:01 by hsawamur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int	ft_isdigit(int c);
int	ft_isspace(char c);

double	process_integer(const char **str)
{
	double	result;

	result = 0.0;
	while (ft_isdigit(**str))
	{
		result = (result * 10.0) + (**str - '0');
		(*str)++;
	}
	return (result);
}

double	process_fraction(const char **str)
{
	double	fraction;
	double	result;

	fraction = 0.1;
	result = 0.0;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			result += (**str - '0') * fraction;
			fraction *= 0.1;
			(*str)++;
		}
	}
	return (result);
}

int	process_exponent(const char **str, double *exponent_sign)
{
	int	exponent;

	exponent = 0;
	if (**str == 'e' || **str == 'E')
	{
		(*str)++;
		if (**str == '-')
		{
			*exponent_sign = -1.0;
			(*str)++;
		}
		else if (**str == '+')
			(*str)++;
		while (ft_isdigit(**str))
		{
			exponent = (exponent * 10) + (**str - '0');
			(*str)++;
		}
	}
	return (exponent);
}

double	ft_strtod(const char *str, char **endptr)
{
	double	result;
	double	sign;
	double	exponent_sign;
	int		exponent;

	result = 0.0;
	sign = 1.0;
	exponent_sign = 1.0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1.0;
		str++;
	}
	else if (*str == '+')
		str++;
	result = process_integer(&str);
	result += process_fraction(&str);
	exponent = process_exponent(&str, &exponent_sign);
	if (endptr != NULL)
		*endptr = (char *)str;
	return (result * sign * pow(10.0, exponent * exponent_sign));
}

// #include <stdlib.h>
// int main() {
//     // const char *str = " -123.456e-2";
//     const char *str = " -3ee";
//     char *endptr;

//     double value = strtod(NULL, &endptr);

//     printf("Converted value: %f\n", value);
//     printf("Remaining string: %s\n", endptr);

//     return 0;
// }
