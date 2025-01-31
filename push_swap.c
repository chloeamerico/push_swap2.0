/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:53:36 by camerico          #+#    #+#             */
/*   Updated: 2025/01/31 14:39:46 by chloeameric      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_stack *init_stack(int value)
// {
// 	t_stack *stack;

// 	stack = malloc(sizeof(t_stack));
// 	if (!stack)
// 		return (NULL);
// 	stack->value = value;
// 	stack->index = -1;
// 	stack->next = NULL;
// 	return (stack);
// }

// void *add_first(int value, t_stack *stack)
// {
// 	t_stack	*new;
	
// 	new = malloc(sizeof(*new));
// 	if (!new)
// 		return;
// 	new->value = value;
// 	new->index = 1;
// 	new->next = NULL;
// }

// fonction pour cree un nouveau noeud avec la valeur qu'il doit stocker
t_stack *new_node(int value)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	return (new);
}

// fonction pour ajouter un noeud en haut de la stack
void	add_first(t_stack **stack, t_stack *new)
{
	new->next = *stack;
	*stack = new;
}

// OU on fusionne les deux du dessus
t_stack	*create_node_first(t_stack **stack, int	value)
{
	t_stack	*new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = *stack;

	*stack = new;
	return (new); //peut-etre renvoyer *stack ??
}

//fonction pour verifier si c'est deja trié
bool	is_sorted(t_stack *stack) //fonction en booleen
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//pour choisir quel algorithme choisir
void	which_algo(t_stack *a, t_stack *b)
{
	int	size;

	size = stack_size(a);
	if (is_sorted(a) == true)
		return;
	if (size <= 3)
		sort_3(a, b);
	else if (size <= 5)
		sort_5(a, b);
	else
		radix_sort(a, b);
}

// // initialiser une pile a vide
// t_stack	*init_empty_stack(void)
// {
// 	return (NULL);
// }

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int	i;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	if (check_args == 1) //check si c'est valide et les limites
	{
		write(1, "Error\n", 6);
		return (0);
	}
	
	a = NULL;
	b = NULL;
	i = argc - 1;
	while(i > 1)
	{
		create_node_first(&a, ft_atoi(argv[i]));
		i--;
	}
	if (check_double(a)) // check les doubles dans a
	{
		write(1, "Error\n", 6);
		free(a);
		free(b);
		return (0);
	}
	which_algo(a, b);
	free(a);
	free(b);
	return (0);
}
