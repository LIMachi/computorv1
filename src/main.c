/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:12:17 by hmartzol          #+#    #+#             */
/*   Updated: 2018/10/15 19:20:02 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <stdlib.h>
#include <inttypes.h>
#include <errno.h>
#include <stdio.h>
#include <math.h>
#include "../inc/computorv1.h"

void	computorv1(t_computorv1_equation *eq)
{
	printf("got: ");
	print(eq);
	printf("\n");
}

int		main(int argc, char const *argv[])
{
	int								error;
	static t_computorv1_equation	eq = {
		.degree = 0, .nb_solutions = 0, .variable = '\0',
		.mult = {0.0, 0.0, 0.0}, .result = {0.0, 0.0, 0.0},
		.solutions = {0.0, 0.0}};
	
	if (argc != 2)
		return (0 * printf("Usage: %s \"equation\" " EXAMPLE "\n", argv[0]));
	if ((error = parse(&eq, (char*)argv[1])))
		return (error);
	computorv1(&eq);
	return (0);
}
