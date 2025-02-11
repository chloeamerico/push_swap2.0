/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:53:36 by camerico          #+#    #+#             */
/*   Updated: 2025/02/11 16:58:00 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pr creer un nouveau noeud et le mette en haut de la pile directement.
t_stack	*create_node_first(t_stack **stack, int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = *stack;
	*stack = new;
	return (new);
}

//fonction pour verifier si c'est deja trié
bool	is_sorted(t_stack *stack)
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
void	which_algo(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a) == true)
		return ;
	if (size <= 5)
		sort_5(a, b);
	if (size > 5)
		radix_sort(a, b);
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}
