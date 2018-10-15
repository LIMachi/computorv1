/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 19:01:35 by hmartzol          #+#    #+#             */
/*   Updated: 2018/10/15 19:03:17 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/computorv1.h"
#include <stdio.h>

static inline void	beautified_print(double mult, long exp, char variable)
{
	char	tmp[42];
	int		i;

	if (mult == 0.0)
		printf("0");
	else
	{
		if (mult != 1.0)
		{
			snprintf(tmp, 41, "%.12f", mult);
			i = 0;
			while (tmp[i] != '\0')
				++i;
			while (i > 0 && tmp[i - 1] == '0')
				tmp[--i] = '\0';
			if (i > 0 && tmp[i - 1] == '.')
				tmp[i - 1] = '\0';
			printf("%s%s", tmp, exp ? " * " : "");
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