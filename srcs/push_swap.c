/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 15:53:36 by camerico          #+#    #+#             */
/*   Updated: 2025/02/12 14:09:30 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction pr creer un nouveau noeud et le mette en bas de la pile directement.
t_stack	*create_node_last(t_stack **stack, int value)
{
	t_stack	*new;
	t_stack	*tmp;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->next = NULL;
	if (*stack == NULL)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
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
	if (size == 0)
		return ;
	else if (is_sorted(*a) == true)
		return ;
	else if (size >= 2 && size <= 5)
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
