/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:12:17 by hmartzol          #+#    #+#             */
/*   Updated: 2018/10/16 17:37:18 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/computorv1.h"

void	simplify(t_computorv1_equation *eq)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		eq->mult[i] -= eq->result[i];
		eq->result[i] = 0.0;
		if (eq->degree == 0 && eq->mult[i] != 0.0)
			eq->degree = i;
	}
}

void	second_degree(t_computorv1_equation *eq)
{
	double disc;

	disc = eq->mult[1] * eq->mult[1] - eq->mult[0] * eq->mult[2] * 4.0;
	if (disc < 0.0)
		printf("Discriminant is strictly negative\n"
		"Solutions: not in R\n");
	else if (disc == 0.0)
	{
		printf("Discriminant is 0\nSolution: %c = ", eq->variable);
		beautified_real(-eq->mult[1] / (2.0 * eq->mult[2]));
		printf("\n");
	}
	else
	{
		printf("Discriminnt is strictly positive\n"
		"First solution: %x = ", eq->variable);
		beautified_real(-eq->mult[1] + sqrt(disc));
		printf("\nSecond solution: %x = ", eq->variable);
		beautified_real(-eq->mult[1] - sqrt(disc));
		printf("\n");
	}
}

void	computorv1(t_computorv1_equation *eq)
{
	printf("Got: ");
	print(eq);
	printf("\n");
	simplify(eq);
	printf("Simpliffied in (%s degree equation): ",
		((char*[3]){"no", "first", "second"})[eq->degree]);
	print(eq);
	printf("\n");
	if (eq->degree == 0)
		printf("Solution: %c = R (all real numbers)\n", eq->variable);
	else if (eq->degree == 1)
	{
		printf("Solution: %c = ", eq->variable);
		beautified_real(-eq->mult[0] / eq->mult[1]);
		printf("\n");
	}
	else
		second_degree(eq);
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
	if (eq.variable == '\0')
		return (0 * printf("Please, at least give us a variable\n"));
	computorv1(&eq);
	return (0);
}
