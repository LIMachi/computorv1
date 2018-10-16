/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:01:35 by hmartzol          #+#    #+#             */
/*   Updated: 2018/10/16 17:37:26 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/computorv1.h"

void				beautified_real(double r)
{
	char	tmp[42];
	int		i;

	snprintf(tmp, 41, "%.12f", r);
	i = 0;
	if (tmp[i] == '-')
		++i;
	while (isnumber(tmp[i]))
		++i;
	if (tmp[i++] == '.')
	{
		while (isnumber(tmp[i]))
			++i;
		while (tmp[--i] == '0')
			tmp[i] = '\0';
		if (tmp[i] == '.')
			tmp[i] = '\0';
	}
	printf("%s", tmp);
}

static inline void	beautified_print(double mult, long exp, char variable)
{
	int		i;

	if (mult == 0.0)
		printf("0");
	else
	{
		if (mult != 1.0)
		{
			beautified_real(mult);
			printf("%s", exp ? " * " : "");
		}
		if (exp > 0)
			printf("%c", variable);
		if (exp == 2)
			printf(" ^ 2");
	}
}

void				print(t_computorv1_equation *eq)
{
	if (eq->mult[0] != 0.0)
		beautified_print(eq->mult[0], 0, eq->variable);
	if (eq->mult[0] != 0.0 && eq->mult[1] != 0.0)
		printf(" + ");
	if (eq->mult[1] != 0.0)
		beautified_print(eq->mult[1], 1, eq->variable);
	if ((eq->mult[0] != 0.0 || eq->mult[1] != 0.0) && eq->mult[2] != 0.0)
		printf(" + ");
	if (eq->mult[2] != 0.0)
		beautified_print(eq->mult[2], 2, eq->variable);
	if (eq->mult[0] == 0.0 && eq->mult[1] == 0.0 && eq->mult[2] == 0.0)
		printf("0");
	printf(" = ");
	if (eq->result[0] != 0.0)
		beautified_print(eq->result[0], 0, eq->variable);
	if (eq->result[0] != 0.0 && eq->result[1] != 0.0)
		printf(" + ");
	if (eq->result[1] != 0.0)
		beautified_print(eq->result[1], 1, eq->variable);
	if ((eq->result[0] != 0.0 || eq->result[1] != 0.0) && eq->result[2] != 0.0)
		printf(" + ");
	if (eq->result[2] != 0.0)
		beautified_print(eq->result[2], 2, eq->variable);
	if (eq->result[0] == 0.0 && eq->result[1] == 0.0 && eq->result[2] == 0.0)
		printf("0");
}
