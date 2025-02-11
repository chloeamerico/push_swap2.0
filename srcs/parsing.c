/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:52:42 by camerico          #+#    #+#             */
/*   Updated: 2025/02/11 18:34:24 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// verifie qu'il n'y a que des nombres valides (y compris les signes)
// avant de faire atol (step 1)
int	valid_number(char *str)
{
	int	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	if (str[0] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	limits(char *str)
{
	long	nb;

	nb = ft_atol(str);
	if ((nb > INT_MAX) || (nb < INT_MIN))
		return (1);
	return (0);
}

// applique la fonction valid_number et limits a chaque argument
int	check_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	**number;

	i = 1;
	while (i < argc)
	{
		number = ft_split(argv[i], ' ');
		if (!number)
			return (1);
		j = 0;
		while (number[j])
		{
			if (valid_number(number[j]) == 1 || limits(number[j]) == 1)
			{
				free_split(number);
				return (1);
			}
			j++;
		}
		free_split(number);
		i++;
	}
	return (0);
}

// parcours la stack et verifie si aucune valeur n'est presente en double
int	check_double(t_stack *stack)
{
	t_stack	*i;
	t_stack	*j;

	i = stack;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
