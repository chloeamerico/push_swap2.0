/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:52:42 by camerico          #+#    #+#             */
/*   Updated: 2025/02/04 14:16:22 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// step 1 : verifie si le nombre est valide
// step 2 : converti en long et on le met dans la stack a
// step 3 : reprend la stack a et verifie si chaque nb est dans les limites de int
// attetion a skip les arguments vides
// un ./push_swap 3 "" "    42  17" 4 ==> est cense passer 
// 42 et 17 seront mis dans 2 indexes differents dans ma stack (faire un split pour chaque argumt)
// faire le check des doubles sur la stack directement
// si tous les arguments sont vides ==> erreur

// verifie qu'il n'y a que des nombres valides (y compris les signes)
// avant de faire atol (step 1)
int valid_number(char *str)
{
	int i;

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

int limits(char *str)
{
	long nb;

	nb = atol(str); //ATTENTION !! avant de push, mettre ft_atol
	if ((nb > INT_MAX) || (nb < INT_MIN))
		return (1);
	return (0);
}


// applique la fonction valid_number et limits a chaque argument
int check_args(int argc, char **argv)
{
	int i;
	
	if (argc < 2) //on verifie min 2 arguments
		return (1);
	
	i = 1;
	while (i < argc)
	{
		if (valid_number(argv[i]) == 1 || limits(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

// parcours la stack et verifie si aucune valeur n'est presente en double
int check_double(t_stack *stack)
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
