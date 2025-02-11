/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camerico <camerico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 23:43:44 by chloeameric       #+#    #+#             */
/*   Updated: 2025/02/11 16:44:43 by camerico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// //Décale d’une position vers le bas tous les élements de la pile a. 
// //Le dernier élément devient le premier.
void	reverse_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*before_last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		before_last = *stack;
		while (before_last->next->next)
			before_last = before_last->next;
		before_last->next->next = first;
		*stack = before_last->next;
		before_last->next = NULL;
	}	
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
