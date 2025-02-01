/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chloeamerico <chloeamerico@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:53:36 by camerico          #+#    #+#             */
/*   Updated: 2025/01/31 15:59:33 by chloeameric      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// // fonction pour creer un nouveau noeud avec la valeur qu'il doit stocker
// t_stack *new_node(int value)
// {
// 	t_stack *new;

// 	new = malloc(sizeof(t_stack));
// 	if (!new)
// 		return (NULL);
// 	new->value = value;
// 	new->next = NULL;
// 	return (new);
// }

// // fonction pour ajouter un noeud en haut de la stack
// void	add_first(t_stack **stack, t_stack *new)
// {
// 	new->next = *stack;
// 	*stack = new;
// }

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
		sort_3(a);
	else if (size <= 5)
		sort_5(a, b);
	else
		radix_sort(&a, &b);
}


