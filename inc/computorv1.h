/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmartzol <hmartzol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:03:18 by hmartzol          #+#    #+#             */
/*   Updated: 2018/10/16 17:37:54 by hmartzol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include <stdlib.h>
# include <inttypes.h>
# include <errno.h>
# include <stdio.h>
# include <math.h>
# include <ctype.h>

# define EXAMPLE "(example: \"5 + 4 * X + X ^ 2 = X ^ 2\")"

typedef struct		s_computorv1_equation
{
	int				degree;
	int				nb_solutions;
	char			variable;
	double			mult[3];
	double			result[3];
	double			solutions[2];
}					t_computorv1_equation;

typedef struct		s_computorv1_tmp
{
	double			mult;
	long			exp;
	int				in_result;
	int				error;
}					t_computorv1_tmp;

void				print(t_computorv1_equation *eq);
void				beautified_real(double r);
int					parse(t_computorv1_equation *eq, char *str);

#endif
