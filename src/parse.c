/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:11:14 by hmartzol          #+#    #+#             */
/*   Updated: 2018/10/15 19:26:36 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include <stdio.h>
#include <math.h>
#include "../inc/computorv1.h"

static inline void	jump_spaces(char **str)
{
	while (isspace(**str))
		++*str;
}

static inline int	parse_single_mult_1(char **str, double *mult, long *exp,
									char *variable)
{
	char	*tmp_str;

	jump_spaces(str);
	if (**str == '^')
		++*str;
	else if (**str == '+' || **str == '=' || **str == '\0')
		return (!(*exp = 1));
	else
		return (EINVAL);
	*exp = strtol(*str, &tmp_str, 10);
	if (*exp == 0 && tmp_str == *str)
		return (EINVAL);
	if (*exp < 0 || *exp > 2)
		return (ERANGE);
	*str = tmp_str;
	jump_spaces(str);
	return (0);
}

static inline int	parse_single_mult(char **str, double *mult, long *exp,
									char *variable)
{
	char	*tmp_str;

	errno = 0;
	jump_spaces(str);
	*mult = strtod(*str, &tmp_str);
	if (*mult == 0.0 && tmp_str == *str)
		*mult = 1.0;
	if ((*mult == HUGE_VAL || *mult == -HUGE_VAL) && errno == ERANGE)
		return (ERANGE);
	*str = tmp_str;
	jump_spaces(str);
	if (**str == '*')
		++*str;
	jump_spaces(str);
	if (isalpha(**str))
		if (*variable != '\0' && *variable != **str)
			return (EINVAL);
		else
			*variable = *(*str)++;
	else if (**str == '+' || **str == '=' || **str == '\0')
		return ((*exp = 0));
	else
		return (EINVAL);
	return (parse_single_mult_1(str, mult, exp, variable));
}

int					parse(t_computorv1_equation *eq, char *str)
{
	t_computorv1_tmp	tmp;

	tmp.in_result = 0;
	while (*str != '\0' && !(tmp.error = parse_single_mult(&str,
			&tmp.mult, &tmp.exp, &eq->variable)))
	{
		if (tmp.in_result)
			if (*str != '+' && *str != '\0')
				return (EINVAL);
			else
				eq->result[tmp.exp] = tmp.mult;
		else
		{
			if (*str != '+' && *str != '=')
				return (EINVAL);
			if (*str == '=')
				tmp.in_result = 1;
			eq->mult[tmp.exp] = tmp.mult;
		}
		if (*str != '\0')
			++str;
	}
	return (tmp.error || !tmp.in_result ? EINVAL : 0);
}