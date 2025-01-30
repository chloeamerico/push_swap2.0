/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:52:42 by camerico          #+#    #+#             */
/*   Updated: 2025/01/21 15:05:11 by camerico         ###   ########.fr       */
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

// applique la fonction valid_number a chaque argument
int check_args(int argc, char **argv)
{
	int i;
	
	if (argc < 2) //on verifie min 2 arguments
		return (1);
	
	i = 1;
	while (argv[i] < argc - 1)
	{
		if (valid_number(argv[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}

//parcours la stack et verifie si aucune valeur ne depasse le int min ou le int max
int	check_limits(t_stack *stack)
{
	while (stack)
	{
		if((stack->value > INT_MAX) || (stack->value < INT_MIN))
			return (1);
		stack = stack->next;
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

// -- NEW--

// verifie si le nombre depasse ou non les limites d'un int.
int limits(long nb)
{
	if ((nb > INT_MAX) || (nb < INT_MIN))
		return (1);
	return (0);
}

int check_double(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int limits(char *str)
{
	long nb;

	nb = ft_atol(str);
	if ((nb > INT_MAX) || (nb < INT_MIN))
		return (1);
	return (0);
}

// verifie qu'il n'y a pas de doublons
int check_double(char *str)
{
	int i;
	int j;

	i = 0;
	j = 1;
	while (str[i])
	{
		while (str[j])
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
		j++;
	}
	return (0);
}

int atoi_v2(char *str, int *error)
{
	long nb;
	int sign;

	*error = 0;
	nb = 0;
	sign = 1;
	if (valid_number(str))
	{
		*error = 1;
		return (0);
	}
	if (*str == '+' || *str == '-') // on gere le signe
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		nb = nb * 10 + (*str - 48);
		if ((nb * sign) > INT_MAX || (nb * sign) < INT_MIN)
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(nb * sign));
}

// verifie qu'iln'y a que des nombres valides (y compris les signes)
int valid_number(char *str)
{
	int i;

	i = 0;
	if (!str || str[0] == '\0')
		return (1);
	if (str[0] == '+' || str[0] == '-')
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

int atoi_v2(char *str, int *error)
{
	long nb;
	long sign;

	*error = 0;
	sign = 1;
	nb = 0;
	if (!str || *str == '\0')
	{
		*error = 1;
		return (0);
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '\0')
	{
		*error = 1;
		return (0);
	}
	while (*str)
	{
		if (*str < '0' || *str > '9')
		{
			*error = 1;
			return (0);
		}
		nb = nb * 10 + (*str - 48);
		if ((nb * sign > INT_MAX) || (nb * sign < INT_MIN))
		{
			*error = 1;
			return (0);
		}
		str++;
	}
	return ((int)(nb * sign));
}

int atoi_v2(char *str)
{
	int i;
	long nb;
	long sign;

	i = 0;
	sign = 1;
	nb = 0;
	if (!str || str[0] == '\0')
		return (1);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (1);

	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		nb = nb * 10 + (str[i] + 48);
		i++;
	}
	if ((nb * sign > INT_MAX) || (nb * sign < INT_MIN))
		return (1);
	return (nb * sign);
}

// transfome en long et verifie si ca ne depasse pas les INT_MIN et INT_MAX
//  int	to_long_and_limits(char *str, long	*result)
//  {
//  	int	i;
//  	int	nb;
//  	int	sign;

// 	i = 0;
// 	sign = 1;
// 	nb = 0;
// 	if (str[i] == '+' || str[i] == '-')
// 	{
// 		if (str[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	while (str[i])
// 	{
// 		nb = nb * 10 + (str[i] + 48);
// 		i++;
// 	}
// 	if ((nb * sign > INT_MAX) || (nb * sign < INT_MIN))
// 		return (1);
// 	else
// 		return (nb * sign);
// }

int main(void)
{
	check_double("1 2 3 4 4 6 7");
	return (0);
}
